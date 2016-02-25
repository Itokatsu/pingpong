#include "Match.h"

//temporary includes
#include <iostream>
using namespace std;

Player::Player(vec2f pos)
{
	score = 0;
	pad = Paddle(pos);
	cout << "Creation of Player instance" << endl;
}

int Player::GetScore()
{
	return this->score;
}

int Player::IncrScore(int d)
{
	this->score += d;
	return score;
}