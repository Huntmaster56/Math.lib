#include "Rigidbody.h"
#include "sfwdraw.h"

Rigidbody::Rigidbody()
{
	force = vec2		{ 0,0 };
	impulse = vec2		{ 0,0 };
	acceleration = vec2 { 0,0 };
	velocity = vec2		{ 0,0 };

	angularDrag			= 1.0f;
	drag				= .25f;
	mass				= 1.0f;
	angularVelocity		= 0.0f;
	angularAcceleration = 0.0f;
	torque				= 0.0f;
}

void Rigidbody::addForce  (const vec2 &a_force)
{
	force += a_force;
}

void Rigidbody::addImpulse(const vec2 &a_impulse)
{
	impulse += a_impulse;
}

void Rigidbody::addTorque (float a_torque)
{
	torque += a_torque;
}

//void Rigidbody::addTorque(float &torque)
//{
//	angularAcceleration += torque;
//}

void Rigidbody::integrate(Transform &trans, float deltaTime)
{
	acceleration	 = force / mass;
	velocity		+= acceleration * deltaTime + impulse / mass;
	trans.m_position  += velocity	 * deltaTime;
	force = impulse  = { 0,0 };

	force = -velocity * drag;

	//force.y -= 10; // gravity!

	angularAcceleration  = torque / mass;
	trans.m_facing		+= angularVelocity		* deltaTime;
	angularVelocity	    += angularAcceleration  * deltaTime;
	torque				 = 0;
	torque				 = -angularVelocity		* angularDrag;
}

void Rigidbody::debugDraw(const mat3& T, const Transform & trans)
{
	vec2 p = (T * trans.getGlobalTransform())[2].xy;
	vec2 v = p + velocity;
	vec2 a = acceleration + p;

	sfw::drawLine(p.x, p.y, a.x, a.y, MAGENTA);
	sfw::drawLine(p.x, p.y, v.x, v.y, CYAN);
}
