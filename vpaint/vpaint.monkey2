#Import "<std>"
#Import "<mojo>"
#Import "<portmidi>"

#Import "assets/thrust.wav"
#Import "assets/engine1.wav"
#Import "assets/bang.wav"
#Import "assets/whale52hz.wav"

Using std..
Using mojo..
Using portmidi..

Global title:String="VPaint 0.3"	

Global AboutApp:="VPaint Control,,Cursor Left=-RPM,Cursor Right=+RPM,,Mouse Button=Lift Pen,Mouse Wheel=Zoom,Space Key=Hold,S Key=Smile Box,C Key=Clear,Cursor Up=+Pen Size,Cursor Down=-Pen Size,Hold,F1=Toggle Fullscreen,Click To Start"
Global Contact:=",,Latest Source: github.com/nitrologic/m2/tree/master/vpaint"
Global Credits:=",,Transpiled by Monkey2 the primate language of champions."

Global instance:AppInstance

Class VPane Extends Image
	Field canvas:Canvas
	Field pixmap:Pixmap

	Method New(w:Int,h:Int,bg:Color)		
		Super.New(w,h,TextureFlags.Dynamic|TextureFlags.Filter|TextureFlags.Mipmap)		
		canvas=New Canvas(Self)	
		canvas.Clear(bg)
		canvas.Alpha=0.8
		canvas.Translate(w/2,h/2)
		Handle=New Vec2f(0.5,0.5)		
	End
	
	Method Draw(display:Canvas)	
		canvas.Flush()
		display.DrawImage(Self,0,0)
	End
	
	Method Clear(bg:Color)
		canvas.Clear(bg)
	End
	
	Field segcount:Int
	Field edge0:Vec2f
	Field edge1:Vec2f
	
	Method EndSegment()
		segcount=0
	End

	Method FatSegment(x:Float,y:Float,x1:Float,y1:Float,fat:Float)

		If Not canvas Return
				
		Local verts:=New Float[8]
		
		Local dy:Float=y1-y
		Local dx:Float=x1-x
				
		Local len:Float=Sqrt(dx*dx+dy*dy) 
		Local q:Float=fat/len
				
		If segcount=0
			edge0=New Vec2f(x+dy*q,y-dx*q)
			edge1=New Vec2f(x-dy*q,y+dx*q)
		Endif
		segcount+=1
				
		Local v0:=edge0
		Local v1:=New Vec2f(x1+dy*q,y1-dx*q)
		Local v2:=New Vec2f(x1-dy*q,y1+dx*q)
		Local v3:=edge1
				
		canvas.DrawTriangle(v0,v1,v2)
		canvas.DrawTriangle(v0,v2,v3)
				
		edge0=v1
		edge1=v2
	End
	
	Function Curve:Float[](seg:Int,p0:Vec2f,p1:Vec2f,p2:Vec2f,p3:Vec2f)
		Local verts:=New Float[(seg+1)*2]		
		For Local i:Int=0 To seg		
			Local mu:Float=i*1.0/seg			    
        	Local x:Float=CatmullInterpolate(p0.x,p1.x,p2.x,p3.x,mu)
	       	Local y:Float=CatmullInterpolate(p0.y,p1.y,p2.y,p3.y,mu)
          	verts[i*2+0]=x
        	verts[i*2+1]=y
		Next		
		Return verts
	End
	
	Method OpenCurve(p0:Vec2f,p1:Vec2f,p2:Vec2f,p3:Vec2f,fat:Float)
		If Not canvas Return
		Local seg:Int=9
		Local verts:=Curve(seg,p0,p1,p2,p3)
		For Local i:Int=0 Until seg		
			FatSegment(verts[i*2+0],verts[i*2+1],verts[i*2+2],verts[i*2+3],fat)
		Next
	End
		
	Method ClosedCurve(p0:Vec2f,p1:Vec2f,p2:Vec2f,p3:Vec2f,fat:Float)
		If Not canvas Return
		OpenCurve(p3,p0,p1,p2,fat)
		OpenCurve(p0,p1,p2,p3,fat)
		OpenCurve(p1,p2,p3,p0,fat)
		OpenCurve(p2,p3,p0,p1,fat)
		EndSegment()
	End

 	Function CubicInterpolate:Float(y0:Float,y1:Float,y2:Float,y3:Float,mu:Float)
		Local a0:Float,a1:Float,a2:Float,a3:Float,mu2:Float
		mu2 = mu*mu
		a0 = y3 - y2 - y0 + y1
		a1 = y0 - y1 - a0
		a2 = y2 - y0
		a3 = y1
		Return(a0*mu*mu2+a1*mu2+a2*mu+a3)
	End
		
 	Function CatmullInterpolate:Float(y0:Float,y1:Float,y2:Float,y3:Float,mu:Float)
		Local a0:Float,a1:Float,a2:Float,a3:Float,mu2:Float	
		mu2 = mu*mu
		a0 = -0.5*y0 + 1.5*y1 - 1.5*y2 + 0.5*y3
		a1 = y0 - 2.5*y1 + 2*y2 - 0.5*y3
		a2 = -0.5*y0 + 0.5*y2
		a3 = y1
		Return(a0*mu*mu2+a1*mu2+a2*mu+a3)
	End
 	 	
 	Function CubicInterpolate2:Float(p0:Float,p1:Float,p2:Float,p3:Float,x:Float)
		Return p1 + 0.5 * x*(p2-p0+x*(2.0*p0-5.0*p1+4.0*p2-p3+x*(3.0*(p1-p2)+p3-p0)))
	End

	Method StraightLine(x:Int,y:Int,x1:Int,y1:Int,fat:Float)
		If Not canvas Return				
		Local dy:Int=y1-y
		Local dx:Int=x1-x				
		Local len:Float=Sqrt(dx*dx+dy*dy) 
		Local q:Float=fat/len				
		Local v0:=New Vec2f(x+dy*q,y-dx*q)
		Local v1:=New Vec2f(x1+dy*q,y1-dx*q)
		Local v2:=New Vec2f(x1-dy*q,y1+dx*q)
		Local v3:=New Vec2f(x-dy*q,y+dx*q)				
		canvas.DrawTriangle(v0,v1,v2)
		canvas.DrawTriangle(v0,v2,v3)
	End


	Method Smile(x:Float,y:Float,r:Float)
		Local v0:=New Vec2f(x-100,y+100)
		Local v1:=New Vec2f(x-100,y-20)
		Local v2:=New Vec2f(x+100,y-20)
		Local v3:=New Vec2f(x+100,y+100)
		EndSegment()
		OpenCurve(v0,v1,v2,v3,r)
		EndSegment()
	End
		
	Method Circle(x:Float,y:Float,r:Float)
		Local v0:=New Vec2f(x-100,y-100)
		Local v1:=New Vec2f(x+100,y-100)
		Local v2:=New Vec2f(x+100,y+100)
		Local v3:=New Vec2f(x-100,y+100)
		EndSegment()
		ClosedCurve(v0,v1,v2,v3,r)
	End
  
