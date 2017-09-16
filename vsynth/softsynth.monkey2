' softsynth.monkey2

'#Import "assets/whale52hz.wav"
#Import "assets/engine1.wav"

Alias V:Double ' Voltage(volts)
Alias F:Double ' Frequency(hz)
Alias T:Double ' Time(seconds)
Alias M:Double ' Distance(meters)

'Alias Note:Int
Alias Tempo:Int ' BeatsPerMinute
Alias K:Key

Global Duration:=0

Global AudioFrequency:=44100
Const SpeedOfSound:=340.29

Const MaxPolyphony:=64
Const MaxOctave:=12

Struct Note
	Field note:Int
	Field velocity:Int
	Method New(n:Int,v:Int)
		note=n
		velocity=v
	End
End

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
	Field sampleData:SampleData
'	Field pitch:=220.0
	Field freq:=44100
	
	Method Normalise()
		Local m:V=0.0
		For Local i:=0 Until sampleData.Length
			Local s:=sampleData[i]
			If s*s>m m=s*s
		Next
		
		If m>1
			Local q:=1.0/Sqrt(m)		
			For Local i:=0 Until sampleData.Length
				sampleData[i]*=q
			Next
			Print "SampleBank Nomalised with Q "+q
		Else 
			Print "Normalisation not required for M "+m
		Endif
		
	End

	Method Record(samples:V[],count:Int)
		If Not sampleData
			sampleData=New SampleData
		Endif
		For Local i:=0 Until count*2
			sampleData.PushLast(samples[i])
		Next
	End
	
	Method Save(dir:String)
		Local path:=dir+"test.wav"
		Local file:=FileStream.Open(path,"w")
		Normalise()
		WriteWAV(file)
		file.Close()
		Print "saved wav to "+path
	End
	
	Function ByteFromHex:Int(hex:String)
		Local n0:=hex[0]
		Local n1:=hex[1]
		n0=(n0>=97)?n0-87 Else n0-48
		n1=(n1>=97)?n1-87 Else n1-48
		Return n0*16+n1
	End
	
	Global WAVE_FORMAT_IEEE_FLOAT:="00000003-0000-0010-8000-00aa00389b71"
	Const FORMAT_EXTENSIBLE:=$FFFE

	Function MakeGuid:String(guid:String)	
		Local byteorder:=New Int[](3,2,1,0,5,4,7,6,8,9,10,11,12,13,14,15)
		guid=guid.Replace("-","")		
		Local buffer:=New Byte[16]
		For Local i:=0 Until 16
			Local b8:=ByteFromHex(guid.Slice(i*2,i*2+2))		
			Print Hex(b8)
			Local index:=byteorder[i]
			buffer[index]=b8
		Next
		Return String.FromCString(buffer.Data,16)			
	End

' based on http://www-mmsp.ece.mcgill.ca/Documents/AudioFormats/WAVE/WAVE.html

	Method WriteWAV( stream:std.stream.Stream)
		Const FORMAT_FLOAT:=$0003
		Const RIFF:=$46464952
		Const WAVE:=$45564157
		Const FMT:=$20746d66
		Const DATA:=$61746164
'		Local guid:=MakeGuid(WAVE_FORMAT_IEEE_FLOAT)
		Local len:=sampleData.Length*4
		Local rifflen:=4+24+8+len
		stream.WriteUInt(RIFF)
		stream.WriteUInt(rifflen)
		stream.WriteUInt(WAVE)
		stream.WriteUInt(FMT)
		stream.WriteUInt(16)		
		Local channels:=2
		Local bitspersample:=32
		Local align:=8
		stream.WriteUShort(FORMAT_FLOAT)		'2
		stream.WriteUShort(channels)			'2
		stream.WriteUInt(freq)					'4
		stream.WriteUInt(freq*align)			'4
		stream.WriteUShort(align)				'2
		stream.WriteUShort(bitspersample)		'2
		stream.WriteUInt(DATA)
		stream.WriteUInt(len)
		For Local sample:=Eachin sampleData
			stream.WriteFloat(sample)
		Next
	End

End
	
Class Sampler Extends Oscillator
	Field samples:SampleData
	Field pitch:=220.0
	Field freq:=44100
	
	Method setBank(sampleBank:SampleBank)
		samples=sampleBank.sampleData
	End

	Method Sample:V(hz:F) Override		
		If Not samples Or samples.Length=0 Return 0
		Local t:=hz*freq/(pitch*AudioFrequency)		
		Local delta0:=delta
		delta+=t
		Local f:=delta
		f=f Mod samples.Length
		Return samples[f]
	End	
