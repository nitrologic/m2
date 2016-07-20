#Import "<std>"
#Import "<mojo>"

Using std..
Using mojo..
Using openal..

' P is coordinate type for drawing pixels

Alias P:Float	

' LowSaturatedGreen is suitable for additive blendmode

Global LowSaturatedGreen:=New Color(0.0, 0.02, 0.0, 1.0)

' Quad is a square Image with canvas

Class Quad Extends Image
	Field index:int
	Field canvas:Canvas
	Field bg:=Color.Black
	Field fg:=LowSaturatedGreen

	Method New(dim:Int,id:Int)		
'		Super.New(dim,dim,TextureFlags.Dynamic|TextureFlags.Filter|TextureFlags.Mipmap)		
		Super.New(dim,dim,TextureFlags.Dynamic|TextureFlags.Filter)		
		index=id
		canvas=New Canvas(Self)	
		canvas.BlendMode=BlendMode.Additive		
		Clear(0,0,dim,dim)
	End
		
	Method Plot(x:P,y:P)
		canvas.DrawPoint(x,y)
	end

	Method Clear(x:P,y:P,w:P,h:P)
		canvas.BlendMode=BlendMode.Opaque
		canvas.Color=bg
		canvas.DrawRect(x,y,w,h)
		canvas.BlendMode=BlendMode.Additive		
		canvas.Color=fg
	end

	Method Flush()	
		canvas.Flush()
	End
End

' Scope is an array of Quads to graph waveforms

Class Scope

	Field columns:int
	Field dimension:Int
	Field mask:Int
	Field width:int
	Field quads:=New Stack<Quad>
	Field bg:=Color.Black
	
	Method New(cols:int=4)
		' TODO: assert columns is power of 2
		columns=cols
		dimension=256
		mask=columns-1
		width=dimension*mask
		For Local index:=0 Until columns
			quads.Push(New Quad(dimension,index))
		Next
		Advance(0)
	End
	
	Field current:Quad
	Field position:P	' global x head position
	Field xlocal:P		' head position on current quad 
	
	Method Plot(y:P)
		current.Plot(xlocal,y)
	End

	Method Advance(xpos:P)
		Local index:=Int(xpos/dimension)
		current=quads[index & mask]
		position=index*dimension
		xlocal=xpos-position		
		current.Clear(xlocal,0,1,dimension)
	end
	
	Method Draw(canvas:Canvas,x:P,y:P)
		Local index:=current.index		
		canvas.Scissor=New Recti(x,y,x+width,y+dimension)		
		For Local quad:=Eachin quads			
			quad.Flush()
			Local order:=mask-(index-quad.index)&mask
			Local xx:=x+order*dimension-xlocal
			canvas.DrawImage(quad,xx,y)
		Next
		canvas.Scissor=null
	End
	
	Method Clear()
		For Local quad:=Eachin quads
			quad.canvas.Clear(bg)
		next
	End
		
End

' AudioIn is an OpenAL Microphone / Line In listener

Class AudioIn
	Field rate:=44100
	Field fragsize:=1024
	Field device:ALCdevice Ptr
	Field buffer:=New Stack<Byte>
	Field scope:Scope
	Field position:Int

	Method New(owner:Scope)
		scope=owner
		device=alcCaptureOpenDevice(NULL, rate, AL_FORMAT_STEREO16, fragsize)
		Local result:=alGetError()
		If result
			Print "OpenAL audio in failed to open="+result
			Return
		endif
	    alcCaptureStart(device)
	End
			
	Method Poll()
		Local sample:Int			
		alcGetIntegerv(device, ALC_CAPTURE_SAMPLES,4,Varptr sample)
		If sample=0 Return
		buffer.Resize(sample*4)
		alcCaptureSamples(device,Varptr buffer.Data[0],sample)
' Assert audioFormat=AL_FORMAT_STEREO16 return 
		Local udata:=Varptr buffer.Data[0]		
		Local sdata:=Cast<Byte Ptr>(udata)
		For Local i:=0 Until sample
			Local s16:=sdata[i*4+1]*256+sdata[i*4+0]
			scope.Plot(128+(s16 Shr 8))			
		Next
		position+=1
		scope.Advance(position)
	End
	
	Method Close()	
	    alcCaptureStop(device)
    	alcCaptureCloseDevice(device)
    End
end

' application main window

Class VscopeWindow Extends Window

	Field framecount:=0
	Field scope:=New Scope()	
	Field cx:Double
	Field t:Double
	Field mic:AudioIn
	Field inputNames:String

	Method New()
		Super.New("VScope 0.1",1024,768)
		ClearColor=Color.Blue
		local p:=Cast<Byte Ptr>(alcGetString(Cast<ALCdevice ptr>(0), ALC_DEVICE_SPECIFIER))
		inputNames=String.FromCString(p)
		print "OpenAL inputs:"+inputNames
		mic=New AudioIn(scope)
	End

	Method OnRender( canvas:Canvas ) Override
		mic.Poll()	
		App.RequestRender()
		Local title:="Monitoring Audio Input"
		Local status:="vscope0.1 framecount="+framecount+" fps="+App.FPS+" ms="+App.Millisecs	
		canvas.DrawText( title,0,0,0,0 )
		canvas.DrawText( status,0,Height,0,1 )			
		scope.Draw(canvas,10,100)
		framecount+=1	
	End
		
	Method OnKeyEvent(event:KeyEvent) Override
		Select event.Type
			Case EventType.KeyDown
				Select event.Key
					Case Key.Escape
						App.Terminate()
				End
		end
	end
	
End

Function Main()
	New AppInstance
	New VscopeWindow
	App.Run()
End
