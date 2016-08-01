#Import "<std>"
#Import "<mojo>"	
#Import "<mojox>"

#import "gridspace.monkey2"

Using std..
Using mojo..
Using mojox..

Global title:String="VGrid 0.2"	
Global AboutApp:=title+" Isometric Volumetric Encounter" 
Global Controls:="Clear=C,,Grow=G,GrowX=X,GrowY=Y,GrowZ=Z,Smooth 1=Shift,Smooth 2=Control,,Zoom=MouseWheel,Rotate=Cursor Keys,,FullScreen=F1,Mesh=F5"
Global Contact:=",github.com/nitrologic/m2"
Global Credits:=",Transpiled by Monkey2 :)"

Global Transparent:=New Color(0,0,0,0)
Global SmokedGlass:=New Color(0,0,0,0.7)
Global Hot:=New Color(1,0.8,0.5,1)

'	new MainWindowInstance( "BigTed",New Recti( 0,0,800,600 ),WindowFlags.Resizable|WindowFlags.Center )

Global MainWindow:GridWindow

Class Document

	Field DirtyChanged:Void()

	Method New( path:String )
	
		_path=path
	End
	
	Property Path:String()

		Return _path
	End
	
	Property View:View()
	
		If Not _view _view=OnCreateView()
		
		Return _view
	End
	
	Property Dirty:Bool()
	
		Return _dirty
	
	Setter( dirty:Bool)

		If dirty=_dirty Return
		
		_dirty=dirty
		DirtyChanged()

		Local enamel:=New List<Cube>		
		For Local cube:=Eachin surface
			Local sx:=cube.x-org.x
			Local sy:=cube.y-org.y
			Local sz:=cube.z-org.z
			For local x:=-dx To dx
				For Local y:=-dy To dy
					For local z:=-dz To dz
						If (x|y|z)=0 Continue
						If smooth&1 And ((x&y&z)&1)=1 continue
						If smooth&2 And (x*y or x*z or y*z) continue
						If grid[sx+x,sy+y,sz+z]=Null And cube.Vacant(x,y,z)
							Local cube2:=root.Clone()
							cube2.x=cube.x+x							
							cube2.y=cube.y+y
							cube2.z=cube.z+z							
							Assert(sx+x=cube2.x-org.x)
							Assert(sy+y=cube2.y-org.y)
							Assert(sz+z=cube2.z-org.z)
							enamel.AddLast(cube2)
							grid[sx+x,sy+y,sz+z]=cube2
						Endif
					Next
				Next
			Next
		Next
		
		' second visit all neighbors (none must be inferred)
		
		For Local cube:=Eachin enamel
			AddCube(cube)
'			surface.AddLast(cube)
			Local sx:=cube.x-org.x
			Local sy:=cube.y-org.y
			Local sz:=cube.z-org.z
			For local x:=-1 To 1
				For Local y:=-1 To 1
					For Local z:=-1 To 1
						If (x|y|z)=0 Continue
						Local cube2:=grid[sx+x,sy+y,sz+z]								
						if cube2<>Null cube.Meet(cube2,x,y,z)
					Next
				Next
			Next
		Next
		
		CullSurface()
		BakeSort()
	End
		
End


Class IsoSkin
	Field atlas:Image
	Field pix:=New Pixmap(1024,1024)
	Field tx:Int
	Field ty:Int	
	Field lineheight:Int
	Field reservewidth:int
	field rects:=New Stack<Recti>
	Field balls:=new Stack<Image>
	
	Global Center:=New Vec2f( .5,.5 )

	Const D:=7
	
	Method DrawCube2(cube:Cube,display:Canvas,zx:Double,zy:Double,rz:Double)
		Assert(cube.rubit<>RubitMask)


		Local sx:Float=(cube.x-cube.z)+zy*cube.y*2
		Local sy:Float=(cube.x+cube.z)+zx*cube.y*2		

		Local x0:=sx*D
		Local y0:=sy*D
		Local x1:=x0+D
		Local y1:=y0+D
		Local x2:=x1+zy*D
		Local y2:=y1+zx*D
		Local x3:=x0+zy*D
		Local y3:=y0+zx*D

		display.Color=Color.White
		
'		display.DrawImage(tile,sx*D,sy*D,Pi/4,0.125,0.125)	'facing sky
		display.DrawQuad(x0,y0,x1,y1,x2,y2,x3,y3)

'		display.DrawImage(balls[cube.skin],sx*D,sy*D,rz,0.125,0.25)	'facing eye		


