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
		Next
		image=new Image(pixmap)
'		image.Handle=New Vec2f( .5,.5 )
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
	Field z:Int
	Field neighbors:Cube[]
	Field vacant:int
	Field kids:Cube[]
	Field style:Int

	Field image:Image
	
	Const D:=24
	
	Method New(skin:Image)
		image=skin
		vacant=26
		neighbors=New Cube[Qube]		
	End

	Method Clone:Cube() Virtual
		Local cube:=New Cube(image)
		Return cube
	End
	
	Method Draw(display:Canvas,zx:Double,zy:Double,rz:Double) virtual
		If vacant=0 return
		Local sz:=y
		Local sx:=x*D+sz*zx*D
		Local sy:=z*D+sz*zy*D
		display.DrawImage(image,sx,sy)
	end	
	
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
		If color=scan Return count	
		color=scan
		x=cx
		y=cy
		z=cz
		If collect collect.AddLast(Self)
		count+=1
		If neighbors=Null Return count		
		Local cube:Cube
		For local dx:=-1 To 1
			For Local dy:=-1 To 1
				For local dz:=-1 To 1
					Local index:=Rubik+dx+dy*3+dz*3*3
					cube=neighbors[index]
					If cube And (dx|dy|dz)
						count=cube.Visit(scan,count,cx+dx,cy+dy,cz+dz,collect)
					endif
				Next
			Next
		Next
		
		Return count
	End

	Method Neighbor:Cube(dx:Int,dy:Int,dz:Int)
		Local index:=Rubik+dx+dy*3+dz*3*3
		If neighbors Return neighbors[index]
		Return Null
	End

	Method Detach2:Cube(dx:Int,dy:Int,dz:Int)	
		Local index:=Rubik+dx+dy*3+dz*3*3
		Local result:Cube
		If neighbors 
			result=neighbors[index]
			neighbors[index]=Null ' todo null container if empty
			'todo modify vacant l
		Endif
		Return result
	End
	
end

class Bill Extends Cube
	Method New(skin:Image)
		Super.New(skin)
	end

	Method Clone:Cube() Override
		Local cube:=New Bill(image)
		Return cube
	End

	Method Draw(display:Canvas,zx:Double,zy:Double,rz:Double) Override
		If vacant=0 return
		Local sz:=y
		Local sx:=x*D+sz*zx*D
		Local sy:=z*D+sz*zy*D
		display.DrawImage(image,sx,sy,rz)
	end	
End

Global scanCount:int

Const IMax:=1024

Class Clump
	Field root:Cube
	Field org:Vec3<Int>
	Field dim:Vec3<Int>

	Field count:int	
	Field grid:Cube[,,]
	Field stack:List<Cube>

