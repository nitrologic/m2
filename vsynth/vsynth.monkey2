' class 1

' instance chain audio component synth

#Import "<std>"
#Import "<mojo>"
#Import "<sdl2>"

#Import "audiopipe.h"

Using std..
Using mojo..
Using sdl2..

Alias V:Double	' Voltage(volts)
Alias T:Double ' Time(seconds)
Alias F:Double ' Frequency(hz)

Extern

Class AudioPipe Extends Void 
	Field readPointer:Int
	Field writePointer:Int
	Method Handle:Void Ptr()
	Method WriteSamples(samples:Double Ptr,sampleCount:Int)
	Function Callback(a:Void Ptr, b:UByte Ptr, byteCount:Int)
	Function Create:AudioPipe()
End

Public

Global instance:AppInstance
Global vsynth:VSynth

Global Duration:=0
Global FragmentSize:=32
Global WriteAhead:=8192
Global AudioFrequency:=44100

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
	
	Method Mix(buffer:Double[],samples:Int)
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

	Field audioPipe:=AudioPipe.Create()

	Method New(title:String)
		Super.New(title,720,560,WindowFlags.Resizable)				
		vsynth=Self
		UpdateAudio()					
		Print audioPipe.readPointer
		OpenAudio()
	End
	
	Method OnRender( display:Canvas ) Override	
		App.RequestRender()	
		UpdateAudio()
	End
	
	Field frame:Int
	Field tick:Int
	
	Const MusicKeys:=New Key[]( Key.A,Key.W,Key.S,Key.E,Key.D,  Key.F,Key.T,Key.G,Key.Y,Key.H,Key.U,Key.J,Key.K)
	
	Field keyNoteMap:=New Map<Key,Int>
		
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

	Field buffer:=New Double[FragmentSize*2]

	Field mousex:Int
	Field mousey:Int
	
	Field voices:=New List<Voice>
	Field tone:=New Voice

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
		
		For Local i:=0 Until MusicKeys.Length
			keyNoteMap.Set(MusicKeys[i],60+i)
		Next
		
		tone.SetOscillator(New Square)
'		tone.SetEnvelope(New Envelope)
		tone.SetEnvelope(New ADSR(0.06,0.01,0.92,0.5))
		voices.AddLast(tone)
		
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
		
	Method FillAudioBuffer:Double[](samples:Int)	
		For Local i:=0 Until samples
			buffer[i*2+0]=0
			buffer[i*2+1]=0
		Next			
		For Local voice:=Eachin voices
			voice.Mix(buffer,samples)
		Next
		
		Duration+=samples
		Return buffer
	End
		
	Function Limit:Int(value:Int, lo:Int, hi:Int)
		If value<lo Return lo
		If value>hi Return hi
		Return value
	End
				
	Field monoKey:Key
	
	Method KeyDown(key:Key)
		Local note:=keyNoteMap[key]
		tone.NoteOn(note)
		monoKey=key
	End

	Method KeyUp(key:Key)
		If key<>monoKey Return
		Local note:=keyNoteMap[key]
		tone.NoteOff()
	End

	Method OnKeyEvent( event:KeyEvent ) Override	
		Select event.Type
		Case EventType.KeyDown
			Select event.Key
			Case Key.Escape
				instance.Terminate()
			Default
				KeyDown(event.Key)
			End
		Case EventType.KeyUp
			Select event.Key
			Case Key.Escape
			Default
				KeyUp(event.Key)
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
