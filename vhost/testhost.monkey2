#import "<mojo>"
#import "<std>"

#import "host.monkey2"

Using std..
Using mojo..

class MojoWindow extends Window

	Global active:MojoWindow
	Field host:=GetHost()

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
		New Timer(5,Tick)
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
		next
	end
	
	Field blinkOn:=false
	field enterMillis:int
	
	field blink:Pixel=$2004
	field blink1:Pixel=$8010
	field ink:Pixel=$f800

	Method Move(dx:Int,dy:Int)
		If blinkOn Blink()
		cx=(cx+dx)&7
		cy=(cy+dy)&7
		fb.Plot(cx,cy,ink)
	End

	method Clear()
		fb.Clear()
	end

	Method Blink()
		If blinkOn
			fb.Add(cx,cy,blink)
		Else
			fb.Add(cx,cy,$10000-blink)
		Endif
		blinkOn=Not blinkOn
	end

	method Click()
		ink=(ink shr 3) | (ink shl 13)
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
		end
	end
end

function Main()
	Print "INT_THS_H_M="+i2c.INT_THS_H_M
	new AppInstance
	new MojoWindow
	App.Run()
end
