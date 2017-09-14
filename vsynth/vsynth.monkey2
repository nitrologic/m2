#Import "audiopipe.monkey2"
#Import "oscpipe.monkey2"

#Import "<std>"
#Import "<mojo>"
#Import "<sdl2>"
#import "<sdl2-mixer>"
#Import "<portmidi>"

Using std..
Using mojo..
Using sdl2..
Using portmidi..
Using openal..

Extern 

'Function JsonArray

Function SDL_GetPrefPath:Byte Ptr(org:CString,app:CString)

Public 

Global OSCPort:=8000

Global DefaultWindowFlags:=WindowFlags.Resizable|WindowFlags.HighDPI

Global AppTitle:String="VSynth 0.05"	
Global Contact:="Latest Source=github.com/nitrologic/m2"

Global FragmentSize:=512

Global About:="VSynth Control"
Global Octave1:= "Sharps=    W   E       T   Y   U      "
Global Octave0:= "Notes=A   S   D  F   G   H    J  K"
Global Controls:="Midi Panic=Escape,Quit=LongEscape"

Global RecordNames:=New String[]("Paused","Recording")
Global SustainNames:=New String[]("Up","Down")
Global OscillatorNames:=New String[]("Square","Sine","Sawtooth","Triangle","Noise","Rom","Live Mic","Sampler")
Global EnvelopeNames:=New String[]("None","Plain","Punchy","SlowOut","SlowIn")
Global ArpNames:=New String[]("None","Natural","Ascending","Descending","UpDown","Random1","Random2")
Global ProgNames:=New String[]("None","Recurse","Ascend","Descend")
Global SynthNames:=New String[]("Mono1","Poly64","MidiOut")
Global HoldNames:=New String[]("Off","On")
Global DivisorNames:=New String[]("Whole","Half","Third","Quarter","Fifth","Sixth","Seventh","Eighth")
Global DutyNames:=New String[]("1:2","3:4","1:4","7:8","1:8","5:8","3:8")
Global DutyCycle:=New Double[](0.5,0.75,0.25,0.875,0.125,0.625,0.375)
Global RepeatNames:=New String[]("1x","2x","3x","4x")

#import "softsynth.monkey2"

Public

Global WriteAhead:=8192

Global instance:AppInstance
Global vsynth:VSynth

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
	Field panSpeed:Double=22.0'/128'1024	'samples per pixel
	Field panAmp:V
	
	Field sampleBank:=New SampleBank()
	Field recording:=False
	Field bankPath:String

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
				Record(buffer,samples)
			Endif
		Endif
		Return buffer
	End
		
	Method PlotScope(samples:Int)	
		' green left channel
		scope.Pen(LowSaturatedGreen)
		For Local i:=0 Until samples
			scope.Plot(panSpeed*i,buffer[i*2+0])			
		Next
		' red right channel
		scope.Pen(LowSaturatedRed)
		For Local i:=0 Until samples
			scope.Plot(panSpeed*i,panAmp*buffer[i*2+1])			
		Next
' advance head
		position+=samples*panSpeed
'		scope.Advance(Int(8*position))
		scope.Advance(position)		'Int(8*position))
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
	
	Method NoteOn(note:Note)
		root.NoteOn(note)
	End

	Method NoteOff(note:Note)	
		root.NoteOff(note)
	End

	Method GetKeys:Keys()
		Return root.GetKeys()
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
		If Not recording sampleBank.Save(bankPath)
	End

	Method Record(samples:V[],length:Int)
		sampleBank.Record(samples,length)
	End
	
	Method SetBankPath(path:String)
		bankPath=path
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
	
	Method Command(command:SynthCommand,down:bool)
		If Not down Return
		Select command
			Case SynthCommand.Record
				CycleRecord()
			Default
				root.Command(command,down)
		End
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

Class OSCHost

	Const BufferSize:=1024
	Field HostName:="0.0.0.0"
	Field HostPort:Int

	Field buffer:=New DataBuffer(BufferSize,ByteOrder.BigEndian)
	Field clients:=New Map<SocketAddress,Int>		
	Field addr:=New SocketAddress				
	Field socket:Socket

	Method Listen(port:Int)	
		HostPort=port
		socket=Socket.Bind( HostName, HostPort )
		If Not socket 
			Print "OSCHost Receiver failed to bind socket to " + HostName+":"+HostPort
			Return
		Endif		
