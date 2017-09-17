' my mojo3d project
' by simon

#Import "<std>"
#Import "<mojo>"
#Import "<mojo3d>"

Using std..
Using mojo..
Using mojo3d..

Class Edge
	Field a:Int
	Field b:Int
	Field index:Int
		
	Method New(a0:int,b0:Int)
		If(a0>b0)
			a=a0
			b=b0
		Else
			a=b0
			b=a0
		End
	End			
End

Class EdgeMap<T> Extends Map<Edge,T>

	Field count:Int

	Method get:Int( e:Edge )
'		Local node:=FindNode( e )
'		Local node:<T>:=
		If Contains(e)
			Return Self[e]	'node.Value
		Endif
		count+=1		
		Set(e,count)
		Return count
	End

	Method Compare:Int(lhs:Edge,rhs:Edge)
		If lhs.a=rhs.a And lhs.b=rhs.b Return 0
		If lhs.a>rhs.a Return 1
		If lhs.a=rhs.a And lhs.b>rhs.b Return 1
		Return -1
	End

End


Class EdgeList
	
	Field edges:=New List<Edge>
					
	Method addTri(v0:int,v1:int,v2:Int)
		edges.AddLast(New Edge(v0,v1))
		edges.AddLast(New Edge(v1,v2))
		edges.AddLast(New Edge(v2,v0))
	End
	
End

Function CopyFloats(src:Float[],dest:Float[],count:Int)
	For Local i:=0 Until count
		dest[i]=src[i]
	Next
