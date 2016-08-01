Class PixelMap
	Field width:Int
	Field height:Int
	Field data:Ushort Ptr
	Field bytecount:Int
	Field wspan:int

	Method New(w:Int,h:Int,m:Ushort Ptr,n:Int)
		width=w
		height=h
		data=m
		bytecount=n
		wspan=bytecount/(2*height)
	End
	
	Method Plot(x:int,y:int,c:Short)
		data[y*wspan+x]=c
	End
	
	Method Color:Color(x:Int,y:Int)
		Local c:=data[y*wspan+x]
		Local r:=((c Shr 11)&$1f)/31.0
		Local g:=((c Shr 5)&$3f)/63.0
		Local b:=(c&$1f)/31.0
		Return New Color(r,g,b)
	end
	
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