#ifndef DEF_GAMEENGINE
#define DEF_GAMEENGINE

#include <vector>
#include "GraphicEngine.h"

class GameScreen;
class DrawEngine;

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

		GraphicEngine* GetGraphicEngine();
		DrawEngine* GetDrawEngine();

		const unsigned int FPSMAX = 60;

	private:
		//stack of Screen
		std::vector<GameScreen*> screens;
		bool running;
		GraphicEngine* gfx;
		DrawEngine* drawer;

};

#include "DrawEngine.h"
#include "GameScreen.h"

#endif