End

Class VBrowse
End

Enum AppState
	Title
	Draw
	Browse
End

Enum Tool
	Line
	Curve
End

Const TickMark:String=String.FromChar(65)	'(0xE2 0x9C 0x93)

Class VToolbar Extends Window
	Method New(title:String)
		Super.New(title,480,34,WindowFlags.Resizable)		
	End
End

Class VPaint Extends Window
	Field appState:AppState

'	Field tool:VToolbar
	Field pane:VPane
	Field browse:VBrowse
	Field status:String
	
	Field zoom:Float
	Field ink:Color
	Field mousex:Int
	Field mousey:Int
	Field mousew:Int
	Field framecount:Int
	Field drawcount:Int
	Field mousecount:Int
	Field cx:Float
	Field cy:Float
	Field rot:Float
	Field rotSpeed:Float
	Field radius:Float
	Field tool:=Tool.Curve

	Field panx:Float
	Field pany:Float
	Field panxSpeed:Float
	Field panySpeed:Float

	Field sample:Sound
	Field wheel:Channel
	
	Method ToggleTwo()	
	End
	
	Global Transparent:=New Color(0,0,0,0)
	
	Method New(title:String)
		Super.New(title,720,560,WindowFlags.Resizable)		
		zoom=2
		pane=New VPane(2048,2048,Transparent)
'		pane=New VPane(4096,4096,Transparent)
		browse=New VBrowse()
		ink=New Color
		radius=2.5
