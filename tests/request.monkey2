#Import "<std>"
#Import "<mojo>"
#Import "<mojox>"

Class AppWindow Extends mojo.app.Window
	Method RequestString()
		Local result:=mojox.RequestString("enter name","enter name escape will kill app")
	End

	Method OnKeyEvent(event:mojo.app.KeyEvent) Override
		If event.Type=mojo.app.EventType.KeyUp
			Print "KeyUp"
			Return			
		endif
		If event.Key=mojo.input.Key.F1
			New std.fiber.Fiber(RequestString)
		endif
	End
	
	Method OnRender(canvas:mojo.graphics.Canvas) Override
		canvas.DrawText("F1 - request string",0,0)
	end
End

Function Main()
	New mojo.app.AppInstance
	New AppWindow()
	mojo.app.App.Run()
End