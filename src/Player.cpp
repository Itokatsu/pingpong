#include "Game.h"

//temporary includes
#include <iostream>
using namespace std;

Player::Player()
{
	this->score = 0;
	cout << "Creation of Player instance : " << this->score << endl;
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