#include "Paddle.h"
#include <iostream>

Paddle::Paddle()
{
	size = {100, 20};
	position = {50, 50};
	velocity = {0, 0};
}

Paddle::Paddle(int posX, int posY)
{
	size = {100, 20};
	position = {posX, posY};
	velocity = {0, 0};
	std::cout << "paddle created" << std::endl;
}

void Paddle::Draw(GraphicEngine* gfx)
{
	SDL_Rect padRect = {position.x , position.y, size.x, size.y };
	SDL_SetRenderDrawColor( gfx->getRenderer(), 0xFF, 0xFF, 0xFF, 0xFF );
	SDL_RenderFillRect( gfx->getRenderer(), &padRect );
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

SDL_Point Paddle::GetPos()
{
	return position;
}

SDL_Point Paddle::GetSize()
{
	return size;
}