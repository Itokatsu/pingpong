#ifndef DEF_GRAPHENGINE
#define DEF_GRAPHENGINE

#include "SDL.h"

class GraphicEngine {

	public:
		GraphicEngine();
		int Init();
		void Cleanup();

	private:
		SDL_Window* window;
		SDL_Surface* screenSurface;
		const int SCREEN_WIDTH = 640;
		const int SCREEN_HEIGHT = 480;
		bool initialized;

};

#endif