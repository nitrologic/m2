#import "<mojo>"
#import "<std>"
Using mojo..
Using std..

' work in progress

' an example of process management in monkey2

' useful for dashboard style appliances and multi core algorithms
' spawn are intended to share layers of a display (not glcontexts) using overlay magic
' todo: prototype display overlay per spawn on pi2 via Broadcom VideoCore IV overlay selector

Class Spawn Extends Process

	field in:=new Deque<String>

	Method new(command:String)
		Start(AppPath()+" "+command)		
	End

	method WriteLine(line:String)		
	End

	method ReadLine:String()
		If in.Empty Poll()
		if in.Empty return null
		return in.PopLast()
	End
	
	Method Poll()
		Local n:=StdoutAvail
		If n=0 Return
		Local line:=ReadStdout()
		Print "Spawn:"+line	
		in.PushFirst(line)
	end		
end

Class Stand
	Field registry:=New Map<String,Spawn>
	field open:=new Map<int,Spawn>

	Method Eval:String(arguments:String[])
		Return Null
	End

	method Run()
	end

	method WriteLine(handle:int,line:String)
		open[handle].WriteLine(line)
	end

	method ReadLine:String(handle:int)
		Return open[handle].ReadLine()
	end

	method Close()
	end

	Method Poll()
		For Local p:=Eachin open.Values
			p.Poll()
		next
	end	
end

Class BananaStand Extends Stand
End

Class PiCommands Extends Stand
End

Class MainWindow Extends Window

 	Field stand:=New Stand
 	
	Method New()
		Super.New("Process test",640,480)
		Print "Main "+AppPath()		
'		Local p:=New Spawn()		
'		Run("HelloWorld")
'		processStack.Push(p)
	End
		
	Method OnRender(canvas:Canvas) Override
		App.RequestRender()						
		stand.Poll()
		canvas.DrawText("hello",0,0)
	end
		
	Method OnKeyEvent(event:KeyEvent) override
		App.Terminate()
	End
End

Function Main()
	Local a:=AppArgs()	

	If a.Length=0 Print "AppArgs is empty!";Return
	
	If a.Length>1 
		' this is a sub process spawned by MainWindow feel free to block :)
		Print a[1]
		Return
	endif

	New AppInstance
	New MainWindow()
	App.Run()
End
