Namespace vsynth

#import "vsynth.monkey2"

Public 

Function Main()
	Print "vsynth process"
	instance = New AppInstance	
	New VSynthWindow(AppTitle)	
	App.Run()	
End
