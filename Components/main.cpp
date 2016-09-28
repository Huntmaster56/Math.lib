#include "sfwdraw.h"
#include "vec2.h"
#include "Transform.h"
#include "flpos.h"

using namespace sfw;
void main()
{
	sfw::initContext();
	Transform trans;

	trans.position = vec2{ 400,300 };
	trans.facing = deg2rad(45);
	trans.scale = vec2{ 12,8 };

	while (sfw::stepContext())
	{
		trans.debugDraw();
		trans.facing += getDeltaTime();
	}

	sfw::termContext();
}

