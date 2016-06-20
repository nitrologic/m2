' readgif.bmx

Strict

Global CODEMASK[]=[0,$0001,$0003,$0007,$000F,$001F,$003F,$007F,$00FF,$01FF,$03FF,$07FF,$0FFF]

Const MAXCODES=4096

Const HASALPHA=1

Global stack:Short[MAXCODES]
Global suffix:Short[MAXCODES]
Global prefix:Short[MAXCODES]

Global lzhbuffer:Byte[256]
Global bbptr,bits,bytes,bval

Local stream:TStream
Local pixmaps:TList
Local pix:TPixmap

stream=ReadFile("HylianSymbol.gif")
'stream=ReadFile("acidsoftware.gif")
'stream=ReadFile("grid.gif")
pixmaps=ReadGifPixmaps(stream)
pix=TPixmap(pixmaps.valueatindex(0))
SavePixmapPNG pix,"testpng.png"

Function LoadGif:TImage(url:Object)
	Local stream:TStream
	Local pixmaps:TList
	Local pix:TPixmap
	stream=ReadFile(url)
	If stream
		pixmaps=ReadGifPixmaps(stream)
		CloseFile stream
		If pixmaps
			pix=TPixmap(pixmaps.valueatindex(0))
			Return LoadImage(pix)
		EndIf
	EndIf
End Function

Function ReadGifPixmaps:TList(stream:TStream)
	Local pixmaps:TList=New TList
	Local pix:TPixmap
	Local pal:Int Ptr
	Local bgcol
	Local aspect
	Local i,r,g,b,w,h,f,n,t
	Local _delay,_start,_end,_loop,_flags

	Local hdr:Byte[6]

	If stream.Read(hdr,6)<>6 Return
	If hdr[0]<>Asc("G") Or hdr[1]<>Asc("I") Or hdr[2]<>Asc("F") Return
' 89A	
	Print hdr[3]+Chr(hdr[3])
	Print hdr[4]+Chr(hdr[4])
	Print hdr[5]+Chr(hdr[5])
	w=stream.ReadShort()
	h=stream.ReadShort()
	f=stream.ReadByte()
	bgcol=stream.ReadByte()
	aspect=stream.ReadByte()
	If f&128
		n=2Shl(f&7)
		pal=New Int[n]
		For i=0 Until n
			r=stream.ReadByte()
			g=stream.ReadByte()
			b=stream.ReadByte()
			pal[i]=$ff000000|(r Shl 16)|(g Shl 8)|(b)
		Next
	EndIf
	_delay=-1
	While True
		n=stream.ReadByte()
		Select n
		Case -1
			Return pixmaps
		Case $2c
			parsegif(pixmaps,stream,pal,_flags)
			DebugLog "gif $2c complete pixmaps.count()="+pixmaps.count()
			Return pixmaps		
'			DebugStop
		Case $21
			n=stream.ReadByte()
			Select n
				Case $f9'graphic control block
					n=stream.ReadByte()
					f=stream.ReadByte()
					_delay=stream.ReadShort()
					t=stream.ReadByte()
					If f&1 
						pal[t]:&$ffffff
						_flags=HASALPHA
						DebugLog "hasalpha"
					EndIf
					stream.seek(stream.pos()+n-4)
					While True
						n=stream.ReadByte()
						If n=0 Exit
						stream.seek(stream.pos()+n)
					Wend
			Default
				n=stream.ReadByte()
				stream.Seek stream.pos()+n
				While True
					n=stream.ReadByte()
					If n=0 Exit
					stream.seek(stream.pos()+n)
				Wend				
			End Select
		End Select
	Wend
End Function

Function lzhread(stream:TStream,currsize)
	Local	i,r
	If bits=0
		If bytes<=0
			bbptr=0
			bytes=stream.ReadByte()
			For i=0 Until bytes
				lzhbuffer[i]=stream.ReadByte()
			Next
		EndIf
		bval=lzhbuffer[bbptr]
		bbptr:+1
		bits=8
		bytes:-1
	EndIf
	r=bval Shr(8-bits)
	While bits<currsize
		If bytes<=0
			bbptr=0
			bytes=stream.ReadByte()
			For i=0 Until bytes
				lzhbuffer[i]=Stream.ReadByte()
			Next
		EndIf
		bval=lzhbuffer[bbptr]
		bbptr:+1
		r:|(bval Shl bits)
		bits:+8
		bytes:-1
	Wend
	bits:-currsize
	Return r&CODEMASK[currsize]
End Function

Function parsegif(pixmaps:TList,stream:TStream,pal:Int Ptr,flags,squash=False)
	Local x,y,w,h,f	'i,r,g,b,n
	Local size,csize,topslot,clear
	Local ending,slot,newcodes,avail,bitsleft
	Local c,code,oc,fc,sp,bptr
	Local yinc,lpass
	Local pix:TPixmap

	x=stream.ReadShort()
	y=stream.ReadShort()
	w=stream.ReadShort()
	h=stream.ReadShort()
	f=stream.ReadByte()

	yinc=1
	If (f&64) yinc=8

	DebugLog "createpixmap("+w+","+h+")"
	
	If flags&HASALPHA
		pix=CreatePixmap(w,h,PF_BGRA8888)
	Else
		pix=CreatePixmap(w,h,PF_BGR888)
	EndIf
	pixmaps.addlast pix
'	can->SetHandle(-x,-y)
'	If (squash)
'		can->resize(w,(h+1)>>1,canflags,False)
'	Else
'		can->resize(w,h,canflags,False)
' image data

	size=stream.ReadByte()'system.debug("size="+size)
	csize=size+1
	topslot=1 Shl csize
	clear=1 Shl size
	ending=clear+1
	slot=ending+1
	newcodes=ending+1
	bbptr=0
	bits=0
	bytes=0
	bval=0
	
	While True
		c=lzhread(stream,csize)
		If c=ending Exit
		If c=clear
			csize=size+1
			slot=newcodes
			topslot=1 Shl csize
			While True 
				c=lzhread(stream,csize)
				If c<>clear Exit
			Wend
			If c=ending Exit
			If c>=slot c=0
			oc=c
			fc=c
'			If (squash)
'				If ((x&1)=(y&1)) WritePixel(x,y Shr 1,pal[c])
'			Else
				WritePixel(pix,x,y,pal[c])
'			EndIf
			x:+1
			If x=w
				x=0
				y:+yinc
				If y>=h 
					y=4 Shr lpass
					yinc=y*2
					lpass:+1
				EndIf
			EndIf
		Else
			code=c
			If code>=slot
				code=oc		
				stack[sp]=Short(fc)	'simon was here
				sp:+1
			EndIf
			While code>=newcodes
				stack[sp]=suffix[code]
				sp:+1
				code=prefix[code]
			Wend
			stack[sp]=Short(code)	'simon was here
			sp:+1
			If slot<topslot
				fc=code
				suffix[slot]=Short(fc)
				prefix[slot]=Short(oc)
				slot:+1
				oc=c
			EndIf	
			If slot>=topslot And csize<12
				topslot=topslot Shl 1
				csize:+1
			EndIf
			While sp>0
				sp:-1
				c=stack[sp]
				If squash
					If (y=h-1) Or (x&1)=(y&1)
						WritePixel(pix,x,y Shr 1,pal[c])
					EndIf
				Else
					WritePixel(pix,x,y,pal[c])
				EndIf
				x:+1
				If x=w 
					x=0
					y:+yinc
					If y>=h
						y=4 Shr lpass
						yinc=y*2
						lpass:+1
					EndIf
				EndIf
			Wend
		EndIf
	Wend
End Function
