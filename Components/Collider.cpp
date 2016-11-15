#include "Collider.h"
#include "shapedraw.h"
#include <cmath>
Collider::Collider(const vec2 * verts, int size)
				: hull(verts,size)
{
	int maxX = -INFINITY;
	int minX =  INFINITY;
	int maxY = -INFINITY;
	int minY =  INFINITY;

	for (int i = 0; i < size; i++)
	{
		if (verts[i].x < minX)
		{
			minX = verts[i].x;
		}
		if (verts[i].x > maxX)
		{
			maxX = verts[i].x;
		}
		if (verts[i].y < minY)
		{
			minY = verts[i].y;
		}
		if (verts[i].y > maxY)
		{
			maxY = verts[i].y;
		}
	}
	vec2 min{ minX, minY };
	vec2 max{ maxX, maxY };

	box.pos = (min + max) / 2;
	box.he =  (max - min) / 2;

}

void Collider::DebugDraw(const mat3 & T,
						 const Transform & trans)
{
	mat3 glob = T * trans.getGlobalTransform();

	drawAABB(glob * box, 0x888888ff);
	drawHull(glob * hull, 0x888888ff);
	
	
	//drawAABB(T * trans.getGlobalTransform() * box, 0x888888ff);
}

collisionData ColliderCollision(const Transform & AT, const Collider & AC, const Transform & BT, const Collider & BC)
{
	collisionData retval;

	retval = boxCollision(AT.getGlobalTransform() * AC.box,
						  BT.getGlobalTransform() * BC.box);

	if (retval.penetrationDepth >= 0)
		retval = HullCollision(AT.getGlobalTransform() * AC.hull,
							   BT.getGlobalTransform() * BC.hull);

	return retval;
}
collisionData DynamicResolution(Transform & AT, )
collisionData results = ColliderCollision(AT, AC, BT, BC);
if (results.penetrationDepth >= 0)
{
	vec2 MTV = results.penetrationDepth
}
