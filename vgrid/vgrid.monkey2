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
		zx=ty
		zy=tx
		c.Matrix=new AffineMat3f(tx,ty*0.5,-ty,tx*0.5,400,240)		
	End
	
	Field zx:Double
	Field zy:Double
	
	Global Order4:=New Int[](
		1,0,0,1, 
		0,1,-1,0,
		-1,0,0,-1,
		0,-1,1,0)
	
	Method OnRender( c:Canvas ) Override
		App.RequestRender()							
		
		Local zoom:=0.1*Mouse.Location.Y

		Local theta:=0.03*framecount
		
		IsoView(c,theta,zoom)

' calulate draw order so we scan grid from far to near

		Local quadrant:Int=Int(2*theta/Pi)&3		
		local ix:=Order4[quadrant*4+0]
		local jx:=Order4[quadrant*4+1]
		local iy:=Order4[quadrant*4+2]
		local jy:=Order4[quadrant*4+3]

		Local n:=20		
		For Local i:=-n To n
			For Local j:=-n To n
				Local x:=i*ix+j*jx
				Local y:=i*iy+j*jy
				For Local z:=12 To 0 Step -3					
					c.DrawImage(tile.image,x*34+z*zx,y*34+z*zy)
'					c.DrawImage(tile.image,x*24,y*24,theta)
				next
			Next
		next
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
