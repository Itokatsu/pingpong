#ifndef DEF_IFIELD
#define DEF_IFIELD

#include "IHasCollision.h"

#include "Vec2.h"
#include <vector>
//#include "CollisionBox.h"

class IField
{
	public:
		//place paddles & ballz
		//void Init(Match m);

		int GetWidth();
		int GetHeight();

		std::vector<vec2f> GetPlayersInitPos();
		vec2f GetPaddleSize();

		vec2f GetBallInitPos();
		vec2f GetBallInitVelocity();


	protected:
		int width;
		int height;

		std::vector<vec2f> playersInitPos;
		vec2f paddleSize;
		
		int ballSize;
		vec2f ballInitPos;
		vec2f ballInitVelocity;

		//hitboxes
		//std::vector<CollisionBox> collisionBoxes;

		/* IDEA
		class Goal (inherit IHasCollision)
		-> int worth 
		points to add for hitting the goal à la windjammer
		*/

};

#endif

