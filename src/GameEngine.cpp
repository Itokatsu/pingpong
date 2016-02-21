#include "GameEngine.h"
#include "GameScreen.h"
#include "Screen_Intro.h"
#include <SDL.h>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
//The window we'll be rendering to
SDL_Window* window = NULL;

void GameEngine::Init()
{
	//The surface contained by the window
	SDL_Surface* screenSurface = NULL;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
	else
	{
		//Create window
		window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		}
		else
		{
			//Get window surface
			screenSurface = SDL_GetWindowSurface(window);

			//Fill the surface white
			SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));

			//Update the surface
			SDL_UpdateWindowSurface(window);

			//Wait two seconds
			SDL_Delay(2000);
		}
	}
	screens.push_back(Screen_Intro::Instance());
	screens.back()->Init();
	running = true;
}

void GameEngine::Cleanup()
{
	//clear the stack
	while (!screens.empty()) {
		screens.back()->Cleanup();
		screens.pop_back();
	}
	//Destroy window
	SDL_DestroyWindow(window);

	//Quit SDL subsystems
	SDL_Quit();
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
	screens.back()->Draw(this);
}

bool GameEngine::isRunning()
{
	return running;
}