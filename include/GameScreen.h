#ifndef DEF_GAMESCREEN
#define DEF_GAMESCREEN

#include "GameEngine.h"
#include "GraphicEngine.h"
#include "SDL.h"


/*Pure abstract class 
  i.e. TitleScreen LoadingScreen MatchScreen PostMatchScreen ... */

class GameScreen
{
	public:
		//Creation of all the GameScreen's assets
		virtual void Init() = 0;
		//Deleting assets
		virtual void Cleanup() = 0;

		//Halts updates of the screen
		virtual void Pause() = 0;
		//Resumes the screen updates
		virtual void Unpause() = 0;

		/*  Handles things like user inputs
		    a menu doesn't treat them in the same way a MatchScreen does */
		virtual void HandleEvents(GameEngine* game) = 0;
		/*  Goes to next frame */
		virtual void Update(GameEngine* game) = 0;
		/* Draw the screen */
		virtual	void Draw(GameEngine* game) = 0;

		bool isPaused();
		bool allowBG();

	private:
		bool paused = false;
		//allowing background screen to update
		bool allowRunningBG = false;
};

#endif