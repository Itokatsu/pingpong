#include "Screen_Test.h"
#include <iostream>
#include <time.h>
#include "SDL.h"
#include "Field_Basic.h"

#include <string>
#include <stdio.h>

Screen_Test Screen_Test::myTest;

const std::string currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    // Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
    // for more information about date/time format
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

    return buf;
}

Screen_Test::Screen_Test()
{

}

void Screen_Test::Init()
{
	std::cout << "[Test Screen Start]" << std::endl;
	m.Init(Field_Basic());

	runTime.start();
	updateTime.start();
	FPSTimer.start();
	framesThisSec = 0;
	std::cout << "starting @ " << currentDateTime() << std::endl;
}

void Screen_Test::Cleanup()
{
	std::cout << "[Test Screen Quit]" << std::endl;
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
	//clock_t diff = clock()-timerStart;
	//Uint32 diff = updateTime.getTime(); //ms
	//float dTime = diff / 1000.f; //seconds

	//timerStart = clock();
	updateTime.reset();
	//affichage ghetto
	/*if (runTime.getTime() > 1000 && !once) {
		once = true;
		std::cout << "1sec passed @ " << currentDateTime() << std::endl;
	}*/

	//affichage fps
	if (FPSTimer.getTime() >= 1000) {
		std::cout << "FPS : " << framesThisSec << std::endl;
		FPSTimer.reset();
		framesThisSec = 0;
	}


	framesThisSec++;
	//SDL_Delay(20);
}

void Screen_Test::Draw(GameEngine* game)
{
	//set BG color
	SDL_SetRenderDrawColor( game->GetGraphicEngine()->GetRenderer(), 0x2A, 0x2A, 0x34, 0xFF );
	SDL_RenderClear( game->GetGraphicEngine()->GetRenderer() );

	//game->GetDrawEngine()->DrawPaddle(&paddle1, game);
	//game->GetDrawEngine()->DrawPaddle(&paddle2, game);
	game->GetDrawEngine()->DrawMatch(&m, game);

	//update
	SDL_RenderPresent( game->GetGraphicEngine()->GetRenderer() );
}

Screen_Test* Screen_Test::Instance()
{
	return &myTest;
}