End

Class Microphone
	Field device:ALCdevice Ptr
	Field error:Int
	Field audioFormat:Int
	Field rate:=44100
	Field fragsize:=1024
	Field buffer:=New Stack<Byte>
	Field recording:Bool
	Field length:=3
	Field count:=0
	
	Method ErrorState:Bool()
		Local error:=alGetError()
		If error
			Print "OpenAL error "+error
			Return True
		Endif
		Return False
	End
	
	Method New()
		audioFormat=AL_FORMAT_STEREO16		
		device=alcCaptureOpenDevice(Null,rate,audioFormat,fragsize)
		If ErrorState() Return
'		Local b:=alcGetString(Cast<ALCdevice ptr>(0), ALC_CAPTURE_DEVICE_SPECIFIER)
'		local p:=Cast<Byte ptr>(b)
'		local s:=String.FromCString(p)
'		print "Microphone OpenAL Capturing "+s
	End
	
	Method Start()
		If Not recording
			alcCaptureStart(device)
			If ErrorState() Return			
			recording=True
			print "OpenAL capture started"
		Endif
	End

	Method Stop()
		If recording
			alcCaptureStop(device)
			If ErrorState() Return			
			recording=False
			print "OpenAL capture stopped"
		Endif
	End

	Method Close()	
	    alcCaptureStop(device)
    	alcCaptureCloseDevice(device)
    End

	Method Poll(sampleBank:SampleBank)
		Local samples:Int			
		alcGetIntegerv(device, ALC_CAPTURE_SAMPLES,4,Varptr samples)
		If samples=0 Return
		' capture raw data from device
		buffer.Resize(samples*4)
		alcCaptureSamples(device,Varptr buffer.Data[0],samples)
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
				Local vdata:= New V[samples]
				For Local i:=0 Until samples
					vdata[i]=(sdata[i*4+1]*256+sdata[i*4+0])/32767.0
'					sampleData.PushLast((sdata[i*4+1]*256+sdata[i*4+0])/32767.0)
				Next
				sampleBank.Record(vdata,samples)				
			Default
				Print "Unsupported Microphone audioFormat"
		End
		' update state
		count+=samples
		If count>length*rate
			Stop()		
		Endif
		
		Print samples
	End
		
End

Class LiveMicrophone Extends Sampler

	Global mic:Microphone

	Field sampleBank:SampleBank
	Field count:Int
	
	Method New()
		sampleBank=New SampleBank
		setBank(sampleBank)
	End

	Method Poll()
		If Not mic 
			mic=New Microphone
		endif		
		mic.Poll(sampleBank)
	End
	
	Method Sample:V(hz:F) Override			
		count-=1
		If count<0
			Poll()
			count=mic.fragsize 
		Endif
		Return Super.Sample(hz)
	End

End

Interface NotePlayer
	Method SetOscillator(osc:Int)
	Method SetEnvelope(env:Int)
	Method SetPan(value:V)
	Method SetGain(value:V)
	Method Stop()
	Method NoteOn(note:Note)
	Method NoteOff(note:Note)
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
				envelope=New ADSR(0.001,1.5,0.2,0.5)
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
		noteOn=False
		envelope.Off()
	End	
	
	Method NoteOn(note:Note)
		hz=440.0*Pow(2.0,(note.note-67.0)/12)
		amp=note.velocity/100.0
		noteOn=True
	End
	
	Method NoteOff(note:Note)
		Stop()
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
	Method SetTempo(tempo:Tempo,divisor:Int,duty:V,rept:Int)
	Method SetTone(osc:Int,env:Int)
	Method Command(command:SynthCommand,depressed:bool)
	Method SetVolume(volume:V)
	Method NoteOn(note:Note)
	Method NoteOff(note:Note)
	Method SetSustain(sustain:Bool)
	Method FillAudioBuffer(buffer:Double[],samples:Int,detune:V[],fade:V[])	
	Method Panic()
	Method GetKeys:Keys()
End

Interface Effect
	Method ControlNames:String[]()
	Method EffectAudio(buffer:V Ptr,samples:Int,control:V[][])	
End

