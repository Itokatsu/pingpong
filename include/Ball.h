#ifndef DEF_BALL
#define DEF_BALL

#include "IMovable.h"
#include "SDL.h"

class Ball : public IMovable
{
	public:
		Ball();
		Ball(int x, int y);

		int GetRadius();

		void SetRadius(int rad);

	private:
		int radius;

};

#endif