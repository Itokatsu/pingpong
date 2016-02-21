#include "GameEngine.h"
#include "GameScreen.h"
#include "Screen_Intro.h"

int GameEngine::Init()
{
	screens.push_back(Screen_Intro::Instance());
	screens.back()->Init();
	running = true;
	GraphicEngine gfx;
	return gfx.Init();
}

void GameEngine::Cleanup()
{
	//clear the stack
	while (!screens.empty()) {
		screens.back()->Cleanup();
		screens.pop_back();
	}
	gfx.Cleanup();
}

void GameEngine::ChangeScreen(GameScreen* screen)
{
	//quit current Screen
	if (!screens.empty()) {
		screens.back()->Cleanup();
		screens.pop_back();
	}

	//add new screen
	screens.push_back(screen);
	screens.back()->Init();
}

void GameEngine::PushScreen(GameScreen* screen)
{
	if (!screen->allowBG()) {
		screens.back()->Pause();
	}

	screens.push_back(screen);
	screens.back()->Init();
}

void GameEngine::PopScreen()
{
	//remove current screen
	if (!screens.empty()) {
		screens.back()->Cleanup();
		screens.pop_back();
	}

	//resume previous screen
	if (!screens.empty() && screens.back()->isPaused()) {
		screens.back()->Unpause();
	}

	if (screens.empty()) {
		running = false;
	}
}

void GameEngine::HandleEvents()
{
	screens.back()->HandleEvents(this);
}

void GameEngine::Update()
{
	screens.back()->Update(this);
}

void GameEngine::Draw()
{
	screens.back()->Draw(this, &gfx);
}

bool GameEngine::isRunning()
{
	return running;
}