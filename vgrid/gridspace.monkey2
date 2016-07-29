#Import "<std>"
#Import "<mojo>"

Using std..
Using mojo..

Const RubikBits:=27
Const RubitMask:=$7ffffff 'bit per neighbor tenancy mask
Const Rubik:=13 ' -1 -3 -9 (-13) is rubik offset
Const RubikBit:=1 shl Rubik 'yes we are home

Global Order4:=New Int[](1,0,0,1,  0,1,-1,0,  -1,0,0,-1,  0,-1,1,0)

Class Cube

	Global CubeCounter:=0
	Field id:int
	Field x:Int
	Field y:Int
	Field z:Int
	Field rubit:=RubikBit
	Field skin:Int
	Field index:Int
	
	Method New(skinbits:Int)
		skin=skinbits
		CubeCounter+=1
		id=CubeCounter
	End

	Method Vacant:Bool(dx:int,dy:int,dz:Int)
		Local index:=Rubik+dx+dy*3+dz*9
		Local bit:=1 Shl index
		return (rubit&bit)=0
	End

	Method Clone:Cube()
		Local cube:=New Cube(skin)
		Return cube
	End
	
	Method SortDepth:Int(quadrant:Int)
		Local ix:=Order4[quadrant*4+0]
		local iy:=Order4[quadrant*4+1]
		local jx:=Order4[quadrant*4+2]
		local jy:=Order4[quadrant*4+3]			
		Local dx:=x*ix+z*jx
		Local dy:=x*iy+z*jy					
		Return ((dx+dy) Shl 16) + y
	End

	' meet cube at dx,dy,dz offset
	
	Method Meet(cube:Cube,dx:int,dy:int,dz:Int)			
		Local index:=Rubik+dx+dy*3+dz*9
		Local bit:=1 Shl index
		rubit|=bit
		Local mindex:=Rubik-dx-dy*3-dz*9
		Local mbit:=1 Shl mindex
		cube.rubit|=mbit
	End
end

Global scanCount:int

Class IsoSurface
	Field root:Cube
	Field org:Vec3<Int>
	Field dim:Vec3<Int>
	Field volume:int
	Field surface:List<Cube>
	Field ordered:=New Cube[][4] ' quadrant facing 2d march order where y is always up
				
	Method New(rootCube:Cube)
		root=rootCube
		org=New Vec3<int>(-1,-1,-1)
		dim=new Vec3<Int>(3,3,3)
		surface=New List<Cube>		
		AddCube(root)
		BakeSort()
	End
	
	Method AddCube(cube:Cube)
		surface.AddLast(cube)
		volume+=1	
	end
	
	Method CullSurface()
		local cull:=New List<Cube>()
		For Local cube:=Eachin surface
			If cube.rubit<>RubitMask ' level1 view cull
				cull.AddLast(cube)
			Endif
		Next
		surface=cull
	End
		
	Method BakeSort()		
		For local quadrant:=0 Until 4			
			Local order:=New List<Cube>(surface)
			local func:=Lambda:Int(a:Cube,b:Cube)
				return b.SortDepth(quadrant)-a.SortDepth(quadrant)
			End				
			order.Sort(func)
			ordered[quadrant]=order.ToArray()			
		Next
	End		

end

class IsoMesh
	Field vertCount:Int
	Field triCount:int
	field verts:=New Vec3<Int>[65536]
	Field tris:=New Int[65536*6]
	Method AddVert:Int(x:Int,y:Int,z:Int)
		verts[vertCount].x=x
		verts[vertCount].y=y
		verts[vertCount].z=z
		vertCount+=1
		Return vertCount-1
	End
	Method AddTri:Int(t0:int,t1:int,t2:Int)
		tris[triCount*3+0]=t0
		tris[triCount*3+1]=t1
		tris[triCount*3+2]=t2
		triCount+=1
		Return triCount-1
	End
End

