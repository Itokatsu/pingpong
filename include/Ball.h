#ifndef DEF_BALL
#define DEF_BALL

#include "IMovable.h"
#include "SDL.h"

class Ball : public IMovable
{
	public:
		Ball();
		Ball(vec2f pos);

		int GetRadius();

		void SetRadius(int rad);

	private:
		int radius;

};

#endif