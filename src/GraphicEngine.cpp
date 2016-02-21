#include "GraphicEngine.h"
#include "SDL.h"
#include <stdio.h>

GraphicEngine::GraphicEngine()
{
	window = NULL;
	screenSurface = NULL;
	initialized = false;
}


int GraphicEngine::Init()
{
	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		return -1;
	}
	else {
		//Create window
		window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,	
									SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL)	{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			return -2;
		}
		else {
			initialized = true;
			//Get window surface
			screenSurface = SDL_GetWindowSurface(window);
			return 0;
		}
	}
}

void GraphicEngine::Cleanup()
{
	if ( initialized ) {
		//Destroy window
		SDL_DestroyWindow(window);

		//Quit SDL subsystems
		SDL_Quit();
	}
}