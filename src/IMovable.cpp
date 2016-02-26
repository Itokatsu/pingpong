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

void IMovable::UpdatePosition(float dT, IField field) 
{
	//Update Velocity
	vec2f dAccel = acceleration * dT;
	velocity = velocity + dAccel;

	vec2f dVelocity = velocity * dT;
		
	//last step
	if ( dVelocity.length() < 1){
		position += dVelocity;
		//check & handle collision here
	}
	else {
		float t_norm = dT / dVelocity.length();
		position += dVelocity.normalize();
		//check & handle collision here
		UpdatePosition(dT-t_norm, field);
	}
}
