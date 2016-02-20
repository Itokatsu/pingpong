#ifndef DEF_MATCH
#define DEF_MATCH

#include "GameScreen.h"

class Screen_Intro : public GameScreen
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