Class IsoGrid Extends IsoSurface
	Field grid:Cube[,,]
	Field skin:IsoMesh

	Method New(rootCube:Cube)
		Super.New(rootCube)
		grid=New Cube[dim.x,dim.y,dim.z]
	End
	
	Method Neighbors:Stack<Cube>(cube:Cube,result:Stack<Cube>)
		Local sx:=cube.x-org.x
		Local sy:=cube.y-org.y
		Local sz:=cube.z-org.z
		For local x:=-1 To 1
			For Local y:=-1 To 1
				For local z:=-1 To 1
					If (x|y|z)=0 Continue
					local neighbor:=grid[sx+x,sy+y,sz+z]
					If neighbor result.Push(neighbor)
				Next
			Next
		Next
		Return result
	end
	
	Method Skin:IsoMesh()
		If	skin
			skin=Null
		else
			skin=New IsoMesh
			For Local point:=Eachin surface
				point.index=skin.AddVert(point.x,point.y,point.z)
			next			
			For Local point:=Eachin surface			
				Local neighbors:=Neighbors(point,New Stack<Cube>)
				For Local i:=0 Until neighbors.Length
					For Local j:=i+1 Until neighbors.Length
						skin.AddTri(point.index,neighbors[i].index,neighbors[j].index)
					Next
				Next
			next			
		Endif
		Return skin
	End
			
	Method Extrude(xaxis:Bool=True,yaxis:bool=True,zaxis:Bool=True,smooth:Int=0)
		Local dx:=Int(xaxis)
		Local dy:=Int(yaxis)
		Local dz:=Int(zaxis)		

		org=new Vec3<int>(org.x-dx,org.y-dy,org.z-dz)
		dim=New Vec3<Int>(dim.x+dx*2,dim.y+dy*2,dim.z+dz*2)

		grid=New Cube[dim.x,dim.y,dim.z]
		
		For Local point:=Eachin surface
			grid[point.x-org.x,point.y-org.y,point.z-org.z]=point
		Next
		
		' first enamel outer surface (inner mass inferred)
		
		Local enamel:=New List<Cube>		
		For Local cube:=Eachin surface
			Local sx:=cube.x-org.x
			Local sy:=cube.y-org.y
			Local sz:=cube.z-org.z
			For local x:=-dx To dx
				For Local y:=-dy To dy
					For local z:=-dz To dz
						If (x|y|z)=0 Continue
						If smooth&1 And ((x&y&z)&1)=1 continue
						If smooth&2 And (x*y or x*z or y*z) continue
						If grid[sx+x,sy+y,sz+z]=Null And cube.Vacant(x,y,z)
							Local cube2:=root.Clone()
							cube2.x=cube.x+x							
							cube2.y=cube.y+y
							cube2.z=cube.z+z							
							Assert(sx+x=cube2.x-org.x)
							Assert(sy+y=cube2.y-org.y)
							Assert(sz+z=cube2.z-org.z)
							enamel.AddLast(cube2)
							grid[sx+x,sy+y,sz+z]=cube2
						Endif
					Next
				Next
			Next
		Next
		
		' second visit all neighbors (none must be inferred)
		
		For Local cube:=Eachin enamel
			AddCube(cube)
'			surface.AddLast(cube)
			Local sx:=cube.x-org.x
			Local sy:=cube.y-org.y
			Local sz:=cube.z-org.z
			For local x:=-1 To 1
				For Local y:=-1 To 1
					For Local z:=-1 To 1
						If (x|y|z)=0 Continue
						Local cube2:=grid[sx+x,sy+y,sz+z]								
						if cube2<>Null cube.Meet(cube2,x,y,z)
					Next
				Next
			Next
		Next
		
		CullSurface()
		BakeSort()
	End
		
End


Class IsoSkin
	Field atlas:Image
	Field pix:=New Pixmap(1024,1024)
	Field tx:Int
	Field ty:Int	
	Field lineheight:Int
	Field reservewidth:int
	field rects:=New Stack<Recti>
	Field balls:=new Stack<Image>
	
	Global Center:=New Vec2f( .5,.5 )

	Method Reserve(w:Int,h:Int)
		tx+=reservewidth
		reservewidth=w
		If tx+w>pix.Width
			tx=0
			ty+=lineheight
			lineheight=0
		Endif
		lineheight=Max(lineheight,h)		
		rects.Push(New Recti(tx,ty,tx+w,ty+h))
	End

	Method New()
		pix.Clear(Color.None)				

		Balls(New Color[](Color.Red,Color.Blue,Color.Green,Color.Yellow,Color.Cyan,Color.Magenta,Color.White,Color.Black))

		atlas=New Image(pix)
		For Local rect:=Eachin rects
			AddBall(rect)
		Next
	End
	
	Method AddBall(recti:Recti)
		Local image:=New Image(atlas,recti)
		image.Handle=Center
		balls.Push(image)
	End
	
	Method TileImage()
		Reserve(128,128)
		Rect(20,20,88,88,Color.White)
		Rect(24,24,80,80,Color.None)
		Rect(20,6,88,8,Color.White)
	End

	Method Balls(palette:Color[])		
		For Local color:=Eachin palette
			Ball(color,Color.Black)
			Ball(color,Hot)
		Next
	End
	
	Method Ball(primary:Color,ring:Color)		
		Reserve(128,128)
		Circle(64,64,40,Color.DarkGrey)		
		Circle(64,64,34,ring)		
		Circle(64,64,30,primary)		
		Circle(56,52,6,Color.White,True)	
	End

	method Circle(rx:int,ry:int,r:int,c:Color,blend:Bool=False)
		Local x0:=rx-r
		Local x1:=rx+r
		Local y0:=ry-r
		Local y1:=ry+r
		x0=Max(x0,0)
		y0=Max(y0,0)
		For Local y:=y0 To y1
			For Local x:=x0 To x1
				If blend And ((x+y)&1) Continue
				Local dd:=(x-rx)*(x-rx)+(y-ry)*(y-ry)
				If dd<r*r
					local sh:=0.5+0.25*Sin(float(y)/16)-0.25*Sin(float(x)/16)
					pix.SetPixel(x+tx,y+ty,c*new Color(sh,1))
				Endif
			Next
		Next
	End
	
	method Rect(rx:Int,ry:int,rw:int,rh:Int,c:Color)
		For Local y:=ry Until ry+rh
			For Local x:=rx until rx+rw
				pix.SetPixel(x+tx,y+ty,c)
			Next
		next
	End

	Const D:=7
	
	Method DrawCube(cube:Cube,display:Canvas,zx:Double,zy:Double,rz:Double)
		Assert(cube.rubit<>RubitMask)
		Local sx:Float=(cube.x-cube.z)+zy*cube.y*2
		Local sy:Float=(cube.x+cube.z)+zx*cube.y*2		
