namespace posix

#import "<unistd.h>"
#import "<sys/ioctl.h>"
#import "<libc>"

Using libc

'#if __HOSTOS__="pi"

extern 

Function open:Int( path:CString,mode:Int )

function ioctl:int( fd:int,request:uint,memory:void ptr)
function ioctl:int( fd:int,request:uint,value:int)

function read:int( fd:int,buffer:void ptr,count:uint)
function write:int( fd:int,buffer:void ptr,count:uint)

Function close:Int( fd:int)


'#endif
