#import "<mojo>"
#import "<std>"

#import "host.monkey2"

Using std..
Using mojo..
Using socket

global host:=GetHost()

Global HexDigits:=New String[]("0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F")

Function HexByte:String(value:Int)
	Local v0:=(value Shr 4)&15
	Local v1:=value&15
	Return HexDigits[v0]+HexDigits[v1]
End

Function HexList:String(binary:byte ptr,count:int)
	Local h:String
	For Local i:=0 Until count
		h+=HexByte(binary[i])+" "	
	Next
	Return h
End

Class TextureStream
	Field width:Int
	Field height:Int
	Field images:Image[]
	Field pixmaps:=New Stack<Pixmap>
	Field size:Int
	Field write:int
	
	Method New(w:Int,h:Int,n:Int)
		width=w
		height=h
		images=New Image[w*h]
		For Local i:=0 Until n
			pixmaps.Push(new Pixmap(w,h,PixelFormat.RGB24))			
		Next		
		size=w*h*3
	End
	
	Method Write(src:Int Ptr)	
		Local index:=write Mod pixmaps.Length 
		Local pixmap:=pixmaps[index]
		memcpy(pixmap.Data,src,size)
		Local image:=New Image(pixmap)		
		If images[index] images[index].Discard()
		images[index]=image		
		write+=1
	end
	
	Method Draw(canvas:Canvas,frame:Int,x:Float,y:Float,z:Float)
		Local index:=frame Mod pixmaps.Length
		Local image:=images[index]	
		If image canvas.DrawImage(image,x,y,0,z,-z)
	End

End

Class MojoWindow extends Window

	Global active:MojoWindow

	Field fb:PixelMap
	Field cx:Int
	Field cy:Int
	Field cap:video.Capture
	Field vid:=New TextureStream(640,480,160)
	
	Method New()
		active=Self
		ClearColor=New Color(0.1,1)

		print "Enumerating framebuffer devices."
		Local n:=host.EnumerateFramebuffers()		

		For Local i:=0 Until n
			Local fbi:=host.GetFramebuffer(i)
			Print "fb"+i+":"+fbi.width+"x"+fbi.height
			If fbi.width=8 fb=fbi
		Next
		Move(0,0)		
		
		host.EnumerateVideoCapture()
		cap=host.GetVideoCapture(0)
		If cap
			cap.Open()
			cap.Start()
		Endif
		
		New Timer(2,Tick)
	End
	
	Function Tick()
		active.OnTimer()
	End

	Method UpdateTestFrame()
		Local test:=New Int[320*240]
		Local tx:=vid.write Mod 320
		For Local y:=0 Until 240
			Local p:=Varptr test[y*320]
			For Local x:=0 Until 320
				If x=tx
				p[x]=-1
				else
				p[x]=$ff884400
				endif
			Next
		Next
		vid.Write(test.Data)
	End
		
	Method UpdateCapture()
	
		If cap=Null
			UpdateTestFrame()
			return
		Endif
	
		If cap.Read()
			Print "Capture Error"
		Else
			If cap.DataLen()
'				local src:=byte ptr(cap.Data())
'				Print HexList(src,32)
				For Local y:=0 To 8
					local src:=byte ptr(cap.Data())+y*320*4
					For Local x:=0 To 8
						Local c16:Int=((src[0] Shr 4)Shl 11) | ((src[1] Shr 3)Shl 5) | (src[2] Shr 4)
						src+=4					
						fb.Plot(x,y,c16)
					Next
				next						
			endif	
'			print frame_size+":"+HexList(i,20)
			vid.Write(Int Ptr(cap.Data()))
		Endif
	End
	
	Method DrawHat(canvas:Canvas)
		Local n:=24
		Local n2:=20
		For Local y:=0 Until fb.height
			For Local x:=0 Until fb.width
				canvas.Color=fb.Color(x,y)
				canvas.DrawRect(x*n,y*n,n2,n2)
			Next
		Next
	End
			
	Method OnRender(canvas:Canvas) Override

		UpdateCapture()
		
		App.RequestRender()

		Local cx:=0
		Local cy:=32				
		For Local i:=0 Until 240
			Local index:=vid.write-i-1
			If index<0 index=0
			vid.Draw(canvas,index,10+cx,10+cy,0.125)
			If i=0
				vid.Draw(canvas,index,0,Height-40,1.0)		
			endif
			cx=cx+50
			If cx+50>Width
				cx=0
				cy+=44
			Endif
		Next

		canvas.Translate(Width-200,Height-200)		
		DrawHat(canvas)		
	End
	
	Field blinkOn:=false
	field enterMillis:int
	
	field blink:Pixel=$4208
	field blink2:Pixel=$2104
	field ink:Pixel=$f800
	Field ink2:Pixel=$7000

	Method Move(dx:Int,dy:Int)
		If blinkOn Blink()
		cx=(cx+dx)&7
		cy=(cy+dy)&7
		fb.Plot(cx,cy,ink2)
	End


	Method Clear()
		fb.Clear()
	End

	Method Blink()
		fb.Xor(cx,cy,blink)
		blinkOn=Not blinkOn
	End

	method Click()
		ink=(ink shr 3) | (ink shl 13)
		ink2=(ink Shr 1)&$7bef
		ink2=(ink2 Shr 1)&$7bef
		Move(0,0)
	End
	
	Method OnTimer()
		Blink()
		if enterMillis
			local enterTime:=Millisecs()-enterMillis
			if enterTime>200
				Clear()
				enterMillis=0
			endif
		endif
	end

	method OnKeyEvent(e:KeyEvent) Override
'		print "KeyEvent!"+int(e.RawKey)
		Select e.Type
			Case EventType.KeyDown
				Select e.Key
					Case Key.Escape
						App.Terminate()
					Case Key.Enter
						Click()
						enterMillis=Millisecs()
					Case Key.Up
						Move(0,-1)
					Case Key.Down
						Move(0,1)
					Case Key.Left
						Move(-1,0)
					Case Key.Right
						Move(1,0)
				End

			Case EventType.KeyUp
				Select e.Key
					Case Key.Enter
						enterMillis=0
				end
		end
	end
end


Function TestSocketConnect()
	Local s:=Socket.Connect("google.com",80)
	Local res:=s.Write("GET / HTTP/1.0~r~n~r~n")
	While True
		Local t:=s.Read()
		If t.Length=0 Exit
		Print t
	Wend
	s.Close()
End


Function TestSocketListen()
	Print "Listening on port 8080"
	Local s1:=Socket.Listen(8080)
	If s1=Null
		Print "Listen failed"
		Return
	endif
	Local s2:=s1.Accept()
	Print "Got Connection"
	While True
		Local t:=s2.Read()
		If t.Length=0 Exit
		Print t
	Wend
	Print "Lost Connection"
	s2.Close()
	s1.Close()
End


Function TestI2CBus()
	print "Enumerating I2C bus"
	Local i2cCount:=host.EnumerateI2C()				
	Print "i2cCount="+i2cCount
	if i2cCount
		local i2c:=host.GetI2C(0)
	endif
end

function Main()
'	TestSocketListen()
'	TestSocketConnect()
'	TestI2CBus()
'	Socket.TestOSCIn(Null,"7000")
'	Socket.TestOSCOut("192.168.1.255","7000")

	new AppInstance
	new MojoWindow
	App.Run()	

End