Class Distortion Implements Effect
	Const DistortionControls:=New String[]("Overdrive","Gain")
	
	Method ControlNames:String[]()
		Return DistortionControls
	End
	
	Method EffectAudio(samples:V Ptr,sampleCount:Int,control:V[][])	
		Local overdrive:=control[0]
		Local gain:=control[1]
		
		For Local s:=0 Until sampleCount*2
			Local i:=s/2
			Local v:=samples[s]			
			v*=overdrive[i]
			If v>0
				v=1-Exp(-v)
			Else
				v=-1+Exp(v)
			Endif
			v*=gain[i]
			samples[s]=v
		Next		
	End
End


Class Reverb Implements Effect
	Const Controls:=New String[]("Wet","Dry")

	Struct Pole
		Field distance:M
		Field dampen:V
		Method New(meters:M,gain:V)
			distance=meters
			dampen=gain
		End		
	End
	
	Field poles:=New List<Pole>
	Field future:V[]
	Field removeSource:=True
	
	Method New()
		poles.Add(New Pole(210,0.5))
	End
		
	Method ControlNames:String[]()
		Return Controls
	End
		
	Method EffectAudio(samples:V Ptr,sampleCount:Int,control:V[][])	

		Local wetness:=control[0]
		Local dryness:=control[1]
		
		Local n1:=math.Min(future.Length,sampleCount*2)
		For Local i:=0 Until n1
			samples[i]+=future[i]
		Next

		For Local pole:=Eachin poles
			Local seconds:=pole.distance/SpeedOfSound
			Local offset:=Int(AudioFrequency*seconds)
			
			Local maxOffset:Int=(sampleCount+offset)*2
			
			If future.Length<maxOffset future=future.Resize(maxOffset)
						
			Local dampen:=pole.dampen
			For Local i:=0 Until sampleCount
				Local l:=samples[i*2+0]
				Local r:=samples[i*2+1]
				future[(offset+i)*2+0]+=l*dampen
				future[(offset+i)*2+1]+=r*dampen		
			Next
		Next

		Local n2:=math.Min(future.Length,sampleCount*2)
		For Local i:=0 Until n2
			Local wet:=wetness[i/2]
			Local dry:=dryness[i/2]
			samples[i]=wet*future[i]+dry*(samples[i]-future[i])
		Next
				
		future=future.Slice(sampleCount*2)		
	End
End

'y(0) = alpha*x(0) - alpha*x(-2) + chi*y(-1) - beta*y(-2) = alpha*1 because other parts of the sum are zero
'y(1) = alpha*x(1) - alpha*x(-1) + chi*y(0) - beta*y(-1) = chi*alpha*1
'y(2)= alpha*x(2) - alpha*x(0) + chi*y(1) - beta*y(0) = -alpha*1 + chi*chi*alpha*1 - beta*alpha*1

Class Equalise Implements Effect
	Const Controls:=New String[]("Wet","Dry")

	Struct Tap
		Field distance:M
		Field dampen:V
		Method New(meters:M,gain:V)
			distance=meters
			dampen=gain
		End		
	End
	
	Field taps:=New List<Tap>
	Field future:V[]
	Field removeSource:=True
	
	Method New()
		taps.Add(New Tap(210,0.5))
	End
		
	Method ControlNames:String[]()
		Return Controls
	End
		
	Method EffectAudio(samples:V Ptr,sampleCount:Int,control:V[][])	

		Local wetness:=control[0]
		Local dryness:=control[1]
		
		Local n1:=math.Min(future.Length,sampleCount*2)
		For Local i:=0 Until n1
			samples[i]+=future[i]
		Next

		For Local pole:=Eachin taps
			Local seconds:=pole.distance/SpeedOfSound
			Local offset:=Int(AudioFrequency*seconds)
			
			Local maxOffset:Int=(sampleCount+offset)*2
			
			If future.Length<maxOffset future=future.Resize(maxOffset)
						
			Local dampen:=pole.dampen
			For Local i:=0 Until sampleCount
				Local l:=samples[i*2+0]
				Local r:=samples[i*2+1]
				future[(offset+i)*2+0]+=l*dampen
				future[(offset+i)*2+1]+=r*dampen		
			Next
		Next

		Local n2:=math.Min(future.Length,sampleCount*2)
		For Local i:=0 Until n2
			Local wet:=wetness[i/2]
			Local dry:=dryness[i/2]
			samples[i]=wet*future[i]+dry*(samples[i]-future[i])
		Next
				
		future=future.Slice(sampleCount*2)		
	End
