#ifndef DEF_GAMEENGINE
#define DEF_GAMEENGINE

#include <vector>

class GameScreen;

class GameEngine
{
	public:
		/*Load SDL etc..*/
		void Init();
		void Cleanup();

		void ChangeScreen(GameScreen* screen);
		void PushScreen(GameScreen* screen);
		void PopScreen();

		void HandleEvents();
		void Update();
		void Draw();

		bool isRunning();

	private:
		//stack of Screen
		std::vector<GameScreen*> screens;
		bool running;

};

#endif
