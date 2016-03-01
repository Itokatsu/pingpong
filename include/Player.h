#ifndef DEF_PLAYER
#define DEF_PLAYER

#include "Vec2.h"
#include "Paddle.h"
#include <string>

class Player
{
	public:
		Player(vec2f pos);
		Player(std::string name, vec2f pos, SDL_Point padSize);
		~Player();
	
		//Return new score value
		int IncrScore(int d=1);
		Paddle* GetPaddle();
		std::string GetName();
		int GetScore();

	private:
		std::string name;
		int id;
		int score;
		Paddle* pad;

};

#endif