'		socket.SetOption( "SO_REUSEADDR",1 )
		Print "OSCHost receving at address "+socket.Address+" ready"	
	End
	
	method PeekCString:String(offset:Int)
		Local len:=0
		While buffer.PeekByte(offset+len)
			len+=1
		Wend
		Return buffer.PeekString(offset,len)
	End
	
	Method Poll()	
		While True 
			Local ready:=socket.CanReceive
			If Not ready Return
			Local bytes:=socket.ReceiveFrom(buffer.Data,ready,addr)

'			Print "socket received "+bytes +" from client "+addr
			If Not clients[addr]
				Local id:=clients.Count()+1
				clients[ New SocketAddress( addr ) ]=id
				Print "New Client! id="+id
			Endif
			
			Local p:=0
			While p<bytes
				Local code:=buffer.PeekByte(p)
				Select code
					Case 47
						Local a:=PeekCString(p+1)
						Local n:=(1+a.Length+1+3)&-4
						p+=n
						Print "OSC Address "+a
					Case 44
						Local f:=PeekCString(p+1)
						Local n:=(1+f.Length+1+3)&-4
						p+=n
'						Print "OSC Format "+f
						For Local ff:=Eachin f
							Select ff
								Case "f"[0]
									Local v:=buffer.PeekFloat(p)
									p+=4
									Print "f:"+v
								Default
									Print "OSC Format Error:"+ff
							end
						Next
					Default
						Print "OSC Parse Error code "+code
						Return
				End			
			Wend
		wend
	End
	
	Method CloseAll()		
		socket.Close()
	End
	
End

Class VSynthWindow Extends Window

	Const MusicKeys:=New Key[]( Key.Q,Key.A,Key.W,Key.S,Key.E,Key.D,  Key.F,Key.T,Key.G,Key.Y,Key.H,Key.U,Key.J,  Key.K,Key.O,Key.L,Key.P,Key.Semicolon)',Key.Apostrophe )
	Field keyNoteMapping:=New Map<Key,Int>

	Field frame:Int
	Field tick:Int
	Field mousex:Int
	Field mousey:Int
	
	Field volume:V=0.1
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
	Field arpstate:JsonObject
		
	Field tempo:Tempo=92
	Field pressure:Int
	Field resetMidi:Int
	field resetOSC:Int
	
	Field oscHost:OSCHost
		
	Field portMidi:PortMidi

	Field midiInputs:Int
	Field midiOutputs:Int
	Field midiSend:Int
	Field midiSendName:="None"
	
	Field audioLatency:Int=2 '1 Shl (10+n) samples
	Field applet:Applet
	Field goFullscreen:Bool
	Field bankPath:String
		
	Method New(host:Applet, rect:Recti, fullscreen:bool, title:String)
		Super.New(title,rect,DefaultWindowFlags)		
		applet=host
		goFullscreen=fullscreen
		Create()
	End
	
	Method New(host:Applet, title:String)
		Super.New(title,800,600,DefaultWindowFlags)		
		applet=host
		Create()
	End
	
	Method SelectBankPath()
		Local path:=RequestDir("Select Bank Path",bankPath)
		If path bankPath = path
	End
	
	Method Create()
		volume=applet.DefaultNumber("synthVolume")
		synth=applet.DefaultNumber("synthMode")
		oscillator=applet.DefaultNumber("synthOscillator")
		envelope=applet.DefaultNumber("synthEnvelope")
		octave=applet.DefaultNumber("synthOctave")

		tempo=applet.DefaultNumber("arpTempo")		
		
		arp=applet.DefaultNumber("arpMode")
		prog=applet.DefaultNumber("arpProg")
		hold=applet.DefaultNumber("arpHold")
		div=applet.DefaultNumber("arpDivisor")
		duty=applet.DefaultNumber("arpDuty")
		rept=applet.DefaultNumber("arpRepeat")
		arpstate=applet.DefaultObject("arpState")

		audioLatency=applet.DefaultNumber("audioLatency")
		
		bankPath=Applet.prefsPath
		bankPath=applet.DefaultString("bankPath",bankPath)

		For Local i:=0 Until MusicKeys.Length
			keyNoteMapping.Set(MusicKeys[i],i-1)
		Next

		vsynth=New VSynth()
		vsynth.SetSynth(synth)
		
		applet.OnFrame(Self)
		OpenAudio()
#If __HOSTOS__<>"windows"
		ResetMidi()
