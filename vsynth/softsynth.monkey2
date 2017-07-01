' softsynth.monkey2

'#Import "assets/whale52hz.wav"
#Import "assets/engine1.wav"

Alias V:Double ' Voltage(volts)
Alias F:Double ' Frequency(hz)
Alias T:Double ' Time(seconds)

Alias Note:Int
Alias Tempo:Int ' BeatsPerMinute
Alias K:Key

Global Duration:=0

Global AudioFrequency:=44100

Const MaxPolyphony:=64
Const MaxOctave:=12

Class Envelope
	Field p:V
	Method On:V() Virtual
		Return 1.0
	End
	Method Off:V() Virtual
		Return 0.0
	End
End

Class ADSR Extends Envelope
	Field attack:T
	Field decay:T
	Field sustain:V
	Field release:T
	
	Method New(a:T,d:T,s:V,r:T)
		attack=a
		decay=d
		sustain=s
		release=r
	End
	
	Field t:T
	Field value:V
	Field noteOn:Bool

	Method On:V() Override
		If Not noteOn
			t=0
			noteOn=True
		Endif
		t+=1.0/AudioFrequency
		Local v:=sustain
		If t<attack 
			v=t/attack
		Elseif t-attack<decay 
			v=1.0-((1-sustain)*(t-attack)/decay)
		Endif
		value=v
		Return v
	End

	Method Off:V() Override
		If noteOn
			t=0
			noteOn=False
		Endif
		t+=1.0/AudioFrequency
		If t<release 
			Return value*(1.0-t/release)
		Endif
		Return 0.0
	End
End


Class Oscillator
	Field delta:T
	Method Sample:V(hz:F) Virtual
		Return 0
	End
End

Class Sine Extends Oscillator	
	Method Sample:V(hz:F) Override
		Local t:T=hz/AudioFrequency
		delta+=t
		Return Cos(2*Pi*delta)
	End
End

Class Sawtooth Extends Oscillator
	Method Sample:V(hz:F) Override
		Local t:T=hz/AudioFrequency
		delta+=t		
		Return ((delta+1) Mod 2)-1
	End
End

Class Triangle Extends Oscillator
	Method Sample:V(hz:F) Override
		Local t:T=hz/AudioFrequency
		delta+=t
		Return (Abs(delta Mod 2)-1)
	End
End

Class Square Extends Oscillator
	Method Sample:V(hz:F) Override
		Local t:T=hz/AudioFrequency
		delta+=t
		Return -1+2*(Int(delta)&1)
	End
End

Class Noise Extends Oscillator
	Field a:V
	Method Sample:V(hz:F) Override
		Local t:T=hz/AudioFrequency
		Local delta0:=delta
		delta+=t		
		Local f:=delta Mod 1				
		If Int(delta0)<>Int(delta)
			a=Rnd()
		Endif	
		Return 1-2*a	'(a+f*(b-a)		
	End
End

Class Rompler Extends Oscillator
	Global SampleCache:=New Map<String,AudioData>
	Field a:V
	Field audioData:AudioData
	Field bytespersample:Int
	Field pitch:F
		
	Method New()
		audioData=Load("asset::engine1.wav")	
		bytespersample=BytesPerSample(audioData.Format)
		pitch=110.0
	End
	
	Function Load:AudioData(uri:String)
		If SampleCache.Contains(uri) Return SampleCache[uri]
		Local audioData:=AudioData.Load(uri)
		Print "sampler loaded:"+audioData.Length+"@"+audioData.Hertz+" format="+Int(audioData.Format)
		SampleCache[uri]=audioData
		Return audioData
	End

	Method Sample:V(hz:F) Override		
		Local t:=hz*audioData.Hertz/(pitch*AudioFrequency)		
		Local delta0:=delta
		delta+=t
		Local f:=delta
		f=f Mod (audioData.Length/bytespersample)
		Local i:Int=f		
		Local udata:=audioData.Data		
		Local sdata:=Cast<Byte Ptr>(udata)
		Select audioData.Format
			Case AudioFormat.Mono8 
				Return (udata[i]-128)/127.0
			Case AudioFormat.Mono16 
				Return (sdata[i*2+1]*256+sdata[i*2+0])/32767.0
			Case AudioFormat.Stereo8 
				Return (udata[i*2+0]-128)/127.0
			Case AudioFormat.Stereo16 
				Return (sdata[i*4+1]*256+sdata[i*4+0])/32767.0
		End
		Return 0
	End
