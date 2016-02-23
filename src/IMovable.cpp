#include "IMovable.h"
#include "SDL.h"

SDL_Point IMovable::GetPos()
{
	return position;
}

SDL_Point IMovable::GetVelocity()
{
	return velocity;
}

SDL_Point IMovable::GetAcceleration()
{
	return acceleration;
}

void IMovable::SetPos(SDL_Point pos)
{
	position = pos;
}

void IMovable::SetVelocity(SDL_Point velo)
{
	velocity = velo;
}

void IMovable::SetAcceleration(SDL_Point accel)
{
	acceleration = accel;
}

void IMovable::UpdatePosition(float dTime) 
{
	int dT = (int)(dTime*100);
	//Update Acceleration
	SDL_Point dAccel = { acceleration.x * dT, acceleration.y * dT };

	//Update Velocity
	velocity = { velocity.x + dAccel.x, velocity.y + dAccel.y };
	SDL_Point dVelocity = { velocity.x * dT, velocity.y * dT };

	//Update Position
	position = { position.x + dVelocity.x, position.y + dVelocity.y };
}