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

Class GridView Extends View

	Method OnRender(canvas:Canvas) Override
		canvas.Clear(Color.Blue)
	end
End

#rem
	Field _path:String
	Field _view:View
	Field _dirty:Bool

	Field DirtyChanged:Void()

	Method New( path:String )
	
		_path=path
	End
	
	Property Path:String()

		Return _path
	End
	
	Property View:View()
	
'		If Not _view _view=OnCreateView()
		
		Return _view
	End
#End


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
		
'		Theme.Load("vgrid.theme.json")

'		ClearColor=Color.Black
		zoom=.5
		radius=2.5			
		Local style:=new IsoSkin()
		gridspace=New GridSpace(style)

'		ClearColor=Theme.ClearColor	
		SwapInterval=1
		
'		InitPaths()
'		InitActions()
'		InitMenus()

		InitViews()
'		AddChild( _docker )
		
'		LoadState()		
'		DeleteTmps()		
'		UpdateRecentFilesMenu()
'		UpdateCloseProjectMenu()
		
		App.Idle+=AppIdle

'		Update()
		
'		_console.Document.ReplaceText(1024,1024,"VGrid 0.1~n]")
'		_console.MoveLine(2)
'		_console.MakeKeyView()
	End

	Field _menuBar:MenuBar
	Field _dock:DockingView
	Field _console:TextView
	Field _tabs:TabView

'	Field _currentDoc:Document
'	Field _openDocs:=New Stack<Document>


	Method NewDocument()
'		_currentDoc=New Document
		_tabs.AddTab("Untitled",New GridView())
	end

#rem

	Method UpdateKeyView()
	
		If Not _currentDoc Return
		
		_currentDoc.View.MakeKeyView()
	End
	
	Method MakeCurrent( doc:Document )
	
		If doc=_currentDoc Return
		
		If doc And _tabs.CurrentView<>doc.View
			_tabs.CurrentView=doc.View
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
		
'		Update()
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
#end

	Method InitViews()
		InitMenuBar()
		_console=New TextView	

		_tabs=New TabView( TabViewFlags.ClosableTabs|TabViewFlags.DraggableTabs )
		
'		_tabs.CurrentChanged=Lambda()
'			MakeCurrent( FindDocument( _docTabber.CurrentView ) )
'		End		

		_tabs.RightClicked=Lambda()
		
			Local menu:=New Menu
			menu.AddAction( "Action 1" )
			menu.AddAction( "Action 2" )
			menu.AddAction( "Action 3" )
			
			menu.Open()
		End
		
		_tabs.CloseClicked=Lambda( index:Int )
'		_tabs.RemoveTab( index )
'		If tabView.CurrentView Or Not tabView.Count Return
'		If index=tabView.Count index-=1
'		tabView.CurrentIndex=index
		End
		_dock=New DockingView
		_dock.ContentView=_tabs
		_dock.AddView( _console,"bottom",200 )
		_dock.AddView( _menuBar,"top" )
		ContentView=_dock
	End
		
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
	
	Field newFile:=New Action("New").Triggered=Lambda()
		NewDocument()
	End

								
	Method InitMenuBar()
		Local fileMenu:=New Menu( "File" )
		
		fileMenu.AddAction( newFile )

		Local recentFiles:=New Menu( "Recent Files..." )
		recentFiles.AddAction( "File1" )
		recentFiles.AddAction( "File2" )
		recentFiles.AddAction( "File3" )
		recentFiles.AddAction( "File4" )
		recentFiles.AddAction( "File5" )
		
		fileMenu.AddAction( "Open" ).Triggered=Lambda()
			Alert( "Open Selected..." )
		End
		
		fileMenu.AddSubMenu( recentFiles )
		
		fileMenu.AddAction( "Save" ).Triggered=Lambda()
			Alert( "Save Selected..." )
		End
		
		fileMenu.AddSeparator()

		fileMenu.AddAction( "Close" ).Triggered=Lambda()
			Alert( "Close Selected..." )
		End
		
		fileMenu.AddAction( "Quit" ).Triggered=Lambda()
			App.Terminate()
		End
		
		Local editMenu:=New Menu( "Edit" )

		editMenu.AddAction( "Cut" ).Triggered=Lambda()
			Alert( "Cut Selected..." )
		End
		
		editMenu.AddAction( "Copy" ).Triggered=Lambda()
			Alert( "Copy Selected..." )
		End
		
		editMenu.AddAction( "Paste" ).Triggered=Lambda()
			Alert( "Paste Selected..." )
		End

		_menuBar=New MenuBar
		
		_menuBar.AddMenu( fileMenu )
		_menuBar.AddMenu( editMenu )
	End
	
	Method OnMouseEvent( event:MouseEvent ) Override	
		Select event.Type
		Case EventType.MouseUp
			Select event.Button
			Case MouseButton.Right			
				Local menu:=New Menu
				menu.AddAction( "Action 1" )
				menu.AddAction( "Action 2" )
				menu.AddAction( "Action 3" )				
				menu.Open( event.Location,event.View )				
				event.Eat()
			end
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
