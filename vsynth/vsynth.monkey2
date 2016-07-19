#Import "<std>"
#Import "<mojo>"
#Import "<sdl2>"
#Import "<portmidi>"
#Import "audiopipe.monkey2"

' VSynth 0.05 tasks
' common midi button mapping and vsynth window commands
' communicate between instances
' persist performance patch and configuration

Using std..
Using mojo..
Using sdl2..
Using portmidi..

Global AppTitle:String="VSynth 0.04"	
Global Contact:="Latest Source=github.com/nitrologic/m2"

Global About:="VSynth Control"
Global Octave1:= "Sharps=    W   E       T   Y   U      "
Global Octave0:= "Notes=A   S   D  F   G   H    J  K"
Global Controls:="Reset Keys=Space,Quit=Escape,,Enable MIDI=Backspace"

Global SustainNames:=New String[]("Up","Down")
Global OscillatorNames:=New String[]("Square","Sine","Sawtooth","Triangle","Noise")
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
Global FragmentSize:=1024
Global WriteAhead:=4096

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
		delta+=t
		Return 2*Pi*Sin(Pi*delta)
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
		Local t:T=2*hz/AudioFrequency
		delta+=t
		Return (Abs(delta Mod 4)-2)-1
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
	Field gain:V=0.12
	Field amp:V
	
	Method SetOscillator(osc:Int)
		Select osc
			Case 0 oscillator=New Square
			Case 1 oscillator=New Sine
			Case 2 oscillator=New Sawtooth
			Case 3 oscillator=New Triangle
			Case 4 oscillator=New Noise
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
	
	Method Mix(buffer:Double[],samples:Int,detune:V,fade:V)
		Local left:=1.0
		Local right:=1.0
		If pan<0 right+=pan
		If pan>0 left-=pan		
		For Local i:=0 Until samples
			Local v:=oscillator.Sample(hz*detune)			
			Local e:V
			If noteOn e=envelope.On() Else e=envelope.Off()
			e*=gain
			e*=amp
			e*=fade
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
	Method FillAudioBuffer(buffer:Double[],samples:Int,detune:V,fade:V)	
	Method Panic()
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
	End
	
	Method NoteOff(note:Int) virtual
		output.NoteOff(note)
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

	Method FillAudioBuffer(buffer:Double[],samples:Int,detune:V,fade:V)	
		Update(2.0*samples/AudioFrequency)
		output.FillAudioBuffer(buffer,samples,detune,fade)
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
	
	Method New()
		For Local i:=0 Until MaxPolyphony
			Local tone:=New Voice
			tone.SetOscillator(0)
			tone.SetEnvelope(0)
			polyList.AddLast(tone)
		Next
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
	End

	Method FillAudioBuffer(buffer:Double[],samples:Int,detune:V,gain:V)	
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
	End

	Method NoteOff(note:Int)
		notes.Remove(note)
		If notes.Empty
			tone.NoteOff()		
		Else
			note=notes.Pop()
			monoNote=note
			notes.Push(note)
			tone.NoteOn(note,monoVelocity)
		Endif
	End

	Method FillAudioBuffer(buffer:Double[],samples:Int,detune:V,fade:V)	
		tone.Mix(buffer,samples,detune,fade)
	End

End


Class MidiSynth Implements Synth
	Const _NoteOn:=144
	Const _NoteOff:=128
	Const _ControllerChange:=176

	Const _VolumeController:=7
	Const _ExpressionController:=11
	Const _SustainPedal:=64

	Field portMidi:PortMidi
	Field send:Int

	method new(driver:PortMidi,channel:Int)
		portMidi=driver
		send=channel
	end

	Method SetTempo(tempo:Tempo,divisor:Int,duty:V,rept:int)
	End
	
	Method SetVolume(volume:V)
		If volume<0 volume=0
		If volume>1 volume=1
		local value7:Int=127*volume
		Local setVolume:Int=(_ControllerChange)|(_VolumeController Shl 8)|(value7 Shl 16)
		portMidi.OutputData(send,setVolume)
	end

	Method SetSustain(depress:Bool)
		local value7:Int
		If depress value7=127
		Local setSustain:Int=(_ControllerChange)|(_SustainPedal Shl 8)|(value7 Shl 16)
		portMidi.OutputData(send,setSustain)
	End
	
	method SetTone(oscillator:Int,envelope:Int)
	End
	
	Method NoteOn(note:Int,velocity:int)
		Local noteOn:Int=(_NoteOn)|(note Shl 8)|(velocity Shl 16)
		portMidi.OutputData(send,noteOn)
	End
	
	Method NoteOff(note:Int)
		Local noteOff:Int=(_NoteOff)|(note Shl 8)
		portMidi.OutputData(send,noteOff)
	End
			
	Method FillAudioBuffer(buffer:Double[],samples:Int,detune:V,fade:V)	
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
	Field audioPipe:=AudioPipe.Create()
	Field detune:V
	Field fade:V=1.0
	Field poly:Synth=New PolySynth()
	Field mono:Synth=New MonoSynth()
	Field root:Synth
	Field arpeggiator:=New Arpeggiator()
	Field midiSynth:MidiSynth
	Field synthMode:int
	
	Method New()
		OpenAudio()
		arpeggiator.SetSynth(mono)
		arpeggiator.SetArpeggiation(1,0)
		root=arpeggiator
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
	
	Method ClearKeys()
		root.Panic()
	End
	
	Method OnButtonDown(button:Int)
		Select button
			Case NextProgram
