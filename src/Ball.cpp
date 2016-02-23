#include "Ball.h"
#include "SDL.h"
#include <iostream>

Ball::Ball() 
{

}

Ball::Ball(int x, int y) 
{
	radius = 10;
	position = {x, y};
	velocity = { 0, 0 };
	acceleration = { 0, 0 };
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