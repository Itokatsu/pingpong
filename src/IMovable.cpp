#include "IMovable.h"
#include "SDL.h"
#include <iostream>

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
	dT = dT * 60; // 1/60th of second
	//Update Acceleration
	//SDL_Point dAccel = { acceleration.x * dT, acceleration.y * dT };
	vec2f dAccel = acceleration * dT;

	//Update Velocity
	//velocity = { velocity.x + dAccel.x, velocity.y + dAccel.y };
	//SDL_Point dVelocity = { velocity.x * dT, velocity.y * dT };
	velocity = velocity + dAccel;
	vec2f dVelocity = velocity * dT;

	//Update Position
	//position = { position.x + dVelocity.x, position.y + dVelocity.y };
	position = position + dVelocity;
}