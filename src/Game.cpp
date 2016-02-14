#include "Game.h"

//temporary includes
#include <iostream>

using namespace std;

Game::Game()
{
	this->settings.scoreLimit = 3;
	cout << "Creation of Game instance" << endl;
}

void Game::Init()
{
	//create Players
	Player p1, p2;
	players.push_back(p1);
	players.push_back(p2);
}

void Game::Start()
{
	this->time = 0;
}


void Game::Draw()
{
	//temporary toString behaviour
	cout << "Player1  " << players[0].GetScore();
	cout << " - " << players[1].GetScore() << " Player2" << endl;
}

bool Game::isGameFinished()
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