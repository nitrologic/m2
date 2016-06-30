Namespace portmidi

#Import "<std>"

#Import "pm_common/*.h"
#Import "porttime/*.h"

#Import "pm_common/portmidi.h"
#Import "pm_common/portmidi.c"
#Import "pm_common/pmutil.c"

#Import "porttime/porttime.h"
#Import "porttime/porttime.c"

#If __HOSTOS__="windows"

#Import "pm_win/pmwin.c"
#Import "pm_win/pmwinmm.c"
#Import "porttime/ptwinmm.c"

#Endif

#If __HOSTOS__="macos"

#Import "<CoreMIDI.framework>"

#Import "pm_mac/finddefault.c"
#Import "pm_mac/pmmac.c"
#Import "pm_mac/pmmacosxcm.c"
#Import "pm_mac/readbinaryplist.c"
#Import "porttime/ptmac.c"

#Endif

#If __HOSTOS__="linux"

#import "pm_linux/finddefault.c"
#import "pm_linux/pmlinux.c"
#import "pm_linux/pmlinuxalsa.c"
#import "porttime/ptlinux.c"

#Endif

#Import "mididriver.h"

Extern

Class PmDeviceInfo Extends Void
	Field structVersion:Int
	Field interf:Byte Ptr		' underlying MIDI API, e.g. MMSystem or DirectX
	Field name:Byte Ptr		' device name, e.g. USB MidiSport 1x1 
	Field input:Int
	Field output:Int	
	Field opened:Int
End

Alias Handle:Int

Class MidiDriver Extends Void 
	Field deviceCount:Int
	Field error:Int
	Field errorText:Byte Ptr
	Field info:PmDeviceInfo

	Method Sleep(duration:Double)
	Method GetInfo(index:Int)	
	Method OpenInput:Handle(index:Int)
	Method PollDevice:Bool(handle:Handle)
	Method CloseDevice(handle:Handle)

	Method MidiEventData:Int()
	Method MidiEventMessage:Byte Ptr()
	Method MidiEventMessageLength:Int()
	Method MidiEventTimestamp:Double()
	
End

Public

Alias IntStack:std.collections.Stack<Int>

Class PortMidi
	Field version:="0.01"
	Field deviceCount:Int
	
	Field driver:MidiDriver
	
	Field inputDevices:=New IntStack()
	Field outputDevices:=New IntStack()
	
	Field openDevices:=New IntStack()
	
	Method Sleep(seconds:Double)
		driver.Sleep(seconds)
	End

	Method New() 
		Print "PortMidi"							
		driver=New MidiDriver()
		Print "countDevices="+driver.deviceCount
		
		For Local id:=0 Until driver.deviceCount
			driver.GetInfo(id)
			Print "info:interf"+String.FromCString(driver.info.interf)
			Print "info.name:"+String.FromCString(driver.info.name)
			Print "info.input:"+driver.info.input
			Print "info.output:"+driver.info.output
			
			If driver.info.input inputDevices.Push(id)
			If driver.info.output outputDevices.Push(id)
		Next
		
		Local input0:=inputDevices.Get(0)		
		Local in0:=driver.OpenInput(input0)

		Print "in0="+in0
		
		openDevices.Push(in0)
	End	
		
	Method Poll:Int()
		Local count:Int
		For Local device:=Eachin openDevices
			count+=driver.PollDevice(device)
		Next
		Return count
	End
	
	Method EventData:Int()
		Return driver.MidiEventData()
	End
End