End

Alias SampleData:Deque<V>

Class SampleBank
	Global this:=New SampleBank
	Field sampleData:=New SampleData
	Field pitch:=220.0
	Field freq:=44100

	Function SampleData:SampleData()
		Return this.sampleData
	End

	Method Record(sample:V Ptr,count:Int)
		For Local i:=0 Until count
			sampleData.PushLast(sample[i])
		Next
	End
End
	
Class Sampler Extends Oscillator
	Field samples:SampleData
	Field pitch:=220.0
	Field freq:=44100
	
	Method New()
		samples=SampleBank.SampleData()
	End

	Method Sample:V(hz:F) Override		
		If samples.Length=0 Return 0
		Local t:=hz*freq/(pitch*AudioFrequency)		
		Local delta0:=delta
		delta+=t
		Local f:=delta
		f=f Mod samples.Length
		Return samples[f]
	End	
End

Class LiveMicrophone Extends Sampler

	Global mic:Microphone
	Field count:int

	Method Poll()
		If Not mic 
			mic=New Microphone
		endif		
		mic.Poll(samples)
	End
	
	Method Sample:V(hz:F) Override			
		count-=1
		If count<0
			Poll()
			count=mic.fragsize 
		endif
		Return Super.Sample(hz)
	End

End

Class Microphone
	Field device:ALCdevice Ptr
	Field error:Int
	Field audioFormat:int
	Field rate:=44100
	Field fragsize:=1024
	Field buffer:=New Stack<Byte>
	Field recording:Bool
	
	Method New()
		local p:=Cast<Byte ptr>(alcGetString(Cast<ALCdevice ptr>(0), ALC_CAPTURE_DEVICE_SPECIFIER))	
		local s:=String.FromCString(p)
		print "Microphone OpenAL Capture List:"+s
		audioFormat=AL_FORMAT_STEREO16
		device=alcCaptureOpenDevice(NULL,rate,audioFormat,fragsize)
		error=alGetError()
		If error
			Print "Microphone error "+error
			Return
		Endif
	End
	
	Method Stop()
		If recording
			alcCaptureStop(device)
			recording=false
		Endif
	end

	Method Poll(sampleData:SampleData)
		If Not recording
		    alcCaptureStart(device)		
			recording=True
		Endif		
		Local sample:Int			
		alcGetIntegerv(device, ALC_CAPTURE_SAMPLES,4,Varptr sample)
		If sample=0 Return
		buffer.Resize(sample*4)
		alcCaptureSamples(device,Varptr buffer.Data[0],sample)
		Local udata:=Varptr buffer.Data[0]		
		Local sdata:=Cast<Byte Ptr>(udata)
		Select audioFormat
'			Case AudioFormat.Mono8 
'				Return (udata[i]-128)/127.0
'			Case AudioFormat.Mono16 
'				Return (sdata[i*2+1]*256+sdata[i*2+0])/32767.0
'			Case AudioFormat.Stereo8 
'				Return (udata[i*2+0]-128)/127.0
			Case AL_FORMAT_STEREO16 
				For Local i:=0 Until sample
					sampleData.PushLast((sdata[i*4+1]*256+sdata[i*4+0])/32767.0)
				Next
			Default
				Print "Unsupported Microphone audioFormat"
		End
	End
		
	Method Close()	
	    alcCaptureStop(device)
    	alcCaptureCloseDevice(device)
    End
End

Interface NotePlayer
	Method SetOscillator(osc:Int)
	Method SetEnvelope(env:Int)
	Method SetPan(value:V)
	Method SetGain(value:V)
	Method Stop()
	Method NoteOn(note:Int,Velocity:Int)
	Method NoteOff()