'				oscillator=Wrap(oscillator+1,0,OscillatorNames.Length)
			Case PrevProgram
'				oscillator=Wrap(oscillator-1,0,OscillatorNames.Length)
			default
				Print "button@"+button
		end
	End

	Method OnButtonUp(button:Int)
	End	

	Field buffer:=New Double[FragmentSize*2]

	Method UpdateAudio()
		While True
			Local buffered:=audioPipe.writePointer-audioPipe.readPointer
			If buffered>=WriteAhead Exit
			For Local i:=0 Until FragmentSize*2
				buffer[i]=0
			Next	

			Local samples:=FragmentSize
			vsynth.root.FillAudioBuffer(buffer,samples,detune,fade)			
			Duration+=samples

			Local pointer:=Varptr buffer[0]
			audioPipe.WriteSamples(pointer,FragmentSize*2)
		Wend
	End
			
	Method OpenAudio()
		Local spec:SDL_AudioSpec
		spec.freq=AudioFrequency	
		spec.format = AUDIO_S16
		spec.channels = 2
		spec.samples = FragmentSize
		spec.callback = AudioPipe.Callback
		spec.userdata = audioPipe.Handle()
		
		Local error:Int = SDL_OpenAudio(Varptr spec,Varptr audioSpec)		
		If error
			Print "error="+error+" "+String.FromCString(SDL_GetError())
		Else
			Print "Audio Open freq="+audioSpec.freq
			AudioFrequency=audioSpec.freq
		Endif
						
		SDL_PauseAudio(0)
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
	
	Method New(title:String)
		Super.New(title,1280,720,WindowFlags.Resizable)				
		For Local i:=0 Until MusicKeys.Length
			keyNoteMap.Set(MusicKeys[i],i-1)
		Next
		vsynth=New VSynth
#If __HOSTOS__="pi"
		ResetMidi()
#endif
		ClearColor=new Color(1.0/16,1.0)
		
' midi mappings		
		MapKontrol()
		MapAkai()
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
		Next
		If midiSend<midiOutputs
			midiSendName=portMidi.OutputName(midiSend)
		Endif			
	End
		
	Method CycleMidiSend()
		If midiOutputs	
			midiSend=(midiSend+1)Mod midiOutputs
			midiSendName=portMidi.OutputName(midiSend)
			vsynth.SetMidiOutput(portMidi,midiSend)
		Endif			
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
		vsynth.OnButtonDown(Patch+index)
	End
	
	Method OnControl(index:Int, value:Int)	
	
		local f:=value/128.0
		value-=64
		
		If buttons.Contains(index)
			Local button:=buttons[index]
			If value<0
				vsynth.OnButtonDown(button)
			Else
				vsynth.OnButtonUp(button)
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
			Case Key.F3
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
			Case Key.Escape
				instance.Terminate()
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
			Case Key.Space
				vsynth.ClearKeys()
			Case Key.LeftShift
				sustain=true
			Case Key.RightShift
				sustain=not sustain
			Case Key.PageUp
				volume=1.20*volume
			Case Key.PageDown
				volume=0.92*volume
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

		vsynth.Detune(pitchbend)
		vsynth.SetVolume(volume)
'		vsynth.SetVolumeFader(volume)
		vsynth.SetArp(arp,prog)
		vsynth.SetHold(hold)
		vsynth.SetSustain(sustain)
		vsynth.SetTempo(tempo,1+div,DutyCycle[duty],rept)
		vsynth.SetTone(oscillator,envelope)
		vsynth.UpdateAudio()

		Local text:String = About+",,"+Octave1+","+Octave0
		text+=",,Octave=< >="+octave
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
		text+=",,MidiIn["+midiInputs+"]=F2=All"
		text+= ",MidiOut["+midiOutputs+"]=F3="+midiSendName
		text+=",,"+Contact
		
		display.Color=Color.Black
		display.DrawRect(0,0,400,Height)
		display.Color=Color.Grey

		Local cy:=20
		For Local line:=Eachin text.Split(",")
			Local cx:=50
			For Local tab:=Eachin line.Split("=")
				display.DrawText(tab,cx,cy)
				cx+=100
			Next
			cy+=20
		Next

		pixels.Zoom(12)
		pixels.Dim(32,2)		
		pixels.Draw(display)	
		
		keys.DrawKeyboard(display,440,100)
	End				
	
	Field pixels:=New ColorMap(420,20)
	Field keys:=New SynthStyle()
End

Class SynthStyle

	Field BlackKey:=New Color(20,120,120)
	Field WhiteKey:=New Color(20,200,200)
	Field HotKey:=New Color(20,20,20)

	Field canvas:Canvas

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
	
	Method DrawKeyboard(display:Canvas,x:Int,y:Int)				
		canvas=display
		For Local p:=0 To 1			
			Local px:=x+2
			Local py:=y+6
			For Local i:=0 To 127			
				Local octave:=i/12
				Local note:=i-octave*12				
				Local sharp:Bool=note=1 Or note=3 Or note=6 Or note=8 Or note=10				
				Local down:Bool				
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
