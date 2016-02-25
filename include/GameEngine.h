#ifndef DEF_GAMEENGINE
#define DEF_GAMEENGINE

#include <vector>
#include "GraphicEngine.h"

class IGameScreen;
class DrawEngine;

class GameEngine
{
	public:
		/*Load SDL etc..*/
		int Init();
		void Cleanup();

		void ChangeScreen(IGameScreen* screen);
		void PushScreen(IGameScreen* screen);
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
		std::vector<IGameScreen*> screens;
		bool running;
		GraphicEngine* gfx;
		DrawEngine* drawer;

};

#include "DrawEngine.h"
#include "IGameScreen.h"

#endif
