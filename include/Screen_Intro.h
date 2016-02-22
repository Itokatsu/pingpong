#ifndef DEF_SCREEN_INTRO
#define DEF_SCREEN_INTRO

#include "GameScreen.h"
#include "SDL.h"

class Screen_Intro : public GameScreen
{
	public:
		void Init();
		void Cleanup();

		void Pause();
		void Unpause();

		void HandleEvents(GameEngine* game);
		void Update(GameEngine* game);
		void Draw(GameEngine* game, GraphicEngine* gfx);

		static Screen_Intro* Instance();

	protected:
		Screen_Intro();

	private:
		static Screen_Intro myIntro;

};

#endif