End


Class Voice Implements NotePlayer
	Field oscillator:Oscillator
	Field envelope:Envelope
	Field noteOn:Bool
	Field hz:F
	Field pan:V
	Field gain:V=0.80	'0.12 was pre record setting
	Field amp:V
	
	Method SetOscillator(osc:Int)
		Select osc
			Case 0 oscillator=New Square
			Case 1 oscillator=New Sine
			Case 2 oscillator=New Sawtooth
			Case 3 oscillator=New Triangle
			Case 4 oscillator=New Noise
			Case 5 oscillator=New Rompler
			Case 6 oscillator=New LiveMicrophone
			Case 7 oscillator=New Sampler
		End
	End
	
	Method SetEnvelope(env:Int)
		Select env
			Case 0 
				envelope=New Envelope()
			Case 1 
				envelope=New ADSR(0.002,1.5,0.2,0.5)
			Case 2
				envelope=New ADSR(0.06,0.01,0.92,0.2)
			Case 3 
				envelope=New ADSR(0.06,2.0,0.2,1.2)
			Case 4
				envelope=New ADSR(0.2,0.2,0.92,0.4)
		End
	End

	Method SetPan(value:V)
		pan=value
	End
	
	Method SetGain(value:V)
		gain=value
	End

	Method Stop()
		NoteOff()
		envelope.Off()
	End	
	
	Method NoteOn(note:Int,velocity:Int)
		hz=440.0*Pow(2.0,(note-67.0)/12)
		amp=velocity/100.0
		noteOn=True
	End
	
	Method NoteOff()
		noteOn=False
	End
	
	Method Mix(buffer:Double[],samples:Int,detune:V[],fade:V[])
		Local left:=1.0
		Local right:=1.0
		If pan<0 right+=pan
		If pan>0 left-=pan		
		For Local i:=0 Until samples
			Local v:=oscillator.Sample(hz*detune[i])			
			Local e:V
			If noteOn e=envelope.On() Else e=envelope.Off()
			If e=0
				oscillator.delta=0			
			Else
				e*=gain
				e*=amp
				e*=fade[i]
				buffer[i*2+0]+=e*left*v
				buffer[i*2+1]+=e*right*v
			Endif
		Next
	End
End

Enum SynthCommand
	Rewind=1
	Play=2
	Forward=3
	Loop=4
	Stop=5
	Record=6
	NextProgram=7
	PreviousProgram=8
	User=10
	Patch1=128
	Patch2=129
	Patch3=130
	Patch4=131
End

Interface Synth
	Method SetTempo(tempo:Tempo,divisor:Int,duty:V,rept:int)
	Method SetTone(osc:Int,env:Int)
	Method Command(command:SynthCommand,depressed:bool)
	Method SetVolume(volume:V)
	Method NoteOn(note:Int,velocity:int)
	Method NoteOff(note:Int)
	Method SetSustain(sustain:Bool)
	Method FillAudioBuffer(buffer:Double[],samples:Int,detune:V[],fade:V[])	
	Method Panic()
	Method GetKeymap:Keymap()
End


Struct Keymap
	Field low:Long
	Field high:Long	

	Method KeyDown:Bool(index:Int)
		Local bit:Long=1	
		Local shift:Long=index&63
		If index<64 Return ((low Shr shift)&bit)=bit
		index-=64
		Return ((high Shr shift)&bit)=bit
	End
	
	Method NoteOn(index:Int)
		Local bit:Long=1
		Local shift:Long=index&63
		bit=bit Shl shift
		If index<64 low|=bit Else high|=bit
	End

	Method NoteOff(index:Int)
		Local bit:Long=1
		Local shift:Long=index&63
		bit=bit Shl shift
		If index<64 low&=~bit Else high&=~bit
	end
End


