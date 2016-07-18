
Namespace myapp

#Import "<std>"
#Import "<mojo>"

Using std..
Using mojo..

Class MyWindow Extends Window

	Field framecount:=0

	Method OnRender( canvas:Canvas ) Override
	
		App.
	
		Local text:="Hi! framecount="+framecount+" fps="+App.FPS+" ms="+App.Millisecs
	
		canvas.DrawText( text,10,Height/2,0,1 )
		
		framecount+=1
	
	End
	
End

Function Main()

	New AppInstance
	
	New MyWindow
	
	App.Run()
End
