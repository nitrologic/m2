
#Import "<std>"
#Import "<mojo>"
#Import "<portmidi>"

Using std..
Using portmidi..

Function Main()

	Print "PortMidi test 0.1"

	Print "Scanning Midi Bus, please wait."

	Local portMidi:=New PortMidi()
	
	Local inputs:=portMidi.inputDevices.Length
	
	Print "inputs="+inputs
	
	For Local i:=0 Until inputs
		portMidi.OpenInput(i)
		'Print "Open #"+i+" handle="+h 
	next
	
	Local counter:Int
	
	Const NoteOn=144
	Const NoteOff=128

	While True
		While portMidi.HasEvent()
			Local b:=portMidi.EventDataBytes()
			Print b[0]+" "+b[1]+" "+b[2]+" "+b[3]
		Wend
		portMidi.Sleep(1.0/60)
	Wend

End
