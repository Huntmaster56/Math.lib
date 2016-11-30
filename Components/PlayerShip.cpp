#include "GameState.h"
#include "PlayerShip.h"

PlayerShip::PlayerShip()
{
	vec2 hullVerts[] = { { 0, 3 },{ -2,-3 },{ 2,-3 } };
	collider = Collider(hullVerts, 3);

	transform.m_scale = vec2{ 20,10 };
}


void PlayerShip::Update(float deltaTime, GameState & gs)
{
	controller.update(locomotion);
	locomotion.update(transform, rigidbody);

	rigidbody.integrate(transform, deltaTime);

	rigidbody.addForce(vec2{ 0,-100 }); // gravity

}

void PlayerShip::Draw(const mat3 &camera)
{
	transform.debugDraw(camera);
	collider.DebugDraw(camera, transform);
	rigidbody.debugDraw(camera, transform);
}
