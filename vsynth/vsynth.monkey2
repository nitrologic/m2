#Import "<std>"
#Import "<mojo>"
#Import "<sdl2>"

Using std..
Using mojo..
Using sdl2..

Global instance:AppInstance
Global vsynth:VSynth

Global Pos:Int
Global FragmentSize:=4096

Class VSynth Extends Window

	Method New(title:String)
		Super.New(title,720,560,WindowFlags.Resizable)				
		vsynth=Self
		OpenAudio()
	End
	
	Field audioSpec:SDL_AudioSpec Ptr
	Field buffer:Float[]
	Field mousex:Int
	Field mousey:Int

	Method OpenAudio()
		buffer=New Float[FragmentSize*2]
		Local spec:SDL_AudioSpec
		spec.freq=44100	
		spec.format = AUDIO_S16
		spec.channels = 2
		spec.samples = FragmentSize	'16384
		spec.callback = audio_callback
'		spec.userdata = Void Ptr(Self)
		Mix_CloseAudio()		
		Local error:Int = SDL_OpenAudio(Varptr spec,audioSpec)		
		If error
			Print "error="+error+" "+String.FromCString(SDL_GetError())
		Endif
		SDL_PauseAudio(0)
	End
	
	Method FillAudioBuffer:Float[](samples:Int)	
		Local p0:Float=mousey/5000.0
		Local p1:Float=mousex/5000.0
		For Local i:=0 Until samples
			Local left:=Sin(p0*(Pos+i))
			Local right:=Sin(p1*(Pos+i))
			buffer[i*2+0]=left
			buffer[i*2+1]=right
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
