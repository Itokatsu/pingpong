#include "Match.h"

//temporary includes
#include <iostream>
using namespace std;

Player::Player(vec2f pos)
{
	score = 0;
	pad = Paddle(pos);
}

Player::Player(vec2f pos, SDL_Point padSize)
{
	score = 0;
	pad = Paddle(pos, padSize);
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