End


Struct Keys
	Field low:Long
	Field high:Long	
	Field vel:Int[]
	
	Method ToJson:String()
		Local s:String
		Return "["+low+","+high+"]"
	End


	Method FromJsonArray:String()
	Return ""
	End

	Method KeyDown:Bool(index:Int)
		Local bit:Long=1	
		Local shift:Long=index&63
		If index<64 Return ((low Shr shift)&bit)=bit
		index-=64
		Return ((high Shr shift)&bit)=bit
	End
	
	Method KeyOn(index:Int)
		Local bit:Long=1
		Local shift:Long=index&63
		bit=bit Shl shift
		If index<64 low|=bit Else high|=bit
	End

	Method KeyOff(index:Int)
		Local bit:Long=1
		Local shift:Long=index&63
		bit=bit Shl shift
		If index<64 low&=~bit Else high&=~bit
	End
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
	Field count:Int
	
	Field notePeriod:T
	Field dutyPeriod:T

	Field keys:=New Keys
	
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
	End

	Method Command(command:SynthCommand,depressed:bool)
		output.Command(command,depressed)
	End

	Method NoteOn(note:Note) Virtual
		recent=note
		keys.KeyOn(note.note)
	End
	
	Method NoteOff(note:Note) virtual
		output.NoteOff(note)
		keys.KeyOff(note.note)
	End
	
	Method Beat() Virtual
		If recent.note
			NoteOn(recent)
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
	End

	Field noteDuration:=new Map<Note,T>
	
	Method StepDuration(duration:T)
		For Local note:=Eachin noteDuration.Keys			
			If noteDuration[note]>0
				noteDuration[note]-=duration
				If noteDuration[note]<=0
					output.NoteOff(note)
				Endif
			Endif
		Next
	End

	Method FillAudioBuffer(buffer:Double[],samples:Int,detune:V[],fade:V[])	
		Update(2.0*samples/AudioFrequency)
		output.FillAudioBuffer(buffer,samples,detune,fade)
	End

	Method GetKeys:Keys()
		Return output.GetKeys()
	End
	
	Method Panic()
		ReleaseAll()
		output.Panic()	
	End

	Method TriggerNote(note:Note)	
		output.NoteOn(note)
		noteDuration[note]=dutyPeriod
	End
	
	Method ReleaseAll() Virtual
		For Local note:=Eachin noteDuration.Keys			
			output.NoteOff(note)
		Next	
		noteDuration.Clear()
	End

End

Class Arpeggiator Extends BeatGenerator
	Field notemap:=New IntMap<Note>
	Field natural:=New Stack<Note>
	Field sorted:Stack<Note>
	Field index:Int
	Field algorithm:Int
	Field progression:Int
	Field hold:Bool
	Field noteCount:Int
	Field note:Note
	Field cycle:Int
	
	Method New()
	End
	
	Method SetState(state:JsonObject)
		ReleaseAll()
		Local notes:=state.GetArray("natural")
		For Local i:=0 Until notes.Length
			Local note:=notes.GetNumber(i)
