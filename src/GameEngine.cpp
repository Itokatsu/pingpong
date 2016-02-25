#include "GameEngine.h"
#include "DrawEngine.h"
#include "IGameScreen.h"
#include "Screen_Test.h"
//#include "Screen_Intro.h"

int GameEngine::Init()
{
	int returnValue = 0;
	running = true;
	//start intro
	//screens.push_back(Screen_Intro::Instance());
	//start test
	screens.push_back(Screen_Test::Instance());
	screens.back()->Init();

	//init graphic engine
	gfx = new GraphicEngine();
	if (gfx->Init() < 0) {
		returnValue = -1;
	}
	else {
		//init draw engine
		drawer = new DrawEngine();
		drawer->Init(gfx); //TODO : handle init errors
	}
	return returnValue;
}

void GameEngine::Cleanup()
{
	//clear the stack
	while (!screens.empty()) {
		screens.back()->Cleanup();
		screens.pop_back();
	}
	//clean draw engine
	drawer->Cleanup();
	delete drawer;
	drawer = NULL;

	//clean graphic engine
	gfx->Cleanup();
	delete gfx;
	gfx = NULL;

}

void GameEngine::ChangeScreen(IGameScreen* screen)
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

void GameEngine::PushScreen(IGameScreen* screen)
{
	//pause current screen
	if (!screen->allowBG()) {
		screens.back()->Pause();
	}

	//start new top screen
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

	//no screen > exit game
	if (screens.empty()) {
		this->Quit();
	}
}

//let current screen handle events, update and draw
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
	screens.back()->Draw(this);
}

void GameEngine::Quit()
{
	running = false;
}

bool GameEngine::isRunning()
{
	return running;
}

GraphicEngine* GameEngine::GetGraphicEngine()
{
	return gfx;
}

DrawEngine* GameEngine::GetDrawEngine()
{
	return drawer;
}