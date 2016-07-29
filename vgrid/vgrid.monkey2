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
