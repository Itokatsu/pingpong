#include "IField.h"
#include "Goal.h"

IField::~IField()
{
	for (auto &goal : goals) {
		delete goal;
		goal = NULL;
	}
	goals.clear();
}

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

std::vector<Goal*> IField::GetGoals()
{
	return goals;
}