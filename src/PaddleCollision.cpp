#include "Paddle.h"

#include "IHasCollision.h"
#include "Ball.h"

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
	//bounce off the edges
	// * exact same behavior as Ball/Paddle collision
	if (cMask.x == collisionBox.x
				&& velocity.x < 0) {
		velocity.x = 0;
	}
	//top side collides
	else if (cMask.y == collisionBox.y
	 				 && velocity.y < 0) {
		velocity.y = - velocity.y;
	}
	//right side collides
	else if ( cMask.x + cMask.w == collisionBox.x + collisionBox.w
								&& velocity.x > 0) {
		velocity.x = - velocity.x;
	}
	//bottom side collides
	else if ( cMask.y + cMask.h == collisionBox.y + collisionBox.h
								&& velocity.y > 0) {
		velocity.y = - velocity.y;
	}
}

void Paddle::CollidesWith(Paddle* p, SDL_Rect cMask)
{

}

void Paddle::CollidesWith(Ball* b, SDL_Rect cMask)
{
	b->CollidesWith(this, cMask); //already implemented there
}