'		For Local i:=0 To 5
'			display.DrawImage(image,sx*D+i*zy,sy*D+i*zx,-Pi/4,0.125,0.125)	'facing sky
'		next
	end	

	Method Reserve(w:Int,h:Int)
		tx+=reservewidth
		reservewidth=w
		If tx+w>pix.Width
			tx=0
			ty+=lineheight
			lineheight=0
		Endif
		lineheight=Max(lineheight,h)		
		rects.Push(New Recti(tx,ty,tx+w,ty+h))
	End

	Method New()
		pix.Clear(Color.None)				
		Balls(New Color[](Color.Red,Color.Blue,Color.Green,Color.Yellow,Color.Cyan,Color.Magenta,Color.White,Color.Black))
		atlas=New Image(pix)
		For Local rect:=Eachin rects
			AddBall(rect)
		Next
	End
	
	Method Load:Bool()
	
		If Not OnLoad() Return False

		Dirty=False
		
		Return True
	End
	
	Method Save:Bool()
	
		If Not _dirty Return True
		
		If Not OnSave() Return False
		
		Dirty=False

		Return True
	End
	
	Method Rename( path:String )
	
		_path=path
		
		Dirty=True
	End
	
	Method Close()
	
		OnClose()
	end
	
	Method Balls(palette:Color[])
		For Local color:=Eachin palette
			Ball(color,Color.Black)
		Next
		For Local color:=Eachin palette
			Ball(color,Color.White)
		Next
	End
	
	Method Ball(primary:Color,ring:Color)		
		Reserve(128,128)
		Circle(64,64,40,Color.DarkGrey)		
		Circle(64,64,34,ring)		
		Circle(64,64,30,primary)		
		Circle(50,52,2,Color.White)	
	End

	method Circle(rx:int,ry:int,r:int,c:Color)
		Local x0:=rx-r
		Local x1:=rx+r
		Local y0:=ry-r
		Local y1:=ry+r
		x0=Max(x0,0)
		y0=Max(y0,0)
		For Local y:=y0 To y1
			For Local x:=x0 To x1
'				If blend And ((x+y)&1) Continue
				Local dd:=(x-rx)*(x-rx)+(y-ry)*(y-ry)
				If dd<r*r
					local sh:=0.5+0.25*Sin(float(y)/24)-0.25*Cos(float(x)/24)
					pix.SetPixel(x+tx,y+ty,c*new Color(sh,1))
				Endif
			Next
		Next
	End
	
	method Rect(rx:Int,ry:int,rw:int,rh:Int,c:Color)
		For Local y:=ry Until ry+rh
			For Local x:=rx until rx+rw
				pix.SetPixel(x+tx,y+ty,c)
			Next
		Next
	End
	
	Method DrawCube(cube:Cube,display:Canvas,zx:Double,zy:Double,rz:Double)
		Assert(cube.rubit<>RubitMask)
		Local sx:Float=(cube.x-cube.z)+zy*cube.y*2
		Local sy:Float=(cube.x+cube.z)+zx*cube.y*2		
'		display.DrawImage(tile,sx*D,sy*D,Pi/4,0.125,0.125)	'facing sky

		display.DrawImage(balls[cube.skin],sx*D,sy*D,rz,0.125,0.25)	'facing eye		

'		For Local i:=0 To 5
'			display.DrawImage(image,sx*D+i*zy,sy*D+i*zx,-Pi/4,0.125,0.125)	'facing sky
'		next
	end	
	
	Global verts:=new Float[65536*2]
	
	Method DrawMesh(mesh:IsoMesh,display:Canvas,t:Mat4<Float>)
		Local n:=mesh.vertCount
		For Local i:=0 Until n
			Local vert:=mesh.verts[i]
			Local sx:=vert.x * t.i.x + vert.y * t.j.x + vert.z * t.k.x + t.t.x
			Local sy:=vert.x * t.i.y + vert.y * t.j.y + vert.z * t.k.y + t.t.y
			verts[i*2+0]=sx
			verts[i*2+1]=sy
		Next	
		Local iptr:Int Ptr=mesh.tris.Data
		local vptr:Float Ptr=verts.Data
		display.DrawPrimitives(3,mesh.triCount,vptr,8,Null,0,iptr)
	End
	
	Protected

	Method OnLoad:Bool() Virtual
	
		Return False
	End
	
	Method OnSave:Bool() Virtual
	
		Return False
	End
	
	Method OnClose() Virtual
	End
	
	Method OnCreateView:View() Virtual
	
		Return Null
	End
	
	Private

	Field _dirty:Bool
	Field _path:String
	Field _view:View
	
End

Class GridWindow Extends Window
	Field gridspace:GridSpace
	Field status:String
	
	Field zoom:Float
	Field framecount:Int
	Field drawcount:Int
	Field mousecount:Int
	Field cx:Float
	Field cy:Float
	
	Field rot:Double
	Field rotSpeed:Double
	
	Field radius:Float
		
	Method New(title:String)
		Super.New(title,1024,800,WindowFlags.Resizable)		

		MainWindow=Self
		
		Theme.Load("vgrid.theme.json")

'		ClearColor=Color.Black
		zoom=.5
		radius=2.5			
		Local style:=new IsoSkin()
		gridspace=New GridSpace(style)

		ClearColor=Theme.ClearColor	
		SwapInterval=1
		
'		InitPaths()
'		InitActions()
'		InitMenus()

		InitViews()
		AddChild( _docker )
		
'		LoadState()		
'		DeleteTmps()		
'		UpdateRecentFilesMenu()
'		UpdateCloseProjectMenu()
		
		App.Idle+=AppIdle

		Update()
		
		_console.Document.ReplaceText(1024,1024,"VGrid 0.1~n]")
