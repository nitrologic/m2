#import "<mojo>"
#import "<std>"

#import "framebuffer.monkey2"

Using std..
Using mojo..

class MojoWindow extends Window

	Field host:=GetHost()

	Field cx:Int
	Field cy:Int

	Field fb:PixelMap
	
	Method New()
		print "Enumerating framebuffer devices."
		Local n:=host.EnumerateFramebuffers()		
		For Local i:=0 Until n
			Local fbi:=host.GetFramebuffer(i)
			Print "fb"+i+":"+fbi.width+"x"+fbi.height
			If fbi.width=8 fb=fbi
		Next
		Move(0,0)
	End
	
	Method OnRender(canvas:Canvas) Override
		App.RequestRender()
		Local tw:=Width/fb.width
		Local th:=Height/fb.height
		Local n:=8
		Local n2:=16
		For Local y:=0 Until fb.height
			For Local x:=0 Until fb.width
				canvas.Color=fb.Color(x,y)
				canvas.DrawRect(x*tw+n,y*th+n,tw-n2,th-n2)
			Next
		next
	end
	
	field ink:ushort=$f800

	Method Move(dx:Int,dy:Int)
		cx=(cx+dx)&7
		cy=(cy+dy)&7
		fb.Plot(cx,cy,ink)
	end

	method Click()
		ink=(ink shr 3) | (ink shl 13)
	end

	method OnKeyEvent(e:KeyEvent) Override
		print "KeyEvent!"+int(e.RawKey)
		Select e.Type
			Case EventType.KeyDown
				Select e.Key
					Case Key.Escape
						App.Terminate()
					Case Key.Enter
						Click()
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
	new AppInstance
	new MojoWindow
	App.Run()
end
