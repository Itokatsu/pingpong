//Using SDL and standard IO
#include <iostream>
#include "GameEngine.h"


int main( int argc, char* args[] )
{

	GameEngine game;
	game.Init();
	game.Draw();
	while ( game.isRunning() ) {
		game.Draw();
		game.HandleEvents();
		game.Update();
	}

	game.Cleanup();

	return 0;
}