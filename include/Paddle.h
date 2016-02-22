#ifndef DEF_PADDLE
#define DEF_PADDLE

#include "GraphicEngine.h"
#include "SDL.h"

class Paddle
{
	public:
		Paddle();
		Paddle(int x, int y);

		void Draw(GraphicEngine* gfx);
		void PrintCoords();


		SDL_Point GetPos();
		SDL_Point GetSize();

		void SetPos(SDL_Point pos);
		void SetSize(SDL_Point pos);

	private:
		SDL_Point position;
		SDL_Point velocity;
		SDL_Point size;

};

#endif