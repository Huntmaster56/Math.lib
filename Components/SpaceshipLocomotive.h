#pragma once

#include "Rigidbody.h"

class SpaceshipLocomotive
{
	float vertThrust;
	float horzThrust;
	float stopAction;
	float boost;

	float boostPower;
	float breakPower;
	float turnSpeed;
	float maxSpeed;
	float speed;

public:
	SpaceshipLocomotive();

	void doThrust(float value);
	void doTurn(float value);

	void doStop(float value);
	void doBoost(float value);

	void update(const Transform &trans, Rigidbody &rigidbody);
};