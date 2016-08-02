#import "<std>"

Using std..

Alias Pixel:UShort

Class PixelMap
	Field width:Int
	Field height:Int
	Field data:Pixel Ptr
	Field bytecount:Int
	Field wspan:Int

	Method New(w:Int,h:Int,m:Ushort Ptr,n:Int)
		width=w
		height=h
		data=m
		bytecount=n
		wspan=bytecount/(2*height)
	End

	method Clear()
		for local y:=0 until height
			local p:Pixel Ptr=data+y*wspan
			for local x:=0 until width
				p[x]=0
			next
		next
	end
	
	Method Plot(x:int,y:int,c:Pixel)
		data[y*wspan+x]=c
	End
	
	Method Add(x:int,y:int,c:Pixel)
		data[y*wspan+x]+=c
	End

	Method Color:Color(x:Int,y:Int)
		Local c:=data[y*wspan+x]
		Local r:=((c Shr 11)&$1f)/31.0
		Local g:=((c Shr 5)&$3f)/63.0
		Local b:=(c&$1f)/31.0
		Return New Color(r,g,b)
	end
	
	Method Box(x:Int,y:Int,w:Int,h:Int,c:Pixel)
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
