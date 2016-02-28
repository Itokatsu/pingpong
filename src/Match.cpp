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
		Player p = Player(pos, field.GetPaddleSize().ToSDLPoint());
		players.push_back(p);
	}

	vec2f bPos = field.GetBallInitPos();
	vec2f bVelo = field.GetBallInitVelocity();
	ball = Ball(bPos);
	ball.SetVelocity(bVelo);
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

void Match::Update(float dT)
{
	for (auto &player : players) {
		player.GetPaddle()->UpdatePosition(dT, this);
	}
	ball.UpdatePosition(dT, this);
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

//JUST A BABY CHECK
void Match::ChkCollision(IHasCollision* c)
{
	SDL_Rect cBox = c->GetCollisionBox();
	SDL_Rect cMask = {0,0,0,0};
	//SDL_bool SDL_IntersectRect(SDL_Rect* A, SDL_Rect* B, SDL_Rect* intersect)
	for (auto &player : players) {
		SDL_Rect padBox= player.GetPaddle()->GetCollisionBox();
		if ( SDL_IntersectRect(&cBox, &padBox, &cMask) == SDL_TRUE ) {
			//std::cout << "Collision detected !" << std::endl;
			c->AcceptCollision(player.GetPaddle(), cMask);
		}
	}
}