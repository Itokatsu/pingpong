#include "GraphicEngine.h"
#include "SDL.h"
#include <iostream>

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
		std::cerr << "SDL could not initialize! SDL_Error:" << SDL_GetError() << std::endl;
		returnValue = -1;
	}
	else {
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) ) {
			std::cerr << "Warning: Linear texture filtering not enabled!" << std::endl;
			returnValue = -1;
		}
		//Create window
		window = SDL_CreateWindow("Game of the year : Hobo Edition", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,	
									SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL)	{
			std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
			returnValue = -1;
		}
		else {
			initialized = true;
			
			// for surface usage
			/*screenSurface = SDL_GetWindowSurface(window);*/

			// creating renderer (texture usage)
			renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
			// renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED);
			SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
			if( renderer == NULL ) {
				std::cerr << "Renderer could not be created! SDL Error: " << SDL_GetError() << std::endl;
				returnValue = -1;
			}
			SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
			SDL_RenderClear( renderer );
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

SDL_Renderer* GraphicEngine::GetRenderer()
{
	return renderer;
}