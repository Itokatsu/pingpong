#include "Match.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

int main( )
{
	cout << "testing this shit" << endl;
	Match m(10);
	m.Init();
	while (not m.isMatchFinished()) {
		m.Draw();
		int playerId = rand() % 2;
		m.players[playerId].IncrScore();
	}
	cout << "Match Ended" << endl;
	m.Draw();
}