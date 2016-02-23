#include "Screen_Test.h"
#include <iostream>
#include <time.h>
#include "SDL.h"

Screen_Test Screen_Test::myTest;

Screen_Test::Screen_Test()
{

}

void Screen_Test::Init()
{
	std::cout << "Test Screen Start" << std::endl;
	paddle1 = Paddle(400,400);
	paddle2 = Paddle(400,50);
	//paddle.PrintCoords();
	paddle1.SetVelocity({2, 0});
	paddle2.SetVelocity({-1, 0});
	paddle2.SetSize({120, 10});
	t = clock();
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
		//Close window
		if( e.type == SDL_QUIT ) {
			game->Quit();
		}

		else {
			if( e.type == SDL_KEYDOWN ) {
				//ESCAPE is pressed
				if (e.key.keysym.sym == SDLK_ESCAPE) {
					game->Quit();
				}
			}
		}
	}
}

void Screen_Test::Update(GameEngine* game)
{
	t = clock()-t;
	float dTime = ((float)t) / CLOCKS_PER_SEC;
	t = clock();

	if (paddle1.GetPos().x + paddle1.GetSize().x + paddle1.GetVelocity().x <= 640 &&
		paddle1.GetPos().x + paddle1.GetVelocity().x >= 0) {
		//SDL_Point pos = {paddle1.GetPos().x + paddle1.GetVelocity().x, paddle1.GetPos().y};
		//paddle1.SetPos( pos );
		paddle1.UpdatePosition(dTime);
	}
	else {
		paddle1.SetVelocity( {-paddle1.GetVelocity().x ,paddle1.GetVelocity().y} );
		
		//Out of Bounds
		if (paddle1.GetPos().x < 0)
		{
			paddle1.SetPos({ 0, paddle1.GetPos().y });
		}
		else if ((paddle1.GetPos().x + paddle1.GetSize().x) > 640)
		{
			paddle1.SetPos({ 640 - paddle1.GetSize().x, paddle1.GetPos().y });
		}
	}


	if (paddle2.GetPos().x + paddle2.GetSize().x + paddle2.GetVelocity().x <= 640 &&
		paddle2.GetPos().x + paddle2.GetVelocity().x >= 0) {
		SDL_Point pos = {paddle2.GetPos().x + paddle2.GetVelocity().x, paddle2.GetPos().y};
		paddle2.SetPos( pos );
		//paddle2.UpdatePosition(dTime);
	}
	else {
		paddle2.SetVelocity( {-paddle2.GetVelocity().x ,paddle2.GetVelocity().y} );

		////Out of Bounds
		//if (paddle2.GetPos().x < 0)
		//{
		//	paddle2.SetPos({ 0, paddle2.GetPos().y });
		//}
		//else if ((paddle2.GetPos().x + paddle2.GetSize().x) > 640)
		//{
		//	paddle2.SetPos({ 640 - paddle2.GetSize().x, paddle2.GetPos().y });
		//}
	}	

	SDL_Delay(30);
}

void Screen_Test::Draw(GameEngine* game)
{
	//set BG color
	SDL_SetRenderDrawColor( game->GetGraphicEngine()->GetRenderer(), 0x2A, 0x2A, 0x34, 0xFF );
	SDL_RenderClear( game->GetGraphicEngine()->GetRenderer() );
	game->GetDrawEngine()->DrawPaddle(&paddle1, game);
	game->GetDrawEngine()->DrawPaddle(&paddle2, game);

	//update
	SDL_RenderPresent( game->GetGraphicEngine()->GetRenderer() );
}

Screen_Test* Screen_Test::Instance()
{
	return &myTest;
}