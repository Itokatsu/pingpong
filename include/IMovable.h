#ifndef DEF_IMOVABLE
#define DEF_IMOVABLE

#include "SDL.h"
#include "Vec2.h"

/*Pure abstract class
i.e. TitleScreen LoadingScreen MatchScreen PostMatchScreen ... */

class IMovable
{
	public:

		vec2f GetPos();
		vec2f GetVelocity();
		vec2f GetAcceleration();

		void SetPos(vec2f pos);
		void SetVelocity(vec2f velo);
		void SetAcceleration(vec2f accel);

		void UpdatePosition(float dTime);

	protected:
		vec2f position;
		vec2f velocity;
		vec2f acceleration;
};

#endif