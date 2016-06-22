Namespace box2d

#Import "box2d/*.h"

#Import "<Box2D.h>"

#Import "box2d/Box2D/Collision/Shapes/b2ChainShape.cpp"
#Import "box2d/Box2D/Collision/Shapes/b2CircleShape.cpp"
#Import "box2d/Box2D/Collision/Shapes/b2EdgeShape.cpp"
#Import "box2d/Box2D/Collision/Shapes/b2PolygonShape.cpp"
#Import "box2d/Box2D/Collision/b2BroadPhase.cpp"
#Import "box2d/Box2D/Collision/b2CollideCircle.cpp"
#Import "box2d/Box2D/Collision/b2CollideEdge.cpp"
#Import "box2d/Box2D/Collision/b2CollidePolygon.cpp"
#Import "box2d/Box2D/Collision/b2Collision.cpp"
#Import "box2d/Box2D/Collision/b2Distance.cpp"
#Import "box2d/Box2D/Collision/b2DynamicTree.cpp"
#Import "box2d/Box2D/Collision/b2TimeOfImpact.cpp"
#Import "box2d/Box2D/Common/b2BlockAllocator.cpp"
#Import "box2d/Box2D/Common/b2Draw.cpp"
#Import "box2d/Box2D/Common/b2Math.cpp"
#Import "box2d/Box2D/Common/b2Settings.cpp"
#Import "box2d/Box2D/Common/b2StackAllocator.cpp"
#Import "box2d/Box2D/Common/b2Timer.cpp"
#Import "box2d/Box2D/Dynamics/Contacts/b2ChainAndCircleContact.cpp"
#Import "box2d/Box2D/Dynamics/Contacts/b2ChainAndPolygonContact.cpp"
#Import "box2d/Box2D/Dynamics/Contacts/b2CircleContact.cpp"
#Import "box2d/Box2D/Dynamics/Contacts/b2Contact.cpp"
#Import "box2d/Box2D/Dynamics/Contacts/b2ContactSolver.cpp"
#Import "box2d/Box2D/Dynamics/Contacts/b2EdgeAndCircleContact.cpp"
#Import "box2d/Box2D/Dynamics/Contacts/b2EdgeAndPolygonContact.cpp"
#Import "box2d/Box2D/Dynamics/Contacts/b2PolygonAndCircleContact.cpp"
#Import "box2d/Box2D/Dynamics/Contacts/b2PolygonContact.cpp"
#Import "box2d/Box2D/Dynamics/Joints/b2DistanceJoint.cpp"
#Import "box2d/Box2D/Dynamics/Joints/b2FrictionJoint.cpp"
#Import "box2d/Box2D/Dynamics/Joints/b2GearJoint.cpp"
#Import "box2d/Box2D/Dynamics/Joints/b2Joint.cpp"
#Import "box2d/Box2D/Dynamics/Joints/b2MotorJoint.cpp"
#Import "box2d/Box2D/Dynamics/Joints/b2MouseJoint.cpp"
#Import "box2d/Box2D/Dynamics/Joints/b2PrismaticJoint.cpp"
#Import "box2d/Box2D/Dynamics/Joints/b2PulleyJoint.cpp"
#Import "box2d/Box2D/Dynamics/Joints/b2RevoluteJoint.cpp"
#Import "box2d/Box2D/Dynamics/Joints/b2RopeJoint.cpp"
#Import "box2d/Box2D/Dynamics/Joints/b2WeldJoint.cpp"
#Import "box2d/Box2D/Dynamics/Joints/b2WheelJoint.cpp"
#Import "box2d/Box2D/Dynamics/b2Body.cpp"
#Import "box2d/Box2D/Dynamics/b2ContactManager.cpp"
#Import "box2d/Box2D/Dynamics/b2Fixture.cpp"
#Import "box2d/Box2D/Dynamics/b2Island.cpp"
#Import "box2d/Box2D/Dynamics/b2World.cpp"
#Import "box2d/Box2D/Dynamics/b2WorldCallbacks.cpp"
#Import "box2d/Box2D/Rope/b2Rope.cpp"

Extern

Struct b2Vec2
	Field x:Float
	Field y:Float
	Method New(gx:Float,gy:Float)
End

Struct b2AABB
End

Enum b2BodyType
	Static_BODY,KINEMATIC_BODY,DYNAMIC_BODY
End

