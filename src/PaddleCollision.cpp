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

}

void Paddle::CollidesWith(Paddle* p, SDL_Rect cMask)
{

}

void Paddle::CollidesWith(Ball* b, SDL_Rect cMask)
{
	b->CollidesWith(this, cMask); //already implemented there
}