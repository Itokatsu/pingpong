#ifndef DEF_HASCOLLISION
#define DEF_HASCOLLISION

#include "SDL.h"
class IField;
class Ball;
class Paddle;
class Goal;

class IHasCollision
{
	public:
		//cMask parameter is collision mask

		//Accept : double dispatch (visitor pattern)
		virtual void AcceptCollision(IHasCollision* c, SDL_Rect* cMask) = 0;

		virtual void CollidesWith(IField* f, SDL_Rect* cMask) = 0;
		virtual void CollidesWith(Paddle* p, SDL_Rect* cMask)= 0;
		virtual void CollidesWith(Ball* b, SDL_Rect* cMask) = 0;
		virtual void CollidesWith(Goal* g, SDL_Rect* cMask) = 0;

		virtual void UpdateCollisionBox() = 0;
		SDL_Rect* GetCollisionBox() {
			return &collisionBox;
		}

	protected:
		SDL_Rect collisionBox;
};

#endif