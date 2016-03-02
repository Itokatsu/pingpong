#ifndef DEF_GOAL
#define DEF_GOAL

#include "IHasCollision.h"

#include "SDL.h"
#include "IField.h"
#include <string>

class Goal : public IHasCollision {

	public:
		Goal(IField* f, SDL_Rect area, int pts=1);
		Goal(IField* f, int x, int y, int w, int h, int pts=1);
		~Goal();

		void UpdateCollisionBox();

		void AcceptCollision( IHasCollision* c, SDL_Rect* cMask );
		void CollidesWith( IField* f, SDL_Rect* cMask );
		void CollidesWith( Paddle* p, SDL_Rect* cMask );
		void CollidesWith( Ball* b, SDL_Rect* cMask );
		void CollidesWith( Goal* g, SDL_Rect* cMask );

		int GetValue();
		IField* GetField();

	private:
		std::string str;
		int pts;
		IField* field;
		SDL_Rect area;

};

#endif