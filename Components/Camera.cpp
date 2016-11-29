#include "Camera.h"
#include "GameState.h"

Camera::Camera()
{
	projection = translate(600, 600) * scale(.5f, .5f);
}

mat3 Camera::getCameraMatrix() const
{
	return projection * inverse(transform.getGlobalTransform());
}

void Camera::Update(float deltaTime, class GameState & gs)
{
	transform.m_position = gs.player.transform.getGlobalPosition();
}