#Endif
		ResetOSC()

		ClearColor=new Color(1.0/16,1.0)
' midi mappings		
		MapKontrol()
		MapAkai()
		
		
		vsynth.arpeggiator.SetState(arpstate)
	End

	Method OnWindowEvent(event:WindowEvent) Override
		Local host:=applet
		Select event.Type
			Case EventType.WindowClose
				Print "OnClose"
				host.OnClose()
			Case EventType.WindowResized
				host.OnFrame(Self)
				Print "OnSize "+Width+"x"+Height
			Case EventType.WindowMoved
				host.OnFrame(Self)
				Print "OnMove"
		End
	End

	Field EscapeTime:Int
	
	Method EscapeDown()			
		pitchbend=1.0
		vsynth.ClearKeys()
		EscapeTime=App.Millisecs
	End

	Method EscapeUp()			
		Local duration:=App.Millisecs-EscapeTime
		If duration>500
			applet.OnClose()
		Endif
	End

	Field audioSpec:SDL_AudioSpec
	Field buffer:=New Double[FragmentSize*2]
	Field audioPipe:=AudioPipe.Create()
			
	Method OpenAudio()
		Local spec:SDL_AudioSpec
		spec.freq=AudioFrequency	
		spec.format = AUDIO_S16
		spec.channels = 2
		spec.samples = FragmentSize
		spec.callback = AudioPipe.Callback
		spec.userdata = audioPipe.Handle()
		
		Mix_CloseAudio()		
		Local error:Int = SDL_OpenAudio(Varptr spec,Varptr audioSpec)		
		If error
			Print "error="+error+" "+String.FromCString(SDL_GetError())
		Else
			Print "Audio Open freq="+audioSpec.freq
			AudioFrequency=audioSpec.freq
		Endif				
		SDL_PauseAudio(0)
	End

	Method UpdateAudio()
		While True
			Local buffered:=audioPipe.writePointer-audioPipe.readPointer
			If buffered>=WriteAhead Exit
			Local samples:=FragmentSize
			Local buffer:=vsynth.FillAudioBuffer(samples)			
			Local pointer:=Varptr buffer[0]
			audioPipe.WriteSamples(pointer,samples*2)
		Wend
	End
			
	Method ResetOSC()
		resetOSC=0
		oscHost=New OSCHost()
		oscHost.Listen(OSCPort)
	End
	
	Method PollOSC()
		If oscHost
			oscHost.Poll()
		Endif
	end
	
	Method ResetMidi()
		resetMidi=0
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
	End
	
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
			Local note:=New Note(b[1],b[2])
			Local word:Int=note.note+(note.velocity Shl 7)
						
			Select b[0]
				Case NoteOn
					If note.velocity=0
						vsynth.NoteOff(note)
					Else
						vsynth.NoteOn(note)
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
	Field commands:=New Map<Int,SynthCommand>
	
	Method MapAkai()
		commands[83]=SynthCommand.Patch1
		commands[80]=SynthCommand.Patch2
		commands[81]=SynthCommand.Patch3
		commands[82]=SynthCommand.Patch4
		commands[84]=SynthCommand.NextProgram
		commands[85]=SynthCommand.PreviousProgram	
	End	
	
	Method MapKontrol()
		For Local i:=23 To 41
			commands[i]=Cast<SynthCommand>(Int(SynthCommand.User)+i-23)
		Next
		commands[47]=SynthCommand.Rewind
		commands[45]=SynthCommand.Play
		commands[48]=SynthCommand.Forward
		commands[49]=SynthCommand.Loop
		commands[46]=SynthCommand.Stop
		commands[44]=SynthCommand.Record
	End
	
	Method OnProgramChange(index:Int)
