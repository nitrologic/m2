#import "<libc>"
#import "capture.h"

using libc..

Extern

#rem
function capture_main(count:Int,args:char_t ptr ptr)
function errno_exit(s:char_t Ptr)
Function xioctl:Int(fh:int, request:int, arg:Void Ptr)
function process_image(p:Void ptr, size:Int)
Function read_frame:Int()
function init_read(buffer_size:uint)
function init_mmap()
function init_userp(buffer_size:uint)
#end

function open_device:Int()
function init_device()
function start_capturing()
function readFrame:int()
function stop_capturing()
function uninit_device()
function close_device:Int()

public

function Main()
	print "hello"

 	Local res:=open_device()

 	Print "open_device:"+res
	if res<>0 return
 	
	init_device()
	start_capturing()

	for local i:=0 until 20
		print i
		local error:=readFrame()
		if error
			print "Read frame failed"
			return
		endif
	next

	stop_capturing()
	uninit_device()
	close_device()

	Print "Capture Complete"
end