'		_console.MoveLine(2)
		_console.MakeKeyView()
	End

	Field _docker:DockingView
	Field _console:TextView
	Field _docTabber:TabView

	Field _currentDoc:Document
	Field _openDocs:=New Stack<Document>

	Method UpdateKeyView()
	
		If Not _currentDoc Return
		
		_currentDoc.View.MakeKeyView()
	End
	
	Method MakeCurrent( doc:Document )
	
		If doc=_currentDoc Return
		
		If doc And _docTabber.CurrentView<>doc.View
			_docTabber.CurrentView=doc.View
		Endif
		
		_currentDoc=doc
'		_currentTextView=Null
'		If doc _currentTextView=Cast<TextView>( doc.View )
				
		App.Idle+=Lambda()
			If _currentDoc
				Title="VGrid - "+_currentDoc.Path
			Else
				Title="VGrid"
			Endif
		End

		UpdateKeyView()
		
		Update()
	End

	Method FindDocument:Document( path:String )
		For Local doc:=Eachin _openDocs
			If doc.Path=path Return doc
		Next
		Return Null
	End	

	Method FindDocument:Document( view:View )
		For Local doc:=Eachin _openDocs
			If doc.View=view Return doc
		Next
		Return Null
	End	

	Method InitViews()
		_console=New TextView	
		_docTabber=New TabView
		_docTabber.CurrentChanged=Lambda()
			MakeCurrent( FindDocument( _docTabber.CurrentView ) )
		End		
		_docker=New DockingView
		_docker.ContentView=_docTabber
		_docker.AddView( _console,"bottom",200 )
	end
		
	Method AppIdle()	
'		UpdateActions()		
		App.RequestRender()
		App.Idle+=AppIdle
		GCCollect()	'thrash that GC!
	End
			
	Method DrawStats(display:Canvas)
		Local cy:=10
		
		display.Color=SmokedGlass
		display.DrawRect(0,0,200,Height)
		display.Color=Color.Grey
		
		Local content:=AboutApp
		content+=",,"+Controls
		
		Local grid:=gridspace.grid

		content+=",,Surface="+grid.surface.Count()
		content+=",Volume="+grid.volume

		content+=",CubeCounter="+Cube.CubeCounter

		content+=",Quadrant="+gridspace.DrawQuadrant

		content+=","+Contact+","+Credits
		
		For Local line:=Eachin content.Split(",")				
			Local cx:=10
			For Local tab:=Eachin line.Split("=")
				tab=tab.Replace(":)",":=")
				display.DrawText(tab,cx,cy)
				cx+=100
			Next
			cy+=16
		Next
	End
	
	Method OnRender2( display:Canvas )' Override	
		App.RequestRender()						
		rot+=rotSpeed*rotSpeed*rotSpeed							
		If rot<0
			rot=Pi*2-((-rot) Mod (Pi*2))
		Else		
			rot=rot Mod (Pi*2)
		Endif		
		
		gridspace.DrawGrid(display,Width,Height,rot,zoom)

		DrawStats(display)		
	End

	Method Hold()
		rotSpeed=0
		rot=0
	End
		
	Method OnKeyEvent( event:KeyEvent ) Override	
		Local smooth:=0
		If event.Modifiers&Modifier.Shift smooth|=1
		If event.Modifiers&Modifier.Control smooth|=2
		
		Local grid:=gridspace.grid
		
		Select event.Type
		Case EventType.KeyDown
			Select event.Key			
			
			Case Key.Key1
				grid.root.skin=0
			Case Key.Key2
				grid.root.skin=2
			Case Key.Key3
				grid.root.skin=4
			Case Key.Key4
				grid.root.skin=6
			Case Key.Key5
				grid.root.skin=8
			Case Key.Key6
				grid.root.skin=10
			Case Key.Key7
				grid.root.skin=12
			Case Key.Key8
				grid.root.skin=14
			Case Key.Key9
				grid.root.skin=16				
			Case Key.C
				gridspace.Clear()
			Case Key.G
				gridspace.Generate(True,True,True,smooth)
			Case Key.X
				gridspace.Generate(True,False,False,smooth)
			Case Key.Y
				gridspace.Generate(False,True,False,smooth)
			Case Key.Z
				gridspace.Generate(false,false,True,smooth)
			Case Key.Escape
				App.Terminate()
			Case Key.F1
				Fullscreen = Not Fullscreen
			Case Key.F5
				gridspace.Mesh()
			Case Key.Space
				Hold()
			Case Key.Left
				rotSpeed+=1.0/16			
			Case Key.Right
				rotSpeed-=1.0/16
			Case Key.Down
				radius*=0.8			
			Case Key.Up
				radius*=1.2			
			End
		End
	End
								
	Method OnMouseEvent(event:MouseEvent ) Override	
		Select event.Type		
			Case EventType.MouseWheel
				local w:=event.Wheel.Y
				zoom-=w/8.0
				If zoom<1.0/8 zoom=1.0/8				
		End
	End	
End

Function Main()
	Print title
	New AppInstance	
	New GridWindow(title)
	App.Run()	
End
