' applet class 

' manage preferences by json in sdl generated prefpath
' remember window dimensions
' fullscreen toggle on F1
' long press on Escape to close

' todo:
' 

#Import "<std>"
#Import "<mojo>"
#Import "<sdl2>"
#Import <math>

Using std..
Using mojo..
Using sdl2..
Using math..

Extern 

Function SDL_GetPrefPath:Byte Ptr(org:CString,app:CString)

Public 

Global AppletName:="MyNewApplet"
Global AppletAuthor:="nitrologic"

Global prefsPath:=String.FromCString(SDL_GetPrefPath(AppletAuthor,AppletName))
Global prefsFile:=AppletName+".prefs.json"

Global DefaultWindowFlags:=WindowFlags.Resizable|WindowFlags.HighDPI

Function Main()
	New AppInstance	
	New Editor
	App.Run()
End

Alias Nanos:Long

Const NanosPerMilli:Long = 1000000

Class Editor Extends Applet
	Field background:Color=Color.Blue

	Method New()
	End
	
	Field time:Nanos
	
	Method Update(elapsed:Nanos)
		time+=elapsed
		Local period:=50/1e9
		Local s:=math.Sin(time*Period)

		background.b=New Color(0.5+0.44*s,0,0
	End
	
	Method KeyDown(key:Key) Override
	End

	Method KeyUp(key:Key) Override
	End

	Method Render( display:Canvas ) Override	
		display.Clear(background)
	End
End


Class Applet

	Field hasPrefs:Bool
	Field windowRect:Recti
	Field windowFullscreen:Bool		
	Field window:AppWindow
	Field defaults:JsonObject

	Method New()
		LoadPrefs()
		Local title:=AppletName
		If hasPrefs
			window=New AppWindow(Self, windowRect, windowFullscreen, title)
		Else
			window=New AppWindow(Self, title)
		Endif
	End

	Method KeyDown(key:Key) Virtual
	End

	Method KeyUp(key:Key) Virtual
	End
	
	Method Render( display:Canvas ) Virtual
	End

	Function TrueFalse:String(b:Bool)
		If b Return "true"
		Return "false"
	End
	
	Method DefaultNumber:Double(name:String)
		Return defaults?defaults.GetNumber(name) Else 0
	End

	Method LoadPrefs()	
		defaults=JsonObject.Load(prefsPath+prefsFile)

		Local prefs:=defaults

		If Not prefs
			Print "prefs not loaded from "+prefsPath			
			Local raw:=LoadString(prefsPath)
			Print "raw="+raw
			Return
		Endif

		If prefs.Contains("winRect")
			Local a:=prefs.GetArray("winRect")
			Local f:=prefs.GetBool("winFullscreen")
			Local x:=a.GetNumber(0)
			Local y:=a.GetNumber(1)
			Local w:=a.GetNumber(2)
			Local h:=a.GetNumber(3)
			If w<240 w=240
			If h<120 h=120
			windowRect=New Recti(x,y,x+w,y+h)
			windowFullscreen=f
			hasPrefs=True
			Print "prefs loaded r="+x+","+y+","+w+","+h+" f="+TrueFalse(f)
		Endif
		
	End

	Method OnFrame(window:Window)
		If window.Fullscreen
			windowFullscreen=True
		Else
			windowFullscreen=False
			windowRect=window.Frame
		Endif
	End

	Function JsonString:String(args:Stack<String>)
		Local s:String
		For Local i:=0 Until args.Length Step 2
			Local a:=args[i+0]
			Local b:=args[i+1]
			If i>0 s+=","
			s+="~q"+a+"~q:"+b
		Next
		Return "{"+s+"}"
	End

	Method OnClose()		
		Local winRect:="["+windowRect.X+","+windowRect.Y+","+windowRect.Width+","+windowRect.Height+"]"
		Local winFS:=windowFullscreen?"true"else"false"

		Local json:=New Stack<String>
		json.Add("winRect")
		json.Add(winRect)
		json.Add("winFullscreen")
		json.Add(winFS)
		
		' add app specific serialisation from prefs here

		If GetFileType(prefsPath)=FileType.None CreateDir(prefsPath)
		
		Local js:=JsonString(json)

		If Not SaveString(js, prefsPath+prefsFile)
			'Notify("Warning", "Unable to open "+path, False)
			Print "Unable to save prefs to "+prefsPath
			Return
		Endif
		Print "saved prefs as "+js+" in "+prefsPath
		App.Terminate()
	End


End


Class AppWindow Extends Window
	Field applet:Applet
	Field goFullscreen:Bool
	Field Millisecs:Int
			
	Method New(host:Applet, rect:Recti, fullscreen:bool, title:String)
		Super.New(title,rect, DefaultWindowFlags)		
		applet=host
		goFullscreen=fullscreen
		Create()
	End
	
	Method New(host:Applet, title:String)
		Super.New(title,800,600,DefaultWindowFlags)		
		applet=host
		Create()
	End
	
	Method Create()
		applet.OnFrame(Self)
	End

	Method OnRender( display:Canvas ) Override	
		If goFullscreen
			goFullscreen=False
			Fullscreen=True
			App.RequestRender()
			Return
		Endif
		Local millis:=App.millisecs-millisecs
		millisecs+=millis		
		applet.Update(millis*NanosPerMilli)
		applet.Render(display)
	End

	Method OnWindowEvent(event:WindowEvent) Override
		Select event.Type
			Case EventType.WindowClose
				applet.OnClose()
			Case EventType.WindowResized
				applet.OnFrame(Self)
			Case EventType.WindowMoved
				applet.OnFrame(Self)
		End
	End

	Field EscapeTime:Int
	
	Method EscapeDown()			
		EscapeTime=App.Millisecs
	End

	Method EscapeUp()			
		Local duration:=App.Millisecs-EscapeTime
		If duration>300
			applet.OnClose()
		Endif
	End

	Method OnKeyEvent( event:KeyEvent ) Override	
		Select event.Type
		Case EventType.KeyDown
			Select event.Key
			Case Key.F1
				Fullscreen = Not Fullscreen				
				applet.OnFrame(Self)
				App.RequestRender()
			Case Key.Escape
				EscapeDown()
			Default
				applet.KeyDown(event.Key)
			End
		Case EventType.KeyUp
			Select event.Key
			Case Key.Escape
				EscapeUp()
			Default
				applet.KeyUp(event.Key)
			End
		End
	End
End

