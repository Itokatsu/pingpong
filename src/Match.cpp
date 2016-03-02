#include "Match.h"
#include "Goal.h"
//temporary includes
#include <iostream>
#include <string>

Match::Match(int limit)
{
	this->settings.scoreLimit = limit;
	std::cout << " + Match created" << std::endl;
}

Match::~Match()
{
	delete ball;
	ball = NULL;
	delete field;
	field = NULL;

	for (auto &player : players) {
		delete player;
		player = NULL;
	}
	players.clear();


	std::cout << " - Match deleted" << std::endl;
}


void Match::Init(IField* f)
{
	field = f;
	int playerid = 1;
	for ( auto &pos : field->GetPlayersInitPos() ) {
		//create and push_back
		Player* p = new Player("Player " + std::to_string(playerid++), pos, field->GetPaddleSize().ToSDLPoint());
		Paddle* pad = p->GetPaddle();
		pad->SetVelocity({0,-1});
		players.push_back(p);
	}

	vec2f bPos = field->GetBallInitPos();
	vec2f bVelo = field->GetBallInitVelocity();
	ball = new Ball(bPos);
	ball->SetVelocity(bVelo);
}

void Match::Start()
{
	//this->time = 0;
}

bool Match::IsMatchFinished()
{	
	bool flag = false;
	for (auto &p : this->players) {
		if (p->GetScore() >= this->settings.scoreLimit) {
			flag = true;
			break;
		}
	}
	return flag;
}

void Match::Update(float dT)
{
	for (auto &player : players) {
		player->GetPaddle()->UpdatePosition(dT, this);
	}
	ball->UpdatePosition(dT, this);
}

IField* Match::GetField()
{
	return field;
}

std::vector<Player*> Match::GetPlayers()
{
	return players;
}

Ball* Match::GetBall()
{
	return ball;
}

//JUST A BABY CHECK
void Match::ChkCollision(IHasCollision* c)
{
	SDL_Rect* cBox = c->GetCollisionBox();
	SDL_Rect cMask = {0,0,0,0};
	//SDL_bool SDL_IntersectRect(SDL_Rect* A, SDL_Rect* B, SDL_Rect* intersect)

	//out of bounds check
	SDL_Rect fBox = {0,0,field->GetWidth(),field->GetHeight()};
	if ( SDL_IntersectRect(cBox, &fBox, &cMask) == SDL_FALSE) {
		c->AcceptCollision(field, &cMask);
		std::cout << "Collision detected !" << std::endl;
	}
	else if (SDL_RectEquals(cBox, &cMask) == SDL_FALSE) {
		c->AcceptCollision(field, &cMask);
		std::cout << "Collision with Field detected !" << std::endl;
	}

	//check for goal
	for (auto &goal : field->GetGoals() ) {
		SDL_Rect* goalBox = goal->GetCollisionBox();
		if ( SDL_IntersectRect(cBox, goalBox, &cMask) == SDL_TRUE ) {
			c->AcceptCollision(goal, &cMask);
		}
	}

	//paddle check
	for (auto &player : players) {
		//do nothing if c is the paddle. (you don't want to check paddles with themselves)
		Paddle* pad = player->GetPaddle();
		if (c != pad) {
			SDL_Rect* padBox = pad->GetCollisionBox();
			if ( SDL_IntersectRect(cBox, padBox, &cMask) == SDL_TRUE ) {
				std::cout << "Mask : (" << cMask.x << "," << cMask.y << "," << cMask.w << "," << cMask.h << ")" << std::endl;
				//std::cout << "Collision with Paddle detected !" << std::endl;
				c->AcceptCollision(pad, &cMask);
			}
		}
	}
}