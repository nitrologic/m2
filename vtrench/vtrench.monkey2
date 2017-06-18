Namespace vtrench

#Import "<std>"
#Import "<mojo>"
#Import "<mojo3d>"

#Import "assets/"

#Import "util"

Using std..
Using mojo..
Using mojo3d..

Global AboutApp:="VTrench Control,,F1=Toggle Fullscreen,Click To Start"
Global Contact:=",,Latest Source: github.com/nitrologic/m2/tree/master/vtrench"
Global Credits:=",,Transpiled by Monkey2 the primate language of champions."

Class Trench
	
	Global White:=New PbrMaterial( Color.White,0,1 )
	
	Function CreateBox:Model()
		Local box:=Model.CreateBox( New Boxf( -1,-1,-1,1,1,1 ),1,1,1,White )
		Return box
	End
#rem
	Function BuildShip:Ship(scene:b3dScene)
		Local box:=Model.CreateBox( -5,-.4,-5,5,.4,5,white,tissue )
		b3dEntity_SetParent box,scene
		b3dEntity_SetPosition box,0,10,0
	
		Local box2:=CreateBox( -8,-.1,-8,8,.1,8,white,tissue )
		b3dEntity_SetRotation box2,0,QPi,0	
		b3dEntity_SetParent box2,box
			
		Local cube:=CreateBox( -2,-2,-2,2,2,2,red,tissue )
		b3dEntity_SetParent cube,box
		b3dEntity_SetRotation cube,QPi,0,QPi
		
		Local cube2:=CreateBox( -2,-2,-2,2,2,2,gold,tissue )
		b3dEntity_SetParent cube2,box
		b3dEntity_SetRotation cube2,QPi,0,0
		b3dEntity_SetPosition cube2,0,1,-4

		Local r1#=1.2
		Local rod:=CreateBox( -r1,-r1,-4, r1,r1,12,yellow,tissue )
		b3dEntity_SetRotation rod,0,0,QPi
		b3dEntity_SetParent rod,box
	
		Local cube3:=CreateBox( -2,-2,-.2,2,2,3.2,black,tissue )
		b3dEntity_SetParent cube3,box
		b3dEntity_SetPosition cube3,0,1,-8
		b3dEntity_SetRotation cube3,0,0,QPi
		
		Local pr#=0.5
		Local pilot:=CreateBox( -pr,-0,-pr,pr,2,pr, pulse,tissue )
		b3dEntity_SetParent pilot,box
		b3dEntity_SetPosition pilot,0,0,-1

		Local r#=0.8		
		Local rod1:=CreateBox( -r,-r,-4,r,r,10,red,tissue )
		b3dEntity_SetPosition rod1,-5,0,0
		b3dEntity_SetRotation rod1,0,0,QPi
		b3dEntity_SetParent rod1,box
		
		Local rod2:=CreateBox( -r,-r,-4, r,r,10,red,tissue )
		b3dEntity_SetPosition rod2,5,0,0
		b3dEntity_SetRotation rod2,0,0,QPi
		b3dEntity_SetParent rod2,box
		
		Local ship:Ship=Ship.CreateShip( box,1 )
	
		Return ship	
	End
#end
End



Class MyWindow Extends Window

Function Fly( entity:Entity,view:View )

	If Keyboard.KeyDown( Key.Up )
		entity.RotateX( .1 )
	Else If Keyboard.KeyDown( Key.Down )
		entity.RotateX( -.1 )
	Endif
	
	If Keyboard.KeyDown( Key.Q )
		entity.RotateZ( .1 )
	Else If Keyboard.KeyDown( Key.W )
		entity.RotateZ( -.1 )
	Endif
	
	If Keyboard.KeyDown( Key.Left )
		entity.RotateY( .1,True )
	Else If Keyboard.KeyDown( Key.Right )
		entity.RotateY( -.1,True )
	Endif

	If Mouse.ButtonDown( MouseButton.Left )
		If Mouse.X<view.Width/3
			entity.RotateY( .1,True )
		Else If Mouse.X>view.Width/3*2
			entity.RotateY( -.1,True )
		Else
			entity.Move( New Vec3f( 0,0,.1 ) )
		Endif
	Endif
	
	If Keyboard.KeyDown( Key.A )
		entity.MoveZ( .1 )	'( New Vec3f( 0,0,.1 ) )
	Else If Keyboard.KeyDown( Key.Z )
		entity.MoveZ( -.1 )	'( New Vec3f( 0,0,-.1 ) )
	Endif
		
