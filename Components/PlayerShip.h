#pragma once

#include "Transform.h"
#include "Collider.h"
#include "Rigidbody.h"
#include "SpaceshipController.h"
#include "SpaceshipLocomotive.h"

class GameState;

class PlayerShip
{
public:
	Transform				transform;
	Collider				collider;
	Rigidbody				rigidbody;
	SpacechipController		controller;
	SpaceshipLocomotive		locomotion;

	PlayerShip();

	void Update(float deltaTime, class GameState &gs);
	void Draw(const mat3 &camera);

};



