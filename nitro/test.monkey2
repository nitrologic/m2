#Import "<mojox>"
#Import "<mojo>"
#Import "<std>"
#Import "<nitro>"

Using mojox..
Using mojo..
Using std..

Class MyWindow Extends Window
	Method OnRender:Void(display:Canvas) Override		
		Local title:="size:"+Width+"x"+Height
		display.DrawText(title,10,10)
	end
End

Function Main()
'	nitro.HighDPI()	
	New AppInstance
	New MyWindow
	App.Run()
End
