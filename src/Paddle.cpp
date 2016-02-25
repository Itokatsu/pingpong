#include "Paddle.h"
#include <iostream>

Paddle::Paddle()
{
}

Paddle::Paddle(vec2f pos) : IMovable(pos)
{
	size = {100, 20};
	std::cout << "Paddle created" << std::endl;
}

Paddle::Paddle(int x, int y) : IMovable(x, y)
{
	size = {100, 20};
	// position = {float(x), float(y)};
	// velocity = {0.f, 0.f};
	// acceleration = {0.f, 0.f};
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