Struct b2BodyDef
	Field type:b2BodyType
	Field position:b2Vec2
	Field angle:Float
	Field linearVelocity:b2Vec2
	Field angularVelocity:Float
	Field linearDamping:Float
	Field angularDamping:Float
	Field allowSleep:Bool
	Field awake:Bool
	Field fixedRotation:Bool
	Field bullet:Bool
	Field active:Bool
	Field userData:Object
	Field gravityScale:Float	
End

Struct b2FixtureDef
End

Class b2Shape Extends Void
End

Class b2Fixture Extends Void
End


Class b2Body Extends Void
	Method createFixture:b2Fixture(fixtureDef:b2FixtureDef)
	Method createFixture:b2Fixture(shape:b2Shape,density:Float)
	Method destroyFixture(fixture:b2Fixture)
	Method setTransform(position:b2Vec2,angle:Float)	
End


Class b2Joint Extends Void
End

Class b2Contact Extends Void
End

Class b2ContactFilter Extends Void
End

Class b2Manifold Extends Void
End

Class b2ContactImpulse Extends Void
End

Class b2ContactListener Extends Void
	Method BeginContact(contact:b2Contact)
	Method EndContact(contact:b2Contact)
	Method PreSolve(contact:b2Contact,oldManifold:b2Manifold)
	Method PostSolve(contact:b2Contact,impulse:b2ContactImpulse)
End

Class b2ContactManager Extends Void
End

Class b2Controller Extends Void
End

Class b2JointDef Extends Void
End


Class b2QueryCallback Extends Void
End
Class b2RayCastCallback Extends Void
End

Class b2Draw Extends Void
End
Class b2DestructionListener Extends Void
End

Class b2World Extends Void
	Method New(gravity:b2Vec2)
	Method SetDestructionListener(listener:b2DestructionListener)
	Method SetContactFilter (filter:b2ContactFilter)
	Method SetContactListener (listener:b2ContactListener)
	Method SetDebugDraw (debugDraw:b2Draw)
	Method CreateBody:b2Body(def:b2BodyDef)
	Method DestroyBody(body:b2Body)
	Method CreateJoint:b2Joint(def:b2JointDef)
	Method DestroyJoint (joint:b2Joint)
	Method StepWorld(timeStep:Float,velocityIterations:Int,positionIterations:Int)="Step"
	Method ClearForces()
	Method DrawDebugData()	'Call this to draw shapes and other debug draw data. 
	Method QueryAABB(callback:b2QueryCallback,aabb:b2AABB)
	Method RayCast(callback:b2RayCastCallback,point1:b2Vec2,point2:b2Vec2)
	Method GetBodyList:b2Body()
	Method GetJointList:b2Joint()
	Method GetContactList:b2Contact()
'	Method Const b2Contact * 	GetContactList () Const
	Method SetAllowSleeping(flag:Bool)' 	Enable/disable sleep. 
	Method GetAllowSleeping:Bool()
	Method SetWarmStarting(flag:Bool)	'Enable/disable warm starting. For testing. 
	Method GetWarmStarting:Bool() 
	Method SetContinuousPhysics (flag:Bool)' 	Enable/disable continuous physics. For testing. 
	Method GetContinuousPhysics:Bool () 
	Method SetSubStepping(flag:Bool)' 	Enable/disable single stepped continuous physics. For testing. 
	Method GetSubStepping:Bool() 
	Method GetProxyCount:Int() ' 	Get the number of broad-phase proxies. 
	Method GetBodyCount:Int() ' 	Get the number of bodies. 
	Method GetJointCount:Int() ' 	Get the number of joints. 
	Method GetContactCount:Int() ' 	Get the number of contacts (each may have 0 Or more contact points). 
	Method GetTreeHeight:Int() ' 	Get the height of the dynamic tree. 
	Method GetTreeBalance:Int() ' 	Get the balance of the dynamic tree. 
	Method GetTreeQuality:Float() 
	Method SetGravity(gravity:b2Vec2)' 	Change the Global gravity vector. 
	Method GetGravity:b2Vec2() ' 	Get the Global gravity vector. 
	Method IsLocked:Bool() ' 	Is the world locked (in the middle of a time Step). 
	Method SetAutoClearForces (flag:Bool)' 	Set flag To control automatic clearing of forces after each time Step. 
	Method GetAutoClearForces:Bool() ' 	Get the flag that controls automatic clearing of forces after each time Step. 
'	Method Const b2ContactManager & 	GetContactManager () Const' 	Get the contact manager For testing. 
'	Method Const b2Profile & 	GetProfile () Const' 	Get the current profile. 
	Method 	Dump()

End

Public 
