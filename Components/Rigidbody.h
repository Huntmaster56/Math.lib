#pragma once

#include "vec2.h"
#include "Transform.h"

class Rigidbody
{
public:
	Rigidbody();

	float mass, drag, angularDrag;

	vec2  force, impulse;
	vec2  velocity;
	vec2  acceleration;

	float torque;
	float angularVelocity;
	float angularAcceleration;

	void addForce	(const vec2 &force);
	void addImpulse (const vec2 &impulse);
	void addTorque	(float torque);

	void integrate(Transform &trans, float deltaTime);

	void debugDraw(const mat3& T, const Transform &trans);
};