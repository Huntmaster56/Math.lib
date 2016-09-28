#include "sfwdraw.h"
#include "vec2.h"
#include "Transform.h"
#include "flpos.h"

using namespace sfw;
void main()
{
	sfw::initContext();
	Transform trans(400, 300, 30,30, 23);

	int j = int(4);
	int k(4);
	int l = { 4 };
	int n{ 4 };

	Transform tl = Transform(400, 300);
	Transform tn = { 400, 300 };
	Transform tm(400, 300);
	Transform tp{ 400, 300 };



//	trans.position = vec2{ 400,300 };
	trans.facing = deg2rad(45);
	trans.scale = vec2{ 24,16 };

	vec2 basis = { 40,0 };
	float ang_vec = 0;

	while (sfw::stepContext())
	{
		ang_vec += sfw::getDeltaTime();
		vec2 incident = fromAngle(ang_vec) * 40;
		float proj = dot(basis, incident);
		drawLine(400, 300, 400 + basis.x + basis.y, BLACK);

		trans.debugDraw();
		trans.facing += getDeltaTime();
	}

	sfw::termContext();
}

