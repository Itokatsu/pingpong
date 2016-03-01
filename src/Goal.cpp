#include "Goal.h"
#include <iostream>
#include "IField.h"

Goal::Goal() 
{
	//field = NULL;
	area = {0,0,0,0};
	pts = 0;
	std::cout << "uh oh" << std::endl;
}

Goal::Goal(IField* f, SDL_Rect area, int pts)
{
	field = f;
	this->pts = pts;
	this->area = area;
	UpdateCollisionBox();
	//std::cout << " + Goal \"" << s << "\" (" << area.w << 'x'<< area.h << ") created @ " << area.x << ',' << area.y << std::endl;
	//std::cout << "   * on Field (" << field.GetWidth() << 'x' << field.GetHeight() << ')' << std::endl;
	//std::cout << "   * on Field (" << field.GetWidth() << 'x' << field.GetHeight() << ')' << std::endl;
}

Goal::Goal(IField* f, int x, int y, int w, int h, int pts)
{
	field = f;
	this->pts = pts;
	SDL_Rect areaRect = {x, y, w, h};
	area = areaRect;
	UpdateCollisionBox();
	//std::cout << " + Goal \"" << s << "\" (" << area.w << 'x'<< area.h << ") created @ " << area.x << ',' << area.y << std::endl;
	//std::cout << "   * on Field (" << field.GetWidth() << 'x' << field.GetHeight() << ')' << std::endl;
}

void Goal::PrintShit(){
	std::cout << "Goal \"" << str << "\" (" << field->GetWidth() << 'x' << field->GetHeight() <<')' << std::endl;
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