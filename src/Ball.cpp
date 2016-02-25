#include "Ball.h"
#include <iostream>

Ball::Ball() { }

Ball::Ball(vec2f pos) : IMovable(pos)
{
	radius = 10;
	// position = pos;
	// velocity = { 0.f, 0.f };
	// acceleration = { 0.f, 0.f };
	std::cout << "Baller created" << std::endl;
}

int Ball::GetRadius()
{
	return radius;
}

void Ball::SetRadius(int r) 
{
	radius = r;
}