Class BeatGenerator Implements Synth

	Field bpm:=120
	Field divisor:=3
	Field dutycycle:=0.5
	Field output:Synth
	Field time:T
	Field clock:T
	Field oscillator:Int
	Field envelope:Int
	Field repeats:Int
	Field recent:Note
	Field velocity:Note
	Field count:int
	
	Field notePeriod:T
	Field dutyPeriod:T

	Field keymap:=New Keymap
	
	Method New()
	End
	
	Method SetTempo(tempo:Tempo,div:Int,duty:V,rept:int)
		bpm=tempo
		divisor=div
		dutycycle=duty
		notePeriod=60.0/(bpm*divisor)
		dutyPeriod=duty*notePeriod
		repeats=rept
	End
	
	Method SetSustain(sustain:Bool)
		output.SetSustain(sustain)
	End

	Method SetVolume(volume:V)
		output.SetVolume(volume)
	End

	Method SetSynth(synth:Synth)
		output=synth
		output.SetTone(oscillator,envelope)
	End

	Method SetTone(osc:Int,env:Int)
		oscillator=osc
		envelope=env
		output.SetTone(oscillator,envelope)
	end

	Method Command(command:SynthCommand,depressed:bool)
		output.Command(command,depressed)
	End

	Method NoteOn(note:Int,vel:Int) Virtual
		recent=note
		velocity=vel
		keymap.NoteOn(note)
	End
	
	Method NoteOff(note:Int) virtual
		output.NoteOff(note)
		keymap.NoteOff(note)
	End
	
	Method Beat() Virtual
		If recent
			NoteOn(recent,velocity)
		Endif
	End
	
	Method Update(duration:T)
		time+=duration
		If notePeriod>0
			While clock<time
				Beat()
				clock+=notePeriod
			Wend
			StepDuration(duration)
		Endif
	end

	Field noteDuration:=new Map<Int,T>
	
	Method StepDuration(duration:T)
		For Local note:=Eachin noteDuration.Keys			
			If noteDuration[note]>0
				noteDuration[note]-=duration
				If noteDuration[note]<=0
					output.NoteOff(note)
				Endif
			Endif
		Next
	end

	Method FillAudioBuffer(buffer:Double[],samples:Int,detune:V[],fade:V[])	
		Update(2.0*samples/AudioFrequency)
		output.FillAudioBuffer(buffer,samples,detune,fade)
	End

	Method GetKeymap:Keymap()
		Return output.GetKeymap()
	End
	
	Method Panic()
		output.Panic()
	end

	Method TriggerNote(note:Int)	
		output.NoteOn(note,velocity)
		noteDuration[note]=dutyPeriod
	End
	
	Method ReleaseAll() Virtual
		For Local note:=Eachin noteDuration.Keys			
			output.NoteOff(note)
		Next	
		noteDuration.Clear()
	End

End

