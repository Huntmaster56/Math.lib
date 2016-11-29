#pragma once

#include "Transform.h"
#include "Collider.h"
#include "Rigidbody.h"

class Asteroid
{
public:
	Transform transform;
	Collider collider;
	Rigidbody rigidbody;

	Asteroid();

	void Update(float deltaTime, class GameState &gs);
	void Draw(const mat3 &camera);
};