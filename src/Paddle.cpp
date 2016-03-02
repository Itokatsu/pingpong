#include "Paddle.h"
#include <iostream>

Paddle::Paddle(Player* p, vec2f pos, SDL_Point size) : IMovable(pos)
{
	player = p;
	this->size = size;
	std::cout << " + Paddle (" << size.x << 'x' << size.y << ") created @ " << pos.x << ',' << pos.y << std::endl;
}

Paddle::Paddle(Player* p, int x, int y, int w, int h) : IMovable(x, y)
{
	player = p;
	size = {w, h};
	std::cout << " + Paddle (" << w << 'x' << h << ") created @ " << x << ',' << y << std::endl;
}

Paddle::~Paddle()
{
	std::cout << " - Paddle @ " << position.x << ',' << position.y << " deleted" << std::endl;	
}

SDL_Point Paddle::GetSize()
{
	return size;
}

void Paddle::SetSize(SDL_Point new_size)
{
	size = new_size;
}

Player* Paddle::GetPlayer()
{
	return player;
}