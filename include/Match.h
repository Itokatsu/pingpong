#ifndef DEF_MATCH
#define DEF_MATCH

#include "IField.h"
#include "IHasCollision.h"
#include "Player.h"
#include "Ball.h"
#include <vector>
#include "SDL.h"

struct MatchSettings {
	int scoreLimit;
};

class Match
{
	public:
		Match(int limit=5);
		~Match();

		void Init(IField* f);
		void Start();
		//bool isGameFinished(int& player);
		bool IsMatchFinished();
		void Update(float dT);

		void ChkCollision(IHasCollision* c);

		IField* GetField();
		std::vector<Player*> GetPlayers();
		Ball* GetBall();
		
	private:
		IField* field;
		MatchSettings settings;
		std::vector<Player*> players;
		Ball* ball;

};

#endif