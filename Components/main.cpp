#include "sfwdraw.h"
#include "vec2.h"
#include "Transform.h"
#include "flpos.h"

using namespace sfw;
void main()
{
	sfw::initContext();
	float W = 1200, H = 1200;
	float steps = 100;
//	Transform trans(400, 300, 30,30, 23);
//
//	int j = int(4);
//	int k(4);
//	int l = { 4 };
//	int n{ 4 };
//
//	Transform tl = Transform(400, 300);
//	Transform tn = { 400, 300 };
//	Transform tm(400, 300);
//	Transform tp{ 400, 300 };
//
//
//
////	trans.position = vec2{ 400,300 };
//	trans.facing = deg2rad(45);
//	trans.scale = vec2{ 24,16 };
//
//	vec2 basis = { 40,0 };
//	float ang_vec = 0;
	while (sfw::stepContext())
	{
		for (int i = 0; i < 100; ++i)
		{
			float x1 = i / 100.f;
			float x2 = (i + 1) / 100.f;

			//float x2 = (i + 1) / 100.f;
			//float y2 = linearHalf(x2);
			float y1 = quadBezier(.5f, 0, 1, x1);
			float y2 = quadBezier(.5f, 0, 1, x2);


			x1 *= W;
			x2 *= W;
			y1 *= H;
			y2 *= H;

			sfw::drawLine(x1,y1,x2,y2);
		}
		//ang_vec += sfw::getDeltaTime();
		//vec2 incident = fromAngle(ang_vec) * 40;
		//float proj = dot(basis, incident);
		//drawLine(400, 300, 400 + basis.x + basis.y, BLACK);
		//trans.debugDraw();
		//trans.facing += getDeltaTime();
	}

	sfw::termContext();
}

