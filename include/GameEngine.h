#ifndef DEF_GAMEENGINE
#define DEF_GAMEENGINE

#include <vector>
#include "GraphicEngine.h"

class GameScreen;

class GameEngine
{
	public:
		/*Load SDL etc..*/
		int Init();
		void Cleanup();

		void ChangeScreen(GameScreen* screen);
		void PushScreen(GameScreen* screen);
		void PopScreen();

		void HandleEvents();
		void Update();
		void Draw();

		void Quit();
		bool isRunning();

	private:
		//stack of Screen
		std::vector<GameScreen*> screens;
		bool running;
		GraphicEngine gfx;

};

#endif
