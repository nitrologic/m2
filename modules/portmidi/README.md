##PortMIDI module for monkey2

A work in progress API for communication between desktop computers and MIDI instruments. 

[PortMidi Documentation](README.txt)


``` monkey

#Import "<std>"
#Import "<mojo>"
#Import "<portmidi>"

Using std..
Using portmidi..

Function Main()

	Print "PortMidi test 0.1"

	Print "Scanning Midi Bus, please wait."

	Local portMidi:=New PortMidi()
	
	Local counter:Int

	While True
		While portMidi.Poll()
			Print portMidi.EventData()
		Wend
		portMidi.Sleep(1.0/60)
	Wend

End

```
