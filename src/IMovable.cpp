#include "IMovable.h"

#include "SDL.h"
#include "Match.h"
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

//=============================================
//==  ALWAYS USE THIS FOR CHANGING POSITION ===
//=============================================
void IMovable::SetPos(vec2f pos)
{
	position = pos;
	UpdateCollisionBox();
}

void IMovable::SetVelocity(vec2f velo)
{
	velocity = velo;
}

void IMovable::SetAcceleration(vec2f accel)
{
	acceleration = accel;
}

void IMovable::UpdatePosition(float dT, Match* m) 
{
	//Update Velocity
	vec2f dAccel = acceleration * dT;
	velocity = velocity + dAccel;

	vec2f dVelocity = velocity * dT;
		
	//last step
	if ( dVelocity.length() < 1){
		SetPos(position + dVelocity);
		//check & handle collision here
		m->ChkCollision(this);
	}
	else {
		float t_norm = dT / dVelocity.length();
		SetPos(position + dVelocity.normalize());
		//check & handle collision here
		m->ChkCollision(this);

		UpdatePosition(dT-t_norm, m);
	}
}
