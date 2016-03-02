#ifndef DEF_PADDLE
#define DEF_PADDLE

#include "SDL.h"
#include "IMovable.h"
#include "IHasCollision.h"

class Player;

class Paddle : public IMovable 
{
	public:
		Paddle(Player* p, vec2f pos, SDL_Point size={20,100});
		Paddle(Player* p, int x, int y, int w=20, int h=100);
		~Paddle();

		void UpdateCollisionBox();

		void AcceptCollision( IHasCollision* c, SDL_Rect* cMask );
		void CollidesWith( IField* f, SDL_Rect* cMask );
		void CollidesWith( Paddle* p, SDL_Rect* cMask );
		void CollidesWith( Ball* b, SDL_Rect* cMask );
		void CollidesWith( Goal* g, SDL_Rect* cMask );

		Player* GetPlayer();
		SDL_Point GetSize();
		void SetSize( SDL_Point size );

	private:
		SDL_Point size;
		Player* player;

};

#endif