#include "Field_Basic.h"
#include "Goal.h"
#include <string>
#include <iostream>

Field_Basic::Field_Basic()
{
	//field dimensions
	width = 640;
	height = 480;

	//ball starting attributes
	ballSize = 5;
	ballInitPos = {width/2.f-ballSize, height/2.f-ballSize};
	ballInitVelocity = {6, 1.5};

	//players starting attributes
	paddlesInitPos.push_back({20, 200});
	paddlesInitPos.push_back({600, 200});
	paddleSize = {20, 100};

	std::cout << " + Field (Basic) created" << std::endl;
	//goals 
	Goal* g1 = new Goal(this, 0, 0, 3, height, 1);
	Goal* g2 = new Goal(this, width-3, 0, 3, height, 1);
	goals.push_back(g1);
	goals.push_back(g2);

}

Field_Basic::~Field_Basic()
{
	std::cout << " - Field (Basic) Deleted" << std::endl;
}

void Field_Basic::MakeThisShitAbstract() {

}