Class Arpeggiator extends BeatGenerator
	Field natural:=New Stack<Note>
	Field sorted:Stack<Note>
	Field index:Int
	Field algorithm:Int
	Field progression:Int
	Field hold:Bool
	Field noteCount:Int
	field note:Int
	Field cycle:int
	
	Method New()
	End

	Method SetArpeggiation(mode:Int,prog:Int)
		algorithm=mode
		progression=prog
	End
		
	Method ReleaseAll() Override
		Super.ReleaseAll()
		natural.Clear()
	end
	
	Method SetHold(down:Bool)
		If hold And Not down 
			ReleaseAll()
			noteCount=0
			cycle=0
		End
		hold=down
	End

	Method NoteOn(note:Int,vel:Int) Override
		If hold and noteCount=0
			ReleaseAll()
		Endif
		noteCount+=1
		If algorithm=0			
			output.NoteOn(note,vel)
		else		
			Super.NoteOn(note,vel)
			If natural.Contains(note) natural.Remove(note)
			natural.Push(note)
			sorted=New Stack<Note>(natural)
			sorted.Sort()
		Endif
	End
	
	Method NoteOff(note:Int) Override
		if noteCount>0
			noteCount-=1
		endif
		output.NoteOff(note)
		If Not hold
			natural.Remove(note)
			sorted=New Stack<Note>(natural)
			sorted.Sort()
		endif
	End
	
	Method Beat() Override
		
		If natural.Length=0
			index=0
			return
		Endif
		
		If count>0
			count-=1
			If note TriggerNote(note)
			return
		Endif
		
		If index>=natural.Length cycle+=1

		Select algorithm
			Case 1
				index=index Mod natural.Length
				note=natural[index]
				index+=1
			Case 2			
				index=index Mod sorted.Length
				note=sorted[index]
				index+=1
			Case 3
				index=index Mod sorted.Length
				note=sorted[sorted.Length-index-1]
				index+=1
			Case 4			
				If sorted.Length>1
					Local bounce:=sorted.Length-2
					index=index Mod (sorted.Length+bounce)
					Local i:=index
					If i>bounce i=sorted.Length+bounce-index
					note=sorted[i]
				Else
					note=sorted[0]
				Endif
				index+=1
			Case 5
				index=index Mod sorted.Length
				note=sorted[index]
				if RndULong() & 1
					index+=1
				Else
					index-=1
					If index<0 index=sorted.Length-1
				Endif
			Case 6
				index=Rnd()*sorted.Length
				note=sorted[index]
		End
		
		Select progression
			Case 1
				cycle=cycle Mod natural.Length
				note+=natural[cycle]-natural[0]
			Case 2		
				note+=cycle
			Case 3
				note-=cycle
		end
		
		If note TriggerNote(note)
		count=repeats
	End
End

Class PolySynth Implements Synth

	Field polyList:=New List<Voice>
	Field polyMap:=New Map<Int,Voice>
	Field voices:=New Stack<Voice>
	Field sustained:Bool
	Field oscillator:Int
	Field envelope:Int
	Field volume:V=1.0
	Field sustainedVoices:=New List<Voice>
	Field keymap:=New Keymap
	
	Method New()
		For Local i:=0 Until MaxPolyphony
			Local tone:=New Voice
			tone.SetOscillator(0)
			tone.SetEnvelope(0)
			polyList.AddLast(tone)
		Next
	End
	
	Method GetKeymap:Keymap()
		Return keymap
	End

	Method Panic()
		voices.Clear()
	End

	Method SetTempo(tempo:Tempo,divisor:Int,duty:V,rept:int)
	End
			
	Method SetVolume(vol:V)
		volume=vol
	End

	Method SetSustain(sustain:Bool)
		If sustained And Not sustain
			For Local voice:=Eachin sustainedVoices
				voice.Stop()
			Next
			sustainedVoices.Clear()		
		Endif
		sustained=sustain
	End

	Method SetTone(osc:Int,env:Int)
		oscillator=osc
		envelope=env
	End

	Method Command(command:SynthCommand,depressed:bool)
		Select command
			Case SynthCommand.NextProgram
				oscillator=(oscillator+1) Mod 8
			Case SynthCommand.PreviousProgram
				oscillator=(oscillator+7) Mod 8
		End
	End

	Method NoteOn(note:Int,velocity:Int)
		NoteOff(note)
		If polyList.Empty Return
		Local voice:=polyList.RemoveFirst()
		voice.SetEnvelope(envelope)
		voice.SetOscillator(oscillator)
		voice.NoteOn(note,velocity)
		polyMap[note]=voice
'		polyList.Remove(voice)
		If Not voices.Contains(voice)
			voices.Add(voice)
		Endif	
		keymap.NoteOn(note)
	End

	Method NoteOff(note:Int)	
		Local voice:=polyMap[note]
		If voice
			If sustained
				sustainedVoices.AddLast(voice)
			Else
				voice.Stop()
			Endif
			polyMap.Remove(note)
			polyList.AddLast(voice)
		Endif
		keymap.NoteOff(note)
	End

	Method FillAudioBuffer(buffer:Double[],samples:Int,detune:V[],gain:V[])	
		For Local voice:=Eachin voices
			voice.Mix(buffer,samples,detune,gain)
		Next		
	End
End

