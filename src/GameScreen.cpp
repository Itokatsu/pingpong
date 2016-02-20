#include "GameScreen.h"

bool GameScreen::isPaused() 
{
	return paused;
}

bool GameScreen::allowBG()
{
	return allowRunningBG;
}