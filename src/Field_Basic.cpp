#include "Field_Basic.h"

Field_Basic::Field_Basic(){
	//field dimensions
	width = 640;
	height = 480;

	//ball starting attributes
	ballInitPos = {50, 50};
	ballInitVelocity = {6, 1.5};
	ballSize = 5;

	//players starting attributes
	playersInitPos.push_back({20, 200});
	playersInitPos.push_back({600, 200});
	paddleSize = {20, 100};
}