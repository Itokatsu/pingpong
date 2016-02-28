#include "Paddle.h"
#include <iostream>

Paddle::Paddle()
{
}

Paddle::Paddle(vec2f pos, SDL_Point size) : IMovable(pos)
{
	this->size = size;
	std::cout << " + Paddle (" << size.x << 'x' << size.y << ") created @ " << pos.x << ',' << pos.y << std::endl;
}

Paddle::Paddle(int x, int y, int w, int h) : IMovable(x, y)
{
	size = {w, h};
	std::cout << " + Paddle (" << w << 'x' << h << ") created @ " << x << ',' << y << std::endl;
}

SDL_Point Paddle::GetSize()
{
	return size;
}

void Paddle::SetSize(SDL_Point new_size)
{
	size = new_size;
}