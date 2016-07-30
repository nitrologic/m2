#import "<std>"
#import "fb.h"

Using libc
Using std..

extern 

Function testfb:int()

Public

Class FrameBuffer16 Extends Pixmap

	Method New(w:Int,h:Int,pitch:Int,data:Short Ptr)
		Super.New(w,h,PixelFormat.IA16,UByte Ptr(data),pitch)
	End
	
	Method Copy(source:Pixmap,x:Int,y:Int)
	end

End

Function EnumerateFramebuffers()
	For Local i:=0 Until 16
		Local dev:="/dev/fb/"+i
		Local file:=fopen(dev,"r")
		If file
			Print "Found "+dev
			fclose(file)
		endif
	next
end



function Main()
	print "hello"
	
	EnumerateFramebuffers()
	
'	Print "testfb:"+testfb()

end
