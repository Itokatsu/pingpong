#include "Screen_Intro.h"
#include <iostream>
#include "SDL.h"
#include "Screen_Test.h"

Screen_Intro Screen_Intro::myIntro;

Screen_Intro::Screen_Intro()
{

}

void Screen_Intro::Init(GameEngine* game)
{
	// texture_title = game->GetDrawEngine()->CreateTexture("../media/img/logoa2balles.png");
	SDL_Color textColor = { 0xBB, 0xBB, 0xBB };
	texture_title = game->GetDrawEngine()->LoadText("Press <SPACEBAR> to start a demo", textColor);
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
					game->PushScreen(Screen_Test::Instance());
				}
			}
		}
	}
}

void Screen_Intro::Update(GameEngine* game, float dT)
{
}

void Screen_Intro::Draw(GameEngine* game)
{
	SDL_Renderer* rend = game->GetGraphicEngine()->GetRenderer();
	SDL_SetRenderDrawColor( rend, 0x25, 0x25, 0x30, 0xFF );
	SDL_RenderClear( rend );
	/* SDL_Rect fillRect = { 640 / 4, 480 / 4, 640 / 2, 480 / 2 };
	SDL_SetRenderDrawColor( rend, 0xFF, 0x00, 0x00, 0xFF );        
	SDL_RenderFillRect( rend, &fillRect ); */

	/* for(int x = 0; x <= 640; x+= 80) {
		for (int y = 0; y <= 480; y+=30 ) {
			SDL_Rect area = {x, y, 70, 28};
			SDL_RenderCopy( rend, texture_title, NULL, &area);
		}
	} */

	SDL_Rect area = {100, 340, 420, 30};
	SDL_RenderCopy( rend, texture_title, NULL, &area);

	SDL_RenderPresent( rend );
}

Screen_Intro* Screen_Intro::Instance()
{
	return &myIntro;
}