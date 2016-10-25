#include "sfwdraw.h"
#include "vec2.h"
#include "Transform.h"
#include "flpos.h"
#include "Rigidbody.h"
#include "SpaceshipLocomotive.h"
#include "SpaceshipController.h"
#include "PlanetaryMotor.h"
#include "PlanetaryRenderer.h"
#include "SpaceshipRenderer.h"
using namespace sfw;
void main()
{
	float SCREEN_WIDTH = 800, SCREEN_HEIGHT = 800;
	sfw::initContext(SCREEN_WIDTH, SCREEN_HEIGHT);
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

//sfw::initContext();
	//float W = 1200, H = 1200;
	vec2 start = { 200, 300  },
		 end   = { 900, 800  },
		 mid   = {   0, 1100 };

	Transform playerTransform(400, 400);
	Rigidbody playerRigidbody;
	SpacechipController playerCtrl;
	SpaceshipLocomotive playerLoco;

	//Transform ST1(25, 0);
	//Transform ST2(20, 0);
	//Transform ST3(15, 0);
	//Transform ST4(10, 0);
	//ST1.m_parent = &playerTransform;
	//ST2.m_parent = &ST1;
	//ST3.m_parent = &ST2;
	//ST4.m_parent = &ST3;

	Transform sunTransform;
	sunTransform.m_position = vec2{ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 };
	Rigidbody sunRbody;
	PlanetaryMotor sunMotor;
	sunMotor.m_rotationSpeed = 5;
	PlanetaryRenderer sunRenderer(YELLOW, 100);

	Transform plan1;
	plan1.m_position = vec2{ 150, 0 };
	plan1.m_parent = &sunTransform;
	Rigidbody plan1RB;
	PlanetaryMotor plan1motor;
	plan1motor.m_rotationSpeed = 7;
	PlanetaryRenderer plan1renderer(GREEN, 20);

	Transform moon1;
	moon1.m_position = vec2{ 50, 0 };
	moon1.m_parent = &plan1;
	Rigidbody moon1RB;
	PlanetaryMotor moon1motor;
	moon1motor.m_rotationSpeed = 12;
	PlanetaryRenderer moon1renderer(WHITE, 7);

	Transform cameraTransform;

	//playerRigidbody.velocity = vec2{ 0,0 };
	//playerTransform.m_scale = { 3,3 };
	//ST1.m_scale = { 1,1 };
	//ST1.m_scale = { 1,1 };
	while (sfw::stepContext())
	{
		//if (playerTransform.m_position.x > SCREEN_WIDTH)
		//	playerTransform.m_position.x = 0.0f;
		//else if (playerTransform.m_position.x < 0.0f)
		//	playerTransform.m_position.x = SCREEN_WIDTH;
		//if (playerTransform.m_position.y > SCREEN_HEIGHT)
		//	playerTransform.m_position.y = 0.0f;
		//else if (playerTransform.m_position.y < 0.0f)
		//	playerTransform.m_position.y = SCREEN_HEIGHT;
		float deltaTime = sfw::getDeltaTime();
///////////////////////////////////////////////////////////////
		playerCtrl.update(playerLoco);
		playerLoco.update(playerTransform, playerRigidbody);
		playerRigidbody.integrate(playerTransform, deltaTime);
///////////////////////////////////////////////////////////////

		sunMotor.update(sunRbody);
		plan1motor.update(plan1RB);
		moon1motor.update(moon1RB);

		moon1RB.integrate(moon1, deltaTime);
		plan1RB.integrate(plan1, deltaTime);
		sunRbody.integrate(sunTransform, deltaTime);

		cameraTransform.m_position
			= lerp(cameraTransform.m_position,
				playerTransform.getGlobalPosition(),
				sfw::getDeltaTime() * 10);

		mat3 proj = translate(600, 600) * scale(2, 2);
		mat3 view = inverse(cameraTransform.getGlobalTransform());
	
		mat3 camera = proj * view;

		playerTransform.debugDraw(camera);
		sunTransform.debugDraw(camera);
		plan1.debugDraw(camera);
		moon1.debugDraw(camera);
		cameraTransform.debugDraw(camera);
		
		playerRigidbody.debugDraw(camera, playerTransform);

		sunRenderer.draw(camera, sunTransform);
		plan1renderer.draw(camera, plan1);
		moon1renderer.draw(camera, moon1);

		//playerRender.draw(camera, playerTransform);

		//mat3 test = { 0,1,2,3,4,5,6,7,8 };
		//playerTransform.debugDraw();
		//playerRigidbody.debugDraw(playerTransform);
		//ST1.debugDraw();
		//ST2.debugDraw();
		//ST3.debugDraw();
		//ST4.debugDraw();
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

