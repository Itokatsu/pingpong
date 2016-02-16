#ifndef DEF_GAME
#define DEF_GAME

#include "Player.h"
#include <vector>

struct MatchSettings {
	int scoreLimit;
};

class Game 
{
	public:
		Game(int limit);
		void Init();
		void Start();
		void Pause();
		void Unpause();
		void Draw();
		void DrawOverlay();
		//bool isGameFinished(int& player);
		bool isGameFinished();
		std::vector<Player> players;


	private:
		//Field field;
		MatchSettings settings;
		int time;
		//Ball ball;

};

#endif