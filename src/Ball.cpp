#include "Ball.h"
#include <iostream>

Ball::Ball() { }

Ball::Ball(vec2f pos) : IMovable(pos)
{
	radius = 10;
	UpdateCollisionBox();
	std::cout << " + Baller (" << radius << ") created @ " << pos.x << ',' << pos.y << std::endl;
}

int Ball::GetRadius()
{
	return radius;
}

void Ball::SetRadius(int r) 
{
	radius = r;
}