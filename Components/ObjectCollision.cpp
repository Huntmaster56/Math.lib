#include "ObjectCollision.h"
#include "Floor.h"
#include "Collider.h"
void PlayerAsteroidCollision(PlayerShip & player, Floor & as)
{
	collisionData result =
		DynamicResolution(player.transform, player.rigidbody, player.collider,
						  as.transform, as.rigidbody, as.collider);

	if (result.penetrationDepth >= 0)
	{
		player.transform.m_scale *= .9f;
	}
}

void AsteroidCollision(Floor & as1, Floor & as2)
{
	DynamicResolution(as1.transform, as1.rigidbody, as1.collider,
		as2.transform, as2.rigidbody, as2.collider);
}

void AsteroidCollision2(Spring & as1, Spring & as2)
{
	DynamicResolution(as1.transform, as1.rigidbody, as1.collider,
		as2.transform, as2.rigidbody, as2.collider);
}

void FloorCollision(PlayerShip & player, Floor & floor)
{
	StaticResolution(player.transform, player.rigidbody, player.collider,
								   floor.transform, floor.collider, 1.25);
}

void SpringCollision(PlayerShip & player, Spring & spring)
{
	StaticResolution(player.transform, player.rigidbody, player.collider,
		spring.transform, spring.collider, 1.25);
}
