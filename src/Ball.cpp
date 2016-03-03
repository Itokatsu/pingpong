#include "Ball.h"
#include <iostream>

Ball::Ball() { }

Ball::Ball(vec2f pos) : IMovable(pos)
{
	p_Last = NULL;
	radius = 10;
	UpdateCollisionBox();
	std::cout << " + Baller (" << radius << ") created @ ";
	std::cout << pos.x << ',' << pos.y << std::endl;
}
// testing stuff
Ball::~Ball()
{
	std::cout << " - Baller (" << radius << ") deleted" << std::endl;
}

int Ball::GetRadius()
{
	return radius;
}

void Ball::SetRadius(int r) 
{
	radius = r;
}

Player* Ball::GetLastP()
{
	return p_Last;
}

void Ball::SetLastP(Player* p)
{
	p_Last = p;
}