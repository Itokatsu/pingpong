#ifndef DEF_BALL
#define DEF_BALL

#include "IMovable.h"

#include "IHasCollision.h"
#include "Player.h"

class Ball : public IMovable
{
	public:
		Ball();
		Ball(vec2f pos);

		void UpdateCollisionBox();
		void AcceptCollision(IHasCollision* c, SDL_Rect* cMask);
		void CollidesWith(Ball* b, SDL_Rect* cMask);
		void CollidesWith(IField* f, SDL_Rect* cMask);
		void CollidesWith(Paddle* p, SDL_Rect* cMask);
		void CollidesWith(Goal* g, SDL_Rect* cMask);

		int GetRadius();
		Player* GetLastP();

		void SetLastP(Player* p);
		void SetRadius(int rad);

	private:
		int radius;

		//Last player that hit the ball
		Player* p_Last;
};

#endif