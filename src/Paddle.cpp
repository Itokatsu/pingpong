#include "Paddle.h"
#include <iostream>

Paddle::Paddle()
{
}

Paddle::Paddle(vec2f pos) : IMovable(pos)
{
	size = {20, 100};
	std::cout << "Paddle created" << std::endl;
}

Paddle::Paddle(int x, int y) : IMovable(x, y)
{
	size = {20, 100};
}

SDL_Point Paddle::GetSize()
{
	return size;
}

void Paddle::SetSize(SDL_Point new_size)
{
	size = new_size;
}