#pragma once

#include "Rigidbody.h"

class SpaceshipLocomotive
{
	float vertThrust;
	float horzThrust;

	float maxSpeed;
	float speed;

public:
	SpaceshipLocomotive();

	void doThrust(float value);
	void doTurn(float value);


	void update(Rigidbody &rigidbody, float deltaTime);
};