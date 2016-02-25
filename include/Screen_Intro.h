#ifndef DEF_SCREEN_INTRO
#define DEF_SCREEN_INTRO

#include "IGameScreen.h"

class Screen_Intro : public IGameScreen
{
	public:
		void Init();
		void Cleanup();

		void Pause();
		void Unpause();

		void HandleEvents(GameEngine* game);
		void Update(GameEngine* game);
		void Draw(GameEngine* game);

		static Screen_Intro* Instance();

	protected:
		Screen_Intro();

	private:
		static Screen_Intro myIntro;

};

#endif