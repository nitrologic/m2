Namespace v4l2

#import "capture.h"
#import "capture.cpp"
#import "videocapture.monkey2"

Extern

global frame_data:void ptr
global frame_size:int

function open_device:Int()
function init_device()
function start_capturing()
function readFrame:int()
function stop_capturing()
function uninit_device()
function close_device:Int()

public


Global HexDigits:=New String[]("0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F")

Function HexByte:String(value:Int)
	Local v0:=(value Shr 4)&15
	Local v1:=value&15
	Return HexDigits[v0]+HexDigits[v1]
End

Function HexList:String(binary:byte ptr,count:int)
	Local h:String
	For Local i:=0 Until count
		h+=HexByte(binary[i])+" "	
	Next
	Return h
End


Class Device Implements video.Capture

	method Open:Int()
		Local res:=open_device()
		If res Return res
		init_device()
		Return 0
	end

	Method Start()
		start_capturing()
	end
	
	method Read:Int()
		Return readFrame()
	End
		
	method Stop()
		stop_capturing()
	End
	
	method Close()
		uninit_device()
		close_device()
	End

End
	
function TestV4L2()
	print "hello"

 	Local res:=open_device()

 	Print "open_device:"+res
	if res<>0 return
 	
	init_device()

	start_capturing()

	for local i:=0 until 20

		local error:=readFrame()

		if error
			print "Read frame failed"
			return
		endif
		
		if frame_size
			local i:=byte ptr(frame_data)
			print frame_size+":"+HexList(i,20)
		Else
			Print "empty"
		endif

	next

	stop_capturing()
	uninit_device()
	close_device()

	Print "Capture Complete"
end
