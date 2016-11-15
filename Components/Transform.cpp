#include "Transform.h"
#include "sfwdraw.h"
#include "shapeDraw.h"

Transform::Transform(float x, float y, float w, float h, float a)
{
	m_position.x = x;
	m_position.y = y;

	m_scale.x = w;
	m_scale.y = h;

	m_facing = a;

	m_parent = nullptr;
}
//using namespace sfw;
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

vec2 Transform::getGlobalPosition() const
{
	return getGlobalTransform()[2].xy;
}
vec2 Transform::getGlobalRight()	 const
{
	return getGlobalTransform()[1].xy;
}
vec2 Transform::getGlobalUp()		 const
{
	return getGlobalTransform()[0].xy;
}
float Transform::getGlobalAngle()	 const
{
	return angle(getGlobalRight());
}

mat3 Transform::getGlobalTransform() const
{
	if (m_parent == nullptr)
		return getLocalTransform();
	else
		return m_parent->getGlobalTransform() * getLocalTransform();
}

mat3 Transform::getLocalTransform() const
{
	mat3 T = translate(m_position.x, m_position.y);
	mat3 S = scale(m_scale.x, m_scale.y);
	mat3 R = rotate(m_facing);

	return T * R * S;
}

void Transform::debugDraw(const mat3 &T) const
{
	mat3 L = T * getGlobalTransform();

	vec3 pos = L[2];

	vec3 right = L * vec3{ 20, 0, 1 };
	vec3 up	   = L * vec3{ 0, 40, 1 };

	sfw::drawCircle(pos.x, pos.y, 12, 12, RED);
	sfw::drawLine(pos.x, pos.y, right.x, right.y, GREEN);


	vec3 sgp = m_parent ? T * m_parent->getGlobalTransform()[2] : pos;
	sfw::drawLine(pos.x, pos.y, up.x, up.y, BLUE);

	//vec2 dirEnd = m_position + getDirection() * m_scale.x * 8;
	//vec2 upEnd = m_position - perp(getDirection()) * m_scale.y * 6;
	//drawCircle(L * Circle{ 0, 0, 1 }, 0x888888FF);
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
	//sfw::drawLine(m_position.x, m_position.y,
	//	dirEnd.x, dirEnd.y, GREEN);
	//sfw::drawLine(m_position.x, m_position.y,
	//	upEnd.x, upEnd.y, BLUE);

}
