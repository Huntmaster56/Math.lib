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

Plane operator==(const Plane & A, const Plane & B)
{
	return Plane();
}


vec2 AABB::min() const
{
	return pos - he;
}

vec2 AABB::max() const
{
	return pos + he;
}

AABB operator*(const mat3 & T, const AABB & box)
{
	AABB retval = box;
	vec3 tP[4];

	tP[0] = T * vec3{ box.min().x, box.min().y, 1 };
	tP[1] = T * vec3{ box.max().x, box.max().y, 1 };
	tP[2] = T * vec3{ box.max().x, box.min().y, 1 };
	tP[3] = T * vec3{ box.min().x, box.max().y, 1 };

	vec2 minv = tP[0].xy;
	vec2 maxv = tP[0].xy;

	for (int i = 1; i < 4; ++i)
	{
		minv = min(minv, tP[i].xy);
		maxv = max(maxv, tP[i].xy);
	}

	retval.pos = (minv + maxv) / 2;
	retval.he = (maxv - minv) / 2;


	//retval.pos = (T * vec3{ A.pos.x,A.pos.y,1 }).xy;
	//retval.he = (T * vec3{ A.he.x,A.he.y,0 }).xy;
	return retval;
}

Plane operator*(const mat3 & T, const Plane & P)
{
	Plane retval;
	retval.pos = 
				(T * vec3{ P.pos.x, P.pos.y, 1 }).xy;

	retval.dir = 
				(T * vec3{ P.dir.x, P.dir.y, 1 }).xy;
	return Plane();
}
