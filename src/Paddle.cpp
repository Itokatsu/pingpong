#include "Paddle.h"
#include <iostream>

Paddle::Paddle()
{
	
}

Paddle::Paddle(int posX, int posY)
{
	size = {100, 20};
	position = {posX, posY};
	velocity = {0, 0};
	std::cout << "paddle created" << std::endl;
}

void Paddle::PrintCoords()
{
	std::cout << position.x << " " << position.y << " " << size.x << " " << size.y << std::endl;	
}


void Paddle::SetPos(SDL_Point new_pos)
{
	position = new_pos;
}

void Paddle::SetSize(SDL_Point new_size)
{
	size = new_size;
}

void Paddle::SetVelocity(SDL_Point new_velo)
{
	velocity = new_velo;
}

SDL_Point Paddle::GetPos()
{
	return position;
}

SDL_Point Paddle::GetSize()
{
	return size;
}

SDL_Point Paddle::GetVelocity()
{
	return velocity;
}