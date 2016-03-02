#include "DrawEngine.h"
#include <iostream>

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

void DrawEngine::DrawMatch(Match* match, GameEngine* game)
{
	DrawField(match->GetField(), game);
	for ( auto &player : match->GetPlayers() ) {
		DrawPlayer(player, game);
	}
	DrawBall(match->GetBall(), game);
}

void DrawEngine::DrawField(IField* field, GameEngine* game)
{
	for ( auto &goal : field->GetGoals() ) {
		DrawGoal(goal, game);
	}
}

void DrawEngine::DrawGoal(Goal* goal, GameEngine* game)
{
	SDL_Rect* goalRect = goal->GetCollisionBox();
	// mint 50% opacity
	SDL_SetRenderDrawColor(renderer, 0x98, 0xFF, 0x98, 0x80);
	SDL_RenderFillRect(renderer, goalRect);
}


void DrawEngine::DrawPlayer(Player* player, GameEngine* game)
{
	DrawPaddle(player->GetPaddle(), game);
}

void DrawEngine::DrawPaddle(Paddle* pad, GameEngine* game)
{
	SDL_Rect* padRect = pad->GetCollisionBox();
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderFillRect(renderer, padRect);
}


void DrawEngine::DrawBall(Ball* ball, GameEngine* game)
{
	SDL_Rect* ballRect = ball->GetCollisionBox();
	//yellow degueulasse
	SDL_SetRenderDrawColor(renderer, 0xCC, 0xFF, 0x00, 0xFF);
	SDL_RenderFillRect(renderer, ballRect);	
}