#include "vec2.h"
#include <cmath>
#include "flpos.h"
#include "mat2.h" 

vec2 operator+(const vec2 & lhs, const vec2 & rhs)
{
	return vec2{ lhs.x + rhs.x, lhs.y + rhs.y };
}

vec2 operator-(const vec2 & lhs, const vec2 & rhs)
{
	return vec2{ lhs.x - rhs.x, lhs.y - rhs.y };
}

vec2 operator*(const vec2 &lhs, float rhs)
{
	return vec2{ lhs.x*rhs, lhs.y*rhs };
}

vec2 operator*(float rhs, const vec2 &lhs)
{
	return vec2{ rhs*lhs.x, rhs*lhs.y };
}

vec2 operator/(const vec2 &lhs, float rhs)
{
	return vec2{ lhs.x/rhs, lhs.y/rhs };
}

vec2 operator/(float rhs, const vec2 &lhs)
{
	return vec2{ rhs/lhs.x, rhs/lhs.y };
}

vec2 operator+(const vec2 &v)
{
	return vec2{ +v.x, +v.y };
}

vec2 operator-(const vec2 &v)
{
	return vec2{ -v.x, -v.y };
}

vec2 operator+=( vec2 & lhs, const vec2 & rhs)
{
	return lhs = lhs + rhs;
}

vec2 operator-=( vec2 & lhs, const vec2 & rhs)
{
	return lhs = lhs + rhs;
}

float magnitude(const vec2 &v)
{
	return (sqrt((v.x*v.x) + (v.y*v.y)));
}

bool operator==(const vec2 & lhs, const vec2 & rhs)
{
	return fequals(lhs.x, rhs.x) && fequals(lhs.y, rhs.y);
}

vec2 normal(const vec2 &v)
{
	return v / magnitude(v);
}

float dot(const vec2 &rhs, const vec2 &lhs)
{
	return (lhs.x*rhs.x) + (lhs.y*rhs.y);
}

float angleBetween(const vec2 &rhs, const vec2 &lhs)
{
	return acos(dot(normal(rhs), normal(lhs)));
}

vec2 perp(const vec2 &v)
{
	return vec2{ v.y, -v.x };
}

float angle(const vec2 &v)
{
	return atan2f(v.y, v.x);
}

vec2 fromAngle(float a)
{
	return vec2{ cos(a), sin(a) };
}

/////////////////////////////////////
/////////////////////////////////////

vec2 lerp(const vec2 &start, const vec2 &end, float alpha)
{
	return (1 - alpha)* start + (alpha)* end;
	return alpha *(end - start) + start;	
}

vec2 quadBezier(vec2 start, vec2 mid, vec2 end, float alpha)
{
	vec2 mid1 = lerp(start, mid, alpha);
	vec2 mid2 = lerp(mid, end, alpha);
	return lerp(mid1, mid2, alpha);
}

float hermitSpline(float start, float s_tan, float end, float e_tan, float alpha)
{
	float tsq = alpha*alpha;
	float tcub = tsq * alpha;
	float h00 = 2 * tcub + 3 * tsq + 1;
	float h01 = -2 * tcub + 3 * tsq;
	float h10 = tcub - 2 * tsq + alpha;
	float h11 = tcub - tsq;
	float point = h00*start + h10*s_tan + h01*end + h11 *e_tan;
	return point;
}

float cardinalSpline(float start, float mid, float end, float tightness, float alpha)
{
	float tan0 = (mid - start)*tightness;
	float tan1 = (end - mid) * tightness;
	float tsq = alpha*alpha;
	float tcub = tsq * alpha;
	float h00 = 2 * tcub + 3 * tsq + 1;
	float h01 = -2 * tcub + 3 * tsq;
	float h10 = tcub - 2 * tsq + alpha;
	float h11 = tcub - tsq;
	float point = h00*start + h10*tan0 + h01 *mid + h11 * tan1;
	return point;
}

float catRoomSpline(float start, float mid, float end, float alpha)
{
	float tan0 = (mid - start)*.5;
	float tan1 = (end - mid) * .5;
	float tsq = alpha*alpha;
	float tcub = tsq * alpha;
	float h00 = 2 * tcub + 3 * tsq + 1;
	float h01 = -2 * tcub + 3 * tsq;
	float h10 = tcub - 2 * tsq + alpha;
	float h11 = tcub - tsq;
	float point = h00*start + h10*tan0 + h01 *mid + h11 * tan1;
	return point;
}

float vec2::operator[](unsigned idx) const
{
	return v[idx];
}
float & vec2::operator[](unsigned idx)
{
	return v[idx];
}


vec2 min(const vec2 &A, const vec2 &B)
{
	return vec2{
		A.x < B.x ? A.x : B.x,
		A.y < B.y ? A.y : B.y };
}

vec2 max(const vec2 & A, const vec2 & B)
{
	return vec2{
		A.x > B.x ? A.x : B.x,
		A.y > B.y ? A.y : B.y };
}