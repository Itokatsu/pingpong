#include "Ball.h"

#include "IField.h"
#include "Paddle.h"
#include "Goal.h"

#include <iostream>


void Ball::UpdateCollisionBox() {
	collisionBox = {position.ToSDLPoint().x-radius,
					position.ToSDLPoint().y-radius,
					radius*2,
					radius*2};
}

void Ball::AcceptCollision(IHasCollision* c, SDL_Rect* cMask)
{
	c->CollidesWith(this, cMask);
}

void Ball::CollidesWith(IField* f, SDL_Rect* cMask)
{
	//bounce off the edges
	// * exact same behavior as Ball/Paddle collision
	if (collisionBox.x <= 0 && velocity.x < 0) {
		velocity.x = - velocity.x;
	}
	//right side collides
	else if ( collisionBox.x + collisionBox.w >= f->GetWidth()
											&& velocity.x > 0) {
		velocity.x = - velocity.x;
	}
	//top side collides
	if (collisionBox.y <= 0 && velocity.y < 0) {
		velocity.y = - velocity.y;
	}
	//bottom side collides
	else if ( collisionBox.y + collisionBox.h >= f->GetHeight()
											&& velocity.y > 0) {
		velocity.y = - velocity.y;
	}

}

void Ball::CollidesWith(Paddle* p, SDL_Rect* cMask)
{
	SDL_Rect* pBox = p->GetCollisionBox();
	// left side of the ball collides with right side of paddle
	if (cMask->x == collisionBox.x
			&& cMask->x + cMask->w == pBox->x + pBox->w
			&& velocity.x < 0) {
		velocity.x = - velocity.x;
	}
	//right side collides with left side of paddle
	else if ( cMask->x + cMask->w == collisionBox.x + collisionBox.w
				&& cMask->x == pBox->x
				&& velocity.x > 0) {
		velocity.x = - velocity.x;
	}
	//top side collides with bottom side of paddle
	if (cMask->y == collisionBox.y
			&& cMask->y + cMask->h == pBox->y + pBox->h
	 		&& velocity.y < 0) {
		velocity.y = - velocity.y;
	}
	//bottom side collides with top side of paddle
	else if ( cMask->y + cMask->h == collisionBox.y + collisionBox.h
				&& cMask->y == pBox->y
				&& velocity.y > 0) {
		velocity.y = - velocity.y;
	}
	this->SetLastP(p->GetPlayer()); //Who hit the ball
}

void Ball::CollidesWith(Ball* b, SDL_Rect* cMask)
{

}

void Ball::CollidesWith(Goal* g, SDL_Rect* cMask)
{
	if (p_Last != NULL) {
		p_Last->IncrScore();
		std::cout << p_Last->GetName() << " scored ! (";
		std::cout << p_Last->GetScore() << ')' << std::endl;

	//reset ball Position
	vec2f pos = g->GetField()->GetBallInitPos();
	this->SetPos( pos );
	this->SetVelocity({0,0});
	p_Last = NULL;
	}

}