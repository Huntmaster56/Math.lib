#pragma once
#include "vec2.h"


class Transform
{
public:

	vec2 position;
	vec2 scale;
	float facing;

	//Transform();
	Transform(float x = 0, float y = 0, float w = 1,
			  float h = 1, float a = 0);

	vec2 getDirection();
	void setDirection(const vec2 &dir);

	void debugDraw();
};