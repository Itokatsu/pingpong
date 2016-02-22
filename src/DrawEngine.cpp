#include "DrawEngine.h"

DrawEngine::DrawEngine()
{

}

void DrawEngine::Init(GraphicEngine* gfx)
{
	renderer = gfx->GetRenderer();
}

void DrawEngine::Cleanup()
{
	//clean map
}

void DrawEngine::DrawPaddle(Paddle* pad, GameEngine* game)
{
	SDL_Rect padRect = {pad->GetPos().x , pad->GetPos().y, pad->GetSize().x, pad->GetSize().y };
	SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
	SDL_RenderFillRect( renderer, &padRect );
}


void DrawEngine::DrawBall(Ball* ball, GameEngine* game)
{
	SDL_SetRenderDrawColor( renderer, 0xCC, 0xFF, 0x00, 0xFF );
	
}