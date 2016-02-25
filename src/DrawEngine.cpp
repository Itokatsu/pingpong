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
	SDL_Point pos = pad->GetPos().ToSDLPoint();
	SDL_Point size = pad->GetSize();
	SDL_Rect padRect = {pos.x , pos.y, size.x, size.y };
	SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
	SDL_RenderFillRect( renderer, &padRect );
}


void DrawEngine::DrawBall(Ball* ball, GameEngine* game)
{
	SDL_Point pos = ball->GetPos().ToSDLPoint();
	int rad = ball->GetRadius();
	//rectangle containing the ball
	SDL_Rect ballRect = {pos.x - rad/2, pos.y - rad/2, rad*2, rad*2 };

	//yellow degueulasse
	SDL_SetRenderDrawColor( renderer, 0xCC, 0xFF, 0x00, 0xFF );
	SDL_RenderFillRect(renderer, &ballRect);	
}