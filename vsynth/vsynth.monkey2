#Import "<std>"
#Import "<mojo>"
#Import "<sdl2>"
#Import "<portmidi>"

#Import "assets/whale52hz.wav"
#Import "assets/engine1.wav"

Using std..
Using mojo..
Using sdl2..
Using portmidi..
Using openal..

Global AppTitle:String="VSynth 0.04"	
Global Contact:="Latest Source=github.com/nitrologic/m2"

Global About:="VSynth Control"
Global Octave1:= "Sharps=    W   E       T   Y   U      "
Global Octave0:= "Notes=A   S   D  F   G   H    J  K"
Global Controls:="Midi Panic=Escape,Quit=EscapeEscape"

Global RecordNames:=New String[]("Paused","Recording")
Global SustainNames:=New String[]("Up","Down")
Global OscillatorNames:=New String[]("Square","Sine","Sawtooth","Triangle","Noise","Rom","Live Mic","Sampler")
Global EnvelopeNames:=New String[]("None","Plain","Punchy","SlowOut","SlowIn")
Global ArpNames:=New String[]("None","Natural","Ascending","Descending","UpDown","Random1","Random2")
Global ProgNames:=New String[]("None","Recurse","Ascend","Descend")
Global SynthNames:=New String[]("Mono1","Poly32","MidiOut")
Global HoldNames:=New String[]("Off","On")
Global DivisorNames:=New String[]("Whole","Half","Third","Quarter","Fifth","Sixth","Seventh","Eighth")
Global DutyNames:=New String[]("1:2","3:4","1:4","7:8","1:8","5:8","3:8")
Global DutyCycle:=New Double[](0.5,0.75,0.25,0.875,0.125,0.625,0.375)
Global RepeatNames:=New String[]("1x","2x","3x","4x")

Alias V:Double ' Voltage(volts)
Alias F:Double ' Frequency(hz)
Alias T:Double ' Time(seconds)

Alias Note:Int
Alias Tempo:Int ' BeatsPerMinute
Alias K:Key

Public

Global instance:AppInstance
Global vsynth:VSynth

Global Duration:=0
Global FragmentSize:=24

Global AudioFrequency:=44100

Const MaxPolyphony:=32
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
	Field noteOn:Bool

	Method On:V() Override
		If Not noteOn
			t=0
			noteOn=True
		Endif
		t+=1.0/AudioFrequency
		If t<attack Return t/attack
		If t-attack<decay Return 1.0-((1-sustain)*(t-attack)/decay)
		Return sustain
	End

	Method Off:V() Override
		noteOn=False
		t+=1.0/AudioFrequency
		If t<release 
			Return 1.0-t/release
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
		delta=(delta+t) Mod 1.0
		Return Sin(2*Pi*delta)
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

