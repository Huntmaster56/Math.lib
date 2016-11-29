#pragma once


#include "Transform.h"
#include "Collider.h"
#include "Rigidbody.h"

class Floor
{
public:
	Transform transform;
	Collider collider;
	Rigidbody rigidbody;

	Floor();

	void Update(float deltaTime, class GameState &gs);
	void Draw(const mat3 &camera);

};