#pragma once
#include "Transform.h"

class Camera
{
public:
	mat3 projection;
	Transform transform;

	Camera();
	mat3 getCameraMatrix() const;
	void Update(float deltaTime, class GameState & gs);
};