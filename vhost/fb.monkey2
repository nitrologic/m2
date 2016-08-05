#import "posix.monkey2"

namespace fb

Using posix..

function queryFramebuffer:int(fd:int,width:int ptr,height:int ptr,depth:int ptr,len:int ptr)

	Local fixed:fb_fix_screeninfo
	if ioctl(fd,FBIOGET_FSCREENINFO,Varptr fixed)=-1
		Print "Error reading fixed information"
		return -1
	endif

	Local variable:posix.fb_var_screeninfo
	if ioctl(fd,FBIOGET_VSCREENINFO,Varptr variable)=-1
		Print "Error reading fixed information"
		return -2
	endif

	width[0]=variable.xres
	height[0]=variable.yres
	depth[0]=variable.bits_per_pixel

	len[0]=width[0]*height[0]*depth[0]/8

	return 0
end

function mapFramebuffer:void ptr(fd:int,sizeBytes:int)

	Local memory:=mmap(Void Ptr(0),sizeBytes,PROT_WRITE,MAP_SHARED,fd,0)
	
	Local badPointer:=Void Ptr(-1)

'	if memory-badPointer=0
'		print "mmap failure on fd"
'		return null
'	endif

	print "Framebuffer mapped to memory"
	return memory
end

function unmapFrameBuffer(memory:void ptr,len:int)
	munmap(memory,len)
end
