#include "GraphicEngine.h"
#include "SDL.h"
#include <stdio.h>

GraphicEngine::GraphicEngine()
{
	window = NULL;
	screenSurface = NULL;
	initialized = false;
	renderer = NULL;
}


int GraphicEngine::Init()
{
	int returnValue = 0;
	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		returnValue = -1;
	}
	else {
		//Create window
		window = SDL_CreateWindow("Game of the year : Hobo Edition", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,	
									SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL)	{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			returnValue = -2;
		}
		else {
			initialized = true;
			//Get window surface
			
			//for surface usage
			//screenSurface = SDL_GetWindowSurface(window);

			//creating renderer (texture usage)
			renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );
            if( renderer == NULL ) {
                printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
                returnValue = -3;
            }
		}
	}
	return returnValue;
}

void GraphicEngine::Cleanup()
{
	if ( initialized ) {

	    SDL_FreeSurface(screenSurface);
	    screenSurface = NULL;

		SDL_DestroyRenderer( renderer );
		renderer = NULL;

		//Destroy window
		SDL_DestroyWindow(window);
		window = NULL;

		//Quit SDL subsystems
		SDL_Quit();
	}
}

SDL_Renderer* GraphicEngine::getRenderer()
{
	return renderer;
}