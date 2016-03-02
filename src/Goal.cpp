#include "Goal.h"

#include <iostream>
#include "IField.h"

Goal::Goal(IField* f, SDL_Rect area, int pts)
{
	field = f;
	this->pts = pts;
	this->area = area;
	UpdateCollisionBox();
	std::cout << " + Goal (" << area.w << 'x'<< area.h << ") created @ " << area.x << ',' << area.y << std::endl;
}

Goal::Goal(IField* f, int x, int y, int w, int h, int pts)
{
	field = f;
	this->pts = pts;
	SDL_Rect areaRect = {x, y, w, h};
	area = areaRect;
	UpdateCollisionBox();
	std::cout << " + Goal (" << area.w << 'x'<< area.h << ") created @ " << area.x << ',' << area.y << std::endl;
}

Goal::~Goal() 
{
	std::cout << " - Goal @ " << area.x << ',' << area.y << " deleted" << std::endl;
}

int Goal::GetValue()
{
	return pts;
}

IField* Goal::GetField()
{
	return field;
}


/*=======================**
**==  Collision stuff  ==**
**=======================*/
// #include "IField.h"
#include "Paddle.h"
#include "Ball.h"

void Goal::UpdateCollisionBox()
{
	collisionBox = area;
}

void Goal::AcceptCollision( IHasCollision* c, SDL_Rect* cMask ) {
	c->CollidesWith(this, cMask);
}
void Goal::CollidesWith( IField* f, SDL_Rect* cMask ) {
	f->CollidesWith(this, cMask);
}
void Goal::CollidesWith( Paddle* p, SDL_Rect* cMask ) {
	p->CollidesWith(this, cMask);
}
void Goal::CollidesWith( Ball* b, SDL_Rect* cMask ) {
	b->CollidesWith(this, cMask);
}
void Goal::CollidesWith( Goal* g, SDL_Rect* cMask ) {
	g->CollidesWith(this, cMask);
}