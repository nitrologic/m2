#import "<mojo>"
#import "<std>"
Using mojo..
Using std..

' an example of process management in monkey2

' proposed for banana stand dashboard appliances and multi core algorithms

' research display overlay per spawn via Broadcom VideoCore IV overlay selector

Class Spawn Extends Process
	Method Run(command:String)
		Start(AppPath()+" "+command)		
	End
end

Class Spew Extends New Stack<Spawn>
	Field registry:=New Map<String,Spawn>

	Method Eval:String(arguments:String[])
	end
end

Class BananaStand Extends Spew

end

Class PiCommands Extends Spew

end

Class MainWindow Extends Window

 	Field spew:=New Spew
 	
	Method New()
		Super.New("Process test",640,480)
		Print "Main "+AppPath()		

		Local p:=New Spawn()		
		Run("HelloWorld")
		processStack.Push(p)
	End
		
	Method OnRender(canvas:Canvas) Override
		App.RequestRender()						
		Poll()
	end
	
	Method Poll()
		For Local p:=Eachin processStack
			Local n:=p.StdoutAvail
			If n=0 Return
			Local in:=p.ReadStdout()
			Print ":"+in	
		next
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
