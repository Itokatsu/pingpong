#ifndef DEF_PADDLE
#define DEF_PADDLE

#include "SDL.h"

class Paddle
{
	public:
		Paddle();
		Paddle(int x, int y);

		void PrintCoords();

		SDL_Point GetPos();
		SDL_Point GetSize();
		SDL_Point GetVelocity();

		void SetPos(SDL_Point pos);
		void SetSize(SDL_Point size);
		void SetVelocity(SDL_Point velo);

	private:
		SDL_Point position;
		SDL_Point velocity;
		SDL_Point size;

};

#endif