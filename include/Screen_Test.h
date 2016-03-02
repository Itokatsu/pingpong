#ifndef DEF_SCREEN_TEST
#define DEF_SCREEN_TEST

#include "IGameScreen.h"
#include "TimerSDL.h"
#include "Match.h"

#include <time.h>

class Screen_Test : public IGameScreen
{
	public:
		void Init();
		void Cleanup();

		void HandleEvents(GameEngine* game);
		void Update(GameEngine* game, float dT);
		void Draw(GameEngine* game);

		//Singleton
		static Screen_Test* Instance();

	protected:
		Screen_Test();

	private:
		Match* m;

		//Singleton
		static Screen_Test myTest;

};

#endif