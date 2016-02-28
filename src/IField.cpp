#include "IField.h"

std::vector<vec2f> IField::GetPlayersInitPos()
{
	return playersInitPos;
}

vec2f IField::GetBallInitPos()
{
	return ballInitPos;
}

vec2f IField::GetBallInitVelocity()
{
	return ballInitVelocity;
}

vec2f IField::GetPaddleSize()
{
	return paddleSize;
}

int IField::GetWidth()
{
	return width;
}

int IField::GetHeight()
{
	return height;
}


/*
std::vector<CollisionBox> IField::GetCollisionBoxes()
{
	return collisionBoxes;	
}
*/
