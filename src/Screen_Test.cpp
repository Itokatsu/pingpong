#include "Screen_Test.h"

#include <iostream>
#include <time.h>
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

	std::cout << "[Test Screen Start]" << std::endl;
	m->Init(new Field_Basic());

}

void Screen_Test::Cleanup()
{
	delete m;
	m = NULL;
	std::cout << "[Test Screen Quit]" << std::endl;
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
			if( e.type == SDL_KEYDOWN ) {
				// ESCAPE is pressed
				if (e.key.keysym.sym == SDLK_ESCAPE) {
					game->PopScreen();
				}

				if (e.key.keysym.sym == SDLK_p) {
					this->Pause();
					game->PushScreen(Screen_Pause::Instance());
				}

				if (e.key.keysym.sym == SDLK_UP ) {
					for (auto &player : m->GetPlayers() ) {
						Paddle* pad = player->GetPaddle();
						//vec2f chVelocity = {0.f, -2.f};
						pad->SetVelocity({pad->GetVelocity().x, -4});
					}
				}

				if (e.key.keysym.sym == SDLK_DOWN ) {
					for (auto &player : m->GetPlayers() ) {
						Paddle* pad = player->GetPaddle();
						//vec2f chVelocity = {0.f, 2.f};
						pad->SetVelocity({pad->GetVelocity().x, 4});
					}
				}

			}

			if( e.type == SDL_KEYUP ) {
				if (e.key.keysym.sym == SDLK_UP ) {
					for (auto &player : m->GetPlayers() ) {
						Paddle* pad = player->GetPaddle();
						pad->SetVelocity({pad->GetVelocity().x, 0});
					}
				}

				if (e.key.keysym.sym == SDLK_DOWN ) {
					for (auto &player : m->GetPlayers() ) {
						Paddle* pad = player->GetPaddle();
						pad->SetVelocity({pad->GetVelocity().x, 0});
					}
				}
			}
		}
	}

	/*const Uint8* keyStates = SDL_GetKeyboardState(NULL);
	if( keyStates[SDL_SCANCODE_UP]) {
		for (auto &player : m->GetPlayers() ) {
			Paddle* pad = player->GetPaddle();
			vec2f chVelocity = {0.f, -2.f};
			pad->SetVelocity(pad->GetVelocity() + chVelocity);
		}
	}
	if( keyStates[SDL_SCANCODE_DOWN]) {
		for (auto &player : m->GetPlayers() ) {
			Paddle* pad = player->GetPaddle();
			vec2f chVelocity = {0.f, 2.f};
			pad->SetVelocity(pad->GetVelocity() + chVelocity);
		}
	}*/
}

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