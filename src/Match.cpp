#include "Match.h"

//temporary includes
#include <iostream>
using namespace std;

Match::Match(int limit=5)
{
	this->settings.scoreLimit = limit;
	cout << "Creation of Match instance" << endl;
}


void Match::Init()
{
	//create Players
	Player p1, p2;
	players.push_back(p1);
	players.push_back(p2);
}

void Match::Start()
{
	this->time = 0;
}


void Match::Draw()
{
	//temporary toString behaviour
	cout << "Player1  " << players[0].GetScore();
	cout << " - " << players[1].GetScore() << " Player2" << endl;
}

bool Match::isMatchFinished()
{	
	bool flag = false;
	for (auto &p : this->players) {
		if (p.GetScore() >= this->settings.scoreLimit) {
			flag = true;
			break;
		}
	}
	return flag;
}