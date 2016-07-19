
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
		
	method Mix(s:Sat5)
		R+=s.R
		G+=s.G
		B+=s.B
		A+=s.A		
		T+=s.T
	end

	Method ARGB:Int()
		If T=0 Return $ffff00ff
		Local r8:Int=255*R/T
		Local g8:Int=255*G/T
		Local b8:Int=255*B/T
		Local a8:int=255*A/T
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
		brush.A=1.0
		brush.R=1.0
		brush.G=1.0
		brush.B=1.0
		brush.T=One/1024		
	End
		
	Method Draw(x:Int,y:Int)
		Local i:=y*dimension+x
		If i>0 And i<size buffer[i].Mix(brush)
	end
	
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
	Field cx:Int
	Field t:Double
	
	Method New()
	End

	Method OnRender( canvas:Canvas ) Override
	
		App.RequestRender()

		Local status:="vscope0.1 framecount="+framecount+" fps="+App.FPS+" ms="+App.Millisecs
	
		canvas.DrawText( status,0,Height,0,1 )
		
		For Local i:=0 Until 100
			Local cy:=128+100*Sin(t)
			t+=0.0001					
			scope.Draw(cx,cy)
		Next
		cx+=1
		
'		scope.Draw(Mouse.X,Mouse.Y-10)
		
		canvas.DrawImage(scope.GetImage(),10,10)
		
		framecount+=1
	
	End
	
	Method OnMouseEvent(event:MouseEvent) Override
	end
	
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
