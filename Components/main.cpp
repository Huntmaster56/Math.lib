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
#include "Collider.h"
using namespace sfw;
void main()
{
	float SCREEN_WIDTH = 1200, SCREEN_HEIGHT = 1200;
	sfw::initContext(SCREEN_WIDTH, SCREEN_HEIGHT);

	Transform playerTransform(200, 200);
	playerTransform.m_scale = vec2{ 20, 10 };

	Rigidbody playerRigidbody;
	SpacechipController playerCtrl;
	SpaceshipLocomotive playerLoco;
	SpaceshipRenderer playerRender;

	vec2 hullVrts[] = { { 0, 3 },
						{-2,-3 }, 
						{ 2,-3 } };
	Collider playerCollider(hullVrts, 3);
	
	Transform occularTransform(0, 0);
	occularTransform.m_scale = vec2{ 8,8 };
	Collider occluderCollider(hullVrts, 3);
	
	Transform cameraTransform;
	while (sfw::stepContext())
	{
		float deltaTime = sfw::getDeltaTime();


		playerCtrl.update		 (playerLoco);
		playerLoco.update		 (playerTransform, playerRigidbody);
		playerRigidbody.integrate(playerTransform, deltaTime);

		collisionData results = ColliderCollision(playerTransform, playerCollider, occularTransform, occluderCollider);

		if (results.penetrationDepth >= 0)
		{
			vec2 MTV = results.penetrationDepth * results.collisionNormal;
			playerTransform.m_position -= MTV;
			playerRigidbody.velocity = reflect(playerRigidbody.velocity, results.collisionNormal);
		}

		cameraTransform.m_position = playerTransform.getGlobalPosition();
		mat3 proj = translate(600, 600) * scale(2, 2);
		mat3 view = inverse(cameraTransform.getGlobalTransform());
		mat3 camera = proj * view;

		occularTransform.debugDraw(camera);
		occluderCollider.DebugDraw(camera, occularTransform);

		playerTransform.debugDraw(camera);
		playerRigidbody.debugDraw(camera, playerTransform);
		playerCollider.DebugDraw(camera, playerTransform);
	}
	sfw::termContext();
}

