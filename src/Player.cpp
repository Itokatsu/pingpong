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

Paddle* Player::GetPaddle()
{
	return &pad;
}

int Player::GetScore()
{
	return score;
}

int Player::IncrScore(int d)
{
	score += d;
	return score;
}