'		tool=New VTool("Tools")
'		tool.Title="VPaint Pen : RGBCycle"
		
'		sample=Sound.Load("asset::bang.wav")
'		sample=Sound.Load("asset::whale52hz.wav")
		sample=Sound.Load("asset::whale52hz.wav")
'		sample=Sound.Load("asset::thrust.wav")

		If sample
			wheel=sample.Play(-1)
			wheel.Rate=5
		Else
			Print "Sample not found"
		Endif
		
'		sdl2.SDL_ShowCursor(0)
		
		InitMidi()		
	End

	Field portMidi:PortMidi

	method InitMidi()
		Print "PortMidi test 0.1"
		Print "Scanning Midi Bus, please wait."
		portMidi=New PortMidi()
		Local inputs:=portMidi.inputDevices.Length
		Print "inputs="+inputs
		For Local i:=0 Until inputs
			portMidi.OpenInput(i)
			'Print "Open #"+i+" handle="+h 
		next
	End

	method PollMidi()
		Const NoteOn:=144
		Const NoteOff:=128
		Const Controller:=176
		Const PitchWheel:=224

		While portMidi.HasEvent()
			Local b:=portMidi.EventDataBytes()
			Local note:=b[1]
			Local velocity:=b[2]
			Local word:Int=note+(velocity Shl 7)
			Select b[0]
				Case NoteOn
'					vsynth.NoteOn(note,oscillator,envelope)
				Case NoteOff
'					vsynth.NoteOff(note)
				Case PitchWheel
'					pitchbend=1.0+(word-8192)/8192.0
				Case Controller
					OnControl(b[1],b[2])
				Default
					Print b[0]+" "+b[1]+" "+b[2]+" "+b[3]
			End					
		Wend
