//Using SDL and standard IO
#include <iostream>
#include <unistd.h>
#include "GameEngine.h"


int main( int argc, char* args[] )
{
	GameEngine game;
	game.Init();
	while ( game.isRunning() ) {
		game.HandleEvents();
		game.Update();
	}

	game.Cleanup();

}