End

	
Class Tris
	
	Field verts:Float[]
	Field normals:Float[]
	Field uv:Float[]
	Field tris:Int[]
	
	Method New(numv:int,numn:int,numt:Int)
		verts=New Float[numv*3]
		normals=New Float[numn*3]
		uv=New Float[numn*2]
		tris=New Int[numt*3]
	End

	Method New(verts0:Float[],normals0:Float[],uv0:Float[],tris0:Int[])			
		verts=verts0
		normals=normals0
		uv=uv0
		tris=tris0
	End

	Method New(verts0:Float[],tris0:Int[])			
		
		Local numt:=tris0.Length/3
		Local numv:=numt*3
		
		verts=New Float[numv*3]
		normals=New Float[numv*3]
		tris=New Int[numt*3]
		
		For Local i:=0 Until numt		
			Local v0:=tris0[i*3+0]
			Local v1:=tris0[i*3+1]
			Local v2:=tris0[i*3+2]
			
			verts[i*9+0]=verts0[v0*3+0]
			verts[i*9+1]=verts0[v0*3+1]
			verts[i*9+2]=verts0[v0*3+2]
			
			verts[i*9+3]=verts0[v1*3+0]
			verts[i*9+4]=verts0[v1*3+1]
			verts[i*9+5]=verts0[v1*3+2]

			verts[i*9+6]=verts0[v2*3+0]
			verts[i*9+7]=verts0[v2*3+1]
			verts[i*9+8]=verts0[v2*3+2]
			
			calcNormal(i)
			
			tris[i*3+0]=(i*3+0)
			tris[i*3+1]=(i*3+1)
			tris[i*3+2]=(i*3+2)
		Next
	End
	
	Method GetVerts:Float[]()
		Local n:=verts.Length
		Local t:=New Float[n]
		For Local i:=0 Until n
			t[i]=verts[i]
		Next
		Return t
	End
	
	Method GetTriangles:Float[]()
		Local n:=tris.Length/3
		Local t:=New Float[n*9]
		For Local i:=0 Until n
			Local v0:=tris[i*3+0]
			Local v1:=tris[i*3+1]
			Local v2:=tris[i*3+2]
			t[i*9+0]=verts[v0*3+0]
			t[i*9+1]=verts[v0*3+1]
			t[i*9+2]=verts[v0*3+2]
			t[i*9+3]=verts[v1*3+0]
			t[i*9+4]=verts[v1*3+1]
			t[i*9+5]=verts[v1*3+2]
			t[i*9+6]=verts[v2*3+0]
			t[i*9+7]=verts[v2*3+1]
			t[i*9+8]=verts[v2*3+2]
		Next
		Return t
	End

	Method setVert(index:int,x:Float,y:Float,z:Float)
		verts[index*3+0]=x
		verts[index*3+1]=y
		verts[index*3+2]=z
	End

	Method setUV(index:int,u:Float,v:Float)
		uv[index*2+0]=u
		uv[index*2+1]=v
	End
	
	Method setTri(index:int,v0:int,v1:int,v2:Int)
		tris[index*3+0]=v0
		tris[index*3+1]=v1
		tris[index*3+2]=v2
	End
			
	Method calcNormal(i:Int)
		
		Local ax:Float,ay:Float,az:Float,bx:Float,by:Float,bz:Float,cx:Float,cy:Float,cz:Float
		Local nx:Float,ny:Float,nz:Float
		
		ax=verts[i*9+3]
		ay=verts[i*9+4]
		az=verts[i*9+5]
		
		bx=verts[i*9+0]-ax
		by=verts[i*9+1]-ay
		bz=verts[i*9+2]-az

		cx=verts[i*9+6]-ax
		cy=verts[i*9+7]-ay
		cz=verts[i*9+8]-az
				
		nx=by*cz-bz*cy
		ny=bz*cx-bx*cz			
		nz=bx*cy-by*cx
		
		Local d:Float=Sqrt(nx*nx+ny*ny+nz*nz)

		If d>0 d=1.0/d

		nx*=d
		ny*=d
		nz*=d
		
		normals[i*9+0]=nx
		normals[i*9+1]=ny
		normals[i*9+2]=nz
		
		normals[i*9+3]=nx
		normals[i*9+4]=ny
		normals[i*9+5]=nz

		normals[i*9+6]=nx
		normals[i*9+7]=ny
		normals[i*9+8]=nz
	End
	
	Method setNormal(i:Int,nx:Float,ny:Float,nz:Float)
		Local d:Float=Sqrt(nx*nx+ny*ny+nz*nz)
		If d>0 d=1.0/d
		nx*=d
		ny*=d
		nz*=d
		normals[i*3+0]=nx
		normals[i*3+1]=ny
		normals[i*3+2]=nz			
	End
		
	Global cubeVerts:=New Float[](1.0,1,1, -1,1,1, -1,-1,1, 1,-1,1, 1,1,-1, -1,1,-1, -1,-1,-1, 1,-1,-1)
	
	Global cubeTris:=New Int[](0,1,2, 0,2,3, 4,0,3, 4,3,7, 5,4,7, 5,7,6, 1,5,6, 1,6,2, 4,5,1, 4,1,0, 3,2,6, 3,6,7)
	
	Global cubeUVs:=New Float[](0.0,0.0, 1.0,0.0, 1.0,1.0)

	Function CreateCube:Tris()
		Local cube:=New Tris(cubeVerts,cubeTris)
		Return cube
	End
						
	Function CreateIcosaHedron:Tris()
		
		Local m:=New Tris(12,12,20)		

		Local x3:Float=Sin(math.Pi/3)
		Local y3:Float=Cos(math.Pi/3)
		
		m.setVert(0, 0,1,0)

		For Local p:=0 Until 5
			Local x:Float,z:Float

			x=Sin((p*2)*Pi/5)*x3
			z=Cos((p*2)*Pi/5)*x3				

			m.setVert(1+p, x, y3, z)

			x=Sin((p*2-1)*Pi/5)*x3
			z=Cos((p*2-1)*Pi/5)*x3

			m.setVert(6+p, x, -y3, z)
		Next
		
		m.setVert(11,0,-1,0)

		For Local i:=0 Until 12
			m.setNormal(i,m.verts[i*3+0],m.verts[i*3+1],m.verts[i*3+2])
		Next
					
		m.setTri(0, 0,1,2)
		m.setTri(1, 0,2,3)
		m.setTri(2, 0,3,4)
		m.setTri(3, 0,4,5)
		m.setTri(4, 0,5,1)
		
		m.setTri(5, 1,6,7 )
		m.setTri(6, 2,1,7 )

		m.setTri(7, 2,7,8)
		m.setTri(8, 3,2,8)
		
		m.setTri(9, 3,8,9)			
		m.setTri(10, 4,3,9)
		
		m.setTri(11, 4,9,10)
		m.setTri(12, 5,4,10)
		
		m.setTri(13, 5,10,6)
		m.setTri(14, 1,5,6)
		
		m.setTri(15, 7,6,11)
		m.setTri(16, 8,7,11)
		m.setTri(17, 9,8,11)
		m.setTri(18, 10,9,11)
		m.setTri(19, 6,10,11)
					
		Return m			

	End


	' For every shared edge add a quad
	
	Method Wireframe:Tris(r:Float)
		Local numt:=tris.Length/3
		
		Local edgelist:=New EdgeList()
		
		For Local i:=0 Until numt
					
			Local v0:=tris[i*3+0]
			Local v1:=tris[i*3+1]
			Local v2:=tris[i*3+2]				
			
			edgelist.addTri(v0, v1, v2)
		End
		
		Local nume:=edgelist.edges.Count()
		
		Local numv:=nume*4
		
		Local m:=New Tris(numv,numv,numv/2)
		
		Local n:=0
		
		For Local e:=Eachin edgelist.edges
							
			Local ax:Float,ay:Float,az:Float
			Local bx:Float,by:Float,bz:Float
			
			ax=verts[e.a*3+0]
			ay=verts[e.a*3+1]
			az=verts[e.a*3+2]
			bx=verts[e.b*3+0]
			by=verts[e.b*3+1]
			bz=verts[e.b*3+2]
			
			Local nx:Float,ny:Float,nz:Float
			
			nx=ax+bx
			ny=ay+by
			nz=az+bz
			
			Local d:Float
			
			d=Sqrt(nx*nx+ny*ny+nz*nz)
			
			If d>0 d=1.0/d
			
			nx*=d
			ny*=d
			nz*=d
			
			Local lx:Float,ly:Float,lz:Float

			lx=ax-bx
			ly=ay-by
			lz=az-bz

			d=Sqrt(lx*lx+ly*ly+lz*lz)

			If d>0 d=1.0/d

			lx*=d
			ly*=d
			lz*=d
			
			Local tx:Float,ty:Float,tz:Float

			tx=ny*lz-nz*ly
			ty=nz*lx-nx*lz			
			tz=nx*ly-ny*lx
			
			tx*=r
			ty*=r
			tz*=r
			
			m.setVert(n*4+0,ax-tx,ay-ty,az-tz)
			m.setVert(n*4+1,ax+tx,ay+ty,az+tz)
			m.setVert(n*4+2,bx+tx,by+ty,bz+tz)
			m.setVert(n*4+3,bx-tx,by-ty,bz-tz)
			
			m.setNormal(n*4+0, nx, ny, nz)
			m.setNormal(n*4+1, nx, ny, nz)
			m.setNormal(n*4+2, nx, ny, nz)
			m.setNormal(n*4+3, nx, ny, nz)
			
			m.setTri(n*2+0, n*4+0, n*4+1, n*4+2)
			m.setTri(n*2+1, n*4+0, n*4+2, n*4+3)
			
			n+=1
		Next

		Return m

	End
	
	
	Method Subdivide:Tris()

		Local numt:=tris.Length/3		
		Local numv:=verts.Length/3
		
		Local edges:=New EdgeList()
		
		For Local i:=0 Until numt
			Local v0:=tris[i*3+0]
			Local v1:=tris[i*3+1]
			Local v2:=tris[i*3+2]								
			edges.addTri(v0, v1, v2)
		Next
		
		Local nume:=edges.edges.Count()
					
		Local edgemap:=New EdgeMap<Int>
		
		Local m:=New Tris(numv+nume,numv+nume,numt*4)
		
		CopyFloats(verts,m.verts,3*numv)
		CopyFloats(normals,m.normals,3*numv)

		For Local e:=Eachin edges.edges
			e.index=numv
			numv+=1
			
			edgemap.Set(e,e.index)
							
			Local x:Float,y:Float,z:Float				

			x=(verts[e.a*3+0]+verts[e.b*3+0])/2
			y=(verts[e.a*3+1]+verts[e.b*3+1])/2
			z=(verts[e.a*3+2]+verts[e.b*3+2])/2				
			
			Local d:Float=Sqrt(x*x+y*y+z*z)

			If d>0 d=1.0/d

			m.setVert(e.index, x*d, y*d, z*d)

			x=(normals[e.a*3+0]+normals[e.b*3+0])/2
			y=(normals[e.a*3+1]+normals[e.b*3+1])/2
			z=(normals[e.a*3+2]+normals[e.b*3+2])/2				

			m.setNormal(e.index, x, y, z)
		Next
		
		For Local i:=0 Until numt
							
			Local v0:=tris[i*3+0]
			Local v1:=tris[i*3+1]
			Local v2:=tris[i*3+2]				
			
			Local v3:=edgemap.get(New Edge(v0,v1))
			Local v4:=edgemap.get(New Edge(v1,v2))
			Local v5:=edgemap.get(New Edge(v2,v0))
			
			m.setTri(i*4+0, v0, v3, v5)
			m.setTri(i*4+1, v5, v4, v2)
			m.setTri(i*4+2, v5, v3, v4)
			m.setTri(i*4+3, v3, v1, v4)				
		Next
				
		Return m
	End
	
