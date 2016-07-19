
Namespace myapp

#Import "<std>"
#Import "<mojo>"

Using std..
Using mojo..

Alias S:Double
Global One:S=1.0

Struct Sat5
	Field R:S
	Field G:S
	Field B:S
	Field A:S
	Field T:S
	Field n:Int
		
	method Mix(s:Sat5)
		R+=s.R
		G+=s.G
		B+=s.B
		A+=s.A		
		T+=s.T
		n+=1
	end

	Method ARGB:Int()
		If n=0 Return 0'$ffff00ff
		
		Local r:=0.2/n
'		If n<16 r*=n/16

		Local r8:Int=255*R*r
		Local g8:Int=255*G*r
		Local b8:Int=255*B*r
		Local a8:int=255*A*r
		
		Return (a8 Shl 24)|(b8 Shl 16)|(g8 Shl 8)|r8
	End
End

Class Scope
	Field dimension:Int
	Field size:int
	Field buffer:Sat5[]
	Field pixmap:Pixmap
	Field image:Image
	Field brush:Sat5

	Method New(dim:Int)
		dimension=dim
		size=dim*dim
		buffer=New Sat5[dim*dim]	
		pixmap=New Pixmap(dim,dim)
		brush.R=0.3
		brush.G=0.8
		brush.B=0.4
		brush.A=0.6
		brush.T=One/2
	End
		
	Method Draw(x:Int,y:Int)
		Local i:=y*dimension+x
		If i>0 And i<size buffer[i].Mix(brush)
	End
		
	Method GetImage:Image()
		Bake()
		image=New Image(pixmap)
		Return image
	End
	
	Method Bake()
		Local p:=Cast<Int Ptr>(pixmap.PixelPtr(0,0))
		For Local i:=0 Until size
			p[i]=buffer[i].ARGB()
		Next
	end

'	Method process:Long(a:Long,b:4)
	
End

Class MyWindow Extends Window

	Field framecount:=0
	Field scope:=New Scope(256)	
	Field cx:Double
	Field t:Double
	
	Method New()
		ClearColor=Color.Black
	End

	Method OnRender( canvas:Canvas ) Override
	
		App.RequestRender()

		Local status:="vscope0.1 framecount="+framecount+" fps="+App.FPS+" ms="+App.Millisecs
	
		canvas.DrawText( status,0,Height,0,1 )
		
		For Local i:=0 Until 1000
			Local cy:=128+100*Sin(t)
			t+=0.001					
			cx+=0.32
			scope.Draw(cx,cy)
		Next
		
'		scope.Draw(Mouse.X,Mouse.Y-10)
		
		canvas.DrawImage(scope.GetImage(),10,10)
		canvas.DrawImage(scope.GetImage(),10+256,10)
		
		framecount+=1
	
	End
	
	Method OnMouseEvent(event:MouseEvent) Override
	End
	
	Method OnKeyEvent(event:KeyEvent) Override
		Select event.Type
			Case EventType.KeyDown
				Select event.Key
					Case Key.Escape
						App.Terminate()
				End
		end
	end
	
End

Function Main()

	New AppInstance
	
	New MyWindow
	
	App.Run()
End
