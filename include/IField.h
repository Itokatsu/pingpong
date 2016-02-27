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
		vec2f GetBallInitPos();
		std::vector<vec2f> GetPlayersInitPos();

	protected:
		int width;
		int height;
		int ballSize;
		vec2f paddleSize;
		
		std::vector<vec2f> playersInitPos;
		vec2f ballInitPos;


		//hitboxes
		//std::vector<CollisionBox> collisionBoxes;

};

#endif