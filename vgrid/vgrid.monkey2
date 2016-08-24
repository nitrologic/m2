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

Class GridView Extends DockingView

'	Field palette:=New PaletteView
	Field treeTabs:=New TabView	'( TabViewFlags.DraggableTabs )

	Field gridspace:GridSpace

	Field zoom:Float
	Field radius:Float
	Field rot:Double
	Field rotSpeed:Double

	Method New()
		zoom=.5
		radius=2.5			
		Local style:=new IsoSkin()
		gridspace=New GridSpace(style)
		Activated=Lambda()
			MakeKeyView()
		End
		
		treeTabs.Gravity.X=1
		
'		treeTabs.AddTab("Add",palette)

		AddView( treeTabs,"right",250,True )

'		ContentView=_docsTabView

	End
	
	Method OnRender(canvas:Canvas) Override
		canvas.Clear(Color.Blue)
		rot+=rotSpeed*rotSpeed*rotSpeed							
		If rot<0
			rot=Pi*2-((-rot) Mod (Pi*2))
		Else		
			rot=rot Mod (Pi*2)
		Endif		
		
		gridspace.DrawGrid(canvas,Width,Height,rot,zoom)

'		DrawStats(canvas)		

		RequestRender()
		
		Super.OnRender(canvas)
	end

	Method OnMouseEvent( event:MouseEvent ) Override	
		Select event.Type
		Case EventType.MouseDown
			MakeKeyView()
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
	
	Method Hold()
		rotSpeed=0
		rot=0
	End

end

Class GridWindow Extends Window
	Field status:String
	Field framecount:Int
	Field drawcount:Int
	Field mousecount:Int
	Field cx:Float
	Field cy:Float
			
	Method New(title:String)
		Super.New(title,1024,800,WindowFlags.Resizable)		
		MainWindow=Self
		Local style:=new IsoSkin()
		SwapInterval=1		
		InitViews()
		App.Idle+=AppIdle
	End

	Method AppIdle()	
'		UpdateActions()		
		App.RequestRender()
		App.Idle+=AppIdle
		GCCollect()	'thrash that GC!
	End

	Field _menuBar:MenuBar
	Field _dock:DockingView
	Field _console:TextView
	Field _tabs:TabView

	Method NewDocument()
		Local g:=New GridView()
		_tabs.AddTab("Untitled",g)
		_tabs.CurrentIndex=_tabs.TabIndex(g)
		g.MakeKeyView()
	end

	Method CloseDocument()
		If _tabs.NumTabs=0
			App.Terminate()
		Else
			Local i:=_tabs.CurrentIndex
			_tabs.RemoveTab(_tabs.CurrentIndex)
			If i>=_tabs.NumTabs i-=1
			If i>=0 _tabs.CurrentIndex=i
		Endif
	End
		
	Method NextDocument()
		Local i:=_tabs.CurrentIndex+1
		If i>=_tabs.NumTabs i=0
		_tabs.CurrentIndex=i
	End
	
	Method PrevDocument()
		Local i:=_tabs.CurrentIndex-1
		If i<0 i=_tabs.NumTabs-1
		_tabs.CurrentIndex=i
	End

	Method InitViews()
		InitMenuBar()
		_console=New TextView	
		_tabs=New TabView( TabViewFlags.ClosableTabs|TabViewFlags.DraggableTabs )		
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
					
	Method DrawStats(display:Canvas,gridspace:GridSpace)
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
		
	Field newFile:Action
	Field closeFile:Action
	Field nextFile:Action
	Field prevFile:Action
									
	Method InitMenuBar()
	
		newFile=New Action("New")
		newFile.HotKey=Key.F3
		newFile.Triggered=Lambda()
			NewDocument()
		End
	
		closeFile=New Action("Close")
		closeFile.HotKey=Key.W
		closeFile.HotKeyModifiers=Modifier.Gui
		closeFile.Triggered=Lambda()
			CloseDocument()
		End
		
		nextFile=New Action("Next")
		nextFile.HotKey=Key.Tab
		nextFile.HotKeyModifiers=Modifier.Control	
		nextFile.Triggered=Lambda()
			NextDocument()
		End

		prevFile=New Action("Previous")
		prevFile.HotKey=Key.Tab
		prevFile.HotKeyModifiers=Modifier.Control|Modifier.Shift
		prevFile.Triggered=Lambda()
			PrevDocument()
		End

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

		fileMenu.AddAction( closeFile )
				
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
	
	Method OnKeyEvent( event:KeyEvent ) Override	
		Select event.Type
		Case EventType.KeyDown
			Select event.Key			
			Case Key.F1
				Fullscreen = Not Fullscreen
			End
		End
	End
	
End

Function Main()
	Print title
	New AppInstance	
	New GridWindow(title)
	App.Run()	
End
