#include "Match.h"

//temporary includes
#include <iostream>

Player::Player(std::string name, vec2f pos, SDL_Point padSize)
{
	score = 0;
	this->name = name;
	std::cout << " + Player \"" << this->name << "\" created " << std::endl;
	pad = new Paddle(this, pos, padSize);
}

Player::Player(vec2f pos)
{
	score = 0;
	std::cout << " + Player created " << std::endl;
	pad = new Paddle(this, pos);
}

Player::~Player()
{
	delete pad;
	pad = NULL;
	std::cout << " - Player \"" << this->name << "\" deleted" << std::endl;
}

Paddle* Player::GetPaddle()
{
	return pad;
}

int Player::IncrScore(int d)
{
	score += d;
	return score;
}

int Player::GetScore()
{
	return score;
}

std::string Player::GetName()
{
	return name;
}