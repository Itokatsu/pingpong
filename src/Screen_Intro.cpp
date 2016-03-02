#include "Screen_Intro.h"
#include <iostream>
#include "SDL.h"
#include "Screen_Test.h"

Screen_Intro Screen_Intro::myIntro;

Screen_Intro::Screen_Intro()
{

}

void Screen_Intro::Init()
{
	std::cout << "[Intro Screen Start]" << std::endl;
	std::cout << "Press <SPACEBAR> to start a demo" << std::endl;
}

void Screen_Intro::Cleanup()
{
	std::cout << "[Intro Screen Quit]" << std::endl;
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
		//Close window
		if( e.type == SDL_QUIT ) {
			game->Quit();
		}
		else {
			// Key press 
			if( e.type == SDL_KEYDOWN ) {
				// ESCAPE is pressed
				if (e.key.keysym.sym == SDLK_ESCAPE) {
					game->Quit();
				}
				else if (e.key.keysym.sym == SDLK_SPACE ) {
					game->ChangeScreen(Screen_Test::Instance());
				}
			}
		}
	}
}

void Screen_Intro::Update(GameEngine* game)
{
	SDL_Delay(100);
}

void Screen_Intro::Draw(GameEngine* game)
{
	SDL_Renderer* rend = game->GetGraphicEngine()->GetRenderer();
	SDL_SetRenderDrawColor( rend, 0x1A, 0x1A, 0x1A, 0xFF );
	SDL_RenderClear( rend );
	SDL_Rect fillRect = { 640 / 4, 480 / 4, 640 / 2, 480 / 2 };
	SDL_SetRenderDrawColor( rend, 0xFF, 0x00, 0x00, 0xFF );        
	SDL_RenderFillRect( rend, &fillRect );
	SDL_RenderPresent( rend );
}

Screen_Intro* Screen_Intro::Instance()
{
	return &myIntro;
}