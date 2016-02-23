#include "Paddle.h"
#include <iostream>

Paddle::Paddle()
{
	
}

Paddle::Paddle(int posX, int posY)
{
	size = {100, 20};
	position = {float(posX), float(posY)};
	velocity = {0.f, 0.f};
	acceleration = {0.f, 0.f};
	std::cout << "Paddle created" << std::endl;
}

void Paddle::PrintCoords()
{
	std::cout << position.x << " " << position.y << " " << size.x << " " << size.y << std::endl;	
}

SDL_Point Paddle::GetSize()
{
	return size;
}

void Paddle::SetSize(SDL_Point new_size)
{
	size = new_size;
}