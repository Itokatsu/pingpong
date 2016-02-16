#include "Game.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

int main( )
{
	cout << "testing this shit" << endl;
	Game g(10);
	g.Init();
	while (not g.isGameFinished()) {
		g.Draw();
		int playerId = rand() % 2;
		g.players[playerId].IncrScore();
	}
	cout << "Match Ended" << endl;
	g.Draw();
}