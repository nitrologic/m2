#rem

' 22.06.2016 machine translation of box2d headers to monkey2

class b2ChainShape extends b2Shape
	Method Clear(:)
	Method CreateLoop(vertices:b2Vec2,count:Int)
	Method CreateChain(vertices:b2Vec2,count:Int)
	Method SetPrevVertex(prevVertex:b2Vec2)
	Method SetNextVertex(nextVertex:b2Vec2)
	Method Clone:b2Shape(allocator:b2BlockAllocator)
	Method GetChildCount:Int(:)
	Method GetChildEdge(edge:b2EdgeShape,index:Int)
	Method TestPoint:bool(transform:b2Transform,p:b2Vec2)
	Method RayCast:bool(output:b2RayCastOutput,input:b2RayCastInput)
	Field transform, int32 childIndex):b2Transform&
	Method ComputeAABB(aabb:b2AABB,transform:b2Transform,childIndex:Int)
	Method ComputeMass(massData:b2MassData,density:Float)
	Field m_vertices:b2Vec2
	Field m_count:Int
	Field m_prevVertex, m_nextVertex:b2Vec2
	Field m_hasPrevVertex, m_hasNextVertex:bool
end

class b2CircleShape extends b2Shape
	Method Clone:b2Shape(allocator:b2BlockAllocator)
	Method GetChildCount:Int(:)
	Method TestPoint:bool(transform:b2Transform,p:b2Vec2)
	Method RayCast:bool(output:b2RayCastOutput,input:b2RayCastInput)
	Field transform, int32 childIndex):b2Transform&
	Method ComputeAABB(aabb:b2AABB,transform:b2Transform,childIndex:Int)
	Method ComputeMass(massData:b2MassData,density:Float)
	Method GetSupport:Int(d:b2Vec2)
	Method GetSupportVertex:b2Vec2&(d:b2Vec2)
	Method GetVertexCount:Int(:)
	Method GetVertex:b2Vec2&(index:Int)
	Field m_p:b2Vec2
end

class b2EdgeShape extends b2Shape
	Method Set(v1:b2Vec2,v2:b2Vec2)
	Method Clone:b2Shape(allocator:b2BlockAllocator)
	Method GetChildCount:Int(:)
	Method TestPoint:bool(transform:b2Transform,p:b2Vec2)
	Method RayCast:bool(output:b2RayCastOutput,input:b2RayCastInput)
	Field transform, int32 childIndex):b2Transform&
	Method ComputeAABB(aabb:b2AABB,transform:b2Transform,childIndex:Int)
	Method ComputeMass(massData:b2MassData,density:Float)
	Field m_vertex1, m_vertex2:b2Vec2
	Field m_vertex0, m_vertex3:b2Vec2
	Field m_hasVertex0, m_hasVertex3:bool
end

class b2PolygonShape extends b2Shape
	Method Clone:b2Shape(allocator:b2BlockAllocator)
	Method GetChildCount:Int(:)
	Method Set(points:b2Vec2,count:Int)
	Method SetAsBox(hx:Float,hy:Float)
	Method SetAsBox(hx:Float,hy:Float,center:b2Vec2,angle:Float)
	Method TestPoint:bool(transform:b2Transform,p:b2Vec2)
	Method RayCast:bool(output:b2RayCastOutput,input:b2RayCastInput)
	Field transform, int32 childIndex):b2Transform&
	Method ComputeAABB(aabb:b2AABB,transform:b2Transform,childIndex:Int)
	Method ComputeMass(massData:b2MassData,density:Float)
	Method GetVertexCount:Int(:)
	Method GetVertex:b2Vec2&(index:Int)
	Method Validate:bool(:)
	Field m_centroid:b2Vec2
	Field m_vertices[b2_maxPolygonVertices]:b2Vec2
	Field m_normals[b2_maxPolygonVertices]:b2Vec2
	Field m_count:Int
end

struct b2MassData
	Field mass:Float
	Field center:b2Vec2
	Field I:Float
end

class b2Shape
	Field Type:enum
	Method :~b2Shape()(:)
	Method Clone:b2Shape(allocator:b2BlockAllocator)
	Method GetType:Type(:)
	Method GetChildCount:Int(:)
	Method TestPoint:bool(xf:b2Transform,p:b2Vec2)
	Method RayCast:bool(output:b2RayCastOutput,input:b2RayCastInput)
	Field transform, int32 childIndex) = 0:b2Transform&
	Method ComputeAABB(aabb:b2AABB,xf:b2Transform,childIndex:Int)
	Method ComputeMass(massData:b2MassData,density:Float)
	Field m_type:Type
	Field m_radius:Float
end

struct b2Pair
	Field proxyIdA:Int
	Field proxyIdB:Int
end

class b2BroadPhase
	Method CreateProxy:Int(aabb:b2AABB,userData:void)
	Method DestroyProxy(proxyId:Int)
	Method MoveProxy(proxyId:Int,aabb:b2AABB,displacement:b2Vec2)
	Method TouchProxy(proxyId:Int)
	Method GetFatAABB:b2AABB&(proxyId:Int)
	Method GetUserData(proxyId:Int)
	Method TestOverlap:bool(proxyIdA:Int,proxyIdB:Int)
	Method GetProxyCount:Int(:)
	Field <typename T>:template
	Method UpdatePairs(callback:T)
	Field <typename T>:template
	Method Query(callback:T,aabb:b2AABB)
	Field <typename T>:template
	Method RayCast(callback:T,input:b2RayCastInput)
	Method GetTreeHeight:Int(:)
	Method GetTreeBalance:Int(:)
	Method GetTreeQuality:Float(:)
	Method ShiftOrigin(newOrigin:b2Vec2)
	Field class b2DynamicTree:friend
	Method BufferMove(proxyId:Int)
	Method UnBufferMove(proxyId:Int)
	Method QueryCallback:bool(proxyId:Int)
	Field m_tree:b2DynamicTree
	Field m_proxyCount:Int
	Field m_moveBuffer:Int
	Field m_moveCapacity:Int
	Field m_moveCount:Int
	Field m_pairBuffer:b2Pair
	Field m_pairCapacity:Int
	Field m_pairCount:Int
	Field m_queryProxyId:Int
end

	Field pair = m_pairBuffer + i:b2Pair
	Method :if(!= primaryPair->proxyIdA || pair->proxyIdB != primaryPair->proxyIdB:pair->proxyIdA)
struct b2ContactFeature
	Field Type:enum
	Field indexA:Byte
	Field indexB:Byte
	Field typeA:Byte
	Field typeB:Byte
end

struct b2ManifoldPoint
	Field localPoint:b2Vec2
	Field normalImpulse:Float
	Field tangentImpulse:Float
	Field id:b2ContactID
end

struct b2Manifold
	Field Type:enum
	Field points[b2_maxManifoldPoints]:b2ManifoldPoint
	Field localNormal:b2Vec2
	Field localPoint:b2Vec2
	Field type:Type
	Field pointCount:Int
end

struct b2WorldManifold
	Method Initialize(manifold:b2Manifold)
	Field xfA, float32 radiusA,:b2Transform&
	Field xfB, float32 radiusB):b2Transform&
	Field normal:b2Vec2
	Field points[b2_maxManifoldPoints]:b2Vec2
	Field separations[b2_maxManifoldPoints]:Float
end

struct b2ClipVertex
	Field v:b2Vec2
	Field id:b2ContactID
end

struct b2RayCastInput
	Field p1, p2:b2Vec2
	Field maxFraction:Float
end

struct b2RayCastOutput
	Field normal:b2Vec2
	Field fraction:Float
end

struct b2AABB
	Method IsValid:bool(:)
	Method GetCenter:b2Vec2(:)
	Method GetExtents:b2Vec2(:)
	Method GetPerimeter:Float(:)
	Method Combine(aabb:b2AABB)
	Method Combine(aabb1:b2AABB,aabb2:b2AABB)
	Method Contains:bool(aabb:b2AABB)
	Method RayCast:bool(output:b2RayCastOutput,input:b2RayCastInput)
	Field lowerBound:b2Vec2
	Field upperBound:b2Vec2
end

