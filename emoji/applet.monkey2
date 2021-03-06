' applet framework for monkey2 by simon

#Import "<std>"
#Import "<mojo>"
#Import "<sdl2>"

Using std..
Using mojo..
Using sdl2..

Extern 

Function SDL_GetPrefPath:Byte Ptr(org:CString,app:CString)

Public 


Global prefsPath:=std.filesystem.AppDir()
Global homePath:=String.FromCString(SDL_GetPrefPath(AppletAuthor,AppletName))

'Global prefsPath:=String.FromCString(SDL_GetPrefPath(AppletAuthor,AppletName))
Global prefsFile:=AppletName+".prefs.json"

Global DefaultWindowFlags:=WindowFlags.Resizable|WindowFlags.HighDPI


Class Applet

	Field hasPrefs:Bool
	Field windowRect:Recti
	Field windowFullscreen:Bool		
	Field window:AppWindow
	Field defaults:JsonObject
	
	Method Init()
		LoadPrefs()
		Local title:=AppletName
		If hasPrefs
			window=New AppWindow(Self, windowRect, windowFullscreen, title)
		Else
			window=New AppWindow(Self, title)
		Endif
	End

	Method KeyDown(key:Key)
	End

	Method KeyUp(key:Key)		
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

	Method OnFrame(window:Window)
		If window.Fullscreen
			windowFullscreen=True
		Else
			windowFullscreen=False
			windowRect=window.Frame
		Endif
	End

	Method OnCreate() Abstract

	Method OnRender(canvas:Canvas) Virtual
	End

	Method OnClose() Virtual 
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
		
		std.filesystem.CreateDir(prefsPath,True)
		If Not SaveString(js, prefsPath+prefsFile)
			'Notify("Warning", "Unable to open "+path, False)
			Print "Unable to save prefs to "+prefsPath+prefsFile
			Print "js:"+js
		Else
			Print "saved prefs as "+js+" in "+prefsPath
		Endif
		App.Terminate()
	End


End


Class AppWindow Extends Window
	Field applet:Applet
	Field goFullscreen:Bool
			
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
		applet.OnCreate()
		applet.OnFrame(Self)
	End

	Method OnRender( display:Canvas ) Override	
		If goFullscreen
			goFullscreen=False
			Fullscreen=True
		Endif
		RequestRender()
		applet.OnRender(display)
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
