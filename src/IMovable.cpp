#include "IMovable.h"
#include "SDL.h"
#include <iostream>
#include <cmath>

IMovable::IMovable() 
{
	position = {0.f, 0.f};
	acceleration = {0.f,0.f};
	velocity = {0.f,0.f};
}

IMovable::IMovable(vec2f pos) {
	position = pos;
	acceleration = {0.f,0.f};
	velocity = {0.f,0.f};
}

IMovable::IMovable(int x, int y) {
	position = {(float)x, (float)y};
	acceleration = {0.f,0.f};
	velocity = {0.f,0.f};
}


vec2f IMovable::GetPos()
{
	return position;
}

vec2f IMovable::GetVelocity()
{
	return velocity;
}

vec2f IMovable::GetAcceleration()
{
	return acceleration;
}

void IMovable::SetPos(vec2f pos)
{
	position = pos;
}

void IMovable::SetVelocity(vec2f velo)
{
	velocity = velo;
}

void IMovable::SetAcceleration(vec2f accel)
{
	acceleration = accel;
}

void IMovable::UpdatePosition(float dT_sec) 
{
	float dT = dT_sec * 60; // convert into 1/60th of second
	//Update Acceleration
	vec2f dAccel = acceleration * dT;

	//Update Velocity
	velocity = velocity + dAccel;
	vec2f dVelocity = velocity * dT;

	//Update Position
	//position = position + dVelocity;

	//last step
	if ( dVelocity.length() < 1 ){
		position += dVelocity;
		//check & handle collision here
	}
	else {
		vec2f dV_norm = dVelocity.normalize();
		position += dV_norm;
		//check & handle collision here
		//VERY BAD IDEA
		//this->UpdatePosition(dT_sec - 1/60);
	}
}
