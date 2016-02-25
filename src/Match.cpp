#include "Match.h"

//temporary includes
#include <iostream>
using namespace std;

Match::Match(int limit)
{
	this->settings.scoreLimit = limit;
	cout << "Creation of Match instance" << endl;
}


void Match::Init(IField f)
{
	field = f;
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

bool Match::IsMatchFinished()
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

IField* Match::GetField()
{
	return &field;
}

std::vector<Player> Match::GetPlayers()
{
	return players;
}

Ball* Match::GetBall()
{
	return &ball;
}