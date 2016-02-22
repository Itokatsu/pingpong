#ifndef DEF_BALL
#define DEF_BALL

#include "SDL.h"

class Ball
{
	public:
		Ball();
		Ball(int x, int y);

		SDL_Point GetPos();
		SDL_Point GetSize();
		SDL_Point GetVelocity();

		void SetPos(SDL_Point pos);
		void SetSize(int radius);
		void SetVelocity(SDL_Point velo);

	private:
		SDL_Point position;
		SDL_Point velocity;
		int radius;

};

#endif