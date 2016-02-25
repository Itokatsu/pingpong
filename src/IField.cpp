#include "IField.h"

std::vector<vec2f> IField::GetPlayersInitPos()
{
	return playersInitPos;
}

vec2f IField::GetBallInitPos()
{
	return ballInitPos;
}

/*
std::vector<CollisionBox> IField::GetCollisionBoxes()
{
	return collisionBoxes;	
}
*/
