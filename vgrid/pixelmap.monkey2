
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
		Local x0:=rx-r
		Local x1:=rx+r
		Local y0:=ry-r
		Local y1:=ry+r
		x0=Max(x0,0)
		y0=Max(y0,0)
		For Local y:=y0 To y1
			For Local x:=x0 To x1
				Local dd:=(x-rx)*(x-rx)+(y-ry)*(y-ry)
				If dd<r*r
					SetPixel(x,y,c)
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
		Next
		pixmap.PremultiplyAlpha()
		image=new Image(pixmap)
		image.Handle=New Vec2f( .5,.5 )
	End
End

Class Ball
	Field pixmap:=New PixelMap(128,128)
	Field image:Image
	Method New()
		pixmap.Clear(Color.None)
		pixmap.Ball(64,64,40,Color.Yellow)		
		pixmap.Ball(64,64,34,Color.Black)		
		pixmap.Ball(64,64,24,Color.Blue)		
		pixmap.Ball(42,42,8,Color.White)	
		image=new Image(pixmap,TextureFlags.Filter|TextureFlags.Mipmap)
		image.Handle=New Vec2f( .5,.5 )
	End
End