'		vsynth.Control(Patch+index)
	End
	
	Method OnControl(index:Int, value:Int)	
	
		Local f:=value/128.0
		value-=64
		
		If commands.Contains(index)
			Local command:=commands[index]
			
			Print "command="+int(command)+" value="+value
			
			If value<0
				vsynth.Command(command,False)
			Else
				vsynth.Command(command,True)
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
		End
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
	End
		
	Field noteDownMap:=New IntMap<Bool>
	Field KeyVelocity:=80
	
	Method KeyDown(key:Key)
		If keyNoteMapping.Contains(key)
			KeyUp(key)
			Local note:=keyNoteMapping[key]+octave*12
			noteDownMap[note]=True
			
			vsynth.NoteOn(New Note(note,KeyVelocity))
		Else
			Print "Unmapped keycode "+Int(key)
		Endif
	End

	Method KeyUp(key:Key)		
		If keyNoteMapping.Contains(key)
			For Local octave:=0 Until MaxOctave
				Local note:=keyNoteMapping[key]+octave*12
				If noteDownMap.Contains(note)	
					vsynth.NoteOff(New Note(note,0))
					noteDownMap.Remove(note)
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
				vsynth.NoteOn(New Note(note,KeyVelocity))
			Else
				vsynth.NoteOff(New Note(note,0))			
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
			Case Key.F1
				Fullscreen = Not Fullscreen				
				applet.OnFrame(Self)
			Case Key.F2
				CycleAudioLatency()
			Case Key.F3
				CycleMidiSend()
			Case Key.F4
				SelectBankPath()
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
				resetMidi=1
				resetOSC=1
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
				EscapeDown()
			Case Key.Space
				vsynth.Command(SynthCommand.Record,True)
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
				sustain=True
			Case Key.RightShift
				sustain=Not sustain
			Case Key.PageUp
				volume=volume?1.20*volume Else 0.2
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
				EscapeUp()
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
'				pixels.Click(mousex,mousey)
		End
	End
	

	Method OnRender( display:Canvas ) Override	
		If goFullscreen
			goFullscreen=False
			Fullscreen=True
		Endif
	
		If resetMidi
			ResetMidi()
		Endif
	
		PollMidi()
		PollOSC()
	
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

		UpdateAudio()

		Local text:String = About+",,"+Octave1+","+Octave0
		text+=",,Octave=< >="+octave
		text+=",Sustain=Shift="+SustainNames[sustain]
		text+=",Volume=PageUpDown="+FloatString(volume)
		text+=",PitchBend=Mouse Wheel="+FloatString(pitchbend)		
		text+=",,Oscillator=1-8="+OscillatorNames[oscillator]
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
		text+= ",Scope=CursorKeys="+panx+","+pany
		text+= ",FullScreen=F1"
		text+= ",Buffer=F2="+SampleLatency()+"("+MilliLatency()+"ms)"
		text+=",,Enable MIDI=Backspace"
		text+=",MidiIn=F3=All ["+midiInputs+"]"
		text+= ",MidiOut=F3="+midiSendName+"["+midiOutputs+"]"
		text+=",BankPath=F4="+bankPath
		text+= ",Record=Space="+RecordNames[Int(vsynth.recording)]
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

		Local keymap:=vsynth.GetKeys()		
		
		keystyle.DrawKeyboard(display,440,100,keymap)		
		keystyle.DrawTape(480,70,40,25)
		
		vsynth.scope.Draw(display,440,300)
	End				
	
	Method SampleLatency:Int()
		Return (1 Shl (10+audioLatency))
	End
	
	Method MilliLatency:Int()
		Return 1000*SampleLatency()/AudioFrequency
	End

	Field pixels:=New ColorMap(420,20)
	Field keystyle:=New SynthStyle()

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
	Field index:Int
	Field canvas:Canvas
	Field bg:=LowSaturatedBlue
	Field fg:=LowSaturatedGreen

	Method New(dim:Int,id:Int)		
'		Super.New(dim,dim,TextureFlags.Dynamic|TextureFlags.Filter|TextureFlags.Mipmap)		
'		Super.New(dim,dim,TextureFlags.Dynamic|TextureFlags.Filter)		

		Super.New(dim,dim,TextureFlags.Dynamic)		
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
	End

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
		dimension=400	'	256'128
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

	Method Plot(x:P,y:P)
		current.Plot(xlocal+x,y)
	End
	
	Method Pen(c:Color)
		current.Pen(c)
	End

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
		Next
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
	
	Method DrawKeyboard(display:Canvas,x:Int,y:Int,keymap:Keys)				
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
End