'		portMidi.Sleep(1.0/60)
	End
	
	Method RefreshStatus()	
		Local r:=rotSpeed*rotSpeed*rotSpeed
		Local rpm:Float=Abs(60*60*r/(Pi*2))		
		Local velocity:Int=100*Sqrt(panxSpeed*panxSpeed+panySpeed*panySpeed)
		Local tooltype:="Line"
		If tool=Tool.Curve tooltype="Curve"
		status="RPM "+rpm+" Pan="+velocity+" Tip="+Int(radius*100)+" Tool="+tooltype
		statusCount=200		
		wheel.Rate=rpm/60
	End
	
	Field statusCount:Int
	
	Method OnRender( display:Canvas ) Override	
	
		PollMidi()
		
		App.RequestRender()						

		Select appState

			Case AppState.Title
				Local cy:=40
				For Local line:=Eachin (AboutApp+","+Contact+","+Credits).Split(",")
					Local cx:=50
					For Local tab:=Eachin line.Split("=")
						display.DrawText(tab,cx,cy)
						cx+=120
					Next
					cy+=20
				Next

			Case AppState.Draw
				rot+=rotSpeed*rotSpeed*rotSpeed							
				
				panx+=panxSpeed
				pany+=panySpeed
						
				If rotSpeed Or panxSpeed Or panySpeed
					OnMouseEvent(recentMouseEvent)		
				Endif

				display.PushMatrix()
				cx=Width/2-panx
				cy=Height/2-pany
				display.Translate(cx,cy)
				if zoom
					Local scale:=-1.0/zoom
					display.Scale(scale,scale)
				endif
				display.Rotate(rot)		
				
				pane.Draw(display)		
				framecount+=1				
				ink.r=(framecount&255)/255.0
				ink.g=(framecount&1023)/1023.0
				ink.b=(framecount&511)/511.0
				' ink=Color.FromHSV( framecount/100.0,1,1 )				
				
				pane.canvas.Color=ink
				display.PopMatrix()

			Case AppState.Browse
		End
		
		If statusCount>0
			display.DrawText(status,20,20)
			statusCount-=1
		End

	End

	Method Hold()
		rotSpeed=0
		rot=0
		panxSpeed=0
		panySpeed=0
		panx=0
		pany=0
	End
	
	Field control:=New Int[128]
	
	Method OnControl(index:Int, value:Int)	

		If appState=AppState.Title
			DrawMode()
			Return
		Endif

		local f:=value/128.0
		value-=64

		control[index]=value
		Select index
		Case 15
			radius=(value+65)/4.0
		Case 16
			ClearColor=New Color(f,ClearColor.G,ClearColor.B)
		Case 17
			ClearColor=New Color(ClearColor.R,f,ClearColor.B)
		Case 18
			ClearColor=New Color(ClearColor.R,ClearColor.G,f)
		Case 3
			if f>0 zoom=0.125/f
		Default
	'		Print "OnControl:"+index+" "+value
		end
		rotSpeed=-control[14]/512.0*(control[2]+64)

	End
	
	Field CommandKey:=Modifier.Gui
	
	Method OnKeyEvent( event:KeyEvent ) Override	
		Select event.Type
		Case EventType.KeyDown
			Select event.Key
			Case Key.T
				Select tool
				Case Tool.Curve
					tool=Tool.Line
				Case Tool.Line
					tool=Tool.Curve
				End
			Case Key.S
				pane.Smile(mousex,mousey,radius)
				pane.Circle(mousex,mousey,radius)
			Case Key.C
				pane.Clear(Transparent)
			Case Key.Escape
				instance.Terminate()
			Case Key.F1
				Fullscreen = Not Fullscreen
			Case Key.F2
				ToggleTwo()	
			Case Key.Space
				Hold()
				pane.EndSegment()
			End
				
			If event.Modifiers & CommandKey
				Select event.Key
				Case Key.Left
					panxSpeed+=1.0/4			
				Case Key.Right
					panxSpeed-=1.0/4
				Case Key.Down
					panySpeed+=1.0/4		
				Case Key.Up
					panySpeed-=1.0/4		
				End
			Else
				Select event.Key
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
		RefreshStatus()		
	End
		
	Field history:=New Vec2f[4]

	Field recentMouseEvent:MouseEvent
	
	Method DrawMode()
		appState=AppState.Draw
	End
							
	Method OnMouseEvent(event:MouseEvent ) Override
	
		If appState=AppState.Title
			If event.Type=EventType.MouseDown
				DrawMode()
			Endif
			Return
		Endif

	
		If event=Null Return
		
		Local mx:Int=event.Location.X
		Local my:Int=event.Location.Y
		Local b:Int=event.Button
				
		mx=(mx-cx)*zoom
		my=(my-cy)*zoom

		Local x:=-Cos(rot)*mx+Sin(rot)*my
		Local y:=-Sin(rot)*mx-Cos(rot)*my
						
		Local w:Int
		
		If recentMouseEvent<>event w=event.Wheel.Y
		
		If mousex=x And mousey=y And mousew=w Return
		
		recentMouseEvent = event
		
		Select event.Type
		
		Case EventType.MouseWheel
			zoom-=w/8.0
			If zoom<1.0/8 zoom=1.0/8
				
		Case EventType.MouseUp
			pane.EndSegment()
			drawcount=0
			
		Case EventType.MouseDown
			pane.EndSegment()
			drawcount=0
		End

		history[0]=history[1]
		history[1]=history[2]
		history[2]=history[3]
		history[3]=New Vec2f(x,y)
		
		Select tool
			Case Tool.Line
				If drawcount	
					pane.StraightLine(mousex,mousey,x,y,radius)		
				Endif
			Case Tool.Curve
				If drawcount>3 And Not b
'			pane.FatCurve(mx[0],my[0],mx[1],my[1],mx[2],my[2],mx[3],my[3])				
					pane.OpenCurve(history[0],history[1],history[2],history[3],radius)				
				Endif
		End
		
		drawcount+=1

		mousex=x
		mousey=y
		mousew=w
		
		mousecount+=1
	End	
End

Function Main()
	Print title
	instance = New AppInstance	
	New VPaint(title)
	App.Run()	
End

Function SaveTGA(path:String, pixmap:Pixmap)
	Local stream:=FileStream.Open(path,"w")
	Local buffer:=New Byte[18]		
	Local w:=pixmap.Width
	Local h:=pixmap.Height	
	buffer[2]=2
	buffer[12]=w & 255
	buffer[13]=w Shr 8
	buffer[14]=h & 255
	buffer[15]=h Shr 8
	buffer[16]=32
	buffer[17]=8
	stream.Write(Varptr buffer[0],18)	
	stream.Write(pixmap.Data,w*h*4)
	stream.Close()
End Function