End


Class Node
	Field name:String
	Field type:String
	Field flags:Int
	Field arg:Node
	
	Method New(name0:String,type0:String,flags0:Int,arg0:Node)
		name=name0
		type=type0
		flags=flags0
		arg=arg0
	End
End

Class Vertex
	Field id:Int
	Field xyz:Float[]
	Field uv:Float[]
	Field rgb:Float[]
	Field surf:int
	Method New(id0:Int,xyz0:Float[],uv0:Float[],rgb0:Float[],surf0:Int)
		id=id0
		xyz=xyz0
		uv=uv0
		rgb=rgb0
		surf=surf0
	End
End

Class Pixels
	Field name:String
	Field width:Int
	Field height:Int
	Field frames:Int
	Field flags:Int
	Field stream:Stream
	Field offset:Int
	
	Method New(name0:String,width0:int,height0:int,frames0:int,flags0:int,stream0:Stream,offset0:int)
		name=name0
		width=width0
		height=height0
		frames=frames0
		flags=flags0
		stream=stream0
		offset=offset0
	End

	Method LoadImage:Image()
'		Local imageflags:=Image.DefaultFlags
		
		Local pixels:=New Int[width*height]
			
		stream.Seek(offset)
		For Local i:=0 Until width*height
			pixels[i]=stream.ReadInt()
		Next

		Local format:=PixelFormat.RGBA32
		Local data:=UByte Ptr(pixels.Data)
		Local pixmap:=New Pixmap(width,height,format,data,width*4)
