#ifndef DEF_SCREEN_TEST
#define DEF_SCREEN_TEST

#include "GameScreen.h"
#include "Paddle.h"
#include <time.h>

class Screen_Test : public GameScreen
{
	public:
		void Init();
		void Cleanup();

		void Pause();
		void Unpause();

		void HandleEvents(GameEngine* game);
		void Update(GameEngine* game);
		void Draw(GameEngine* game);

		static Screen_Test* Instance();

	protected:
		Screen_Test();

	private:
		Paddle paddle1;
		Paddle paddle2;
		int direction;
		clock_t t;
		static Screen_Test myTest;

};

#endif