#rem
Class AudioBank Extends Sampler
	
	Method Sample:V(hz:F) Override			
		If samples.Empty Poll()
		If samples.Empty
			For Local i:=0 Until 256
				samples.PushLast(0)
			next 
			Return 0		
		Endif
		Return Super.Sample(
		
		Return samples.PopLast()
'		Local t:=hz*audioData.Hertz/(pitch*AudioFrequency)		
'		Local delta0:=delta
'		delta+=t
	End
	
	Method Poll() Virtual
	End
End

Class LiveMicrophone Extends AudioBank

	Method Poll() Virtual
		Microphone.Default().Poll(
	End
End
#end

Class Microphone
	Field device:ALCdevice Ptr
	Field error:Int
	Field audioFormat:int
	Field rate:=44100
	Field fragsize:=4096
	Field buffer:=New Stack<Byte>
	Field recording:Bool
	
	Method New()
		local p:=Cast<Byte ptr>(alcGetString(Cast<ALCdevice ptr>(0), ALC_CAPTURE_DEVICE_SPECIFIER))	
		local s:=String.FromCString(p)
		print "OpenAL Inputs:"+s
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
		endif
		Local sample:Int			
		alcGetIntegerv(device, ALC_CAPTURE_SAMPLES,4,Varptr sample)
		If sample=0 Return

		buffer.Resize(sample*4)
		alcCaptureSamples(device,Varptr buffer.Data[0],sample)

		Local udata:=Varptr buffer.Data[0]		
		Local sdata:=Cast<Byte Ptr>(udata)

		Select audioFormat
			Case AudioFormat.Mono8 
'				Return (udata[i]-128)/127.0
			Case AudioFormat.Mono16 
'				Return (sdata[i*2+1]*256+sdata[i*2+0])/32767.0
			Case AudioFormat.Stereo8 
'				Return (udata[i*2+0]-128)/127.0
			Case AL_FORMAT_STEREO16 
				For Local i:=0 Until sample
					sampleData.PushLast((sdata[i*4+1]*256+sdata[i*4+0])/32767.0)
				Next
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
'			Case 6 oscillator=New LiveMicrophone
			Case 7 oscillator=New Sampler
		End
	End
	
	Method SetEnvelope(env:Int)
		Select env
			Case 0 
				envelope=New Envelope()
			Case 1 
				envelope=New ADSR(0.05,1.5,0.2,0.3)
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
			e*=gain
			e*=amp
			e*=fade[i]
			buffer[i*2+0]+=e*left*v
			buffer[i*2+1]+=e*right*v
		Next
	End
End

Interface Synth
	Method SetTempo(tempo:Tempo,divisor:Int,duty:V,rept:int)
	method SetTone(oscillator:Int,envelope:Int)
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
end

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
		endif
		sustained=sustain
	End

	Method SetTone(osc:Int,env:Int)
		oscillator=osc
		envelope=env
	End
	
	Method NoteOn(note:Int,velocity:Int)
		NoteOff(note)
		If polyList.Empty Return
		Local voice:=polyList.RemoveFirst()
		voice.SetEnvelope(envelope)
		voice.SetOscillator(oscillator)
		voice.NoteOn(note,velocity)
		polyMap[note]=voice
		polyList.Remove(voice)
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
		endif
	End

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


Const RewindButton:=1
Const PlayButton:=2
Const ForwardButton:=3
Const LoopButton:=4
Const StopButton:=5
Const RecordButton:=6
Const NextProgram:=7
Const PrevProgram:=8
Const UserButton:=10
Const Patch:=128

Class VSynth
	Field audioSpec:SDL_AudioSpec
	Field detune:V
	Field fade:V=1.0
	Field detune0:V
	Field fade0:V=1.0
	Field poly:Synth=New PolySynth()
	Field mono:Synth=New MonoSynth()
	Field root:Synth
	Field arpeggiator:=New Arpeggiator()
	Field midiSynth:MidiSynth
	Field synthMode:Int

	Field buffer:=New Double[FragmentSize*2]
	Field detuneBuffer:=New V[FragmentSize]
	Field fadeBuffer:=New V[FragmentSize]
	Field scope:=New Scope()

	Field position:Double
	Field panSpeed:Double=1.0/1024	'samples per pixel
	Field panAmp:V
	Field recording:=False
		
	Method New()
		arpeggiator.SetSynth(mono)
		arpeggiator.SetArpeggiation(1,0)
		root=arpeggiator
	End
	
	Method FillAudioBuffer:Double[](samples:Int)		
		For Local i:=0 Until samples
			buffer[i*2+0]=0
			buffer[i*2+1]=0
			detuneBuffer[i]=detune0+i*(detune-detune0)/samples
			fadeBuffer[i]=fade0+i*(fade-fade0)/samples
		Next			
		detune0=detune
		fade0=fade
		If root
			root.FillAudioBuffer(buffer,samples,detuneBuffer,fadeBuffer)			
			Duration+=samples			
			PlotScope(samples)
			If recording
				Record(samples)
			Endif
		Endif
		Return buffer
	End
	
	Method PlotScope(samples:Int)	
		' green left channel
		scope.Pen(LowSaturatedGreen)
		For Local i:=0 Until samples
			scope.Plot(buffer[i*2+0])			
		Next
		' red right channel
		scope.Pen(LowSaturatedRed)
		For Local i:=0 Until samples
			scope.Plot(panAmp*buffer[i*2+1])			
		Next
' advance head
		position+=samples*panSpeed
		scope.Advance(0.25*Int(position))
	End
	
	Method Record(samples:Int)
		Local s:=SampleBank.this
		s.Record(buffer.Data,samples)
	End
	
	Method SetMidiOutput(portMidi:PortMidi,midiSend:Int)
		midiSynth=New MidiSynth(portMidi,midiSend)
		SetSynth(synthMode)
	End
	
	Method SetSustain(sustain:Bool)
		root.SetSustain(sustain)
	End

	Method SetTone(oscillator:Int,envelope:Int)
		root.SetTone(oscillator,envelope)
	End
	
	Method NoteOn(note:Int,velocity:Int)
		root.NoteOn(note,velocity)
	End

	Method NoteOff(note:Int)	
		root.NoteOff(note)
	End

	Method GetKeymap:Keymap()
		Return root.GetKeymap()
	End
	
	Method SetSynth(synth:Int)
		synthMode=synth		
		Select synth
			Case 0
				arpeggiator.SetSynth(mono)
			Case 1
				arpeggiator.SetSynth(poly)
			Case 2
				If midiSynth arpeggiator.SetSynth(midiSynth)
		End
	End
		
	Method CycleRecord()
		recording=Not recording
	End

	Method SetTempo(tempo:Tempo,divisor:Int,duty:V,rept:int)
		arpeggiator.SetTempo(tempo,divisor,duty,rept)
	End

'	Method SetVolumeFader(vol:V)
'		fade=vol
'	End
	
	Method SetVolume(volume:V)
		fade=volume*volume
'		arpeggiator.SetVolume(volume)
	End

	Method SetArp(arpmode:Int,prog:Int)
		arpeggiator.SetArpeggiation(arpmode,prog)
	End
	
	Method SetHold(hold:Bool)
		arpeggiator.SetHold(hold)
	End
	
	Method Detune(bend:V)
		detune=bend
	End
	
	Method PanScope(panx:V,pany:V)
		panSpeed=(1+panx*panx)/2048.0
		panAmp=1+pany*pany
	End
	
	Method ClearKeys()
		root.Panic()
	End
	
	Method OnButton(button:Int)
		Select button
			Case RecordButton
				CycleRecord()
			Case NextProgram
'				oscillator=Wrap(oscillator+1,0,OscillatorNames.Length)
			Case PrevProgram
'				oscillator=Wrap(oscillator-1,0,OscillatorNames.Length)
			Default
				Print "button@"+button
		end
 	End

	Method OnButtonUp(button:Int)
	End	
	
End	

Function FloatString:String(value:Float,dp:Int=2)
	Local sign:String
	Local integral:=Int(value*(Pow(10,dp)))
	If integral<0 
		sign="-"
		integral=-integral
	Endif
	Local a:String=integral
	Local l:=dp+1-a.Length
	If l>0 a="0000000000000".Slice(0,l)+a
	Local r:=a.Length 
	Return sign+a.Slice(0,r-dp)+"."+a.Slice(r-dp,r)
End

Function Wrap:Int(value:Int,lower:Int,upper:Int)
	If value<lower value=upper-1
	If value>=upper value=lower
	Return value
End

Class VSynthWindow Extends Window

	Const MusicKeys:=New Key[]( Key.Q,Key.A,Key.W,Key.S,Key.E,Key.D,  Key.F,Key.T,Key.G,Key.Y,Key.H,Key.U,Key.J,  Key.K,Key.O,Key.L,Key.P,Key.Semicolon)',Key.Apostrophe )

	Field frame:Int
	Field tick:Int
	Field mousex:Int
	Field mousey:Int
	
	Field volume:V=0.8
	Field mousebend:V
	Field pitchbend:V=1.0

	Field synth:Int
	Field oscillator:Int=3
	Field envelope:Int
	Field octave:Int=4
	Field sustain:Bool
	Field expression:V

	Field panx:Int	' scope speed
	Field pany:Int	' scope zoom

	Field arp:Int
	Field prog:Int

	Field hold:Bool
	Field div:Int
	Field duty:Int
	Field rept:Int
	Field tempo:Tempo=92
	Field pressure:int
	field reset:Int
	
	Field keyNoteMap:=New Map<Key,Int>
	
	Field portMidi:PortMidi

	Field midiInputs:Int
	Field midiOutputs:Int
	Field midiSend:Int
	Field midiSendName:="None"
	
	Field audioLatency:Int=2 '1 Shl (10+n) samples
		
	Method New(title:String)
		Super.New(title,1280,720,WindowFlags.Resizable)				
		For Local i:=0 Until MusicKeys.Length
			keyNoteMap.Set(MusicKeys[i],i-1)
		Next
		vsynth=New VSynth
		OpenAudio()
#If __HOSTOS__="pi"
		ResetMidi()
#endif
		ClearColor=new Color(1.0/16,1.0)
' midi mappings		
		MapKontrol()
		MapAkai()
	End
	
	Field Panic:=false
	
	Method Escape()			
		If Panic
			instance.Terminate()
		else
			vsynth.ClearKeys()
			Panic=true
		endif
	End
			
	Method OpenAudio()

		local p:=Cast<Byte ptr>(alcGetString(Cast<ALCdevice ptr>(0), ALC_DEVICE_SPECIFIER))	
		local s:=String.FromCString(p)
		print "OpenAL Outputs:"+s

		New Fiber( Lambda()
			Local channel:=New Channel
			Local data:=New AudioData( FragmentSize,AudioFormat.Stereo16,AudioFrequency )
			Local datap:=Cast<Short Ptr>( data.Data )
			Repeat
				Local samples:=vsynth.FillAudioBuffer( FragmentSize )
				For Local i:=0 Until FragmentSize*2
					datap[i]=Clamp( samples[i],Double(-1.0),Double(1.0) ) * 32767.0
				Next
				Local loWater:=SampleLatency()/FragmentSize
				channel.WaitQueued( loWater )
				channel.Queue( data )							
			Forever
		
		End )
	End
		
	Method ResetMidi()
		reset=0
		if portMidi 
			portMidi.CloseAll()
		Endif				
		portMidi=New PortMidi()
		midiInputs=portMidi.inputDevices.Length
		midiOutputs=portMidi.outputDevices.Length
		Title="Found "+midiInputs+" MIDI in and "+midiOutputs+" MIDI out"
		For Local i:=0 Until midiInputs
			portMidi.OpenInput(i)
		Next
		For Local i:=0 Until midiOutputs
			portMidi.OpenOutput(i)		
			SysEx(i)
		Next
		If midiSend<midiOutputs
			midiSendName=portMidi.OutputName(midiSend)
		Endif			
	End
	
	Method SysEx(output:Int)
		If volume<0 volume=0
		If volume>1 volume=1
		local value7:Int=127*volume
		Local sysex:Int=(MidiSynth._SysEx)
		
'		_ControllerChange)|(_VolumeController Shl 8)|(value7 Shl 16)
		portMidi.SendMessage(output,sysex)
	end
	
	Method CycleMidiSend()
		If midiOutputs	
			midiSend=(midiSend+1)Mod midiOutputs
			midiSendName=portMidi.OutputName(midiSend)
			vsynth.SetMidiOutput(portMidi,midiSend)
		Endif			
	End

	Method CycleAudioLatency()
		audioLatency=(audioLatency+1)&3
	End
		
	method PollMidi()
		Const NoteOn:=144
		Const NoteOff:=128
		Const Controller:=176
		Const PitchWheel:=224
		Const Clock:=248	
		Const Start:=250
		Const Resume:=251		
		Const Fin:=252
		Const Cry:=191
		Const ProgramChange:=192

		While portMidi and portMidi.HasEvent()
			Local b:=portMidi.EventDataBytes()
			Local t:=portMidi.EventTime()
			Local note:=b[1]
			Local velocity:=b[2]
			Local word:Int=note+(velocity Shl 7)
						
			Select b[0]
				Case NoteOn
					If velocity=0
						vsynth.NoteOff(note)
					Else
						vsynth.NoteOn(note,velocity)
					Endif
				Case NoteOff					
					vsynth.NoteOff(note)
				Case PitchWheel
					pitchbend=1.0+(word-8192)/8192.0
				Case Controller
					OnControl(b[1],b[2])
				Case ProgramChange
					OnProgramChange(b[1])
				Case Clock
					Assert(b[1]=0 And b[2]=0)
					OnMidiClock(t)
				Case Start
					Assert(b[1]=0 And b[2]=0)
					OnMidiPlay(1,t)
				Case Resume
					Assert(b[1]=0 And b[2]=0)
					OnMidiPlay(2,t)
				Case Fin
					Assert(b[1]=0 And b[2]=0)
					OnMidiPlay(3,t)
'				Case Cry
				Default
					Print b[0]+" "+b[1]+" "+b[2]+" "+b[3]
			End					
		Wend
'		portMidi.Sleep(1.0/60)
	End

	Field control:=New Int[128]	
	Field buttons:=New Map<Int,Int>
	
	Method MapAkai()
		buttons[83]=Patch+0
		buttons[80]=Patch+1
		buttons[81]=Patch+2
		buttons[82]=Patch+3
		buttons[84]=NextProgram
		buttons[85]=PrevProgram	
	End	
	
	Method MapKontrol()
		For Local i:=23 To 41
			buttons[i]=UserButton+i-23
		Next
		buttons[47]=RewindButton
		buttons[45]=PlayButton
		buttons[48]=ForwardButton
		buttons[49]=LoopButton
		buttons[46]=StopButton
		buttons[44]=RecordButton
	End
	
	Method OnProgramChange(index:Int)
		vsynth.OnButton(Patch+index)
	End
	
	Method OnControl(index:Int, value:Int)	
	
		local f:=value/128.0
		value-=64
		
		If buttons.Contains(index)
			Local button:=buttons[index]
			If value<0
				vsynth.OnButtonUp(button)
			Else
				vsynth.OnButton(button)
			Endif
			Return
		endif
		
		Select index
		Case 2
			pressure=f*256
			Print "blow:"+pressure
		Case 14
			tempo=f*256
		Case 16
			ClearColor=New Color(f,ClearColor.G,ClearColor.B)
		Case 17
			ClearColor=New Color(ClearColor.R,f,ClearColor.B)
		Case 18
			ClearColor=New Color(ClearColor.R,ClearColor.G,f)
		Case 3
'			zoom=f/8
		Case 121
			Print "."
		Case 123
			Print "_"			
		Case 1
			expression=4*f*f
			volume=expression
		Case 64
			sustain=value>=0
		Default
			Print "OnControl:"+index+" "+value
		end
	End
	
	Field midiTicks:Int
	Field midiTime:Double
	Field midiTempo:Double
	Const ppqn:=24
	
	Method OnMidiClock(t:Double)
		If midiTicks>0
			Local duration:=t-midiTime
			If duration>0
				Local bpm:=60.0/(duration*ppqn)
				If bpm>666 bpm=666
				midiTempo=(7*midiTempo+bpm)/8
'				tempo=Int(midiTempo)
'				Print "tempo="+Int($fffe&int(midiTempo))
				tempo=$fffe&int(midiTempo)
			Else
				midiTempo=0
'				tempo=0
			Endif
		Endif	
		midiTicks+=1
		midiTime=t		
	End
	
	Method OnMidiPlay(button:Int,t:Double)
		Print "Play "+button
	end
		
	Field noteMap:=New IntMap<Bool>
	Field KeyVelocity:=80
	
	Method KeyDown(key:Key)
		If keyNoteMap.Contains(key)
			KeyUp(key)
			Local note:=keyNoteMap[key]+octave*12
			noteMap[note]=True
			vsynth.NoteOn(note,KeyVelocity)
		Else
			Print "Unmapped keycode "+Int(key)
		Endif
	End

	Method KeyUp(key:Key)		
		If keyNoteMap.Contains(key)
			For Local octave:=0 Until MaxOctave
				Local note:=keyNoteMap[key]+octave*12
				If noteMap.Contains(note)	
					vsynth.NoteOff(note)
					noteMap.Remove(note)
				Endif
			Next
		Endif
	End

	Method UpdateSequence()
		frame+=1
		Local t:Int=(frame/20)	
		If t<>tick
			Local note:=((t Shr 1)&15)*3+40
			If t&1
				vsynth.NoteOn(note,KeyVelocity)
			Else
				vsynth.NoteOff(note)			
			Endif
			tick=t
		Endif				
'		Print "tick d="+d
	End
			
	Function Limit:Int(value:Int, lo:Int, hi:Int)
		If value<lo Return lo
		If value>hi Return hi
		Return value
	End
				
	Method OnKeyEvent( event:KeyEvent ) Override	
		Select event.Type
		Case EventType.KeyDown
			Select event.Key
			Case Key.Slash						
				div=Wrap(div+1,0,DivisorNames.Length)				
			Case Key.Insert
				duty=Wrap(duty+1,0,DutyNames.Length)				
			Case Key.Home
				rept=Wrap(rept+1,0,RepeatNames.Length)				
			Case Key.KeyEnd
				prog=Wrap(prog+1,0,ProgNames.Length)				
			Case Key.Minus
				tempo-=1
			Case Key.Equals
				tempo+=1
			Case Key.F2
				CycleAudioLatency()
			Case Key.F4
				CycleMidiSend()
			Case Key.F5
				arp=0
			Case Key.F6
				arp=1
			Case Key.F7
				arp=2
			Case Key.F8
				arp=3
			Case Key.F9
				arp=4
			Case Key.F10
				If arp=5 arp=6 Else arp=5
			Case Key.Backspace
				Title="Scanning Midi Bus, please wait."
				reset=1
			Case Key.Tab
				hold=Not hold
			Case Key.Key1
				oscillator=0
			Case Key.Key2
				oscillator=1
			Case Key.Key3
				oscillator=2
			Case Key.Key4
				oscillator=3
			Case Key.Key5
				oscillator=4
			Case Key.Key6
				oscillator=5
			Case Key.Key7
				oscillator=6
			Case Key.Key8
				oscillator=7
			Case Key.Escape
				Escape()
			Case Key.Space
				vsynth.OnButton(RecordButton)
			Case Key.LeftBracket
				envelope=Wrap(envelope-1,0,EnvelopeNames.Length)
			Case Key.RightBracket
				envelope=Wrap(envelope+1,0,EnvelopeNames.Length)				
			Case Key.Enter
				synth=Wrap(synth+1,0,SynthNames.Length)				
				vsynth.SetSynth(synth)
			Case Key.Comma
				octave=Clamp(octave-1,0,MaxOctave)
			Case Key.Period
				octave=Clamp(octave+1,0,MaxOctave)
			Case Key.LeftShift
				sustain=true
			Case Key.RightShift
				sustain=not sustain
			Case Key.PageUp
				volume=1.20*volume
			Case Key.PageDown
				volume=0.92*volume
			Case Key.Left
				panx-=1
			Case Key.Right
				panx+=1
			Case Key.Up
				pany-=1
			Case Key.Down
				pany+=1
			Default
				KeyDown(event.Key)
			End
		Case EventType.KeyUp
			Select event.Key
			Case Key.LeftShift
				sustain=False
			Case Key.Escape
			Default
				KeyUp(event.Key)
			End
		End
	End
	
	Method OnMouseEvent( event:MouseEvent ) Override	
		mousex=event.Location.X
		mousey=event.Location.Y
		mousebend+=event.Wheel.Y/48.0
		pitchbend=Pow(2,mousebend)		
		Select event.Type
			Case EventType.MouseDown
				pixels.Click(mousex,mousey)
		End
	End
	

	Method OnRender( display:Canvas ) Override	
	
		If reset
			ResetMidi()
		endif
	
		PollMidi()
	
		App.RequestRender()	
		
		vsynth.PanScope(panx,pany)
		
		' TODO: continous functions

		vsynth.Detune(pitchbend)
		vsynth.SetVolume(volume)
'		vsynth.SetVolumeFader(volume)
		vsynth.SetArp(arp,prog)
		vsynth.SetHold(hold)
		vsynth.SetSustain(sustain)
		vsynth.SetTempo(tempo,1+div,DutyCycle[duty],rept)
		vsynth.SetTone(oscillator,envelope)
'		vsynth.UpdateAudio()

		Local text:String = About+",,"+Octave1+","+Octave0
		text+=",,Octave=< >="+octave
		text+=",Sample=Space="+RecordNames[Int(vsynth.recording)]
		text+=",Sustain=Shift="+SustainNames[sustain]
		text+=",Volume=PageUpDown="+FloatString(volume)
		text+=",PitchBend=Mouse Wheel="+FloatString(pitchbend)		
		text+=",,Oscillator=1-5="+OscillatorNames[oscillator]
		text+=",Envelope=[]="+EnvelopeNames[envelope]
		text+=",,Arpeggiator=F5-F10="+ArpNames[arp]
		text+=",Hold=Tab="+HoldNames[hold]
		text+=",Note Divisor=/="+DivisorNames[div]
		text+=",DutyCycle=Insert="+DutyNames[duty]
		text+=",Progression=End="+ProgNames[prog]
		text+=",Note Repeat=Home="+RepeatNames[rept]
		text+=",,Tempo=- +="+tempo
		text+=",,Synth=Enter Key="+SynthNames[synth]
		text+=",,"+Controls				
		text+= ",Buffer=F2="+SampleLatency()+"("+MilliLatency()+"ms)"
		text+=",,Enable MIDI=Backspace"
		text+=",MidiIn=F3=All ["+midiInputs+"]"
		text+= ",MidiOut=F4="+midiSendName+"["+midiOutputs+"]"
		text+=",,"+Contact
		
		display.Color=Color.Black
		display.DrawRect(0,0,400,Height)
		display.Color=Color.Grey

		Local cy:=20
		For Local line:=Eachin text.Split(",")
			Local cx:=10
			For Local tab:=Eachin line.Split("=")
				display.DrawText(tab,cx,cy)
				cx+=100
			Next
			cy+=20
		Next

		pixels.Zoom(12)
		pixels.Dim(32,2)		
		pixels.Draw(display)	

		Local keymap:=vsynth.GetKeymap()		
		keys.DrawKeyboard(display,440,100,keymap)
		
		keys.DrawTape(480,70,40,25)
		
		vsynth.scope.Draw(display,440,300)
	End				
	
	Method SampleLatency:Int()
		Return (1 Shl (10+audioLatency))
	End
	
	Method MilliLatency:Int()
		Return 1000*SampleLatency()/AudioFrequency
	end

	Field pixels:=New ColorMap(420,20)
	Field keys:=New SynthStyle()

End


' P is coordinate type for drawing pixels

Alias P:Float	

' LowSaturatedGreen is suitable for additive blendmode

Global Low:=20.0/255
Global LowSaturatedGreen:=New Color(0.0, Low, 0.0, 1.0)
Global LowSaturatedRed:=New Color(Low, 0.0, 0.0, 1.0)
Global LowSaturatedBlue:=New Color(0.0, 0.0, Low, 1.0)

' Quad is a square Image with canvas

Class Quad Extends Image
	Field dimension:int
	Field index:int
	Field canvas:Canvas
	Field bg:=LowSaturatedBlue
	Field fg:=LowSaturatedGreen

	Method New(dim:Int,id:Int)		
'		Super.New(dim,dim,TextureFlags.Dynamic|TextureFlags.Filter|TextureFlags.Mipmap)		
		Super.New(dim,dim,TextureFlags.Dynamic|TextureFlags.Filter)		
		dimension=dim
		index=id
		canvas=New Canvas(Self)	
		canvas.BlendMode=BlendMode.Additive		
'		ClearRect(0,0,dim,dim)
		Clear()
	End
		
	Method Pen(color:Color)
		fg=color
		canvas.Color=fg
	End
	
	Method Plot(x:P,v:V)	
		Local y:=(0.5+0.5*v)*dimension
		canvas.DrawPoint(x,y)
	End

	Method Clear()
		canvas.Clear(bg)
		canvas.BlendMode=BlendMode.Additive		
		canvas.Color=fg
	End

	Method ClearRect(x:P,y:P,w:P,h:P)
		canvas.BlendMode=BlendMode.Opaque
		canvas.Color=bg
		canvas.DrawRect(x,y,w,h)
		canvas.BlendMode=BlendMode.Additive		
		canvas.Color=fg
	end

	Method Flush()	
		canvas.Flush()
	End
End

' Scope is an array of Quads to graph waveforms

Class Scope

	Field columns:int
	Field dimension:Int
	Field mask:Int
	Field width:int
	Field quads:=New Stack<Quad>
	
	Method New(cols:int=4)
		' TODO: assert columns is power of 2
		columns=cols
		dimension=128
		mask=columns-1
		width=dimension*mask
		For Local index:=0 Until columns
			quads.Push(New Quad(dimension,index))
		Next
		Advance(0)
	End
	
	Field current:Quad
	Field position:P	' global x head position
	Field xlocal:P		' head position on current quad 
	
	Method Plot(y:P)
		current.Plot(xlocal,y)
	End
	
	Method Pen(c:Color)
		current.Pen(c)
	end

	Method Advance(xpos:P)
		Local index:=Int(xpos/dimension)
		Local target:=quads[index & mask]
		If target<>current
			current=target
			current.Clear()
		Endif
		position=index*dimension		
		xlocal=xpos-position		
	End
	
	Method Draw(canvas:Canvas,x:P,y:P)
		Local index:=current.index		
		canvas.Scissor=New Recti(x,y,x+width,y+dimension)		
		For Local quad:=Eachin quads			
			quad.Flush()
			Local order:=mask-(index-quad.index)&mask
			Local xx:=x+order*dimension-xlocal
			canvas.DrawImage(quad,xx,y)
		Next
		canvas.Scissor=null
	End
	
	Method Clear()
		For Local quad:=Eachin quads
			quad.Clear()
		next
	End
		
End


Class SynthStyle

	Field BlackKey:=New Color(20,120,120)
	Field WhiteKey:=New Color(20,200,200)
	Field HotKey:=New Color(20,20,20)

	Field canvas:Canvas
	
	Method DrawRoll(x:Float,y:Float,r1:Float,r2:Float,r3:Float)
		canvas.Color=BlackKey
		canvas.DrawOval(x-r1,y-r1,r1*2,r1*2)
		canvas.Color=WhiteKey
		canvas.DrawOval(x-r2,y-r2,r2*2,r2*2)
		canvas.Color=HotKey
		canvas.DrawOval(x-r3,y-r3,r3*2,r3*2)
	end
		
	Method DrawTape(x:Float,y:Float,w:Float,h:Float)
		canvas.Color=WhiteKey
		canvas.DrawRect(x,y,w,h)
		DrawRoll(x+10,y+10,9,4,2)
		DrawRoll(x+30,y+10,9,4,2)
		canvas.Color=BlackKey
		canvas.DrawRect(x+8,y+h-4,w-16,3)
	End

	Method DrawKey(x:Float,y:Float,w:Float,h:Float,sharp:Bool,down:Bool)
		If sharp
			canvas.Color=BlackKey
		Else
			canvas.Color=WhiteKey
		Endif		
		canvas.DrawRect(x,y,w,h)
		If down
			canvas.Color=HotKey		
			canvas.DrawRect(x+2,y+h-12,w-4,10)
		Endif		
	End
	
	Method DrawKeyboard(display:Canvas,x:Int,y:Int,keymap:Keymap)				
		canvas=display
		For Local p:=0 To 1			
			Local px:=x+2
			Local py:=y+6
			For Local i:=0 To 127			
				Local octave:=i/12
				Local note:=i-octave*12				
				Local sharp:Bool=note=1 Or note=3 Or note=6 Or note=8 Or note=10				
				Local down:=keymap.KeyDown(i)					
'				If _proc down=_proc._keyDown[i]>0				
				If sharp 
					If p=1 
						DrawKey(px-4,py,7,20,True,down)
					Endif
				Else
					If p=0 
						DrawKey(px,py,9,40,False,down)
					Endif
					px+=10
				Endif
			Next
		Next
	End
End


Class Box
	Field tx:Int
	Field ty:Int
	Field tw:=32
	Field th:=32
	Field padding:=2
	Field margin:=2
end

class ColorMap Extends Box
	Field colors:Int[]
	Field width:Int
	Field height:Int
	Field palette:=new Color[](Color.Black,Color.Blue)

	Method New(x:Int,y:Int)	
		tx=x
		ty=y
	End
	
	Method Zoom(size:Int)
		tw=size
		th=size
	end
	
	Method Dim(w:Int,h:Int)
		If w=width And h=height return
		width=w
		height=h
		colors=New Int[w*h]
	End
	
	Method Plot(x:Int,y:Int,c:Int)
		Local index:=y*width+x
		If index>=0 And index<colors.Length
			colors[index]=c
		endif
	end

	Method Toggle(x:Int,y:Int)
		Local index:=y*width+x
		If index>=0 And index<colors.Length
			colors[index]=1-colors[index]
		endif
	end

	Method Clear(c:Int)
		For Local i:=0 Until width*height
			colors[i]=c
		next
	End
	
	Method Click(x:int,y:int)
		x=(x-tx)/tw
		y=(y-ty)/th
		If x>=0 And y>=0 And x<width And y<height
			Toggle(x,y)
		endif
	end

	Method DrawPad(canvas:Canvas,x:Int,y:Int)		
		canvas.Color=Color.Black
		canvas.DrawRect(tx+x*tw+padding,ty+y*th+padding,tw-padding*2,th-padding*2)
		Local c:=colors[y*width+x]
		c=c Mod palette.Length
		canvas.Color=palette[c]
		canvas.DrawRect(tx+x*tw+padding+margin,ty+y*th+padding+margin,tw-(padding+margin)*2,th-(padding+margin)*2)
	End
	
	Method Draw(canvas:Canvas)
		canvas.Color=Color.DarkGrey
		canvas.DrawRect(tx,ty,tw*width,th*height)
		For Local y:=0 Until height
			For Local x:=0 Until width
				DrawPad(canvas,x,y)
			Next
		next
	end
end


Function Main()
	instance = New AppInstance	
	New VSynthWindow(AppTitle)	
	App.Run()	
End


#rem
yamaha

SysEx=240
TimeCode=241
SongPosition=242
SongSelect=243
EOX=247
Clock=248
Start=250
Continue=251
Stop=252
Reset=255

midi level
Bank Select (cc#0/32)
Modulation Depth (cc#1)
Portamento Time (cc#5)
Channel Volume (cc#7)
Pan (cc#10)
Expression (cc#11)
Hold1 (Damper) (cc#64)
Portamento ON/OFF (cc#65)
Sostenuto (cc#66)
Soft (cc#67)
Filter Resonance (Timbre/Harmonic Intensity) (cc#71)
Release Time (cc#72)
Attack Time (cc#73)
Brightness (cc#74)
Decay Time (cc#75) (new message)
Vibrato Rate (cc#76) (new message)
Vibrato Depth (cc#77) (new message)
Vibrato Delay (cc#78) (new message)
Reverb Send Level (cc#91)
Chorus Send Level (cc#93)
Data Entry (cc#6/38)
RPN LSB/MSB (cc#100/101)
#end
	