'		Local image:=CreateImage(width,height,frames,imageflags)
	
		Local image:=New Image(pixmap)

'		image.WritePixels(pixels,0,0,width,height)		
		Return image
	End
	
End

Class Surface

	Field name:String
	Field rgb:Float[]
	Field emissive:Float
	Field alpha:Float
	Field smooth:Float
	Field hasnorm:Bool
	Field tlist:int[]

'	Field indexes[]
'	Field textures:Image[]	
	
	Method New(name0:String,rgb0:Float[],emissive0:Float,alpha0:Float,smooth0:Float,hasnorm0:Bool,tlist0:Int[])
		name=name0
		rgb=rgb0
		emissive=emissive0
		alpha=alpha0
		smooth=smooth0
		hasnorm=hasnorm0
		tlist=tlist0
	End
	
End

Class Geometry
	Field name:String
	Field geom:Geometry
	Field verts:Vertex[]
	Field triangles:Int[]
	
	Field stash:=New IntStack()

	Method New(name0:String,verts0:Vertex[])
		name=name0
		verts=verts0
	End
	
	Method AddTri(surf:int,v0:int,v1:int,v2:int)
		stash.Push(surf)
		stash.Push(v0)
		stash.Push(v1)
		stash.Push(v2)
	End
	
	Method Compile()		
		Local n:=stash.Length/4
		If n=0 Return
		triangles=New Int[n*3]
		For Local i:=0 Until n
			Local v0:=stash.Get(i*4+1)
			Local v1:=stash.Get(i*4+2)
			Local v2:=stash.Get(i*4+3)
			triangles[i*3+0]=v0
			triangles[i*3+1]=v1
			triangles[i*3+2]=v2
		Next
		stash.Clear()
	End
	
	Method GetTris:Tris()
		Compile()
		Local n:=verts.Length
		Local t:=triangles.Length/3
		Local m:=New Tris(n,t,t)
		For Local i:=0 Until n
			Local v:=verts[i]
			m.verts[i*3+0]=v.xyz[0]
			m.verts[i*3+1]=v.xyz[1]
			m.verts[i*3+2]=v.xyz[2]		
