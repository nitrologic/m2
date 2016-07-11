Namespace myapp

#Import "<std>"
#Import "<mojo>"
#Import "<portmidi>"

Using std..
Using mojo..
Using portmidi..

Global title:String="VGrid 0.1"	

Global AboutApp:="GridPaint Control,,"'Cursor Left=-RPM,Cursor Right=+RPM,,Mouse Button=Lift Pen,Mouse Wheel=Zoom,Space Key=Hold,S Key=Smile Box,C Key=Clear,Cursor Up=+Pen Size,Cursor Down=-Pen Size,Hold,F1=Toggle Fullscreen,Click To Start"
Global Contact:=",,Latest Source: github.com/nitrologic/m2"
Global Credits:=",,Transpiled by Monkey2 the primate language of champions."

Class PixelMap Extends Pixmap

	Method New(w:Int,h:Int)
		Super.New(w,h)
	end

	method Rect(rx:Int,ry:int,rw:int,rh:Int,c:Color)
		For Local y:=ry Until ry+rh
			For Local x:=rx until rx+rw
				SetPixel(x,y,c)
			Next
		next
	End

	method Ball(rx:Int,ry:int,r:Int,c:Color)
		For Local y:=-r To r
			For Local x:=-r To r
				Local dd:=x*x+y*y
				If dd<r*r
					SetPixel(rx+x,ry+y,c)
				endif
			Next
		next
	End

End

Class Tile

	Field pixmap:=New PixelMap(32,32)
	Field image:Image

	Method New()
		pixmap.Clear(Color.None)
		pixmap.Rect(4,4,24,24,Color.Blue)
		pixmap.Rect(6,6,20,20,Color.DarkGrey)
		pixmap.Ball(16,16,10,Color.Black)		
		For Local i:=5 to 27 Step 2
			pixmap.Rect(i,5,1,22,Color.White)
		next
		image=new Image(pixmap)
		image.Handle=New Vec2f( .5,.5 )
	end

End

Const Qube:=27
Const Rubik:=13' -1 -3 -9 (-13) is rubik offset

Global Order4:=New Int[](
	1,0,0,1, 
	0,1,-1,0,
	-1,0,0,-1,
	0,-1,1,0)

Class Cube
	Field color:Int
	Field x:Int
	Field y:Int
	Field z:int
	Field neighbors:Cube[]
	Field kids:Cube[]
	Field style:Int
	
	Method Depth:Int(quadrant:Int)
		local ix:=Order4[quadrant*4+0]
		local jx:=Order4[quadrant*4+1]
		local iy:=Order4[quadrant*4+2]
		local jy:=Order4[quadrant*4+3]			
		Local sx:=x*ix+z*jx
		Local sy:=x*iy+z*jy					
		Return (sx+sy)*512+y
	End

	Method Visit:Int(scan:Int,count:Int,cx:int,cy:int,cz:int,collect:List<Cube>)	
		If color<>scan
			color=scan
			x=cx
			y=cy
			z=cz
			If collect collect.AddLast(Self)
			count+=1
		Endif

		If neighbors=Null Return count
		
		Local cube:Cube
		Local index:=0
		For local dx:=-1 To 1
			For Local dy:=-1 To 1
				For local dz:=-1 To 1
					cube=neighbors[index]
					If cube And (dx|dy|dz)
						count=cube.Visit(scan,count,cx+dx,cy+dy,cz+dz,collect)
					endif
					index+=1
				Next
			Next
		Next
		
		Return count
	End

	Method Grow()
		Local o:=New Cube
		For local x:=-1 To 1
			For local y:=-1 To 1
				For local z:=-1 To 1
					If (x|y|z)=0 Continue
					If Not Neighbor(x,y,z)
						Attach(x,y,z)
					Endif
				Next
			Next
		next
	End

	Method Neighbor:Cube(dx:Int,dy:Int,dz:Int)
		Local index:=Rubik+dx+dy*3+dz*3*3
		If neighbors Return neighbors[index]
		Return Null
	end

	Method Detach:Cube(dx:Int,dy:Int,dz:Int)	
		Local index:=Rubik+dx+dy*3+dz*3*3
		Local result:Cube
		If neighbors 
			result=neighbors[index]
			neighbors[index]=Null ' todo null container if empty
		Endif
		Return result
	End
	
	Method Attach:Cube(dx:Int,dy:Int,dz:Int)
		Local index:=Rubik+dx+dy*3+dz*3*3	
		If neighbors=Null 
			neighbors=New Cube[Qube]
		endif
		If neighbors[index]=Null
			neighbors[index]=New Cube
		Endif
		Return neighbors[index]
	End
end

Global scanCount:int

Const IMax:=1024

Class Clump
	Field root:Cube
	Field origin:Vec3<Int>
	Field dim:Vec3<Int>

	Field count:int	
	Field grid:Cube[,,]

' quadrant facing 2d march order where y is always up

	Field ordered:=New List<Cube>[4]

	Global QuadrantOrder:int
			
	Function Compare:Int(a:Cube,b:Cube)
		Return a.Depth(QuadrantOrder)-b.Depth(QuadrantOrder)
	End
	
	Method New(rootCube:Cube)
		root=rootCube
