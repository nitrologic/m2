Namespace myapp

#Import "<std>"
#Import "<mojo>"

Using std..
Using mojo..


Class PixelMap Extends Pixmap
	Method New(w:Int,h:Int)
		Super.New(w,h)
	end
	method Rect(rx:Int,ry:int,rw:int,rh:Int,c:Color)
		For Local y:=ry Until ry+rh
			For Local x:=rx until rx+rw
				SetPixel(x,y,c)
			Next
		next
	End
	method Ball(rx:Int,ry:int,r:Int,c:Color)
		For Local y:=-r To r
			For Local x:=-r To r
				Local dd:=x*x+y*y
				If dd<r*r
					SetPixel(rx+x,ry+y,c)
				endif
			Next
		next
	End
End


Class Tile
	Field pixmap:=New PixelMap(32,32)
	Field image:Image

	Method New()
		pixmap.Clear(Color.None)
		pixmap.Rect(4,4,24,24,Color.Blue)
		pixmap.Rect(6,6,20,20,Color.DarkGrey)
		pixmap.Ball(16,16,10,Color.Black)		
		For Local i:=5 to 27 Step 2
			pixmap.Rect(i,5,1,22,Color.White)
		next
		image=new Image(pixmap)
	end
end

Class GridWindow Extends Window
	Field framecount:Int	
	Field tile:Tile
	
	Method New()
		Super.New("Grid",800,480)
		ClearColor=Color.Black				
		tile=New Tile()
	End
	
	Method IsoView(c:Canvas, theta:Double, zoom:double)
		Local tx:=Cos(theta)*zoom
		Local ty:=Sin(theta)*zoom
		c.Matrix=new AffineMat3f(tx,ty*0.5,-ty,tx*0.5,400,240)		
	End
	
	Method OnRender( c:Canvas ) Override
		App.RequestRender()							
		
		Local zoom:=0.1*Mouse.Location.Y

		IsoView(c,0.001*framecount,zoom)

'		c.DrawText("Frame"+framecount,10,10 )	

		Local n:=40

		For Local y:=-n To n
			For Local x:=-n To n
				'c.Color=Color.DarkGrey
				'c.DrawRect(x*50,y*50,20,20)
				'c.Color=Color.Yellow
				'c.DrawRect(x*50+5,y*50+5,10,10)
				c.DrawImage(tile.image,x*24,y*24)
			Next
		Next
		
		
		framecount+=1		
	End
	
	Method OnKeyEvent( event:KeyEvent) Override
		If event.Type=EventType.KeyDown
			If event.Key=Key.Escape 
				App.Terminate()
				Print "Escape"
			endif
		endif
	end
End

Function Main()
	New AppInstance
	New GridWindow
	App.Run()
End
