#Import "<std>"
#Import "<mojo>"

Using std..
Using mojo..

Global instance:AppInstance


Class VPane Extends Image
	Field canvas:Canvas

	Method New(w:Int,h:Int)		
		Super.New(w,h,TextureFlags.Dynamic)		
		canvas=New Canvas(Self)				
	End
	
	Method Draw(display:Canvas)
		canvas.Flush()
		display.DrawImage( Self, 0,0)
	End

	Method FatLine(x:Int,y:Int,x1:Int,y1:Int)
		Local fat:Int=3

		If Not canvas Return
		
		Local verts:=New Float[8]
		
		Local dy:Int=y1-y
		Local dx:Int=x1-x
				
		Local len:Float=Sqrt(dx*dx+dy*dy) 
		Local q:Float=fat/len
				
		verts[0]=x+dy*q
		verts[1]=y-dx*q
		
		verts[2]=x1+dy*q
		verts[3]=y1-dx*q

		verts[4]=x1-dy*q
		verts[5]=y1+dx*q

		verts[6]=x-dy*q
		verts[7]=y+dx*q
		
		canvas.DrawPoly(verts)
	End
	
End

Class VPaint Extends Window

	Field pane:VPane
		
'	Field image1:Image
'	Field canvas1:Canvas
	Field ink:Color

	Field mousex:Int
	Field mousey:Int
	Field framecount:Int

	Method New(title:String)
		Super.New(title,800,600)		
		
		pane=New VPane(2048,2048)
'		image=New Image(2048,2048,TextureFlags.Dynamic)		
'		canvas1=New Canvas(image)
'		canvas1.Clear(New Color(.5,.4,.2))
'		canvas1.Alpha=0.5
'		ClearColor=Color.Black		
		ink=New Color
	End
		
	Method OnRender( display:Canvas ) Override	
		App.RequestRender()
		
		If framecount=0
		Endif
		
		pane.Draw(display)
		
		framecount+=1
				
		ink.r=(framecount&255)/255.0
		ink.g=(framecount&1023)/1023.0
		ink.b=(framecount&511)/511.0
		

		pane.canvas.Color=ink
	End

	Method OnKeyEvent( event:KeyEvent ) Override	
		Select event.Type
		Case EventType.KeyDown
			Select event.Key
			Case Key.Escape
				instance.Terminate()
			Case Key.F1
				Fullscreen = Not Fullscreen
			End
		End
		
	End
			
	Method OnMouseEvent(event:MouseEvent ) Override
		Local mx:Int
		Local my:Int
		mx=event.Location.X
		my=event.Location.Y
		
		pane.FatLine(mousex,mousey,mx,my)		
'		Print "OnMouseEvent mx="+mx+" my="+my		
		mousex=mx
		mousey=my
	End

	
End

Global title:String="VPaint 0.0"	

Function Main()
	Print title
	instance = New AppInstance	
	New VPaint(title)
	App.Run()	
End

'Method DrawIndexedPrimitives : Void ( order:Int, count:Int, vertices:Float[], texcoords:Float[], indices:Int[], material:Material=Null )
