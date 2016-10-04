#include "flpos.h"
#include <cmath>

bool fequals(float lhs, float rhs)
{
	if (fabsf(lhs-rhs) < 0.000001f)
	{
		return true;
	}
	else
	{
		return false;
	}
}


float deg2rad(float deg)
{
	return deg * 3.14 / 180;
}
float rad2deg(float rad)
{
	return rad * 180 / 3.14;
}

float linearHalf(float x)
{
	float result = x;
	return result;
}

float growFast(float x)
{
	return  x*x;
}

float growSlow(float x)
{
	return 1 -(1 - x)*(1- x);
}

float steady(float x)
{
	return -abs(2 * (x)-1) + 1;
}

float bounce(float x)
{
	return abs(cos(x * 10)*(1 - x));
}

float bounceFlip(float x)
{
	return 1 - bounce(x);
}

float parabFlip(float x)
{

}
