#import "<mojo>"
#import "<std>"

#import "host.monkey2"

Using std..
Using mojo..

global host:=GetHost()

Class MojoWindow extends Window

	Global active:MojoWindow

	Field fb:PixelMap
	Field cx:Int
	Field cy:Int
	
	Method New()
		active=self
		ClearColor=New Color(0.1,1)

		print "Enumerating framebuffer devices."
		Local n:=host.EnumerateFramebuffers()		

		For Local i:=0 Until n
			Local fbi:=host.GetFramebuffer(i)
			Print "fb"+i+":"+fbi.width+"x"+fbi.height
			If fbi.width=8 fb=fbi
		Next
		Move(0,0)		
		New Timer(2,Tick)
	End
	
	Function Tick()
		active.OnTimer()
	end
	
	Method OnRender(canvas:Canvas) Override
		App.RequestRender()
		canvas.Translate(50,50)		
		Local n:=24
		Local n2:=20
		For Local y:=0 Until fb.height
			For Local x:=0 Until fb.width
				canvas.Color=fb.Color(x,y)
				canvas.DrawRect(x*n,y*n,n2,n2)
			Next
		Next
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

function Main()

	Print "INT_THS_H_M="+i2c.INT_THS_H_M

	print "Enumerating I2C bus"
	Local i2cCount:=host.EnumerateI2C()				
	Print "i2cCount="+i2cCount
	if i2cCount
		local i2c:=host.GetI2C(0)
	endif

'	new AppInstance
'	new MojoWindow
'	App.Run()	

End















