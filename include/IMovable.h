#ifndef DEF_IMOVABLE
#define DEF_IMOVABLE

#include "SDL.h"
#include "Vec2.h"

#include "IField.h"

class IMovable
{
	public:
		IMovable();
		IMovable(vec2f pos);
		IMovable(int x, int y);

		vec2f GetPos();
		vec2f GetVelocity();
		vec2f GetAcceleration();

		void SetPos(vec2f pos);
		void SetVelocity(vec2f velo);
		void SetAcceleration(vec2f accel);

		void UpdatePosition(float dTime, IField field);

	protected:
		vec2f position;
		vec2f velocity;
		vec2f acceleration;
};

#endif