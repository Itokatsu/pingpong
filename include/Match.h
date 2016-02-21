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
		void Pause();
		void Unpause();
		void Draw();
		void DrawOverlay();
		//bool isGameFinished(int& player);
		bool isMatchFinished();
		std::vector<Player> players;

	private:
		//Field field;
		MatchSettings settings;
		int time;
		//Ball ball;

};

#endif