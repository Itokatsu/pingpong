#ifndef DEF_SCREEN_TEST
#define DEF_SCREEN_TEST

#include "IGameScreen.h"
#include "Paddle.h"
#include <time.h>
#include "TimerSDL.h"

class Screen_Test : public IGameScreen
{
	public:
		void Init();
		void Cleanup();

		void Pause();
		void Unpause();

		void HandleEvents(GameEngine* game);
		void Update(GameEngine* game);
		void Draw(GameEngine* game);

		//Singleton
		static Screen_Test* Instance();

	protected:
		Screen_Test();

	private:
		Paddle paddle1;
		Paddle paddle2;
		Ball ball;

		
		TimerSDL updateTime;
		TimerSDL runTime;
		TimerSDL FPSTimer;
		int framesThisSec;
		bool once;


		//Singleton
		static Screen_Test myTest;

};

#endif