End

	Const MaxJoy:=4
	Global Joysticks:=New JoystickDevice[MaxJoy]
	
	Function ScanJoysticks()
		For Local i:=0 Until MaxJoy
			If Not Joysticks[i]
				Joysticks[i]=JoystickDevice.Open( i )
			Endif
		next
	End
	
	Function DrawUI(canvas:Canvas, info:String)
		canvas.DrawText( info,0,0 )
		For Local i:=0 Until MaxJoy		
			Local joy:=Joysticks[i]
			Local x:=10
			If joy
				canvas.DrawText( "Name="+joy.Name,x,16 )
				For Local axis:=0 Until 6
					canvas.DrawText( "Axis "+axis+"="+joy.GetAxis( axis ),x,(axis+3)*16 )
				Next			
			Endif
		Next
	End
		
	Field scene:Scene
	Field camera:Camera
	Field light:Light
	
	Field ground:Model
	Field boxes:=New Stack<Model>
	
	Method New( title:String="Simple mojo app",width:Int=640*2,height:Int=480*2,flags:WindowFlags=WindowFlags.Resizable )

		Super.New( title,width,height,flags )
		
		ScanJoysticks()
		
'		Print gles20.glGetString( gles20.GL_EXTENSIONS ).Replace( " ","~n" )
		
		scene=Scene.GetCurrent()
		scene.SkyTexture=Texture.Load( "asset::skybox.jpg",TextureFlags.FilterMipmap|TextureFlags.Cubemap )
		
		camera=New Camera
		camera.Near=.1
		camera.Far=100
		camera.Move( 0,15,-20 )
	'	camera.Aspect=0.5
		
		light=New Light
		light.RotateX( Pi/2 )	'aim directional light downwards - Pi/2=90 degrees.
		
		ground=Model.CreateBox( New Boxf( -50,-1,-50,50,0,50 ),1,1,1,New PbrMaterial( Color.Green,0,1 ) )
		
		Local box:=Trench.CreateBox()	'	Model.CreateBox( New Boxf( -1,-1,-1,2,2,2 ),1,1,1,New PbrMaterial( Color.White,0,1 ) )	

		Local root:=box.Copy()
		root.Move( 0,2,0 )
'		root.Scale=New Vec3f( 3 )
		
		boxes.Push( root )
		
		For Local m:=0.0 To 1.0 Step .125		
			For Local i:=0.0 Until 360.0 Step 24			
				Local copy:=box.Copy( root )				
				copy.RotateY( i*TwoPi/360 )
'				copy.Move( 0,0,6+m*16 )
				For Local j:=0 Until copy.Materials.Length
					Local material:=Cast<PbrMaterial>( copy.Materials[j].Copy() )
					material.MetalnessFactor=m
					material.RoughnessFactor=i/360.0
					copy.Materials[j]=material
				Next
				boxes.Push( copy )
			
			Next
		Next
		
'		duck.Destroy()

	End
	
	Method OnRender( canvas:Canvas ) Override

		RequestRender()
		
		For Local box:=Eachin boxes
			box.Rotate( 0,rotSpeed*0.001,0 )
		Next
		
		Fly( camera,Self )
		
		scene.Render( canvas,camera )

'		canvas.Scale( Width/640.0,Height/480.0 )
				
		DrawUI(canvas, "Width="+Width+", Height="+Height+", FPS="+App.FPS)
	End

	Field rotSpeed:Float
	Field radius:Float
	Field panx:Float
	Field pany:Float
	Field panxSpeed:Float
	Field panySpeed:Float
	
	Method OnKeyEvent( event:KeyEvent ) Override	
		Select event.Type
		Case EventType.KeyDown
			Select event.Key
			Case Key.Escape
				App.Terminate()
			Case Key.F1
				Fullscreen = Not Fullscreen
			End
				
			If event.Modifiers & Modifier.Control'CommandKey
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
'		RefreshStatus()		
	End
	
	
End

Function Main()

	New AppInstance
	
	New MyWindow
	
	App.Run()
End
