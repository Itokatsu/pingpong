#ifndef DEF_MATCH
#define DEF_MATCH

#include "Player.h"
#include <vector>

struct MatchSettings {
	int scoreLimit;
};

class Match
{
	public:
		Match(int limit);
		void Init();
		void Start();
		void Draw();
		//bool isGameFinished(int& player);
		bool isMatchFinished();
		
	private:
		//Field field;
		MatchSettings settings;
		std::vector<Player> players;
		int time;
		//Ball ball;

};

#endif