Class Applet
	Global title:="VSynth"
	Global prefsPath:=String.FromCString(SDL_GetPrefPath("nitrologic","vsynth"))
	Global prefsFile:="vsynth.prefs.json"

	Field hasPrefs:Bool
	Field windowRect:Recti
	Field windowFullscreen:Bool
		
	Field window:VSynthWindow
	
	Field defaults:JsonObject

	Method New()
		LoadPrefs()
		If hasPrefs
			window=New VSynthWindow(Self, windowRect, windowFullscreen, title)
		Else
			window=New VSynthWindow(Self, title)
		Endif
	End

	Function TrueFalse:String(b:Bool)
		If b Return "true"
		Return "false"
	End
	
	Method DefaultString:String(name:String,value:String)
		Local s:=defaults?defaults.GetString(name) Else ""
		Return s?s Else value
	End

	Method DefaultNumber:V(name:String)
		Return defaults?defaults.GetNumber(name) Else 0
	End

	Method DefaultArray:JsonArray(name:String)	
		Local prefs:=defaults
		If prefs.Contains(name)
			Return prefs.GetArray(name)
		Endif
		Return New JsonArray
	End

	Method DefaultObject:JsonObject(name:String)	
		Local prefs:=defaults
		If prefs.Contains(name)
			Return prefs.GetObject(name)
		Endif
		Return New JsonObject
	End

	Method LoadPrefs()	
		defaults=JsonObject.Load(prefsPath+prefsFile)

		Local prefs:=defaults

		If Not prefs
			Print "prefs not loaded from "+prefsPath			
			Local raw:=LoadString(prefsPath)
			Print "raw="+raw
			Return
		Endif

		If prefs.Contains("winRect")
			Local a:=prefs.GetArray("winRect")
			Local f:=prefs.GetBool("winFullscreen")
			Local x:=a.GetNumber(0)
			Local y:=a.GetNumber(1)
			Local w:=a.GetNumber(2)
			Local h:=a.GetNumber(3)
			If w<240 w=240
			If h<120 h=120
			windowRect=New Recti(x,y,x+w,y+h)
			windowFullscreen=f
			hasPrefs=True
			Print "prefs loaded r="+x+","+y+","+w+","+h+" f="+TrueFalse(f)
		Endif
		
	End

	Method OnFrame(window:Window)
		If window.Fullscreen
			windowFullscreen=True
		Else
			windowFullscreen=False
			windowRect=window.Frame
		Endif
	End

	Function JsonString:String(args:Stack<String>)
		Local s:String
		For Local i:=0 Until args.Length Step 2
			Local a:=args[i+0]
			Local b:=args[i+1]
			If i>0 s+=","
			s+="~q"+a+"~q:"+b
		Next
		Return "{"+s+"}"
	End
	
	Method OnClose()		
		Local winRect:="["+windowRect.X+","+windowRect.Y+","+windowRect.Width+","+windowRect.Height+"]"
		Local winFS:=windowFullscreen?"true"else"false"

'		Local json:String="{~qwinRect~q:"+winRect+",~qwinFullscreen~q:"+winFS+",~qsynthVolume~q:"+window.volume+"}~n"

		Local json:=New Stack<String>
		json.Add("winRect")
		json.Add(winRect)
		json.Add("winFullscreen")
		json.Add(winFS)
		json.Add("audioLatency")
		json.Add(window.audioLatency)
		json.Add("synthVolume")
		json.Add(window.volume)
		json.Add("synthOscillator")
		json.Add(window.oscillator)
		json.Add("synthEnvelope")
		json.Add(window.envelope)
		json.Add("synthMode")
		json.Add(window.synth)
		json.Add("arpMode")
		json.Add(window.arp)
		json.Add("synthOctave")
		json.Add(window.octave)
		json.Add("arpHold")
		json.Add(window.hold?1 Else 0)
		json.Add("arpTempo")
		json.Add(window.tempo)
		json.Add("arpDivisor")
		json.Add(window.div)
		json.Add("arpDuty")
		json.Add(window.duty)
		json.Add("arpProg")
		json.Add(window.prog)
		json.Add("arpState")
'		json.Add(window.notes.ToString())
		json.Add(vsynth.arpeggiator.GetState().ToJson())
		json.Add("arpRepeat")
		json.Add(window.rept)
		json.Add("panSpeed")
		json.Add(window.panx)
		json.Add("panAmp")
		json.Add(window.pany)
		json.Add("bankPath")
		json.Add("~q"+window.bankPath+"~q")
		
		If GetFileType(prefsPath)=FileType.None CreateDir(prefsPath)
		
		Local js:=JsonString(json)

		If Not SaveString(js, prefsPath+prefsFile)
			'Notify("Warning", "Unable to open "+path, False)
			Print "Unable to save prefs to "+prefsPath
			Return
		Endif
		Print "saved prefs as "+js+" in "+prefsPath
		App.Terminate()
	End

End

Function Main()
	instance = New AppInstance	
	New Applet
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
	
