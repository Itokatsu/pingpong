#include "IGameScreen.h"

bool IGameScreen::isPaused() 
{
	return paused;
}

bool IGameScreen::allowBG()
{
	return allowRunningBG;
}