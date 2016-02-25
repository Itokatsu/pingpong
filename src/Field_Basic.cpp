#include "Field_Basic.h"

Field_Basic::Field_Basic(){
	width = 640;
	height = 480;

	//ball starting position
	ballInitPos = {315, 235};
	ballSize = 5;

	//players starting Positions
	playersInitPos.push_back({20, 100});
	playersInitPos.push_back({600, 280});
	paddleSize = {20, 80};
}