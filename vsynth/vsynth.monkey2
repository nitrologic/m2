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
Global FragmentSize:=4096
Global AudioFrequency:=44100


Class Oscillator
	Field r:Double
	Method Sample:Float(hz:Double) Virtual
		Return 0
	End
End

Class Sine Extends Oscillator
	Method Sample:Float(hz:Double) Override
		Local t:Double=hz*Pi/AudioFrequency
		r+=t
		Return Sin(r)
	End
End

Class Sawtooth Extends Oscillator
	Method Sample:Float(hz:Double) Override
		Local t:Double=hz/AudioFrequency
		r+=t
		Return ((r+1) Mod 2)-1
	End
End

Class Triangle Extends Oscillator
	Method Sample:Float(hz:Double) Override
		Local t:Double=hz/AudioFrequency
		r+=t
		Return (Abs(r Mod 4)-2)-1
	End
End

Class Square Extends Oscillator
	Method Sample:Float(hz:Double) Override
		Local t:Double=hz/AudioFrequency
		r+=t
		Local i:Int=r
		Return -1+2*(i&1)
	End
End


Class VSynth Extends Window

	Method New(title:String)
		Super.New(title,720,560,WindowFlags.Resizable)				
		vsynth=Self
		OpenAudio()
	End
	
	Field audioSpec:SDL_AudioSpec
	Field buffer:Float[]
	Field mousex:Int
	Field mousey:Int

	Method OpenAudio()
		buffer=New Float[FragmentSize*2]
		Local spec:SDL_AudioSpec
		spec.freq=AudioFrequency	
		spec.format = AUDIO_S16
		spec.channels = 2
		spec.samples = FragmentSize	'16384
		spec.callback = audio_callback
		
'		spec.userdata = Void Ptr(Self)
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
	
'	Field left:=New Sine()
'	Field right:=New Sine()
'	Field left:=New Sawtooth()
'	Field right:=New Sawtooth()
'	Field left:=New Square()
'	Field right:=New Square()
	Field left:=New Triangle()
	Field right:=New Triangle()
	
	Method FillAudioBuffer:Float[](samples:Int)	
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
			
	Function audio_callback(a:Void Ptr, b:UByte Ptr, byteCount:Int)
		Local samples:Int=byteCount/4
		If samples>FragmentSize
			Print "Audio Overrun"
			samples=FragmentSize
		Endif
		Local buffer:=vsynth.FillAudioBuffer(samples)
		For Local i:=0 Until samples
			Local s0:Int=buffer[i*2+0]*2000			
			If s0>32767 s0=32767
			If s0<-32767 s0=-32767
			b[i*4+0]=s0 & 255
			b[i*4+1]=s0 Shr 8
			Local s1:Int=buffer[i*2+1]*2000			
			If s1>32767 s1=32767
			If s1<-32767 s1=-32767
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
