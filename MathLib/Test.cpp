#include "test.h"
#include <cmath>
int doNothing(int x)
{
	return x*x + 2*x + 5;
}


float test_quad(float x)
{
	return x*x + 2 * x - 7;
}

quad_results quad(float a, float b, float c)
{
	quad_results retval;
	retval.left_root = -b + sqrt(b*b - 4 * a*c) / 2 * a;
	retval.right_root = -b - sqrt(b*b - 4 * a*c) / 2 * a;
	float d = b*b - 4 * a*c;
	if (d < 0)
	{
		retval.roots = 0;
	}
	if (d == 0)
	{
		retval.roots = 1;
	}
	else
		retval.roots = 2;
	return retval;
}

float lerp(float start, float end, float t)
{
	return start + t*(end - start);
}