' class 1

' instance chain audio component synth

' voice per panel UI 

' [class ] 
' [instance 1]
' [instance 2]
' [instance 3]

' [OSC]
' [*    ]
' [ *   ]
' [  *  ]
' [   * ]

#Import "<std>"
#Import "<mojo>"
#Import "<sdl2>"

' release mode only!!!

Using std..
Using mojo..
Using sdl2..

Global instance:AppInstance
Global vsynth:VSynth

Global Pos:Float
Global FragmentSize:=32
Global AudioFrequency:=44100

Alias V:Double	' Voltage
Alias T:Double ' Time
Alias F:Double ' Frequency

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
		Return Sin(Pi*delta)
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

Class Voice
	Field oscillator:Oscillator
	Field envelope:Envelope
	Field noteOn:Bool
	Field hz:F
	Field pan:V
	
	Method SetOscillator(osc:Oscillator)
		oscillator=osc
	End
	
	Method SetEnvelope(env:Envelope)
		envelope=env
	End

	Method SetPan(value:V)
		pan=value
	End
	
	Method NoteOn(note:Int)
		hz=440.0*Pow(2.0,(note-67.0)/12)
		noteOn=True
	End
	
	Method NoteOff()
		noteOn=False
	End
	
	Method Mix(buffer:Float[],samples:Int)
		Local left:=1.0
		Local right:=1.0
		If pan<0 right+=pan
		If pan>0 left-=pan		
		For Local i:=0 Until samples
			Local v:=oscillator.Sample(hz)			
			Local e:V
			If noteOn e=envelope.On() Else e=envelope.Off()
			buffer[i*2+0]+=e*left*v
			buffer[i*2+1]+=e*right*v
		Next
	End
End

Class VSynth Extends Window

	Method New(title:String)
		Super.New(title,720,560,WindowFlags.Resizable)				
		vsynth=Self
		OpenAudio()
	End
	
	Method OnRender( display:Canvas ) Override	
		App.RequestRender()	
'		UpdateSequence()
	End
	
	Field frame:Int
	Field tick:Int
		
	Method UpdateSequence()
		frame+=1
		Local t:Int=(frame/20)
		If t<>tick
			If t&1
				tone.NoteOn((t&15)*3+40)
			Else
				tone.NoteOff()			
			Endif
			tick=t
		Endif		
		
'		Print "tick d="+d
	End
	
	Field audioSpec:SDL_AudioSpec
	Field buffer:Float[]
	Field mousex:Int
	Field mousey:Int
	
	Field voices:=New List<Voice>
	Field tone:=New Voice

	Method OpenAudio()
		buffer=New Float[FragmentSize*2]
		Local spec:SDL_AudioSpec
		spec.freq=AudioFrequency	
		spec.format = AUDIO_S16
		spec.channels = 2
		spec.samples = FragmentSize
		spec.callback = audio_callback
		Mix_CloseAudio()		
		Local error:Int = SDL_OpenAudio(Varptr spec,Varptr audioSpec)		
		If error
			Print "error="+error+" "+String.FromCString(SDL_GetError())
		Else
			Print "Audio Open freq="+audioSpec.freq
			AudioFrequency=audioSpec.freq
		Endif
		
		tone.SetOscillator(New Square)
'		tone.SetEnvelope(New Envelope)
		tone.SetEnvelope(New ADSR(0.06,0.01,0.92,0.5))
		voices.AddLast(tone)
					
		SDL_PauseAudio(0)
	End
		
'	Field left:=New Sine()
'	Field right:=New Sine()
	Field left:=New Sawtooth()
	Field right:=New Sawtooth()
'	Field left:=New Square()
'	Field right:=New Square()
'	Field left:=New Triangle()
'	Field right:=New Triangle()

	Method FillAudioBuffer:Float[](samples:Int)	
		For Local i:=0 Until samples
			buffer[i*2+0]=0
			buffer[i*2+1]=0
		Next			
		For Local voice:=Eachin voices
			voice.Mix(buffer,samples)
		Next
		
		Pos+=samples
		Return buffer
	End

	
	Method FillAudioBuffer2:Float[](samples:Int)	
		Local p0:Float=mousey
		Local p1:Float=mousex
		For Local i:=0 Until samples
			Local sleft:=left.Sample(p0)
			Local sright:=right.Sample(p1)
			buffer[i*2+0]=sleft
			buffer[i*2+1]=sright
		Next			
		Pos+=samples
		Return buffer
	End
	
	Function Limit:Int(value:Int, lo:Int, hi:Int)
		If value<lo Return lo
		If value>hi Return hi
		Return value
	End
			
	Function audio_callback(a:Void Ptr, b:UByte Ptr, byteCount:Int)
		Local samples:Int=byteCount/4
		If samples>FragmentSize
			Print "Audio Overrun"
			samples=FragmentSize
		Endif

		vsynth.UpdateSequence()
		
		Local buffer:=vsynth.FillAudioBuffer(samples)
		For Local i:=0 Until samples
			Local s0:Int=buffer[i*2+0]*2000			
			s0=Limit(s0,-32767,32767)
			b[i*4+0]=s0 & 255
			b[i*4+1]=s0 Shr 8
			Local s1:Int=buffer[i*2+1]*2000			
			s1=Limit(s1,-32767,32767)
			b[i*4+2]=s1 & 255
			b[i*4+3]=s1 Shr 8 
		Next
	End

	Method OnKeyEvent( event:KeyEvent ) Override	
		Select event.Type
		Case EventType.KeyDown
			Select event.Key
			Case Key.Escape
				instance.Terminate()
			End
		End
	End

	Method OnMouseEvent( event:MouseEvent ) Override	
		mousex=event.Location.X
		mousey=event.Location.Y
	End
	
End

Function Main()
	instance = New AppInstance	
	New VSynth("VSynth0.01")	
	App.Run()	
End
