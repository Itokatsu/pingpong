#include "Match.h"

//temporary includes
#include <iostream>
using namespace std;

// Match::Match(int limit=5)
// {
// 	this->settings.scoreLimit = limit;
// 	cout << "Creation of Match instance" << endl;
// }


void Match::Init()
{
	for (auto &pos : field.GetPlayersInitPos()){
		//create and push_back
		Player p = Player(pos);
		players.push_back(p);
	}

	vec2f pos = field.GetBallInitPos();
	ball = Ball(pos);
}

void Match::Start()
{
	//this->time = 0;
}



// void Match::Draw()
// {
// 	//temporary toString behaviour
// 	cout << "Player1  " << players[0].GetScore();
// 	cout << " - " << players[1].GetScore() << " Player2" << endl;
// }

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