#import "videocapture.monkey2"
#import "pixelmap.monkey2"
#import "videocapture.monkey2"
#import "posix.monkey2"
#import "i2c.monkey2"
#import "socket.monkey2"

#if __HOSTOS__="pi"

#import "fb.monkey2"
#import "v4l2.monkey2"

Using libc
Using i2c
using posix

Alias FrameBuffer16:PixelMap

Class LinuxHost

	Field fb16:=New Stack<FrameBuffer16>
	Field i2c:=New Stack<I2C>
	Field vidcap:=New Stack<video.Capture>

	Method EnumerateI2C:Int()
		i2c.Clear()
		For Local i:=0 Until 16
			Local dev:="/dev/i2c-"+i			
			Local fd:=open(dev,2)
			If fd<>-1
				i2c.Push(New I2C(fd))			
			endif
		next
		Return i2c.Length
	End
	
	Method GetI2C:I2C(index:Int)
		Return i2c[index]
	end

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
						local mem16:=ushort ptr(memory)
						fb16.Push(New FrameBuffer16(w,h,mem16,count))
					Endif
				Endif

				close(fd)
			Endif
		Next	
		Return fb16.Length
	End
	
	Method GetFramebuffer:FrameBuffer16(index:Int)
		Return fb16[index]
	End
			
	Method EnumerateVideoCapture:Int()			
		vidcap.Clear()
		vidcap.Push(new v4l2.Device)
		return vidcap.Length
	end

	method GetVideoCapture:video.Capture(index:int)
		return vidcap[index]
	end
	
End

Function GetHost:LinuxHost()
	Return New LinuxHost
end

#else

Public

Using i2c

Alias FrameBuffer16:PixelMap

Class VirtualHost
	Field fb16:=New Stack<FrameBuffer16>
	Field fb0:=New UShort[64]
	Field vidcap:=New Stack<video.Capture>

	Method New()	
	End
	
	Method EnumerateI2C:Int()			
		Return 0
	End

	Method GetI2C:I2C(index:Int)
		return null
	end
	
	Method EnumerateFramebuffers:Int()			
		fb16.Clear()
		fb16.Push(New FrameBuffer16(8,8,fb0.Data,128))
		Return fb16.Length
	End
	
	Method GetFramebuffer:FrameBuffer16(index:Int)
		Return fb16[index]
	end

	Method EnumerateVideoCapture:Int()			
		return 0
	end

	method GetVideoCapture:video.Capture(index:int)
		return null
	end
End

Function GetHost:VirtualHost()
	Return New VirtualHost
End

#endif