'			m.uv[i*2+0]=v.uv[0]
'			m.uv[i*2+1]=v.uv[1]
		Next
		For Local i:=0 Until t
			Local v0:=triangles[i*3+0]
			Local v1:=triangles[i*3+1]
			Local v2:=triangles[i*3+2]			
			m.tris[i*3+0]=v0
			m.tris[i*3+1]=v1
			m.tris[i*3+2]=v2
		Next
		Return m
	End
End

Class Box

	Field _geoms:Geometry[]
	Field _textures:Pixels[]
		
	Method GetTris:Tris(index:Int)
		Return _geoms[index].GetTris()
	End
	
	Method GetTexture:Pixels(texture:Int)
		Return _textures[texture]
	End
				
	Method ModelCount:Int()
		Return _geoms.Length
	End
			
	Method ModelName:String(index:Int)
		Return _geoms[index].name
	End
	
	Method TextureCount:int()
		Return _textures.Length
	End
	
	Method TextureName:String(index:Int)
		Return _textures[index].name
	End

	Field stream:Stream

	Global _buffer:=New Int[1024]

	Method Open(stream0:Stream)
		stream=stream0

		Print "StarterPack is "+stream.Length+" bytes."
		Print ""

		ReadNode()
	End
	
	Method MarkPixels:int(width:int,height:int,frames:Int)		
		Local count:=frames*height*width
		Local position:=stream.Position
		stream.Seek(position+count*4)
		Return position
	End
	
	Method ReadFloat:Float()
		Local f0:Float
		f0=stream.ReadFloat()
		Return f0
	End
	
	Method ReadVector:Float[]()
		Local f0:Float
		Local f1:Float
		Local f2:Float
		f0=stream.ReadFloat()
		f1=stream.ReadFloat()
		f2=stream.ReadFloat()
		Return New Float[](f0,f1,f2)
	End
		
	Method ReadByte:Int()
		Local b0:=stream.ReadByte()
		Return b0
	End

	Method ReadInt:Int()
		Local i0:=stream.ReadInt()
		Return i0
	End
	
	Method ReadString:String()

		Local ch:Int
		Local s0:String
		Local n:=0
		
		While n<1024
			ch=stream.ReadByte()
			_buffer[n]=ch			
			n+=1
			If ch=0 Exit
		Wend
		
		If n>1 s0=String.FromChars(_buffer.Resize(n-1))

		Return s0
	End

	Method ReadUTF8:Int()
		Local b0:int,b1:int,b2:int
		
		b0=stream.ReadByte()

		If b0&$80=0 Return b0
		
		b1=stream.ReadByte()
		
		If (b0&$e0)=$c0 	Return ((b0&$1f)Shl 6) | (b1&$3f)
		
		b2=stream.ReadByte()
		
		Return ((b0&$f)Shl 12) | (( b1&$3f)Shl 6) | (b2&$3f)
		
	End
	
	Method ReadSurf:Surface()
		Local name:=ReadString()
		Local rgb:Float[]=ReadVector()
		
		Local emissive:Float,alpha:Float,smooth:Float,spec:Float
		Local hasnorm:Int,tcount:int
		
		emissive=ReadFloat()
		alpha=ReadFloat()
		smooth=ReadFloat()
		spec=ReadFloat()
		hasnorm=ReadUTF8()
		tcount=ReadUTF8()		
		
		Local tlist:=New Int[tcount]		
		For Local i:=0 Until tcount
			tlist[i]=ReadUTF8()
		Next
		
		Return New Surface(name,rgb,emissive,alpha,smooth,hasnorm,tlist)
