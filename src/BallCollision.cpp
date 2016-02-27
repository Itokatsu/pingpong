#include "Ball.h"

#include "IHasCollision.h"

void Ball::UpdateCollisionBox() {
	collisionBox = {position.ToSDLPoint().x-radius,
					position.ToSDLPoint().y-radius,
					radius*2,
					radius*2};
}

void Ball::AcceptCollision(IHasCollision* c, SDL_Rect cMask)
{
	c->CollidesWith(this, cMask);
}

void Ball::CollidesWith(IField* f, SDL_Rect cMask)
{
	//bounce off the edges
	// * exact same behavior as Ball/Paddle collision
	if (cMask.x == collisionBox.x
				&& velocity.x < 0) {
		velocity.x = - velocity.x;
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

void Ball::CollidesWith(Paddle* p, SDL_Rect cMask)
{
	// SDL_Rect = {x y h w}

	// left side of the ball collides
	if (cMask.x == collisionBox.x
				&& velocity.x < 0) {
		velocity.x = - velocity.x;
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

void Ball::CollidesWith(Ball* b, SDL_Rect cMask)
{

}