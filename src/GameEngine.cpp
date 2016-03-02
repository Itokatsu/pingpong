#include "GameEngine.h"
#include "DrawEngine.h"
#include "IGameScreen.h"
#include "Screen_Intro.h"
#include "Screen_Test.h"

#include <iostream>


int GameEngine::Init()
{
	int returnValue = 0;
	running = true;
	//start intro
	screens.push_back(Screen_Intro::Instance());
	//start test
	//screens.push_back(Screen_Test::Instance());
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

	//start timers
	framesThisSec = 0;
	runTime.start();
	updateTime.start();
	FPSTimer.start();

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
	if (!screen->RunBG()) {
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
	if (!screens.empty() && screens.back()->IsPaused()) {
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
	Uint32 diff = updateTime.getTime(); //ms
	updateTime.reset();
	float dTime = diff*60 / 1000.f; // convert to 1/60ths of second

	// FPS Display
	if (FPSTimer.getTime() >= 1000) { //1sec passed
		std::cout << "FPS : " << framesThisSec << std::endl;
		FPSTimer.reset();
		framesThisSec = 0;
	}

	unsigned int idx = screens.size()-1;
	while ( screens.at(idx)->RunBG() && idx >= 0 ) {
		idx--;
	}
	while ( idx <= screens.size()-1) {
		screens.at(idx)->Update(this, dTime);
		idx++;
	}
	framesThisSec++;
}

void GameEngine::Draw()
{
	SDL_SetRenderDrawColor( gfx->GetRenderer(), 0x2A, 0x2A, 0x34, 0xFF );
	SDL_RenderClear( gfx->GetRenderer() );

	unsigned int idx = screens.size()-1;
	while ( screens.at(idx)->DisplayBG() && idx >= 0 ) {
		idx--;
	}
	while ( idx <= screens.size()-1) {
		screens.at(idx)->Draw(this);
		idx++;
	}
	//update
	SDL_RenderPresent( gfx->GetRenderer() );
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