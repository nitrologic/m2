#import "<mojo>"
#import "<std>"
#import "fb.h"

Using libc
Using std..
Using mojo..

extern 

Function open:Int( path:CString,mode:Int )
Function close:Int( fd:int)

Class fb
	Function queryFramebuffer(descriptor:Int,width:Int ptr,height:Int ptr,depth:Int ptr,bytecount:Int Ptr)
	Function mapFramebuffer:Void Ptr(descriptor:Int,bytecount:Int)
	Function unmapFrameBuffer(memory:Void ptr,bytecount:Int)
end

Public

Class PixelMap
	Field width:Int
	Field height:Int
	Field data:Short Ptr
	Field bytecount:Int
	Field wspan:int

	Method New(w:Int,h:Int,m:Short Ptr,n:Int)
		width=w
		height=h
		data=m
		bytecount=n
		wspan=bytecount/(2*height)
	End
	
	Method Plot(x:int,y:int,c:Short)
		data[y*wspan+x]=c
	End
	
	Method Box(x:Int,y:Int,w:Int,h:Int,c:Short)
		For Local i:=0 To w
			Plot(x+i,y,c)
			Plot(x+i,y+h,c)
		Next
		
		For Local i:=1 Until h
			Plot(x,y+i,c)
			Plot(x+w,y+i,c)
		next
	end
end

Class FrameBuffer16 Extends PixelMap
	Method New(w:Int,h:Int,data:Void Ptr,bytecount:int)
		Super.New(w,h,Short Ptr(data),bytecount)				
		Plot(0,0,$f800)
		Box(1,1,5,4,$07e0)
		Box(4,4,3,3,$001f)
	End	
End

Class LinuxHost

	Field fb16:=New Stack<FrameBuffer16>

	Method EnumerateFramebuffers()
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
		Print "fb16.Count="+fb16.Length
	end
end

class MojoWindow extends Window

	method OnKeyEvent(e:KeyEvent) Override
		print "KeyEvent!"+int(e.RawKey)
	end
end

function Main()
	Local host:=New LinuxHost

	new AppInstance
	new MojoWindow
	
	print "Enumarating framebuffer devices."

	host.EnumerateFramebuffers()
	
	App.Run()
end
