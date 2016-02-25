#ifndef DEF_MATCH
#define DEF_MATCH

#include "IField.h"
#include "Player.h"
#include "Ball.h"
#include <vector>

struct MatchSettings {
	int scoreLimit;
};

class Match
{
	public:
		//Match(int limit);
		void Init();
		void Start();
		//bool isGameFinished(int& player);
		bool isMatchFinished();
		
	private:
		IField field;
		MatchSettings settings;
		std::vector<Player> players;
		//int time;
		Ball ball;

};

#endif