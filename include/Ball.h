#ifndef DEF_BALL
#define DEF_BALL

#include "IMovable.h"
#include "IHasCollision.h"
#include "SDL.h"

class Ball : public IMovable, IHasCollision
{
	public:
		Ball();
		Ball(vec2f pos);

		void UpdateCollisionBox();
		void AcceptCollision(IHasCollision* c, SDL_Rect cMask);
		void CollidesWith(Ball* b, SDL_Rect cMask);
		void CollidesWith(IField* f, SDL_Rect cMask);
		void CollidesWith(Paddle* p, SDL_Rect cMask);

		int GetRadius();
		
		void SetRadius(int rad);

	private:
		int radius;

};

#endif