#include "IField.h"

#include "Ball.h"
#include "Paddle.h"
#include "Goal.h"

void IField::UpdateCollisionBox() {

}

void IField::AcceptCollision(IHasCollision* c, SDL_Rect* cMask)
{
	c->CollidesWith(this, cMask);
}

void IField::CollidesWith(IField* f, SDL_Rect* cMask)
{
	//wait what ?
}

void IField::CollidesWith(Paddle* p, SDL_Rect* cMask)
{
	p->CollidesWith(this, cMask);
}

void IField::CollidesWith(Ball* b, SDL_Rect* cMask)
{
	b->CollidesWith(this, cMask);
}

void IField::CollidesWith(Goal* g, SDL_Rect* cMask)
{
	//that shit doesn't happen yo
}