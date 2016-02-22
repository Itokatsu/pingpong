#include "Screen_Intro.h"
#include <iostream>
#include "SDL.h"

Screen_Intro Screen_Intro::myIntro;

Screen_Intro::Screen_Intro()
{

}

void Screen_Intro::Init()
{
	std::cout << "Intro Screen Start" << std::endl;
}

void Screen_Intro::Cleanup()
{
	std::cout << "Intro Screen Quit" << std::endl;
}

void Screen_Intro::Pause()
{

}

void Screen_Intro::Unpause()
{

}

void Screen_Intro::HandleEvents(GameEngine* game)
{
	SDL_Event e;
	while( SDL_PollEvent( &e ) != 0 ) {
		//User requests quit
		if( e.type == SDL_QUIT ) {
			game->Quit();
		}
	}
}

void Screen_Intro::Update(GameEngine* game)
{
	SDL_Delay(100);
}

void Screen_Intro::Draw(GameEngine* game)
{
	/*SDL_Renderer* rend = gfx->getRenderer();
	SDL_SetRenderDrawColor( rend, 0x1A, 0x1A, 0x1A, 0xFF );
	SDL_RenderClear( rend );
	SDL_Rect fillRect = { gfx->SCREEN_WIDTH / 4, gfx->SCREEN_HEIGHT / 4, gfx->SCREEN_WIDTH / 2, gfx->SCREEN_HEIGHT / 2 };
	SDL_SetRenderDrawColor( rend, 0xFF, 0x00, 0x00, 0xFF );        
	SDL_RenderFillRect( rend, &fillRect );
	SDL_RenderPresent( rend );*/
}

Screen_Intro* Screen_Intro::Instance()
{
	return &myIntro;
}