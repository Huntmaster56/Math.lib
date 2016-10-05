#pragma once

#include "vec2.h"
#include "Transform.h"

class Rigidbody
{
public:
	Rigidbody();

	vec2 velocity;
	float angularVelocity;

	vec2 acceleration;
	float angularAcceleration;

	void addForce(const vec2 &force);
	void addImpulse(const vec2 &impulse);

	void addTorque(float torque);

	void integrate(Transform &trans, float deltaTime);
};