' first scan we count and measure		
		Local minx:=IMax
		Local miny:=IMax
		Local minz:=IMax
		Local maxx:=-IMax
		Local maxy:=-IMax
		Local maxz:=-IMax
		Local stack:=New List<Cube>		
		scanCount+=1
		count=root.Visit(scanCount,0,0,0,0,stack)					
		Print "stack.size="+stack.Count()		
		For Local cube:=Eachin stack
			minx=Min(minx,cube.x)
			miny=Min(miny,cube.y)
			minz=Min(minz,cube.z)
			maxx=Max(maxx,cube.x)
			maxy=Max(maxy,cube.y)
			maxz=Max(maxz,cube.z)
		Next
		origin=New Vec3<int>(minx,miny,minz)
		dim=new Vec3<Int>(1+maxx-minx,1+maxy-miny,1+maxz-minz)
		Print "stack.size="+stack.Count()				
		Print "dim is "+dim.ToString()				
		grid=New Cube[dim.x,dim.y,dim.z]
		For Local cube:=Eachin stack
			grid[cube.x-minx,cube.y-miny,cube.z-minz]=cube
		Next				
		For QuadrantOrder=0 Until 4			
			Local order:=New List<Cube>(stack)
			order.Sort(Compare)
			ordered[QuadrantOrder]=order
		Next
	End
	
End

Class Grid

	Field star:Cube
	Field starClump:Clump

	Field framecount:Int	
	Field tile:Tile
	
	Method New()
		tile=New Tile()		
		star=New Cube()
		Generate()		
	End
	
	Method Generate()
		Local stack:=New List<Cube>		
		scanCount+=1
		local count:=star.Visit(scanCount,0,0,0,0,stack)					
		For Local cube:=Eachin stack
			cube.Grow()
		next		
		starClump=New Clump(star)
		Print "star population is "+starClump.count
	End
	
	Method IsoView(c:Canvas, theta:Double, zoom:double)
		Local tx:=Cos(theta)*zoom
		Local ty:=Sin(theta)*zoom
		zx=ty
		zy=tx
		c.Matrix=new AffineMat3f(tx,ty*0.5,-ty,tx*0.5,400,240)		
	End
	
	Field zx:Double
	Field zy:Double
	
	Method Draw( c:Canvas )	
		c.PushMatrix()
		Local zoom:=1.0'0.1*Mouse.Location.Y
		Local theta:=0.03*framecount
		IsoView(c,theta,zoom)
		
' calulate draw order so we scan grid from far to near

		Local quadrant:Int=Int(2*theta/Pi)&3		

		For Local cube:=Eachin starClump.ordered[quadrant]
			Local z:=cube.y
			Local x:=cube.x*34+z*zx*34
			Local y:=cube.z*34+z*zy*34
			c.DrawImage(tile.image,x,y)
		next


		local ix:=Order4[quadrant*4+0]
		local jx:=Order4[quadrant*4+1]
		local iy:=Order4[quadrant*4+2]
		local jy:=Order4[quadrant*4+3]

		Local n:=1		
		For Local i:=-n To n
			For Local j:=-n To n
				Local x:=i*ix+j*jx
				Local y:=i*iy+j*jy
				For Local z:=12 To 0 Step -3					
'					c.DrawImage(tile.image,x*34+z*zx,y*34+z*zy)
'					c.DrawImage(tile.image,x*24,y*24,theta)
				next
			Next
		Next
		
		c.PopMatrix()
		
		framecount+=1		
	End
	
End

Enum Tool
	Line
	Curve
End

Enum AppState
	Title
	Draw
	Browse
End

Class GridPaint Extends Window
	Field appState:AppState
	
	Field grid:=New Grid

'	Field tool:VToolbar
'	Field pane:VPane
'	Field browse:VBrowse
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
		ClearColor=Color.Black				
		zoom=2
'		pane=New VPane(2048,2048,Transparent)
'		pane=New VPane(4096,4096,Transparent)
'		browse=New VBrowse()
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
		
'		InitMidi()		
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

		If not portMidi return

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
'		If tool=Tool.Curve tooltype="Curve"
		status="RPM "+rpm+" Pan="+velocity+" Tip="+Int(radius*100)+" Tool="+tooltype
		statusCount=200		
		wheel.Rate=rpm/60
	End
	
	Field statusCount:Int
	
	Method OnRender( display:Canvas ) Override	
	
		PollMidi()
		
		App.RequestRender()						

		grid.Draw(display)

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
				
'				pane.Draw(display)		
				framecount+=1				
				ink.r=(framecount&255)/255.0
				ink.g=(framecount&1023)/1023.0
				ink.b=(framecount&511)/511.0
				' ink=Color.FromHSV( framecount/100.0,1,1 )				
				
'				pane.canvas.Color=ink
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
			
			Case Key.G
				grid.Generate()
			
			Case Key.T
				Select tool
				Case Tool.Curve
					tool=Tool.Line
				Case Tool.Line
					tool=Tool.Curve
				End
			Case Key.S
'				pane.Smile(mousex,mousey,radius)
'				pane.Circle(mousex,mousey,radius)
			Case Key.C
'				pane.Clear(Transparent)
			Case Key.Escape
				App.Terminate()
			Case Key.F1
				Fullscreen = Not Fullscreen
			Case Key.F2
				ToggleTwo()	
			Case Key.Space
				Hold()
'				pane.EndSegment()
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
'			pane.EndSegment()
			drawcount=0
			
		Case EventType.MouseDown
'			pane.EndSegment()
			drawcount=0
		End

		history[0]=history[1]
		history[1]=history[2]
		history[2]=history[3]
		history[3]=New Vec2f(x,y)
#rem		
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
#end		
		drawcount+=1

		mousex=x
		mousey=y
		mousew=w
		
		mousecount+=1
	End	
End

Function Main()
	Print title
	New AppInstance	
	New GridPaint(title)
	App.Run()	
End
