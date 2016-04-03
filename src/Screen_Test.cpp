#include "Screen_Test.h"

#include <iostream>
#include "SDL.h"
#include "Field_Basic.h"
#include "Screen_Pause.h"

#include <stdio.h>

Screen_Test Screen_Test::myTest;

Screen_Test::Screen_Test()
{

}

void Screen_Test::Init()
{
	m = new Match();

	baseSpd = 4.f;
	std::cout << "[Test Screen Start]" << std::endl;
	m->Init(new Field_Basic());

}

void Screen_Test::Cleanup()
{
	delete m;
	m = NULL;
	std::cout << "[Test Screen Quit]" << std::endl;
}

void Screen_Test::Pause()
{
	IGameScreen::Pause();
}

void Screen_Test::Unpause()
{
	IGameScreen::Unpause();
	SDL_PumpEvents();
	const Uint8* keyStates = SDL_GetKeyboardState(NULL);
	if( keyStates[SDL_SCANCODE_UP]) {
		for (auto &player : m->GetPlayers() ) {
			Paddle* pad = player->GetPaddle();
			pad->SetVelocity({0.f, -baseSpd});
		}
	}
	else if( keyStates[SDL_SCANCODE_DOWN]) {
		for (auto &player : m->GetPlayers() ) {
			Paddle* pad = player->GetPaddle();
			pad->SetVelocity({0.f, baseSpd});
		}
	}
	else {
		for (auto &player : m->GetPlayers() ) {
			Paddle* pad = player->GetPaddle();
			pad->SetVelocity({0,0});
		}
	}
}

void Screen_Test::HandleEvents(GameEngine* game)
{
	SDL_Event e;
	while( SDL_PollEvent( &e ) != 0 ) {
		//Close window
		if( e.type == SDL_QUIT ) {
			game->Quit();
		}
		else {

			// Key press 
			if( e.type == SDL_KEYDOWN && e.key.repeat == 0) {

				if (e.key.keysym.sym == SDLK_ESCAPE) {
					game->PopScreen();
				} // escape key

				if (e.key.keysym.sym == SDLK_p) {
					game->PushScreen(Screen_Pause::Instance());
				} // p key

				if (e.key.keysym.sym == SDLK_UP ) {
					for (auto &player : m->GetPlayers() ) {
						Paddle* pad = player->GetPaddle();
						vec2f chVelocity = {0.f, -baseSpd};
						// pad->SetVelocity({pad->GetVelocity().x, -4});
						pad->SetVelocity( pad->GetVelocity() + chVelocity );
					}
				} // up arrow key

				if (e.key.keysym.sym == SDLK_DOWN ) {
					for (auto &player : m->GetPlayers() ) {
						Paddle* pad = player->GetPaddle();
						vec2f chVelocity = {0.f, baseSpd};
						// pad->SetVelocity({pad->GetVelocity().x, 4});
						pad->SetVelocity( pad->GetVelocity() + chVelocity );
					}
				} // down arrow key
			} // keypress

			// Key Release
			else if( e.type == SDL_KEYUP ) {
				if (e.key.keysym.sym == SDLK_UP ) {
					for (auto &player : m->GetPlayers() ) {
						Paddle* pad = player->GetPaddle();
						vec2f chVelocity = {0.f, -baseSpd};
						// pad->SetVelocity({pad->GetVelocity().x, 4});
						pad->SetVelocity( pad->GetVelocity() - chVelocity );
					}
				} // up arrow key

				if (e.key.keysym.sym == SDLK_DOWN ) {
					for (auto &player : m->GetPlayers() ) {
						Paddle* pad = player->GetPaddle();
						vec2f chVelocity = {0.f, baseSpd};
						// pad->SetVelocity({pad->GetVelocity().x, 4});
						pad->SetVelocity( pad->GetVelocity() - chVelocity );
					}
				} // down arrow key
			}
		} // else
	} // PollEvent loop
} // HandleEvents()

void Screen_Test::Update(GameEngine* game, float dT)
{
	m->Update(dT);
}

void Screen_Test::Draw(GameEngine* game)
{
	game->GetDrawEngine()->DrawMatch(m, game);
}

Screen_Test* Screen_Test::Instance()
{
	return &myTest;
}