#ifndef DEF_PADDLE
#define DEF_PADDLE

#include "SDL.h"
#include "IMovable.h"
#include "IHasCollision.h"

class Paddle : public IMovable, IHasCollision {
	public:
		Paddle();
		Paddle(vec2f pos);
		Paddle(int x, int y);

		void UpdateCollisionBox();

		void AcceptCollision(IHasCollision* c, SDL_Rect cMask);
		void CollidesWith(IField* f, SDL_Rect cMask);
		void CollidesWith(Paddle* p, SDL_Rect cMask);
		void CollidesWith(Ball* b, SDL_Rect cMask);

		SDL_Point GetSize();

		void SetSize(SDL_Point size);

	private:
		SDL_Point size;

};

#endif