'			natural.Push(note)
		Next
		sorted=New Stack<Note>(natural)
		sorted.Sort()
	End

	Method GetState:JsonObject()	
		Local naturalArray:=New JsonArray(natural.Length*2)
		For Local i:=0 Until natural.Length
			Local note:=natural[i] 
			naturalArray.SetNumber(i*2+0,note.note)
			naturalArray.SetNumber(i*2+1,note.velocity)
		Next
		Local state:=New JsonObject
		state.SetValue("natural",naturalArray)
		Print "state is "+state.ToJson()
		Return state
	End

	Method SetArpeggiation(mode:Int,prog:Int)
		algorithm=mode
		progression=prog
	End
		
	Method ReleaseAll() Override
		Super.ReleaseAll()
		natural.Clear()
	End
	
	Method SetHold(down:Bool)
		If hold And Not down 
			ReleaseAll()
			noteCount=0
			cycle=0
		End
		hold=down
	End

	Method NoteOn(note:Note) Override
		If hold and noteCount=0
			ReleaseAll()
		Endif
		noteCount+=1
		If algorithm=0			
			output.NoteOn(note)
		Else		
			Super.NoteOn(note)
			If notemap.Contains(note.note)
				notemap.Remove(note.note)
				natural.Remove(note)
			Endif
			natural.Push(note)
			sorted=New Stack<Note>(natural)
			sorted.Sort()
		Endif
	End
	
	Method NoteOff(note:Note) Override
		If noteCount>0
			noteCount-=1
		Endif
		output.NoteOff(note)
		If Not hold
			natural.Remove(note)
			sorted=New Stack<Note>(natural)
			sorted.Sort()
		Endif
	End
	
	Method Beat() Override
		
		If natural.Length=0
			index=0
			Return
		Endif
		
		If count>0
			count-=1
			If note.note TriggerNote(note)
			Return
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
		
		Local inc:=0		
		Select progression
			Case 1
				cycle=cycle Mod natural.Length
				inc=natural[cycle].note-natural[0].note
			Case 2		
				inc=cycle
			Case 3
				inc=-cycle
		End
		note.note+=inc
		
		If note.note TriggerNote(note)
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
	Field keys:=New Keys
	
	Method New()
		For Local i:=0 Until MaxPolyphony
			Local tone:=New Voice
			tone.SetOscillator(0)
			tone.SetEnvelope(0)
			polyList.AddLast(tone)
		Next
	End
	
	Method GetKeys:Keys()
		Return keys
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

	Method NoteOn(note:Note)
		NoteOff(note)
		If polyList.Empty Return
		Local voice:=polyList.RemoveFirst()
		voice.SetEnvelope(envelope)
		voice.SetOscillator(oscillator)
		voice.NoteOn(note)
		polyMap[note.note]=voice
'		polyList.Remove(voice)
		If Not voices.Contains(voice)
			voices.Add(voice)
		Endif	
		keys.KeyOn(note.note)
	End

	Method NoteOff(note:Note)	
		Local voice:=polyMap[note.note]
		If voice
			If sustained
				sustainedVoices.AddLast(voice)
			Else
				voice.Stop()
			Endif
			polyMap.Remove(note.note)
			polyList.AddLast(voice)
		Endif
		keys.KeyOff(note.note)
	End

	Method FillAudioBuffer(buffer:Double[],samples:Int,detune:V[],gain:V[])	
		For Local voice:=Eachin voices
			voice.Mix(buffer,samples,detune,gain)
		Next		
	End
End

Class MonoSynth Implements Synth
	Field tone:Voice
	Field monoNote:Note
	Field notes:=New Stack<Note>
	Field oscillator:Int	
	Field envelope:Int
	Field volume:V=1.0
	Field keys:=New Keys

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

	Method GetKeys:Keys()
		Return keys
	End

	Method Panic()
		tone.NoteOff(monoNote)
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
	End

	Method NoteOn(note:Note)
		monoNote=note
		If Not notes.Contains(note)
			notes.Push(note)
		Endif
		tone.NoteOn(note)
		keys.KeyOn(note.note)
	End

	Method NoteOff(note:Note)
		keys.KeyOff(note.note)
		notes.Remove(note)
		If notes.Empty
			tone.NoteOff(note)		
		Else
			note=notes.Pop()
			monoNote=note
			notes.Push(note)
			tone.NoteOn(note)
			keys.KeyOn(note.note)
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
	Field keys:=New Keys

	method New(driver:PortMidi,channel:Int)
		portMidi=driver
		send=channel
	End

	Method SetTempo(tempo:Tempo,divisor:Int,duty:V,rept:int)
	End
	
	Method SetVolume(volume:V)
		If volume<0 volume=0
		If volume>1 volume=1
		Local value7:Int=127*volume
		Local setVolume:Int=(_ControllerChange)|(_VolumeController Shl 8)|(value7 Shl 16)
		portMidi.SendMessage(send,setVolume)
	End

	Method SetSustain(depress:Bool)
		Local value7:Int
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
	End

	Method NoteOn(note:Note)
		Local noteOn:Int=(_NoteOn)|(note.note Shl 8)|(note.velocity Shl 16)
		portMidi.SendMessage(send,noteOn)
		keys.KeyOn(note.note)
	End
	
	Method NoteOff(note:Note)
		Local noteOff:Int=(_NoteOff)|(note.note Shl 8)
		portMidi.SendMessage(send,noteOff)
		keys.KeyOff(note.note)
	End
			
	Method FillAudioBuffer(buffer:Double[],samples:Int,detune:V[],fade:V[])	
	End
	
	Method GetKeys:Keys()
		Return keys
	End

	Method Panic()
	End
End
