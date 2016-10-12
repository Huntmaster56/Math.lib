#include "Transform.h"
#include "sfwdraw.h"

Transform::Transform(float x, float y, float w, float h, float a)
{
	m_position.x = x;
	m_position.y = y;

	m_scale.x = w;
	m_scale.y = h;

	m_facing = a;
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
	return fromAngle(m_facing);
}

void Transform::setDirection(const vec2 &dir)
{
	m_facing = angle(dir);
}

void Transform::debugDraw(const mat3 &T) const
{


	mat3 L = T * getLocalTransform();

	vec3 pos = vec3{ m_position.x, m_position.y, 0 };

	vec3 right = pos + L * vec3{ 1, 0, 1 };
	vec3 up	   = pos + L * vec3{ 0, 4, 1 };

	sfw::drawLine(m_position.x, m_position.y,
				  right.x,		right.y, GREEN);

	sfw::drawLine(m_position.x, m_position.y,
				  up.x,		up.y,  BLUE);

	vec2 dirEnd = m_position + getDirection() * m_scale.x * 8;
	vec2 upEnd = m_position - perp(getDirection()) * m_scale.y * 6;

	sfw::drawLine(m_position.x, m_position.y,
		dirEnd.x, dirEnd.y, GREEN);

	sfw::drawLine(m_position.x, m_position.y,
		upEnd.x, upEnd.y, BLUE);

	sfw::drawCircle(m_position.x, m_position.y,
		12, 12, 0x888888FF);


	//if (getKey(KEY_UP))
	//{
	//	m_position -= getDirection() * 5;
	//}
	//else if (getKey(KEY_LEFT))
	//{
	//	m_facing += .1;
	//}
	//else if (getKey(KEY_RIGHT))
	//{
	//	m_facing -= .1;
	//}
	//else if (getKey(KEY_DOWN))
	//{
	//	m_position += getDirection() * 5;
	//}

}

mat3 Transform::getLocalTransform() const
{
	mat3 S = scale(m_scale.x, m_scale.y);
	mat3 T = translate(m_position.x, m_position.y);
	mat3 R = rotate(m_facing);

	return T * S * R;
	//return T * R * S;
	//return R * S * T;
	//return R * T * S;
	//return S * T * R;
	//return S * R * T;
	
}