' quadrant facing 2d march order where y is always up

	Field ordered:=New Cube[][4]

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
	
		stack=New List<Cube>		
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
		org=New Vec3<int>(minx,miny,minz)
		dim=new Vec3<Int>(1+maxx-minx,1+maxy-miny,1+maxz-minz)
		Print "stack.size="+stack.Count()				
		Print "org is "+org.ToString()				
		Print "dim is "+dim.ToString()				
		grid=New Cube[dim.x,dim.y,dim.z]
		For Local cube:=Eachin stack
			grid[cube.x-minx,cube.y-miny,cube.z-minz]=cube
		Next						
		BakeSort()
	End
		
	Method BakeSort()		
		For QuadrantOrder=0 Until 4			
			Local order:=New List<Cube>(stack)
			order.Sort(Compare)
			ordered[QuadrantOrder]=order.ToArray()
		Next
	End
		
	Method Skin(xaxis:Bool=True,yaxis:bool=True,zaxis:Bool=True)
		Local dx:=Int(xaxis)
		Local dy:=Int(yaxis)
		Local dz:=Int(zaxis)		

		' enlarge dimension 
		dim=New Vec3<Int>(dim.x+dx*2,dim.y+dy*2,dim.z+dz*2)

		Local minx:=org.x-dx
		Local miny:=org.y-dy
		Local minz:=org.z-dz

		' move handle
		org=New Vec3<Int>(minx,miny,minz)
		
		Print "org is "+org.ToString()				
		Print "dim is "+dim.ToString()				
		
		grid=New Cube[dim.x,dim.y,dim.z]

		For Local cube:=Eachin stack
			grid[cube.x-minx,cube.y-miny,cube.z-minz]=cube
		Next
		
		Local edge:=New List<Cube>		
		For Local cube:=Eachin stack
			For local x:=-dx To dx
				For Local y:=-dy To dy
					For local z:=-dz To dz
						If (x|y|z)=0 Continue
						Local sx:=cube.x+x
						Local sy:=cube.y+y
						Local sz:=cube.z+z
						If Not grid[sx-minx,sy-miny,sz-minz]
							Local cube2:=root.Clone()
							cube2.x=sx
							cube2.y=sy
							cube2.z=sz
							grid[sx-minx,sy-miny,sz-minz]=cube2
							edge.AddLast(cube2)
						Endif
					Next
				Next
			Next
		Next
		
		For Local cube:=Eachin edge
			stack.AddLast(cube)
			For local x:=-dx To dx
				For Local y:=-dy To dy
					For local z:=-dz To dz
						If (x|y|z)=0 continue
						Local sx:=cube.x+x-minx
						Local sy:=cube.y+y-miny
						Local sz:=cube.z+z-minz
						If sx>=0 And sy>=0 And sz>=0
							If sx<dim.x And sy<dim.y And sz<dim.z
								Local cube2:=grid[sx,sy,sz]
								if cube2
									Local index2:=Rubik-x-y*3-z*3*3																			
									If not cube2.neighbors[index2]
										Local index:=Rubik+x+y*3+z*3*3								
										Assert(cube.neighbors[index]=Null)
										cube.neighbors[index]=cube2
										cube.vacant-=1
										cube2.neighbors[index2]=cube
										cube2.vacant-=1
									Endif
								Endif
							endif
						Endif
					Next
				Next
			Next
		Next
		
		BakeSort()
	End
End

Class Grid

	Field star:Cube
	Field starClump:Clump

	Field framecount:Int	
	
	Method New(image:Image)
		star=New Cube(image)
'		star=New Bill(image)
		starClump=New Clump(star)
'		Generate()		
	End
	
	Method Generate(xaxis:Bool=True,yaxis:bool=True,zaxis:Bool=True)
		starClump.Skin(xaxis,yaxis,zaxis)
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
			cube.Draw(c,zx,zy,theta)
		next
		c.PopMatrix()
		framecount+=1		
	End	
End

Global Ship:=New String[](
"1",
"1",
"1",
"1",
"21",
"321 1",
"32111")

Function BuildShip(ship:String[])
	Local z:=0
	For Local line:=Eachin ship	
		z+=1
	next
end

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
	
	Field grid:Grid
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
	
	Global Transparent:=New Color(0,0,0,0)
	
	Field tile:Tile

	Method New(title:String)
		Super.New(title,720,560,WindowFlags.Resizable)		
		ClearColor=Color.Black				
		zoom=2
		ink=New Color
		radius=2.5		
'		sdl2.SDL_ShowCursor(0)
'		InitMidi()		
		tile=New Tile()		
		grid=New Grid(tile.image)
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
'		wheel.Rate=rpm/60
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
				grid.Generate(True,True,True)
			Case Key.X
				grid.Generate(True,False,False)
			Case Key.Y
				grid.Generate(False,True,false)
			Case Key.Z
				grid.Generate(false,false,True)
			Case Key.T
				Select tool
				Case Tool.Curve
					tool=Tool.Line
				Case Tool.Line
					tool=Tool.Curve
				End
			Case Key.Escape
				App.Terminate()
			Case Key.F1
				Fullscreen = Not Fullscreen
			Case Key.Space
				Hold()
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
