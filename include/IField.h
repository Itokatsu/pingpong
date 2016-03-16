#ifndef DEF_IFIELD
#define DEF_IFIELD

#include "IHasCollision.h"

#include "Vec2.h"
#include <vector>
//#include "Goal.h"
class Goal;

class IField : public IHasCollision
{
	public:
		//place paddles & ballz
		//void Init(Match m);
		virtual void MakeThisShitAbstract() = 0;
		virtual ~IField();

		int GetWidth();
		int GetHeight();

		//init stuff
		std::vector<vec2f> GetPaddlesInitPos();
		vec2f GetPaddleSize();
		vec2f GetBallInitPos();
		vec2f GetBallInitVelocity();

		//std::vector<IHasCollision*> GetFieldObjects();
		std::vector<Goal*> GetGoals();
		void Cleanup();

		void UpdateCollisionBox();

		void AcceptCollision( IHasCollision* c, SDL_Rect* cMask );
		void CollidesWith( IField* f, SDL_Rect* cMask );
		void CollidesWith( Paddle* p, SDL_Rect* cMask );
		void CollidesWith( Ball* b, SDL_Rect* cMask );
		void CollidesWith( Goal* g, SDL_Rect* cMask );


	protected:
		int width;
		int height;

		//init stuff
		std::vector<vec2f> paddlesInitPos;
		vec2f paddleSize;
		int ballSize;
		vec2f ballInitPos;
		vec2f ballInitVelocity;

		//std::vector<IHasCollision> fieldObjs;
		std::vector<Goal*> goals;

};

#endif

