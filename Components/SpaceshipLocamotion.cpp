#include "SpaceshipLocomotive.h"

#include "sfwdraw.h"

SpaceshipLocomotive::SpaceshipLocomotive()
{
	vertThrust = 0.0f;
	horzThrust = 0.0f;
	breakPower = 4.0f;
	
	turnSpeed = 4.0f;
	speed = 900.0f;
	maxSpeed = 1000.0f;
}

void SpaceshipLocomotive::doThrust(float value)
{
	vertThrust = value;
//	if (sfw::getKey('W')) vertThrust += 1;
//	if (sfw::getKey('S')) vertThrust -= 1;

}

void SpaceshipLocomotive::doTurn(float value)
{
	horzThrust = value;
//	if (sfw::getKey('Q')) horzThrust -= 1;
//	if (sfw::getKey('E')) horzThrust += 1;
}

void SpaceshipLocomotive::doStop(float value)
{
	stopAction += value;
}

void SpaceshipLocomotive::update(const Transform &trans, Rigidbody &rigidbody)
{
//	doThrust();
//	doTurn();

	rigidbody.addForce (trans.getUp() * speed * vertThrust);
	rigidbody.addTorque(turnSpeed * horzThrust);
	
//	float currentSpeed = magnitude(rigidbody.velocity);

	rigidbody.addForce(-rigidbody.velocity * breakPower * stopAction);
	rigidbody.addTorque(-rigidbody.angularVelocity * breakPower * stopAction);

	horzThrust = vertThrust = stopAction = 0;

	//rigidbody.acceleration.x = horzThrust * speed;
	//rigidbody.acceleration.y = vertThrust * speed;
	//if (magnitude(rigidbody.velocity) > maxSpeed)
	//{
	//	vec2 dir = normal(rigidbody.velocity);
	//	rigidbody.velocity = dir * maxSpeed;
	//}
	//vertThrust = 0.0f;
	//horzThrust = 0.0f;
}