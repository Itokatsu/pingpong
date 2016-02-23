#ifndef DEF_IMOVABLE
#define DEF_IMOVABLE

#include "SDL.h"

/*Pure abstract class
i.e. TitleScreen LoadingScreen MatchScreen PostMatchScreen ... */

class IMovable
{
	public:

		SDL_Point GetPos();
		SDL_Point GetVelocity();
		SDL_Point GetAcceleration();

		void SetPos(SDL_Point pos);
		void SetVelocity(SDL_Point velo);
		void SetAcceleration(SDL_Point accel);

		void UpdatePosition(float dTime);

	protected:
		SDL_Point position;
		SDL_Point velocity;
		SDL_Point acceleration;
};

#endif