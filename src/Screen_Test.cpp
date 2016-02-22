#include "Screen_Test.h"
#include <iostream>
#include "SDL.h"

Screen_Test Screen_Test::myTest;

Screen_Test::Screen_Test()
{

}

void Screen_Test::Init()
{
	std::cout << "Test Screen Start" << std::endl;
	paddle = Paddle(400,400);
	paddle.PrintCoords();
	direction = 2;
}

void Screen_Test::Cleanup()
{
	std::cout << "Test Screen Quit" << std::endl;
}

void Screen_Test::Pause()
{

}

void Screen_Test::Unpause()
{

}

void Screen_Test::HandleEvents(GameEngine* game)
{
	SDL_Event e;
	while( SDL_PollEvent( &e ) != 0 ) {
		//User requests quit
		if( e.type == SDL_QUIT ) {
			game->Quit();
		}
	}
}

void Screen_Test::Update(GameEngine* game)
{
	if (paddle.GetPos().x + paddle.GetSize().x + direction <= 640 &&
		paddle.GetPos().x + direction >= 0) {
		SDL_Point pos = {paddle.GetPos().x + direction, paddle.GetPos().y}; 
		paddle.SetPos( pos );
	}
	else {
		direction = -direction;
	}
 
	SDL_Delay(30);
}

void Screen_Test::Draw(GameEngine* game, GraphicEngine* gfx)
{
	//set BG color
	SDL_SetRenderDrawColor( gfx->getRenderer(), 0x2A, 0x2A, 0x34, 0xFF );
	SDL_RenderClear( gfx->getRenderer() );

	paddle.PrintCoords();
	paddle.Draw(gfx);

	//update
	SDL_RenderPresent( gfx->getRenderer() );
}

Screen_Test* Screen_Test::Instance()
{
	return &myTest;
}