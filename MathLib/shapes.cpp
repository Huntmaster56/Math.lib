#include "shapes.h"
#include "flpos.h"
Circle operator*(const mat3 & T, const Circle & c)
{
	Circle retval;

	retval.pos = (T*vec3{ c.pos.x, c.pos.y, 1 }).xy;

	float mX = magnitude(T * vec3{ 0, c.rad, 0 });
	float mY = magnitude(T * vec3{ c.rad, 0, 0 });

	retval.rad = mX > mY ? mX : mY;

	return retval;
	//float rad = c.rad;
	//float xrad = magnitude(T * vec3{ rad, 0, 0 });
	//float yrad = magnitude(T * vec3{ 0, rad, 0 });
	//return Circle();
	//float meh = xrad > yrad ? xrad : yrad;
}

bool operator==(const Circle & A, const Circle & B)
{
	return A.pos == B.pos && fequals(A.rad, B.rad);
}


vec2 AABB::min() const
{
	return pos - he;
}

vec2 AABB::max() const
{
	return pos + he;
}

AABB operator*(const mat3 & T, const AABB & A)
{
	AABB retval = A;

	retval.pos = (T * vec3{ A.pos.x,A.pos.y,1 }).xy;

	retval.he = (T * vec3{ A.he.x,A.he.y,0 }).xy;
	return retval;
}
