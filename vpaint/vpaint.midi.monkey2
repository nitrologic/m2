#import "vpaint.monkey2"

#Import "<portmidi>"

Using portmidi..

Class VPaintMidi Extends VPaint
	Method New(title:String)
		Super.New(title)
		InitMidi()
	End

	Field portMidi:PortMidi

	method InitMidi()
		Print "PortMidi test 0.1"
		Print "Scanning Midi Bus, please wait."
		portMidi=New PortMidi()
		Local inputs:=portMidi.inputDevices.Length
		Print "inputs="+inputs
		For Local i:=0 Until inputs
			portMidi.OpenInput(i)
			'Print "Open #"+i+" handle="+h 
		next
	End

	method PollMidi()
		Const NoteOn:=144
		Const NoteOff:=128
		Const Controller:=176
		Const PitchWheel:=224

		While portMidi.HasEvent()
			Local b:=portMidi.EventDataBytes()
			Local note:=b[1]
			Local velocity:=b[2]
			Local word:Int=note+(velocity Shl 7)
			Select b[0]
				Case NoteOn
'					vsynth.NoteOn(note,oscillator,envelope)
				Case NoteOff
'					vsynth.NoteOff(note)
				Case PitchWheel
'					pitchbend=1.0+(word-8192)/8192.0
				Case Controller
					OnControl(b[1],b[2])
				Default
					Print b[0]+" "+b[1]+" "+b[2]+" "+b[3]
			End					
		Wend
'		portMidi.Sleep(1.0/60)
	End

	Method OnRender( display:Canvas ) Override	
	
		PollMidi()
		
		Super.OnRender(display)
	End

End

Function Main()
	Print title
	instance = New AppInstance	
	New VPaintMidi(title)
	App.Run()	
End
