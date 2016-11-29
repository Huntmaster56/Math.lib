#include "Floor.h"

Floor::Floor()
{
	vec2 hullVrts[] = { { 0,0 }, { 50,0 }, {50,10}, {0,10} };
	collider = Collider(hullVrts, 4);

	transform.m_scale = vec2{ 10,10 };
	rigidbody.drag = 0.0f;
	rigidbody.angularDrag = 0.0f;
	rigidbody.mass = 10;
}

void Floor::Update(float deltaTime, GameState & gs)
{
	rigidbody.integrate(transform, deltaTime);
}

void Floor::Draw(const mat3 & camera)
{
	collider.DebugDraw(camera, transform);
	//transform.debugDraw(camera);
	//rigidbody.debugDraw(camera, transform);
}