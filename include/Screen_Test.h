#ifndef DEF_SCREEN_TEST
#define DEF_SCREEN_TEST

#include "GameScreen.h"
#include "SDL.h"
#include "Paddle.h"

class Screen_Test : public GameScreen
{
	public:
		void Init();
		void Cleanup();

		void Pause();
		void Unpause();

		void HandleEvents(GameEngine* game);
		void Update(GameEngine* game);
		void Draw(GameEngine* game, GraphicEngine* gfx);

		static Screen_Test* Instance();

	protected:
		Screen_Test();

	private:
		Paddle paddle;
		int direction;
		static Screen_Test myTest;

};

#endif