'		Print "Surf name="+name		
	End

	Method ReadVertex:Vertex()
		Local id:=ReadUTF8()
		Local xyz:=New Float[3]
		Local uv:=New Float[4]
		Local rgb:=New Float[3]
		
		xyz[0]=GetFloat()
		xyz[1]=GetFloat()
		xyz[2]=GetFloat()

		uv[0]=GetFloat()
		uv[1]=GetFloat()
		uv[2]=GetFloat()
		uv[3]=GetFloat()

		rgb[0]=GetFloat()
		rgb[1]=GetFloat()
		rgb[2]=GetFloat()
		
		Local surfindex:=ReadUTF8()

		Return New Vertex(id,xyz,uv,rgb,surfindex)
	End
	
	Method GetFloat:Float()
		Local index:=ReadUTF8()
		Return _modelFloats[index]
	End
	
	Method ReadSpot()
		Local surf:=ReadUTF8()
		Local vert:=ReadUTF8()
	End

	Method ReadBone()
		Local surf:=ReadUTF8()
		Local b0:=ReadUTF8()
		Local b1:=ReadUTF8()
	End

	Method ReadTri(geom:Geometry)
		Local surf:=ReadUTF8()
		Local v0:=ReadUTF8()
		Local v1:=ReadUTF8()
		Local v2:=ReadUTF8()
		geom.AddTri(surf,v0,v1,v2)
	End

	Method ReadQuad()
		Local surf:=ReadUTF8()
		Local v0:=ReadUTF8()
		Local v1:=ReadUTF8()
		Local v2:=ReadUTF8()
		Local v3:=ReadUTF8()
	End
	
	Field _modelFloats:Float[]
	Field _modelSurfs:Surface[]
	
	Method ReadGeometry:Geometry()
		Local name:String
		Local count:Int
		
		name=ReadString()
		
		count=ReadUTF8()
		_modelSurfs=New Surface[count]
		For Local i:=0 Until count
			_modelSurfs[i]=ReadSurf()
		Next

		Print "Got "+count+" surfaces"

		count=ReadUTF8()
		_modelFloats=New Float[count]
		For Local i:=0 Until count
			_modelFloats[i]=ReadFloat()
		Next
						
		Print "Got "+count +" floats"

		count=ReadUTF8()
		
		Local verts:=New Vertex[count]
		For Local i:=0 Until count
			verts[i]=ReadVertex()
		Next
		Print "Got "+count +" vertex"

		Local geom:=New Geometry(name,verts)

		count=ReadUTF8()
		For Local i:=0 Until count
			ReadSpot()
		Next
		Print "Got "+count +" spots"

		count=ReadUTF8()
		For Local i:=0 Until count
			ReadBone()
		Next
		Print "Got "+count +" bones"

		count=ReadUTF8()
		For Local i:=0 Until count
			ReadTri(geom)
		Next
		Print "Got "+count +" tris"

		count=ReadUTF8()
		For Local i:=0 Until count
			ReadQuad()
		Next
		Print "Got "+count +" quads"
		
		count=ReadUTF8()
		For Local i:=0 Until count
			Print "Reading Model inside "+name
			ReadGeometry()
		Next
		Print "Got "+count +" models"
		Return geom

	End
	
	Method ReadNode:Node()
	
		Local name:String
		Local classname:String
		Local flags:Int
		Local arg:Node
		Local node:Node
		
		name=ReadString()

		If name="" Return null
		
		classname=ReadString()
		flags=ReadUTF8()
				
