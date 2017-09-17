Namespace myapp
 
#Import "<std>"
#Import "<mojo>"
 
Using std..
Using mojo..
 
Class MyWindow Extends Window
	
	Field _sound:Sound
 
	Method New( title:String="Simple mojo app",width:Int=640,height:Int=480,flags:WindowFlags=Null )
 
		Super.New( title,width,height,flags )
		
		Local n:=256
		
		Local data:=New AudioData( n,AudioFormat.Mono8,11025 )
		For Local i:=0 Until n
			data.Data[i]=128
		Next
		For Local i:=0 Until 32
			data.Data[i]=(i*5)&255
		Next
		_sound=New Sound( data )
				
	End
 
	Method OnRender( canvas:Canvas ) Override
	
		If Keyboard.KeyHit( Key.Space )
			_sound.Play()
			Print "play"
		Endif
		
		App.RequestRender()
	
		canvas.DrawText( "Hello World!",Width/2,Height/2,.5,.5 )
	End
	
End
 
Function Main()
 
	New AppInstance
	
	New MyWindow
	
	App.Run()
End