struct b2DistanceProxy
	Method :b2DistanceProxy()(:)
	Method Set(shape:b2Shape,index:Int)
	Method GetSupport:Int(d:b2Vec2)
	Method GetSupportVertex:b2Vec2&(d:b2Vec2)
	Method GetVertexCount:Int(:)
	Method GetVertex:b2Vec2&(index:Int)
	Field m_buffer[2]:b2Vec2
	Field m_vertices:b2Vec2
	Field m_count:Int
	Field m_radius:Float
end

struct b2SimplexCache
	Field metric:Float
	Field count:uint16
	Field indexA[3]:Byte
	Field indexB[3]:Byte
end

struct b2DistanceInput
	Field proxyA:b2DistanceProxy
	Field proxyB:b2DistanceProxy
	Field transformA:b2Transform
	Field transformB:b2Transform
	Field useRadii:bool
end

struct b2DistanceOutput
	Field pointA:b2Vec2
	Field pointB:b2Vec2
	Field distance:Float
	Field iterations:Int
end

	Field = i:bestIndex
	Field = value:bestValue
	Field = i:bestIndex
	Field = value:bestValue
struct b2TOIInput
	Field proxyA:b2DistanceProxy
	Field proxyB:b2DistanceProxy
	Field sweepA:b2Sweep
	Field sweepB:b2Sweep
	Field tMax:Float
end

struct b2TOIOutput
	Field State:enum
	Field state:State
	Field t:Float
end

class b2BlockAllocator
	Method Allocate(size:Int)
	Method Free(p:void,size:Int)
	Method Clear(:)
	Field m_chunks:b2Chunk
	Field m_chunkCount:Int
	Field m_chunkSpace:Int
	Field m_freeLists[b2_blockSizes]:b2Block
	Field int32 s_blockSizes[b2_blockSizes]:static
	Field uint8 s_blockSizeLookup[b2_maxBlockSize + 1]:static
	Field bool s_blockSizeLookupInitialized:static
end

struct b2Color
	Method :b2Color()(:)
	Method :b2Color(float32(r:Float,g:Float,b:Float,a = 1.0f:Float)
	Method Set(ri:Float,gi:Float,bi:Float,ai = 1.0f:Float)
	Field r, g, b, a:Float
end

class b2Draw
	Method :~b2Draw()(:)
	Method SetFlags(flags:uint32)
	Method GetFlags:uint32(:)
	Method AppendFlags(flags:uint32)
	Method ClearFlags(flags:uint32)
	Method DrawPolygon(vertices:b2Vec2,vertexCount:Int,color:b2Color)
	Method DrawSolidPolygon(vertices:b2Vec2,vertexCount:Int,color:b2Color)
	Method DrawCircle(center:b2Vec2,radius:Float,color:b2Color)
	Method DrawSolidCircle(center:b2Vec2,radius:Float,axis:b2Vec2,color:b2Color)
	Method DrawSegment(p1:b2Vec2,p2:b2Vec2,color:b2Color)
	Method DrawTransform(xf:b2Transform)
	Field m_drawFlags:uint32
end

	Field x:Float
	Field i:Int
	Field convert:}
	Field = x:convert.x
	Field xhalf = 0.5f * x:Float
	Method = 0x5f3759df - :convert.i(>> 1:convert.i)
	Field = convert.x:x
	Method = x * :x(- xhalf * x * x:1.5f)
	Field x:return
