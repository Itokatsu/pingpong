#ifndef DEF_PLAYER
#define DEF_PLAYER

class Player
{
	public:
		Player();
		void Draw();
		int GetScore();
		//Return new score value
		int IncrScore(int d=1);

	private:
		int id;
		int score;

};

#endif