#import "<libc>"
#import "capture.h"

using libc..

Extern

function capture_main(count:Int,args:char_t ptr ptr)
function errno_exit(s:char_t Ptr)
Function xioctl:Int(fh:int, request:int, arg:Void Ptr)
function process_image(p:Void ptr, size:Int)
Function read_frame:Int()
function mainloop()
function stop_capturing()
function start_capturing()
function uninit_device()
function init_read(buffer_size:uint)
function init_mmap()
function init_userp(buffer_size:uint)
function init_device()

function close_device:Int()
function open_device:Int()

#rem
 "Usage: %s [options]\n\n"
 "Version 1.3\n"
 "Options:\n"
 "-d | --device name Video device name [%s]\n"
 "-h | --help Print this message\n"
 "-m | --mmap Use memory mapped buffers [default]\n"
 "-r | --read Use read() calls\n"
 "-u | --userp Use application allocated buffers\n"
 "-o | --output Outputs stream to stdout\n"
 "-f | --format Force format to 640x480 YUYV\n"
 "-c | --count Number of frames to grab [%i]\n"
 "",
#end

'int capture_main(int argc, char **argv)



public

function Main()
	print "hello"
'	local args:=new CString[]("")
'	capture_main(1,null)

 	Local res:=open_device()
 	
 	Print "open_device:"+res
 	
#rem
 init_device()
 start_capturing()
 mainloop()
 stop_capturing()
 uninit_device()
 close_device()
#end
end

