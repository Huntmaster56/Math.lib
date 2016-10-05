#include "Transform.h"
#include "sfwdraw.h"

Transform::Transform(float x, float y, float w, float h, float a)
{
	position.x = x;
	position.y = y;

	scale.x = w;
	scale.y = h;

	facing = a;
}


using namespace sfw;
//Transform::Transform() : facing(0), position({ 0,0 }), scale({28,8})
//{
//		//position.x = 0;
//		//position.y = 0;
//		//scale.x = 28;
//		//scale.y = 8;
//}

//Transform::Transform(float x, float y, float w, float h, float a)
//{
//	position.x = x;
//	position.y = y;
//}

vec2 Transform::getUp() const
{
	return -perp(getDirection());
}

vec2 Transform::getDirection() const
{
	return fromAngle(facing);
}

void Transform::setDirection(const vec2 &dir)
{
	facing = angle(dir);
}

void Transform::debugDraw()
{
	sfw::drawCircle(position.x, position.y, 96);

	vec2 dirEnd = position + getDirection() * scale.x * 8;
	vec2 upEnd = position - perp(getDirection()) * scale.y * 6;


	sfw::drawLine(position.x,	position.y,
				  dirEnd.x,		dirEnd.y, GREEN);

	sfw::drawLine(position.x,	position.y,
				  upEnd.x,		upEnd.y,  BLUE);

	if (getKey(KEY_UP))
	{
		position -= getDirection() * 5;
	}

	else if (getKey(KEY_LEFT))
	{
		facing += .1;
	}

	else if (getKey(KEY_RIGHT))
	{
		facing -= .1;
	}

	else if (getKey(KEY_DOWN))
	{
		position += getDirection() * 5;
	}





}