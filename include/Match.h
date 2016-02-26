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
		Match(int limit=5);
		void Init(IField f);
		void Start();
		//bool isGameFinished(int& player);
		bool IsMatchFinished();
		void Update(float dT);

		IField* GetField();
		std::vector<Player> GetPlayers();
		Ball* GetBall();
		
	private:
		IField field;
		MatchSettings settings;
		std::vector<Player> players;
		//int time;
		Ball ball;

};

#endif