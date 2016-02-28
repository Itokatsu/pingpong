#include "Paddle.h"

#include "IHasCollision.h"
#include "Ball.h"
#include "IField.h"

void Paddle::UpdateCollisionBox()
{
	collisionBox = {position.ToSDLPoint().x,
					position.ToSDLPoint().y,
					size.x,
					size.y};
}

void Paddle::AcceptCollision(IHasCollision* c, SDL_Rect cMask)
{
	c->CollidesWith(this, cMask);
}

void Paddle::CollidesWith(IField* f, SDL_Rect cMask)
{
	if (collisionBox.x <= 0 && velocity.x < 0) {
		velocity.x = 0;
		SetPos( {0, position.y} );
	}
	//top side collides
	else if ( collisionBox.y <= 0 && velocity.y < 0) {
		/*velocity.y = 0;
		SetPos( {position.x, 0} );*/
		//just for demo
		velocity.y = -velocity.y;
	}
	//right side collides
	else if ( collisionBox.x + collisionBox.w >= f->GetWidth()
											&& velocity.x > 0) {
		velocity.x = 0;
		SetPos( {f->GetWidth() - (float)size.x, position.y} );
	}
	//bottom side collides
	else if ( collisionBox.y + collisionBox.h >= f->GetHeight()
											&& velocity.y > 0) {
		/*velocity.y = 0;
		SetPos( {position.x, f->GetHeight() - (float)size.y } );*/
		velocity.y = -velocity.y;
	}
}

void Paddle::CollidesWith(Paddle* p, SDL_Rect cMask)
{

}

void Paddle::CollidesWith(Ball* b, SDL_Rect cMask)
{
	b->CollidesWith(this, cMask); //already implemented there
}