Class MonoSynth Implements Synth
	Field tone:Voice
	Field monoNote:Int
	Field monoVelocity:int
	Field notes:=New Stack<Int>
	Field oscillator:Int	
	Field envelope:Int
	Field volume:V=1.0
	Field keymap:=New Keymap

	Method New()
		tone=New Voice
		tone.SetOscillator(0)
		tone.SetEnvelope(0)
	End
	
	Method SetTempo(tempo:Tempo,divisor:Int,duty:V,rept:int)
	End

	Method SetVolume(vol:V)
		volume=vol
	End
	
	Method SetSustain(sustain:Bool)
	End

	Method GetKeymap:Keymap()
		Return keymap
	end

	Method Panic()
		tone.NoteOff()
	End

	Method SetTone(osc:Int,env:Int)
		If osc<>oscillator
			oscillator=osc
			tone.SetOscillator(oscillator)
		Endif
		If env<>envelope
			envelope=env
			tone.SetEnvelope(envelope)
		Endif
	End

	Method Command(command:SynthCommand,depressed:bool)
		Select command
			Case SynthCommand.NextProgram
				oscillator=(oscillator+1) Mod 8
			Case SynthCommand.PreviousProgram
				oscillator=(oscillator+7) Mod 8
		End
	end

	Method NoteOn(note:Int,velocity:Int)
		monoNote=note
		monoVelocity=velocity
		If Not notes.Contains(note)
			notes.Push(note)
		Endif
		tone.NoteOn(note,velocity)
		keymap.NoteOn(note)
	End

	Method NoteOff(note:Int)
		keymap.NoteOff(note)
		notes.Remove(note)
		If notes.Empty
			tone.NoteOff()		
		Else
			note=notes.Pop()
			monoNote=note
			notes.Push(note)
			tone.NoteOn(note,monoVelocity)
			keymap.NoteOn(note)
		Endif
	End

	Method FillAudioBuffer(buffer:Double[],samples:Int,detune:V[],fade:V[])	
		tone.Mix(buffer,samples,detune,fade)
	End

End

Class MidiSynth Implements Synth
	Const _NoteOn:=144
	Const _NoteOff:=128
	Const _ControllerChange:=176
	Const _SysEx:=240

	Const _VolumeController:=7
	Const _ExpressionController:=11
	Const _SustainPedal:=64

	Field portMidi:PortMidi
	Field send:Int
	Field keymap:=New Keymap

	method new(driver:PortMidi,channel:Int)
		portMidi=driver
		send=channel
	End

	Method SetTempo(tempo:Tempo,divisor:Int,duty:V,rept:int)
	End
	
	Method SetVolume(volume:V)
		If volume<0 volume=0
		If volume>1 volume=1
		local value7:Int=127*volume
		Local setVolume:Int=(_ControllerChange)|(_VolumeController Shl 8)|(value7 Shl 16)
		portMidi.SendMessage(send,setVolume)
	End

	Method SetSustain(depress:Bool)
		local value7:Int
		If depress value7=127
		Local setSustain:Int=(_ControllerChange)|(_SustainPedal Shl 8)|(value7 Shl 16)
		portMidi.SendMessage(send,setSustain)
	End
	
	method SetTone(oscillator:Int,envelope:Int)
	End
	
	Method Command(command:SynthCommand,depressed:bool)
		Select command
			Case SynthCommand.NextProgram
			Case SynthCommand.PreviousProgram
		End
	end

	Method NoteOn(note:Int,velocity:int)
		Local noteOn:Int=(_NoteOn)|(note Shl 8)|(velocity Shl 16)
		portMidi.SendMessage(send,noteOn)
		keymap.NoteOn(note)
	End
	
	Method NoteOff(note:Int)
		Local noteOff:Int=(_NoteOff)|(note Shl 8)
		portMidi.SendMessage(send,noteOff)
		keymap.NoteOff(note)
	End
			
	Method FillAudioBuffer(buffer:Double[],samples:Int,detune:V[],fade:V[])	
	End
	
	Method GetKeymap:Keymap()
		Return keymap
	End

	Method Panic()
	End
End
