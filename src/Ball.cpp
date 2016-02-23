#include "Ball.h"
#include "SDL.h"
#include <iostream>

Ball::Ball() 
{

}

Ball::Ball(int x, int y) 
{
	radius = 10;
	position = {(float)x, (float)y};
	velocity = { 0.f, 0.f };
	acceleration = { 0.f, 0.f };
	std::cout << "Baller created" << std::endl;
}

int Ball::GetRadius()
{
	return radius;
}

void Ball::SetRadius(int rad) 
{
	radius = rad;
}