#include "Floor.h"

Floor::Floor()
{
	vec2 hullVrts[] = { { 0,0 }, { 200,0 }, {200,10}, {0,10} };
	collider = Collider(hullVrts, 4);

	transform.m_scale = vec2{ 10,10 };
	rigidbody.drag = 0.0f;
	rigidbody.angularDrag = 0.0f;
	rigidbody.mass = 10;
}

Spring::Spring()
{
	vec2 hullVrts[] = { { 0,0 },{ 20,0 },{ 20,10 },{ 0,10 } };
	collider = Collider(hullVrts, 4);

	transform.m_scale = vec2{ 10,10 };
	rigidbody.drag = 0.0f;
	rigidbody.angularDrag = 0.0f;
	rigidbody.mass = 10;
}

void Spring::Update(float deltaTime, GameState & gs)
{
	rigidbody.integrate(transform, deltaTime);
}

void Spring::Draw(const mat3 & camera)
{
	collider.DebugDraw(camera, transform);
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