'		display.DrawImage(tile,sx*D,sy*D,Pi/4,0.125,0.125)	'facing sky

		display.DrawImage(balls[cube.skin],sx*D,sy*D,rz,0.125,0.25)	'facing eye		

'		For Local i:=0 To 5
'			display.DrawImage(image,sx*D+i*zy,sy*D+i*zx,-Pi/4,0.125,0.125)	'facing sky
'		next
	end	
	
	Global verts:=new Float[65536*2]
	
	Method DrawMesh(mesh:IsoMesh,display:Canvas,t:Mat4<Float>)
		Local n:=mesh.vertCount
		For Local i:=0 Until n
			Local vert:=mesh.verts[i]
			Local sx:=vert.x * t.i.x + vert.y * t.j.x + vert.z * t.k.x + t.t.x
			Local sy:=vert.x * t.i.y + vert.y * t.j.y + vert.z * t.k.y + t.t.y
			verts[i*2+0]=sx
			verts[i*2+1]=sy
		Next	
		Local iptr:Int Ptr=mesh.tris.Data
		local vptr:Float Ptr=verts.Data
		display.DrawPrimitives(3,mesh.triCount,vptr,8,Null,0,iptr)
	End

End

Class GridSpace
	Field style:IsoSkin
	Field star:Cube
	Field grid:IsoGrid
	Field framecount:Int	
	
	Method New(skin:IsoSkin)
		style=skin
		Clear()
	End
			
	Method Clear()
		star=New Cube(3)
		grid=New IsoGrid(star)
	End
	
	Method Generate(a:Bool,b:Bool,c:Bool,smooth:Int)
		grid.Extrude(a,b,c,smooth)
	End

	Method Mesh()
		grid.Skin()
	end
	
	Field zx:Double
	Field zy:Double
	Field DrawQuadrant:Int
	Field projection:=new Mat4<Float>
	
	Method IsoView(display:Canvas, width:double, height:double, theta:Double, scale:Double)
		zx=Cos(theta)
		zy=Sin(theta)

		local tx:=zx*scale
		local ty:=zy*scale

		display.Matrix=new AffineMat3f(tx,ty*0.5,-ty,tx*0.5,width*0.5,height*0.5)		
	end		

	Const D:=7
	
	Method ProjView(display:Canvas, width:double, height:double, theta:Double, scale:Double)
		display.Matrix=new AffineMat3f()
		
		theta+=Pi/4

		zx=Cos(theta)
		zy=Sin(theta)

		local tx:=zx*scale*D
		local ty:=zy*scale*D

		projection.i.x=-tx
		projection.j.x=0
		projection.k.x=-ty
		projection.t.x=width*0.5

		projection.i.y=-ty/2
		projection.j.y=-scale*D
		projection.k.y=tx/2
		projection.t.y=height*0.5
	End
			
	Method DrawGrid( c:Canvas, width:double, height:double, theta:Double, zoom:Double )		
		c.PushMatrix()
		Local scale:=1.0/zoom
' calulate draw order so we scan grid based inputs from far to near
		Local quadrant:Int=Int(2.5+2*theta/Pi)&3				
		DrawQuadrant=quadrant		

		If grid.skin
			ProjView(c,width,height,theta,scale)
			style.DrawMesh(grid.skin,c,projection)
		Else
			IsoView(c,width,height,theta,scale)
			For Local cube:=Eachin grid.ordered[quadrant]
				style.DrawCube(cube,c,zx,zy,theta)
			Next
		Endif

		c.PopMatrix()
		framecount+=1		
	End	
End
