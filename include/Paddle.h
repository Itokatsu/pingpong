#ifndef DEF_PADDLE
#define DEF_PADDLE

#include "SDL.h"
#include "IMovable.h"

class Paddle : public IMovable
{
	public:
		Paddle();
		Paddle(vec2f pos);
		Paddle(int x, int y);

		void PrintCoords();

		SDL_Point GetSize();

		void SetSize(SDL_Point size);

	private:
		SDL_Point size;

};

#endif