#Import "<std>"
#Import "<mojo>"
#Import "<box2d>"

Using std..

Class Box2DSim Extends box2d.b2ContactListener

	Field world1:box2d.b2World

	Method New()	
		Local down:=New box2d.b2Vec2(0,20)
		
		Local world:=New box2d.b2World(down)		

' uncomment this line

'		world1=world

		
		Local g:=world.GetGravity()		
		
		Print "gravity="+g.x+","+g.y
	End
End


Function Main()
	Print "monkey2 box2d test"
	
	Local sim:=New Box2DSim()


End


#rem

	Box2DBody *addBox(Float x,Float y,Float w,Float h,Int id){
		b2BodyDef bodyDef;
		bodyDef.position.Set(x*scale,y*scale);
		b2Body *body = world.CreateBody(&bodyDef);
		b2PolygonShape box;
		box.SetAsBox(w*scale*0.5,h*scale*0.5);
//		body->CreateFixture(&box, 0.0f);
		b2FixtureDef fixtureDef;
		fixtureDef.restitution = 0.5f;
		fixtureDef.shape = &box;
		fixtureDef.filter.categoryBits=WallBit;
		body->CreateFixture(&fixtureDef);
		Return addBody(body,Points({w,h}),id);
	}

#end