struct b2Vec2
	Method :b2Vec2()(:)
	Method :b2Vec2(float32(x:Float,y:Float)
	Method SetZero(:)
	Method Set(x_:Float,y_:Float)
	Method operator -:b2Vec2(:)
	Method operator :Float(:)
	Method operator :float32&(:)
	Method operator += (v:b2Vec2)
	Method operator -= (v:b2Vec2)
	Method operator *= (a:Float)
	Method Length:Float(:)
	Method LengthSquared:Float(:)
	Method Normalize:Float(:)
	Method IsValid:bool(:)
	Method Skew:b2Vec2(:)
	Field x, y:Float
end

struct b2Vec3
	Method :b2Vec3()(:)
	Method :b2Vec3(float32(x:Float,y:Float,z:Float)
	Method SetZero(:)
	Method Set(x_:Float,y_:Float,z_:Float)
	Method operator -:b2Vec3(:)
	Method operator += (v:b2Vec3)
	Method operator -= (v:b2Vec3)
	Method operator *= (s:Float)
	Field x, y, z:Float
end

struct b2Mat22
	Method :b2Mat22()(:)
	Method :b2Mat22(b2Vec2&(c1:b2Vec2,c2:b2Vec2)
	Method :b2Mat22(float32(a11:Float,a12:Float,a21:Float,a22:Float)
	Method Set(c1:b2Vec2,c2:b2Vec2)
	Method SetIdentity(:)
	Method SetZero(:)
	Method GetInverse:b2Mat22(:)
	Method Solve:b2Vec2(b:b2Vec2)
	Field ex, ey:b2Vec2
end

struct b2Mat33
	Method :b2Mat33()(:)
	Method :b2Mat33(b2Vec3&(c1:b2Vec3,c2:b2Vec3,c3:b2Vec3)
	Method SetZero(:)
	Method Solve33:b2Vec3(b:b2Vec3)
	Method Solve22:b2Vec2(b:b2Vec2)
	Method GetInverse22(M:b2Mat33)
	Method GetSymInverse33(M:b2Mat33)
	Field ex, ey, ez:b2Vec3
end

struct b2Rot
	Method :b2Rot()(:)
	Method b2Rot:explicit(angle:Float)
	Method Set(angle:Float)
	Method SetIdentity(:)
	Method GetAngle:Float(:)
	Method GetXAxis:b2Vec2(:)
	Method GetYAxis:b2Vec2(:)
	Field s, c:Float
end

struct b2Transform
	Method :b2Transform()(:)
	Method :b2Transform(b2Vec2&(position:b2Vec2,rotation:b2Rot)
	Method SetIdentity(:)
	Method Set(position:b2Vec2,angle:Float)
	Field p:b2Vec2
	Field q:b2Rot
end

struct b2Sweep
	Method GetTransform(xfb:b2Transform,beta:Float)
	Method Advance(alpha:Float)
	Method Normalize(:)
	Field localCenter:b2Vec2
	Field c0, c:b2Vec2
	Field a0, a:Float
	Field alpha0:Float
end

struct b2Version
	Field major:Int
	Field minor:Int
	Field revision:Int
end

struct b2StackEntry
	Field data:char
	Field size:Int
	Field usedMalloc:bool
end

class b2StackAllocator
	Method Allocate(size:Int)
	Method Free(p:void)
	Method GetMaxAllocation:Int(:)
	Field m_data[b2_stackSize]:char
	Field m_index:Int
	Field m_allocation:Int
	Field m_maxAllocation:Int
	Field m_entries[b2_maxStackEntries]:b2StackEntry
	Field m_entryCount:Int
end

class b2Timer
	Method Reset(:)
	Method GetMilliseconds:Float(:)
	Field m_start:float64
	Field float64 s_invFrequency:static
	Field long m_start_sec:unsigned
	Field long m_start_usec:unsigned
end

class b2ChainAndCircleContact extends b2Contact
	Method b2Contact* Create:static(fixtureA:b2Fixture,indexA:Int)
	Field fixtureB, int32 indexB, b2BlockAllocator* allocator):b2Fixture
	Method void Destroy:static(contact:b2Contact,allocator:b2BlockAllocator)
	Method :b2ChainAndCircleContact(b2Fixture(fixtureA:b2Fixture,indexA:Int,fixtureB:b2Fixture,indexB:Int)
	Method :~b2ChainAndCircleContact()(:)
	Method Evaluate(manifold:b2Manifold,xfA:b2Transform,xfB:b2Transform)
end

class b2ChainAndPolygonContact extends b2Contact
	Method b2Contact* Create:static(fixtureA:b2Fixture,indexA:Int)
	Field fixtureB, int32 indexB, b2BlockAllocator* allocator):b2Fixture
	Method void Destroy:static(contact:b2Contact,allocator:b2BlockAllocator)
	Method :b2ChainAndPolygonContact(b2Fixture(fixtureA:b2Fixture,indexA:Int,fixtureB:b2Fixture,indexB:Int)
	Method :~b2ChainAndPolygonContact()(:)
	Method Evaluate(manifold:b2Manifold,xfA:b2Transform,xfB:b2Transform)
end

class b2CircleContact extends b2Contact
	Method b2Contact* Create:static(fixtureA:b2Fixture,indexA:Int)
	Field fixtureB, int32 indexB, b2BlockAllocator* allocator):b2Fixture
	Method void Destroy:static(contact:b2Contact,allocator:b2BlockAllocator)
	Method :b2CircleContact(b2Fixture(fixtureA:b2Fixture,fixtureB:b2Fixture)
	Method :~b2CircleContact()(:)
	Method Evaluate(manifold:b2Manifold,xfA:b2Transform,xfB:b2Transform)
end

struct b2ContactRegister
	Field createFcn:b2ContactCreateFcn
	Field destroyFcn:b2ContactDestroyFcn
	Field primary:bool
end

struct b2ContactEdge
	Field other:b2Body
	Field contact:b2Contact
	Field prev:b2ContactEdge
	Field next:b2ContactEdge
end

class b2Contact
	Method GetManifold:b2Manifold(:)
	Method GetManifold:b2Manifold(:)
	Method GetWorldManifold(worldManifold:b2WorldManifold)
	Method IsTouching:bool(:)
	Method SetEnabled(flag:bool)
	Method IsEnabled:bool(:)
	Method GetNext:b2Contact(:)
	Method GetNext:b2Contact(:)
	Method GetFixtureA:b2Fixture(:)
	Method GetFixtureA:b2Fixture(:)
	Method GetChildIndexA:Int(:)
	Method GetFixtureB:b2Fixture(:)
	Method GetFixtureB:b2Fixture(:)
	Method GetChildIndexB:Int(:)
	Method SetFriction(friction:Float)
	Method GetFriction:Float(:)
	Method ResetFriction(:)
	Method SetRestitution(restitution:Float)
	Method GetRestitution:Float(:)
	Method ResetRestitution(:)
	Method SetTangentSpeed(speed:Float)
	Method GetTangentSpeed:Float(:)
	Method Evaluate(manifold:b2Manifold,xfA:b2Transform,xfB:b2Transform)
	Field class b2ContactManager:friend
	Field class b2World:friend
	Field class b2ContactSolver:friend
	Field class b2Body:friend
	Field class b2Fixture:friend
	Field Flags stored in m_flags://
	Method FlagForFiltering(:)
	Method void AddType:static(createFcn:b2ContactCreateFcn,destroyFcn:b2ContactDestroyFcn)
	Field typeA, b2Shape::Type typeB):b2Shape::Type
	Method void InitializeRegisters:static(:)
	Method b2Contact* Create:static(fixtureA:b2Fixture,indexA:Int,fixtureB:b2Fixture,indexB:Int,allocator:b2BlockAllocator)
	Method void Destroy:static(contact:b2Contact,typeA:b2Shape::Type,typeB:b2Shape::Type,allocator:b2BlockAllocator)
	Method void Destroy:static(contact:b2Contact,allocator:b2BlockAllocator)
	Method :b2Contact()(:)
	Method :b2Contact(b2Fixture(fixtureA:b2Fixture,indexA:Int,fixtureB:b2Fixture,indexB:Int)
	Method :~b2Contact()(:)
	Method Update(listener:b2ContactListener)
	Field b2ContactRegister s_registers[b2Shape::e_typeCount][b2Shape::e_typeCount]:static
	Field bool s_initialized:static
	Field m_flags:uint32
	Field World pool and list pointers.://
	Field m_prev:b2Contact
	Field m_next:b2Contact
	Field Nodes for connecting bodies.://
	Field m_nodeA:b2ContactEdge
	Field m_nodeB:b2ContactEdge
	Field m_fixtureA:b2Fixture
	Field m_fixtureB:b2Fixture
	Field m_indexA:Int
	Field m_indexB:Int
	Field m_manifold:b2Manifold
	Field m_toiCount:Int
	Field m_toi:Float
	Field m_friction:Float
	Field m_restitution:Float
	Field m_tangentSpeed:Float
end

struct b2VelocityConstraintPoint
	Field rA:b2Vec2
	Field rB:b2Vec2
	Field normalImpulse:Float
	Field tangentImpulse:Float
	Field normalMass:Float
	Field tangentMass:Float
	Field velocityBias:Float
end

struct b2ContactVelocityConstraint
	Field points[b2_maxManifoldPoints]:b2VelocityConstraintPoint
	Field normal:b2Vec2
	Field normalMass:b2Mat22
	Field K:b2Mat22
	Field indexA:Int
	Field indexB:Int
	Field invMassA, invMassB:Float
	Field invIA, invIB:Float
	Field friction:Float
	Field restitution:Float
	Field tangentSpeed:Float
	Field pointCount:Int
	Field contactIndex:Int
end

struct b2ContactSolverDef
	Field step:b2TimeStep
	Field contacts:b2Contact
	Field count:Int
	Field positions:b2Position
	Field velocities:b2Velocity
	Field allocator:b2StackAllocator
end

class b2ContactSolver
	Method :b2ContactSolver(b2ContactSolverDef(def:b2ContactSolverDef)
	Method InitializeVelocityConstraints(:)
	Method WarmStart(:)
	Method SolveVelocityConstraints(:)
	Method StoreImpulses(:)
	Method SolvePositionConstraints:bool(:)
	Method SolveTOIPositionConstraints:bool(toiIndexA:Int,toiIndexB:Int)
	Field m_step:b2TimeStep
	Field m_positions:b2Position
	Field m_velocities:b2Velocity
	Field m_allocator:b2StackAllocator
	Field m_positionConstraints:b2ContactPositionConstraint
	Field m_velocityConstraints:b2ContactVelocityConstraint
	Field m_contacts:b2Contact
	Field m_count:int
end

class b2EdgeAndCircleContact extends b2Contact
	Method b2Contact* Create:static(fixtureA:b2Fixture,indexA:Int)
	Field fixtureB, int32 indexB, b2BlockAllocator* allocator):b2Fixture
	Method void Destroy:static(contact:b2Contact,allocator:b2BlockAllocator)
	Method :b2EdgeAndCircleContact(b2Fixture(fixtureA:b2Fixture,fixtureB:b2Fixture)
	Method :~b2EdgeAndCircleContact()(:)
	Method Evaluate(manifold:b2Manifold,xfA:b2Transform,xfB:b2Transform)
end

class b2EdgeAndPolygonContact extends b2Contact
	Method b2Contact* Create:static(fixtureA:b2Fixture,indexA:Int)
	Field fixtureB, int32 indexB, b2BlockAllocator* allocator):b2Fixture
	Method void Destroy:static(contact:b2Contact,allocator:b2BlockAllocator)
	Method :b2EdgeAndPolygonContact(b2Fixture(fixtureA:b2Fixture,fixtureB:b2Fixture)
	Method :~b2EdgeAndPolygonContact()(:)
	Method Evaluate(manifold:b2Manifold,xfA:b2Transform,xfB:b2Transform)
end

class b2PolygonAndCircleContact extends b2Contact
	Method b2Contact* Create:static(fixtureA:b2Fixture,indexA:Int,fixtureB:b2Fixture,indexB:Int,allocator:b2BlockAllocator)
	Method void Destroy:static(contact:b2Contact,allocator:b2BlockAllocator)
	Method :b2PolygonAndCircleContact(b2Fixture(fixtureA:b2Fixture,fixtureB:b2Fixture)
	Method :~b2PolygonAndCircleContact()(:)
	Method Evaluate(manifold:b2Manifold,xfA:b2Transform,xfB:b2Transform)
end

class b2PolygonContact extends b2Contact
	Method b2Contact* Create:static(fixtureA:b2Fixture,indexA:Int)
	Field fixtureB, int32 indexB, b2BlockAllocator* allocator):b2Fixture
	Method void Destroy:static(contact:b2Contact,allocator:b2BlockAllocator)
	Method :b2PolygonContact(b2Fixture(fixtureA:b2Fixture,fixtureB:b2Fixture)
	Method :~b2PolygonContact()(:)
	Method Evaluate(manifold:b2Manifold,xfA:b2Transform,xfB:b2Transform)
end

struct b2DistanceJointDef extends b2JointDef
	Method Initialize(bodyA:b2Body,bodyB:b2Body)
	Field anchorA, b2Vec2& anchorB):b2Vec2&
	Field localAnchorA:b2Vec2
	Field localAnchorB:b2Vec2
	Field length:Float
	Field frequencyHz:Float
	Field dampingRatio:Float
end

class b2DistanceJoint extends b2Joint
	Method GetAnchorA:b2Vec2(:)
	Method GetAnchorB:b2Vec2(:)
	Method GetReactionForce:b2Vec2(inv_dt:Float)
	Method GetReactionTorque:Float(inv_dt:Float)
	Method GetLocalAnchorA:b2Vec2&(:)
	Method GetLocalAnchorB:b2Vec2&(:)
	Method SetLength(length:Float)
	Method GetLength:Float(:)
	Method SetFrequency(hz:Float)
	Method GetFrequency:Float(:)
	Method SetDampingRatio(ratio:Float)
	Method GetDampingRatio:Float(:)
	Method Dump(:)
	Field class b2Joint:friend
	Method :b2DistanceJoint(b2DistanceJointDef(data:b2DistanceJointDef)
	Method InitVelocityConstraints(data:b2SolverData)
	Method SolveVelocityConstraints(data:b2SolverData)
	Method SolvePositionConstraints:bool(data:b2SolverData)
	Field m_frequencyHz:Float
	Field m_dampingRatio:Float
	Field m_bias:Float
	Field Solver shared://
	Field m_localAnchorA:b2Vec2
	Field m_localAnchorB:b2Vec2
	Field m_gamma:Float
	Field m_impulse:Float
	Field m_length:Float
	Field Solver temp://
	Field m_indexA:Int
	Field m_indexB:Int
	Field m_u:b2Vec2
	Field m_rA:b2Vec2
	Field m_rB:b2Vec2
	Field m_localCenterA:b2Vec2
	Field m_localCenterB:b2Vec2
	Field m_invMassA:Float
	Field m_invMassB:Float
	Field m_invIA:Float
	Field m_invIB:Float
	Field m_mass:Float
end

struct b2FrictionJointDef extends b2JointDef
	Method Initialize(bodyA:b2Body,bodyB:b2Body,anchor:b2Vec2)
	Field localAnchorA:b2Vec2
	Field localAnchorB:b2Vec2
	Field maxForce:Float
	Field maxTorque:Float
end

class b2FrictionJoint extends b2Joint
	Method GetAnchorA:b2Vec2(:)
	Method GetAnchorB:b2Vec2(:)
	Method GetReactionForce:b2Vec2(inv_dt:Float)
	Method GetReactionTorque:Float(inv_dt:Float)
	Method GetLocalAnchorA:b2Vec2&(:)
	Method GetLocalAnchorB:b2Vec2&(:)
	Method SetMaxForce(force:Float)
	Method GetMaxForce:Float(:)
	Method SetMaxTorque(torque:Float)
	Method GetMaxTorque:Float(:)
	Method Dump(:)
	Field class b2Joint:friend
	Method :b2FrictionJoint(b2FrictionJointDef(def:b2FrictionJointDef)
	Method InitVelocityConstraints(data:b2SolverData)
	Method SolveVelocityConstraints(data:b2SolverData)
	Method SolvePositionConstraints:bool(data:b2SolverData)
	Field m_localAnchorA:b2Vec2
	Field m_localAnchorB:b2Vec2
	Field Solver shared://
	Field m_linearImpulse:b2Vec2
	Field m_angularImpulse:Float
	Field m_maxForce:Float
	Field m_maxTorque:Float
	Field Solver temp://
	Field m_indexA:Int
	Field m_indexB:Int
	Field m_rA:b2Vec2
	Field m_rB:b2Vec2
	Field m_localCenterA:b2Vec2
	Field m_localCenterB:b2Vec2
	Field m_invMassA:Float
	Field m_invMassB:Float
	Field m_invIA:Float
	Field m_invIB:Float
	Field m_linearMass:b2Mat22
	Field m_angularMass:Float
end

struct b2GearJointDef extends b2JointDef
	Field joint1:b2Joint
	Field joint2:b2Joint
	Field ratio:Float
end

class b2GearJoint extends b2Joint
	Method GetAnchorA:b2Vec2(:)
	Method GetAnchorB:b2Vec2(:)
	Method GetReactionForce:b2Vec2(inv_dt:Float)
	Method GetReactionTorque:Float(inv_dt:Float)
	Method GetJoint1:b2Joint(:)
	Method GetJoint2:b2Joint(:)
	Method SetRatio(ratio:Float)
	Method GetRatio:Float(:)
	Method Dump(:)
	Field class b2Joint:friend
	Method :b2GearJoint(b2GearJointDef(data:b2GearJointDef)
	Method InitVelocityConstraints(data:b2SolverData)
	Method SolveVelocityConstraints(data:b2SolverData)
	Method SolvePositionConstraints:bool(data:b2SolverData)
	Field m_joint1:b2Joint
	Field m_joint2:b2Joint
	Field m_typeA:b2JointType
	Field m_typeB:b2JointType
	Field Body A is connected to body C://
	Field Body B is connected to body D://
	Field m_bodyC:b2Body
	Field m_bodyD:b2Body
	Field Solver shared://
	Field m_localAnchorA:b2Vec2
	Field m_localAnchorB:b2Vec2
	Field m_localAnchorC:b2Vec2
	Field m_localAnchorD:b2Vec2
	Field m_localAxisC:b2Vec2
	Field m_localAxisD:b2Vec2
	Field m_referenceAngleA:Float
	Field m_referenceAngleB:Float
	Field m_constant:Float
	Field m_ratio:Float
	Field m_impulse:Float
	Field Solver temp://
	Field m_indexA, m_indexB, m_indexC, m_indexD:Int
	Field m_lcA, m_lcB, m_lcC, m_lcD:b2Vec2
	Field m_mA, m_mB, m_mC, m_mD:Float
	Field m_iA, m_iB, m_iC, m_iD:Float
	Field m_JvAC, m_JvBD:b2Vec2
	Field m_JwA, m_JwB, m_JwC, m_JwD:Float
	Field m_mass:Float
end

struct b2Jacobian
	Field linear:b2Vec2
	Field angularA:Float
	Field angularB:Float
end

struct b2JointEdge
	Field other:b2Body
	Field joint:b2Joint
	Field prev:b2JointEdge
	Field next:b2JointEdge
end

struct b2JointDef
	Field type:b2JointType
	Field userData
	Field bodyA:b2Body
	Field bodyB:b2Body
	Field collideConnected:bool
end

class b2Joint
	Method GetType:b2JointType(:)
	Method GetBodyA:b2Body(:)
	Method GetBodyB:b2Body(:)
	Method GetAnchorA:b2Vec2(:)
	Method GetAnchorB:b2Vec2(:)
	Method GetReactionForce:b2Vec2(inv_dt:Float)
	Method GetReactionTorque:Float(inv_dt:Float)
	Method GetNext:b2Joint(:)
	Method GetNext:b2Joint(:)
	Method GetUserData(:)
	Method SetUserData(data:void)
	Method IsActive:bool(:)
	Method GetCollideConnected:bool(:)
	Method Dump(:)
	Method ShiftOrigin(newOrigin:b2Vec2)
	Field class b2World:friend
	Field class b2Body:friend
	Field class b2Island:friend
	Field class b2GearJoint:friend
	Method b2Joint* Create:static(def:b2JointDef,allocator:b2BlockAllocator)
	Method void Destroy:static(joint:b2Joint,allocator:b2BlockAllocator)
	Method :b2Joint(b2JointDef(def:b2JointDef)
	Method :~b2Joint()(:)
	Method InitVelocityConstraints(data:b2SolverData)
	Method SolveVelocityConstraints(data:b2SolverData)
	Field This returns true if the position errors are within tolerance.://
	Method SolvePositionConstraints:bool(data:b2SolverData)
	Field m_type:b2JointType
	Field m_prev:b2Joint
	Field m_next:b2Joint
	Field m_edgeA:b2JointEdge
	Field m_edgeB:b2JointEdge
	Field m_bodyA:b2Body
	Field m_bodyB:b2Body
	Field m_index:Int
	Field m_islandFlag:bool
	Field m_collideConnected:bool
	Field m_userData
end

struct b2MotorJointDef extends b2JointDef
	Method Initialize(bodyA:b2Body,bodyB:b2Body)
	Field linearOffset:b2Vec2
	Field angularOffset:Float
	Field maxForce:Float
	Field maxTorque:Float
	Field correctionFactor:Float
end

class b2MotorJoint extends b2Joint
	Method GetAnchorA:b2Vec2(:)
	Method GetAnchorB:b2Vec2(:)
	Method GetReactionForce:b2Vec2(inv_dt:Float)
	Method GetReactionTorque:Float(inv_dt:Float)
	Method SetLinearOffset(linearOffset:b2Vec2)
	Method GetLinearOffset:b2Vec2&(:)
	Method SetAngularOffset(angularOffset:Float)
	Method GetAngularOffset:Float(:)
	Method SetMaxForce(force:Float)
	Method GetMaxForce:Float(:)
	Method SetMaxTorque(torque:Float)
	Method GetMaxTorque:Float(:)
	Method SetCorrectionFactor(factor:Float)
	Method GetCorrectionFactor:Float(:)
	Method Dump(:)
	Field class b2Joint:friend
	Method :b2MotorJoint(b2MotorJointDef(def:b2MotorJointDef)
	Method InitVelocityConstraints(data:b2SolverData)
	Method SolveVelocityConstraints(data:b2SolverData)
	Method SolvePositionConstraints:bool(data:b2SolverData)
	Field Solver shared://
	Field m_linearOffset:b2Vec2
	Field m_angularOffset:Float
	Field m_linearImpulse:b2Vec2
	Field m_angularImpulse:Float
	Field m_maxForce:Float
	Field m_maxTorque:Float
	Field m_correctionFactor:Float
	Field Solver temp://
	Field m_indexA:Int
	Field m_indexB:Int
	Field m_rA:b2Vec2
	Field m_rB:b2Vec2
	Field m_localCenterA:b2Vec2
	Field m_localCenterB:b2Vec2
	Field m_linearError:b2Vec2
	Field m_angularError:Float
	Field m_invMassA:Float
	Field m_invMassB:Float
	Field m_invIA:Float
	Field m_invIB:Float
	Field m_linearMass:b2Mat22
	Field m_angularMass:Float
end

struct b2MouseJointDef extends b2JointDef
	Field target:b2Vec2
	Field maxForce:Float
	Field frequencyHz:Float
	Field dampingRatio:Float
end

class b2MouseJoint extends b2Joint
	Method GetAnchorA:b2Vec2(:)
	Method GetAnchorB:b2Vec2(:)
	Method GetReactionForce:b2Vec2(inv_dt:Float)
	Method GetReactionTorque:Float(inv_dt:Float)
	Method SetTarget(target:b2Vec2)
	Method GetTarget:b2Vec2&(:)
	Method SetMaxForce(force:Float)
	Method GetMaxForce:Float(:)
	Method SetFrequency(hz:Float)
	Method GetFrequency:Float(:)
	Method SetDampingRatio(ratio:Float)
	Method GetDampingRatio:Float(:)
	Method Dump(:)
	Method ShiftOrigin(newOrigin:b2Vec2)
	Field class b2Joint:friend
	Method :b2MouseJoint(b2MouseJointDef(def:b2MouseJointDef)
	Method InitVelocityConstraints(data:b2SolverData)
	Method SolveVelocityConstraints(data:b2SolverData)
	Method SolvePositionConstraints:bool(data:b2SolverData)
	Field m_localAnchorB:b2Vec2
	Field m_targetA:b2Vec2
	Field m_frequencyHz:Float
	Field m_dampingRatio:Float
	Field m_beta:Float
	Field Solver shared://
	Field m_impulse:b2Vec2
	Field m_maxForce:Float
	Field m_gamma:Float
	Field Solver temp://
	Field m_indexA:Int
	Field m_indexB:Int
	Field m_rB:b2Vec2
	Field m_localCenterB:b2Vec2
	Field m_invMassB:Float
	Field m_invIB:Float
	Field m_mass:b2Mat22
	Field m_C:b2Vec2
end

struct b2PrismaticJointDef extends b2JointDef
	Method Initialize(bodyA:b2Body,bodyB:b2Body,anchor:b2Vec2,axis:b2Vec2)
	Field localAnchorA:b2Vec2
	Field localAnchorB:b2Vec2
	Field localAxisA:b2Vec2
	Field referenceAngle:Float
	Field enableLimit:bool
	Field lowerTranslation:Float
	Field upperTranslation:Float
	Field enableMotor:bool
	Field maxMotorForce:Float
	Field motorSpeed:Float
end

class b2PrismaticJoint extends b2Joint
	Method GetAnchorA:b2Vec2(:)
	Method GetAnchorB:b2Vec2(:)
	Method GetReactionForce:b2Vec2(inv_dt:Float)
	Method GetReactionTorque:Float(inv_dt:Float)
	Method GetLocalAnchorA:b2Vec2&(:)
	Method GetLocalAnchorB:b2Vec2&(:)
	Method GetLocalAxisA:b2Vec2&(:)
	Method GetReferenceAngle:Float(:)
	Method GetJointTranslation:Float(:)
	Method GetJointSpeed:Float(:)
	Method IsLimitEnabled:bool(:)
	Method EnableLimit(flag:bool)
	Method GetLowerLimit:Float(:)
	Method GetUpperLimit:Float(:)
	Method SetLimits(lower:Float,upper:Float)
	Method IsMotorEnabled:bool(:)
	Method EnableMotor(flag:bool)
	Method SetMotorSpeed(speed:Float)
	Method GetMotorSpeed:Float(:)
	Method SetMaxMotorForce(force:Float)
	Method GetMaxMotorForce:Float(:)
	Method GetMotorForce:Float(inv_dt:Float)
	Method Dump(:)
	Field class b2Joint:friend
	Field class b2GearJoint:friend
	Method :b2PrismaticJoint(b2PrismaticJointDef(def:b2PrismaticJointDef)
	Method InitVelocityConstraints(data:b2SolverData)
	Method SolveVelocityConstraints(data:b2SolverData)
	Method SolvePositionConstraints:bool(data:b2SolverData)
	Field Solver shared://
	Field m_localAnchorA:b2Vec2
	Field m_localAnchorB:b2Vec2
	Field m_localXAxisA:b2Vec2
	Field m_localYAxisA:b2Vec2
	Field m_referenceAngle:Float
	Field m_impulse:b2Vec3
	Field m_motorImpulse:Float
	Field m_lowerTranslation:Float
	Field m_upperTranslation:Float
	Field m_maxMotorForce:Float
	Field m_motorSpeed:Float
	Field m_enableLimit:bool
	Field m_enableMotor:bool
	Field m_limitState:b2LimitState
	Field Solver temp://
	Field m_indexA:Int
	Field m_indexB:Int
	Field m_localCenterA:b2Vec2
	Field m_localCenterB:b2Vec2
	Field m_invMassA:Float
	Field m_invMassB:Float
	Field m_invIA:Float
	Field m_invIB:Float
	Field m_axis, m_perp:b2Vec2
	Field m_s1, m_s2:Float
	Field m_a1, m_a2:Float
	Field m_K:b2Mat33
	Field m_motorMass:Float
end

struct b2PulleyJointDef extends b2JointDef
	Method Initialize(bodyA:b2Body,bodyB:b2Body)
	Field groundAnchorA, b2Vec2& groundAnchorB,:b2Vec2&
	Field anchorA, b2Vec2& anchorB,:b2Vec2&
	Field ratio):Float
	Field groundAnchorA:b2Vec2
	Field groundAnchorB:b2Vec2
	Field localAnchorA:b2Vec2
	Field localAnchorB:b2Vec2
	Field lengthA:Float
	Field lengthB:Float
	Field ratio:Float
end

class b2PulleyJoint extends b2Joint
	Method GetAnchorA:b2Vec2(:)
	Method GetAnchorB:b2Vec2(:)
	Method GetReactionForce:b2Vec2(inv_dt:Float)
	Method GetReactionTorque:Float(inv_dt:Float)
	Method GetGroundAnchorA:b2Vec2(:)
	Method GetGroundAnchorB:b2Vec2(:)
	Method GetLengthA:Float(:)
	Method GetLengthB:Float(:)
	Method GetRatio:Float(:)
	Method GetCurrentLengthA:Float(:)
	Method GetCurrentLengthB:Float(:)
	Method Dump(:)
	Method ShiftOrigin(newOrigin:b2Vec2)
	Field class b2Joint:friend
	Method :b2PulleyJoint(b2PulleyJointDef(data:b2PulleyJointDef)
	Method InitVelocityConstraints(data:b2SolverData)
	Method SolveVelocityConstraints(data:b2SolverData)
	Method SolvePositionConstraints:bool(data:b2SolverData)
	Field m_groundAnchorA:b2Vec2
	Field m_groundAnchorB:b2Vec2
	Field m_lengthA:Float
	Field m_lengthB:Float
	Field Solver shared://
	Field m_localAnchorA:b2Vec2
	Field m_localAnchorB:b2Vec2
	Field m_constant:Float
	Field m_ratio:Float
	Field m_impulse:Float
	Field Solver temp://
	Field m_indexA:Int
	Field m_indexB:Int
	Field m_uA:b2Vec2
	Field m_uB:b2Vec2
	Field m_rA:b2Vec2
	Field m_rB:b2Vec2
	Field m_localCenterA:b2Vec2
	Field m_localCenterB:b2Vec2
	Field m_invMassA:Float
	Field m_invMassB:Float
	Field m_invIA:Float
	Field m_invIB:Float
	Field m_mass:Float
end

struct b2RevoluteJointDef extends b2JointDef
	Method Initialize(bodyA:b2Body,bodyB:b2Body,anchor:b2Vec2)
	Field localAnchorA:b2Vec2
	Field localAnchorB:b2Vec2
	Field referenceAngle:Float
	Field enableLimit:bool
	Field lowerAngle:Float
	Field upperAngle:Float
	Field enableMotor:bool
	Field motorSpeed:Float
	Field maxMotorTorque:Float
end

class b2RevoluteJoint extends b2Joint
	Method GetAnchorA:b2Vec2(:)
	Method GetAnchorB:b2Vec2(:)
	Method GetLocalAnchorA:b2Vec2&(:)
	Method GetLocalAnchorB:b2Vec2&(:)
	Method GetReferenceAngle:Float(:)
	Method GetJointAngle:Float(:)
	Method GetJointSpeed:Float(:)
	Method IsLimitEnabled:bool(:)
	Method EnableLimit(flag:bool)
	Method GetLowerLimit:Float(:)
	Method GetUpperLimit:Float(:)
	Method SetLimits(lower:Float,upper:Float)
	Method IsMotorEnabled:bool(:)
	Method EnableMotor(flag:bool)
	Method SetMotorSpeed(speed:Float)
	Method GetMotorSpeed:Float(:)
	Method SetMaxMotorTorque(torque:Float)
	Method GetMaxMotorTorque:Float(:)
	Method GetReactionForce:b2Vec2(inv_dt:Float)
	Method GetReactionTorque:Float(inv_dt:Float)
	Method GetMotorTorque:Float(inv_dt:Float)
	Method Dump(:)
	Field class b2Joint:friend
	Field class b2GearJoint:friend
	Method :b2RevoluteJoint(b2RevoluteJointDef(def:b2RevoluteJointDef)
	Method InitVelocityConstraints(data:b2SolverData)
	Method SolveVelocityConstraints(data:b2SolverData)
	Method SolvePositionConstraints:bool(data:b2SolverData)
	Field Solver shared://
	Field m_localAnchorA:b2Vec2
	Field m_localAnchorB:b2Vec2
	Field m_impulse:b2Vec3
	Field m_motorImpulse:Float
	Field m_enableMotor:bool
	Field m_maxMotorTorque:Float
	Field m_motorSpeed:Float
	Field m_enableLimit:bool
	Field m_referenceAngle:Float
	Field m_lowerAngle:Float
	Field m_upperAngle:Float
	Field Solver temp://
	Field m_indexA:Int
	Field m_indexB:Int
	Field m_rA:b2Vec2
	Field m_rB:b2Vec2
	Field m_localCenterA:b2Vec2
	Field m_localCenterB:b2Vec2
	Field m_invMassA:Float
	Field m_invMassB:Float
	Field m_invIA:Float
	Field m_invIB:Float
	Field m_mass:b2Mat33
	Field m_motorMass:Float
	Field m_limitState:b2LimitState
end

struct b2RopeJointDef extends b2JointDef
	Field localAnchorA:b2Vec2
	Field localAnchorB:b2Vec2
	Field maxLength:Float
end

class b2RopeJoint extends b2Joint
	Method GetAnchorA:b2Vec2(:)
	Method GetAnchorB:b2Vec2(:)
	Method GetReactionForce:b2Vec2(inv_dt:Float)
	Method GetReactionTorque:Float(inv_dt:Float)
	Method GetLocalAnchorA:b2Vec2&(:)
	Method GetLocalAnchorB:b2Vec2&(:)
	Method SetMaxLength(length:Float)
	Method GetMaxLength:Float(:)
	Method GetLimitState:b2LimitState(:)
	Method Dump(:)
	Field class b2Joint:friend
	Method :b2RopeJoint(b2RopeJointDef(data:b2RopeJointDef)
	Method InitVelocityConstraints(data:b2SolverData)
	Method SolveVelocityConstraints(data:b2SolverData)
	Method SolvePositionConstraints:bool(data:b2SolverData)
	Field Solver shared://
	Field m_localAnchorA:b2Vec2
	Field m_localAnchorB:b2Vec2
	Field m_maxLength:Float
	Field m_length:Float
	Field m_impulse:Float
	Field Solver temp://
	Field m_indexA:Int
	Field m_indexB:Int
	Field m_u:b2Vec2
	Field m_rA:b2Vec2
	Field m_rB:b2Vec2
	Field m_localCenterA:b2Vec2
	Field m_localCenterB:b2Vec2
	Field m_invMassA:Float
	Field m_invMassB:Float
	Field m_invIA:Float
	Field m_invIB:Float
	Field m_mass:Float
	Field m_state:b2LimitState
end

struct b2WeldJointDef extends b2JointDef
	Method Initialize(bodyA:b2Body,bodyB:b2Body,anchor:b2Vec2)
	Field localAnchorA:b2Vec2
	Field localAnchorB:b2Vec2
	Field referenceAngle:Float
	Field frequencyHz:Float
	Field dampingRatio:Float
end

class b2WeldJoint extends b2Joint
	Method GetAnchorA:b2Vec2(:)
	Method GetAnchorB:b2Vec2(:)
	Method GetReactionForce:b2Vec2(inv_dt:Float)
	Method GetReactionTorque:Float(inv_dt:Float)
	Method GetLocalAnchorA:b2Vec2&(:)
	Method GetLocalAnchorB:b2Vec2&(:)
	Method GetReferenceAngle:Float(:)
	Method SetFrequency(hz:Float)
	Method GetFrequency:Float(:)
	Method SetDampingRatio(ratio:Float)
	Method GetDampingRatio:Float(:)
	Method Dump(:)
	Field class b2Joint:friend
	Method :b2WeldJoint(b2WeldJointDef(def:b2WeldJointDef)
	Method InitVelocityConstraints(data:b2SolverData)
	Method SolveVelocityConstraints(data:b2SolverData)
	Method SolvePositionConstraints:bool(data:b2SolverData)
	Field m_frequencyHz:Float
	Field m_dampingRatio:Float
	Field m_bias:Float
	Field Solver shared://
	Field m_localAnchorA:b2Vec2
	Field m_localAnchorB:b2Vec2
	Field m_referenceAngle:Float
	Field m_gamma:Float
	Field m_impulse:b2Vec3
	Field Solver temp://
	Field m_indexA:Int
	Field m_indexB:Int
	Field m_rA:b2Vec2
	Field m_rB:b2Vec2
	Field m_localCenterA:b2Vec2
	Field m_localCenterB:b2Vec2
	Field m_invMassA:Float
	Field m_invMassB:Float
	Field m_invIA:Float
	Field m_invIB:Float
	Field m_mass:b2Mat33
end

struct b2WheelJointDef extends b2JointDef
	Method Initialize(bodyA:b2Body,bodyB:b2Body,anchor:b2Vec2,axis:b2Vec2)
	Field localAnchorA:b2Vec2
	Field localAnchorB:b2Vec2
	Field localAxisA:b2Vec2
	Field enableMotor:bool
	Field maxMotorTorque:Float
	Field motorSpeed:Float
	Field frequencyHz:Float
	Field dampingRatio:Float
end

class b2WheelJoint extends b2Joint
	Method GetAnchorA:b2Vec2(:)
	Method GetAnchorB:b2Vec2(:)
	Method GetReactionForce:b2Vec2(inv_dt:Float)
	Method GetReactionTorque:Float(inv_dt:Float)
	Method GetLocalAnchorA:b2Vec2&(:)
	Method GetLocalAnchorB:b2Vec2&(:)
	Method GetLocalAxisA:b2Vec2&(:)
	Method GetJointTranslation:Float(:)
	Method GetJointSpeed:Float(:)
	Method IsMotorEnabled:bool(:)
	Method EnableMotor(flag:bool)
	Method SetMotorSpeed(speed:Float)
	Method GetMotorSpeed:Float(:)
	Method SetMaxMotorTorque(torque:Float)
	Method GetMaxMotorTorque:Float(:)
	Method GetMotorTorque:Float(inv_dt:Float)
	Method SetSpringFrequencyHz(hz:Float)
	Method GetSpringFrequencyHz:Float(:)
	Method SetSpringDampingRatio(ratio:Float)
	Method GetSpringDampingRatio:Float(:)
	Method Dump(:)
	Field class b2Joint:friend
	Method :b2WheelJoint(b2WheelJointDef(def:b2WheelJointDef)
	Method InitVelocityConstraints(data:b2SolverData)
	Method SolveVelocityConstraints(data:b2SolverData)
	Method SolvePositionConstraints:bool(data:b2SolverData)
	Field m_frequencyHz:Float
	Field m_dampingRatio:Float
	Field Solver shared://
	Field m_localAnchorA:b2Vec2
	Field m_localAnchorB:b2Vec2
	Field m_localXAxisA:b2Vec2
	Field m_localYAxisA:b2Vec2
	Field m_impulse:Float
	Field m_motorImpulse:Float
	Field m_springImpulse:Float
	Field m_maxMotorTorque:Float
	Field m_motorSpeed:Float
	Field m_enableMotor:bool
	Field Solver temp://
	Field m_indexA:Int
	Field m_indexB:Int
	Field m_localCenterA:b2Vec2
	Field m_localCenterB:b2Vec2
	Field m_invMassA:Float
	Field m_invMassB:Float
	Field m_invIA:Float
	Field m_invIB:Float
	Field m_ax, m_ay:b2Vec2
	Field m_sAx, m_sBx:Float
	Field m_sAy, m_sBy:Float
	Field m_mass:Float
	Field m_motorMass:Float
	Field m_springMass:Float
	Field m_bias:Float
	Field m_gamma:Float
end

struct b2BodyDef
	Field type:b2BodyType
	Field position:b2Vec2
	Field angle:Float
	Field linearVelocity:b2Vec2
	Field angularVelocity:Float
	Field linearDamping:Float
	Field angularDamping:Float
	Field allowSleep:bool
	Field awake:bool
	Field fixedRotation:bool
	Field bullet:bool
	Field active:bool
	Field userData
	Field gravityScale:Float
end

class b2Body
	Method CreateFixture:b2Fixture(def:b2FixtureDef)
	Method CreateFixture:b2Fixture(shape:b2Shape,density:Float)
	Method DestroyFixture(fixture:b2Fixture)
	Method SetTransform(position:b2Vec2,angle:Float)
	Method GetTransform:b2Transform&(:)
	Method GetPosition:b2Vec2&(:)
	Method GetAngle:Float(:)
	Method GetWorldCenter:b2Vec2&(:)
	Method GetLocalCenter:b2Vec2&(:)
	Method SetLinearVelocity(v:b2Vec2)
	Method GetLinearVelocity:b2Vec2&(:)
	Method SetAngularVelocity(omega:Float)
	Method GetAngularVelocity:Float(:)
	Method ApplyForce(force:b2Vec2,point:b2Vec2,wake:bool)
	Method ApplyForceToCenter(force:b2Vec2,wake:bool)
	Method ApplyTorque(torque:Float,wake:bool)
	Method ApplyLinearImpulse(impulse:b2Vec2,point:b2Vec2,wake:bool)
	Method ApplyAngularImpulse(impulse:Float,wake:bool)
	Method GetMass:Float(:)
	Method GetInertia:Float(:)
	Method GetMassData(data:b2MassData)
	Method SetMassData(data:b2MassData)
	Method ResetMassData(:)
	Method GetWorldPoint:b2Vec2(localPoint:b2Vec2)
	Method GetWorldVector:b2Vec2(localVector:b2Vec2)
	Method GetLocalPoint:b2Vec2(worldPoint:b2Vec2)
	Method GetLocalVector:b2Vec2(worldVector:b2Vec2)
	Method GetLinearVelocityFromWorldPoint:b2Vec2(worldPoint:b2Vec2)
	Method GetLinearVelocityFromLocalPoint:b2Vec2(localPoint:b2Vec2)
	Method GetLinearDamping:Float(:)
	Method SetLinearDamping(linearDamping:Float)
	Method GetAngularDamping:Float(:)
	Method SetAngularDamping(angularDamping:Float)
	Method GetGravityScale:Float(:)
	Method SetGravityScale(scale:Float)
	Method SetType(type:b2BodyType)
	Method GetType:b2BodyType(:)
	Method SetBullet(flag:bool)
	Method IsBullet:bool(:)
	Method SetSleepingAllowed(flag:bool)
	Method IsSleepingAllowed:bool(:)
	Method SetAwake(flag:bool)
	Method IsAwake:bool(:)
	Method SetActive(flag:bool)
	Method IsActive:bool(:)
	Method SetFixedRotation(flag:bool)
	Method IsFixedRotation:bool(:)
	Method GetFixtureList:b2Fixture(:)
	Method GetFixtureList:b2Fixture(:)
	Method GetJointList:b2JointEdge(:)
	Method GetJointList:b2JointEdge(:)
	Method GetContactList:b2ContactEdge(:)
	Method GetContactList:b2ContactEdge(:)
	Method GetNext:b2Body(:)
	Method GetNext:b2Body(:)
	Method GetUserData(:)
	Method SetUserData(data:void)
	Method GetWorld:b2World(:)
	Method GetWorld:b2World(:)
	Method Dump(:)
	Field class b2World:friend
	Field class b2Island:friend
	Field class b2ContactManager:friend
	Field class b2ContactSolver:friend
	Field class b2Contact:friend
	Field class b2DistanceJoint:friend
	Field class b2FrictionJoint:friend
	Field class b2GearJoint:friend
	Field class b2MotorJoint:friend
	Field class b2MouseJoint:friend
	Field class b2PrismaticJoint:friend
	Field class b2PulleyJoint:friend
	Field class b2RevoluteJoint:friend
	Field class b2RopeJoint:friend
	Field class b2WeldJoint:friend
	Field class b2WheelJoint:friend
	Field m_flags://
	Method :b2Body(b2BodyDef(bd:b2BodyDef,world:b2World)
	Method SynchronizeFixtures(:)
	Method SynchronizeTransform(:)
	Field This is used to prevent connected bodies from colliding.://
	Field It may lie, depending on the collideConnected flag.://
	Method ShouldCollide:bool(other:b2Body)
	Method Advance(t:Float)
	Field m_type:b2BodyType
	Field m_flags:uint16
	Field m_islandIndex:Int
	Field m_xf:b2Transform
	Field m_sweep:b2Sweep
	Field m_linearVelocity:b2Vec2
	Field m_angularVelocity:Float
	Field m_force:b2Vec2
	Field m_torque:Float
	Field m_world:b2World
	Field m_prev:b2Body
	Field m_next:b2Body
	Field m_fixtureList:b2Fixture
	Field m_fixtureCount:Int
	Field m_jointList:b2JointEdge
	Field m_contactList:b2ContactEdge
	Field m_mass, m_invMass:Float
	Field Rotational inertia about the center of mass.://
	Field m_I, m_invI:Float
	Field m_linearDamping:Float
	Field m_angularDamping:Float
	Field m_gravityScale:Float
	Field m_sleepTime:Float
	Field m_userData
end

	Field |= e_awakeFlag:m_flags
	Field = 0.0f:m_sleepTime
class b2ContactManager
	Field Broad-phase callback.://
	Method AddPair(proxyUserDataA:void,proxyUserDataB:void)
	Method FindNewContacts(:)
	Method Destroy(c:b2Contact)
	Method Collide(:)
	Field m_broadPhase:b2BroadPhase
	Field m_contactList:b2Contact
	Field m_contactCount:Int
	Field m_contactFilter:b2ContactFilter
	Field m_contactListener:b2ContactListener
	Field m_allocator:b2BlockAllocator
end

struct b2Filter
	Field categoryBits:uint16
	Field maskBits:uint16
	Field groupIndex:int16
end

struct b2FixtureDef
	Field shape:b2Shape
	Field userData
	Field friction:Float
	Field restitution:Float
	Field density:Float
	Field isSensor:bool
	Field filter:b2Filter
end

struct b2FixtureProxy
	Field aabb:b2AABB
	Field fixture:b2Fixture
	Field childIndex:Int
	Field proxyId:Int
end

class b2Fixture
	Method GetType:b2Shape::Type(:)
	Method GetShape:b2Shape(:)
	Method GetShape:b2Shape(:)
	Method SetSensor(sensor:bool)
	Method IsSensor:bool(:)
	Method SetFilterData(filter:b2Filter)
	Method GetFilterData:b2Filter&(:)
	Method Refilter(:)
	Method GetBody:b2Body(:)
	Method GetBody:b2Body(:)
	Method GetNext:b2Fixture(:)
	Method GetNext:b2Fixture(:)
	Method GetUserData(:)
	Method SetUserData(data:void)
	Method TestPoint:bool(p:b2Vec2)
	Method RayCast:bool(output:b2RayCastOutput,input:b2RayCastInput,childIndex:Int)
	Method GetMassData(massData:b2MassData)
	Method SetDensity(density:Float)
	Method GetDensity:Float(:)
	Method GetFriction:Float(:)
	Method SetFriction(friction:Float)
	Method GetRestitution:Float(:)
	Method SetRestitution(restitution:Float)
	Method GetAABB:b2AABB&(childIndex:Int)
	Method Dump(bodyIndex:Int)
	Field class b2Body:friend
	Field class b2World:friend
	Field class b2Contact:friend
	Field class b2ContactManager:friend
	Field We need separation create/destroy functions from theructor/destructor because://
	Method the destructor cannot access the allocator ://(destructor arguments allowed by C++:no)
	Method Create(allocator:b2BlockAllocator,body:b2Body,def:b2FixtureDef)
	Method Destroy(allocator:b2BlockAllocator)
	Field These support body activation/deactivation.://
	Method CreateProxies(broadPhase:b2BroadPhase,xf:b2Transform)
	Method DestroyProxies(broadPhase:b2BroadPhase)
	Method Synchronize(broadPhase:b2BroadPhase,xf1:b2Transform,xf2:b2Transform)
	Field m_density:Float
	Field m_next:b2Fixture
	Field m_body:b2Body
	Field m_shape:b2Shape
	Field m_friction:Float
	Field m_restitution:Float
	Field m_proxies:b2FixtureProxy
	Field m_proxyCount:Int
	Field m_filter:b2Filter
	Field m_isSensor:bool
	Field m_userData
end

class b2Island
	Method :b2Island(int32(bodyCapacity:Int,contactCapacity:Int,jointCapacity:Int)
	Field allocator, b2ContactListener* listener):b2StackAllocator
	Method Clear(:)
	Method Solve(profile:b2Profile,step:b2TimeStep,gravity:b2Vec2,allowSleep:bool)
	Method SolveTOI(subStep:b2TimeStep,toiIndexA:Int,toiIndexB:Int)
	Method Add(body:b2Body)
	Method Add(contact:b2Contact)
	Method Add(joint:b2Joint)
	Method Report(b2ContactVelocityConstraint*raints:b2ContactVelocityConstraintraint)
	Field m_allocator:b2StackAllocator
	Field m_listener:b2ContactListener
	Field m_bodies:b2Body
	Field m_contacts:b2Contact
	Field m_joints:b2Joint
	Field m_positions:b2Position
	Field m_velocities:b2Velocity
	Field m_bodyCount:Int
	Field m_jointCount:Int
	Field m_contactCount:Int
	Field m_bodyCapacity:Int
	Field m_contactCapacity:Int
	Field m_jointCapacity:Int
end

struct b2Profile
	Field step:Float
	Field collide:Float
	Field solve:Float
	Field solveInit:Float
	Field solveVelocity:Float
	Field solvePosition:Float
	Field broadphase:Float
	Field solveTOI:Float
end

struct b2TimeStep
	Field dt:Float
	Field inv_dt:Float
	Field dtRatio:Float
	Field velocityIterations:Int
	Field positionIterations:Int
	Field warmStarting:bool
end

struct b2Position
	Field c:b2Vec2
	Field a:Float
end

struct b2Velocity
	Field v:b2Vec2
	Field w:Float
end

struct b2SolverData
	Field step:b2TimeStep
	Field positions:b2Position
	Field velocities:b2Velocity
end

class b2DestructionListener
	Method :~b2DestructionListener()(:)
	Method SayGoodbye(joint:b2Joint)
	Method SayGoodbye(fixture:b2Fixture)
end

class b2ContactFilter
	Method :~b2ContactFilter()(:)
	Method ShouldCollide:bool(fixtureA:b2Fixture,fixtureB:b2Fixture)
end

struct b2ContactImpulse
	Field normalImpulses[b2_maxManifoldPoints]:Float
	Field tangentImpulses[b2_maxManifoldPoints]:Float
	Field count:Int
end

class b2ContactListener
	Method :~b2ContactListener()(:)
	Method BeginContact(contact:b2Contact)
	Method EndContact(contact:b2Contact)
	Method PreSolve(contact:b2Contact,oldManifold:b2Manifold)
	Method PostSolve(contact:b2Contact,impulse:b2ContactImpulse)
end

class b2QueryCallback
	Method :~b2QueryCallback()(:)
	Method ReportFixture:bool(fixture:b2Fixture)
end

class b2RayCastCallback
	Method :~b2RayCastCallback()(:)
	Method ReportFixture:Float(fixture:b2Fixture,point:b2Vec2)
	Field normal, float32 fraction) = 0:b2Vec2&
end

struct b2RopeDef
	Field vertices:b2Vec2
	Field count:Int
	Field masses:Float
	Field gravity:b2Vec2
	Field damping:Float
	Field k2:Float
	Field k3:Float
end

class b2Rope
	Method Initialize(def:b2RopeDef)
	Method Step(timeStep:Float,iterations:Int)
	Method GetVertexCount:Int(:)
	Method GetVertices:b2Vec2(:)
	Method Draw(draw:b2Draw)
	Method SetAngle(angle:Float)
	Method SolveC2(:)
	Method SolveC3(:)
	Field m_count:Int
	Field m_ps:b2Vec2
	Field m_p0s:b2Vec2
	Field m_vs:b2Vec2
	Field m_ims:Float
	Field m_Ls:Float
	Field m_as:Float
	Field m_gravity:b2Vec2
	Field m_damping:Float
	Field m_k2:Float
	Field m_k3:Float
end
