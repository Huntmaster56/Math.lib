#include "sfwdraw.h"
#include "vec2.h"
#include "Transform.h"
#include "flpos.h"
#include "Rigidbody.h"
#include "SpaceshipLocomotive.h"
#include "SpaceshipController.h"

using namespace sfw;
void main()
{
	float SCREEN_WIDTH = 400, SCREEN_HEIGHT = 400;
	sfw::initContext(SCREEN_WIDTH, SCREEN_HEIGHT);
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

	vec2 start = { 200, 300  },
		 end   = { 900, 800  },
		 mid   = {   0, 1100 };

	Transform playerTransform(200, 200);
	playerTransform.scale = { 5,5 };
	Rigidbody playerRigidbody;
	playerRigidbody.velocity = vec2{ 0,0 };

	SpacechipController playerCtrl;
	SpaceshipLocomotive playerLoco;

	while (sfw::stepContext())
	{
		//sfw::drawCircle(player.x, player.y, 5.f);

		float deltaTime = sfw::getDeltaTime();

		//if (sfw::getKey('W')) playerRigidbody.velocity.y += 10.0f;
		//if (sfw::getKey('S')) playerRigidbody.velocity.y -= 10.0f;
		//if (sfw::getKey('A')) playerRigidbody.velocity.x -= 10.0f;
		//if (sfw::getKey('D')) playerRigidbody.velocity.x += 10.0f;

		//if (sfw::getKey('Q')) playerRigidbody.angularVelocity += 10.0f;
		//if (sfw::getKey('E')) playerRigidbody.angularVelocity -= 10.0f;

		if (playerTransform.position.x > SCREEN_WIDTH)
			playerTransform.position.x = 0.0f;
		else if (playerTransform.position.x < 0.0f)
			playerTransform = SCREEN_WIDTH;

		if (playerTransform.position.y > SCREEN_HEIGHT)
			playerTransform.position.y = 0.0f;
		else if (playerTransform.position.y < 0.0f)
			playerTransform.position.y = SCREEN_HEIGHT;

///////////////////////////////////////////////////////////////

		playerCtrl.update(playerLoco);
		playerLoco.update(playerRigidbody, deltaTime);
		playerRigidbody.integrate(playerTransform, deltaTime);

///////////////////////////////////////////////////////////////

		playerTransform.debugDraw();
		//for (int i = 0; i < 100; ++i)
		//{
		//	float x1 = i / 100.f;
		//	float x2 = (i + 1) / 100.f;
		//	//float x2 = (i + 1) / 100.f;
		//	//float y2 = linearHalf(x2);
		//	float y1 = quadBezier(.5f, 0, 1, x1);
		//	float y2 = quadBezier(.5f, 0, 1, x2);
		//	x1 *= W;
		//	x2 *= W;
		//	y1 *= H;
		//	y2 *= H;
		//	sfw::drawLine(x1,y1,x2,y2);
		//}
		//ang_vec += sfw::getDeltaTime();
		//vec2 incident = fromAngle(ang_vec) * 40;
		//float proj = dot(basis, incident);
		//drawLine(400, 300, 400 + basis.x + basis.y, BLACK);
		//trans.debugDraw();
		//trans.facing += getDeltaTime();
	}
	sfw::termContext();
}

