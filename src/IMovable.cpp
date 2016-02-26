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

void IMovable::UpdatePosition(float dT) 
{
	//float dT = dT_sec * 60; // convert into 1/60th of second

	//Update Velocity
	vec2f dAccel = acceleration * dT;
	velocity = velocity + dAccel;

	//Update Position
	vec2f dVelocity = velocity * dT;
	std::cout << "dV : " << dVelocity.length() << std::endl;
	//position = position + dVelocity;


	//recursive shit that kills your memory, CPU and eats little children
	//last step
	if ( dVelocity.length() < 1 || dT <= 1 ){
		position += dVelocity;
		std::cout << "DONE" << std::endl;
		//check & handle collision here
	}
	else {
		vec2f dV_norm = dVelocity.normalize();
		position += dV_norm;
		std::cout << "recur" << std::endl;
		//check & handle collision here
		//VERY BAD IDEA
		UpdatePosition(dT-1);
	}
}
