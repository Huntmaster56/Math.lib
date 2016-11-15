#include "GameState.h"
#include "PlayerShip.h"

PlayerShip::PlayerShip()
{
	vec2 hullVerts[] = {{0,3}, {-2,-3}, {}}
}


void PlayerShip::Update(float deltaTime, GameState & gs)
{
	controller.update(locomotion);
	locomotion.update(transform, rigidbody);
	rigidbody.integrate(transform, deltaTime);
}

void PlayerShip::Draw(const mat3 &camera)
{
	transform.debugDraw(camera);
	collider.DebugDraw(camera, transform);
	rigidbody.debugDraw(camera, transform);
}