'		Print "name is "+name+" classname="+classname+" flags="+flags
		
		arg=ReadNode()
		
		Local instance:=ReadByte()
				
		node=New Node(name,classname,flags,arg)
		
		If instance
		
			Select classname
				Case "BOX"
					LoadBox()
					
				Default
					Print "Can't load instance of "+classname
					Return Null
			End
		Endif
		
		While True
			Local kid:=ReadNode		
			If kid=Null Exit 			
		Wend
				
		Return node
		
	End
	
	Field _mapcount:=0
		
	Method LoadPixels:Pixels()

		Local version:=ReadInt()
		Local name:=ReadString()

		Local flags:=ReadUTF8()
		Local frames:=ReadUTF8()
		Local width:=ReadUTF8()
		Local height:=ReadUTF8()
		
		Print " Map:Float"+_mapcount+"  v"+version+"["+flags+"] name="+name+" "+width+"x"+height+"x"+frames
		
		_mapcount+=1
		
		Local offset:=MarkPixels(width,height,frames)
		
		Return New Pixels(name,width,height,frames,flags,stream,offset)
	End
	
	Method LoadBox()
					
		Local mapcount:=ReadUTF8()
		
		Print "MapCount="+mapcount

		_textures=New Pixels[mapcount]
		For Local i:=0 Until mapcount
			_textures[i]=LoadPixels()
		Next	
		
		Local modelcount:=ReadUTF8()
		
		Print "ModelCount="+modelcount

		_geoms=New Geometry[modelcount]
		For Local i:=0 Until modelcount
			_geoms[i]=ReadGeometry()
		Next
					
	End
End

Class Set
	Field scene:Scene
	Field camera:Camera
	Field light:Light
	Field box:Model
	
	Method New()
		scene=Scene.GetCurrent()		
		scene.ClearColor=Color.Sky
		
		camera=New Camera
		camera.Near=.1
		camera.Far=100
		camera.Move(0,10,-10)
		camera.Rotate(20,0,0)
		
		light=New Light
		light.RotateX(90)
		
		Local material:=New PbrMaterial(Color.Yellow,1,0.5)		
		box=Model.CreateBox(New Boxf( -1,1 ),1,1,1,material)
	End

	Method Render(canvas:Canvas)			
		box.Rotate(0,.2,0)		
		scene.Render(canvas,camera)
	end

End

Class AppWindow Extends Window
	Field set:=New Set
	
	Method OnKeyEvent(event:KeyEvent) Override	
		Select event.Type
		Case EventType.KeyDown
			Select event.Key
			Case Key.Escape
				App.Terminate()			
			end
		end
	End
		
	Method OnRender(canvas:Canvas) Override	
		RequestRender()
		set.Render(canvas)
	End
End

Function Main()
	New AppInstance()
	New AppWindow
	App.Run()	
End
