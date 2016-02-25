#ifndef DEF_PLAYER
#define DEF_PLAYER

#include "Vec2.h"
#include "Paddle.h"

class Player
{
	public:
		Player(vec2f pos);
		void Draw();
		int GetScore();
		//Return new score value
		int IncrScore(int d=1);

	private:
		int id;
		int score;
		Paddle pad;

};

#endif