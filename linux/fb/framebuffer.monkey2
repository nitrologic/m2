#import "pixelmap.monkey2"

Alias FrameBuffer16:PixelMap

#if __HOSTOS__="pi"

#import "fb.h"

Using libc

extern 

Function open:Int( path:CString,mode:Int )
Function close:Int( fd:int)

Class FrameBuffer
	Function queryFramebuffer(descriptor:Int,width:Int ptr,height:Int ptr,depth:Int ptr,bytecount:Int Ptr)
	Function mapFramebuffer:Void Ptr(descriptor:Int,bytecount:Int)
	Function unmapFrameBuffer(memory:Void ptr,bytecount:Int)
end

Public

Class LinuxHost

	Field fb16:=New Stack<FrameBuffer16>

	Method EnumerateFramebuffers:Int()
		fb16.Clear()
		For Local i:=0 Until 16
			Local dev:="/dev/fb"+i
			
			Local fd:=open(dev,2)
			
			If fd<>-1

				Local w:Int,h:int,bpp:int,count:Int
	
				fb.queryFramebuffer(fd,Varptr w,Varptr h,Varptr bpp,Varptr count)

				Print "Found "+dev+" "+w+"x"+h+" "+bpp+":bpp count="+count
				
				If bpp=16 
					Local memory:=fb.mapFramebuffer(fd,count)
					If memory
						fb16.Push(New FrameBuffer16(w,h,memory,count))
					Endif
				Endif

				close(fd)
			Endif
		Next	
		Return fb16.Length
	End
	
	Method GetFramebuffer:FrameBuffer16(index:Int)
		Return fb16[index]
	end
	
end

Function GetHost:LinuxHost()
	Return New LinuxHost
end

#else

Public

Class FrameBuffer Extends PixelMap
end

Class VirtualHost
	Field fb16:=New Stack<FrameBuffer16>
	Field fb0:=New UShort[64]

	Method New()	
	End
	
	Method EnumerateFramebuffers:Int()			
		fb16.Clear()
		fb16.Push(New FrameBuffer16(8,8,fb0.Data,128))
		Return fb16.Length
	End
	
	Method GetFramebuffer:FrameBuffer16(index:Int)
		Return fb16[index]
	end
End

Function GetHost:VirtualHost()
	Return New VirtualHost
End

#endif