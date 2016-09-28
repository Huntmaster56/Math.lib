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