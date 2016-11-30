#include "Collider.h"
#include "shapedraw.h"
#include <cmath>
Collider::Collider() {}
//Collider::Collider(const vec2 * verts, int size) : hull(verts,size)
//{
//	int maxX = -INFINITY;
//	int minX =  INFINITY;
//	int maxY = -INFINITY;
//	int minY =  INFINITY;
//
//	for (int i = 0; i < size; i++)
//	{
//		if (verts[i].x < minX)
//		{
//			minX = verts[i].x;
//		}
//		if (verts[i].x > maxX)
//		{
//			maxX = verts[i].x;
//		}
//		if (verts[i].y < minY)
//		{
//			minY = verts[i].y;
//		}
//		if (verts[i].y > maxY)
//		{
//			maxY = verts[i].y;
//		}
//	}
//	vec2 min{ minX, minY };
//	vec2 max{ maxX, maxY };
//
//	box.pos = (min + max) / 2;
//	box.he =  (max - min) / 2;
//
//}

Collider::Collider(const vec2 * verts, int size)
	: hull(verts, size)
{
	vec2 boxMin = { INFINITY,  INFINITY },
		boxMax = { -INFINITY, -INFINITY };

	for (int i = 0; i < size; ++i)
	{
		boxMin = min(boxMin, verts[i]);
		boxMax = max(boxMax, verts[i]);
	}

	box.pos = (boxMin + boxMax) / 2;
	box.he = (boxMax - boxMin) / 2;
}


void Collider::DebugDraw(const mat3 & T, const Transform & trans)
{
	mat3 glob = T * trans.getGlobalTransform();

	drawAABB(glob * box, 0x888888ff);
	drawHull(glob * hull, 0x888888ff);
	
	
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


collisionData StaticResolution(Transform & AT, Rigidbody & AR, const Collider & AC,	
						 const Transform & BT, const Collider & BC, float bounciness)
{
	collisionData results = ColliderCollision(AT, AC, BT, BC);
	if (results.penetrationDepth >= 0)
	{
		vec2 MTV = results.penetrationDepth * results.collisionNormal;
		AT.m_position -= MTV;

		AR.velocity = reflect(AR.velocity, results.collisionNormal) * bounciness;

		
	}

	return results;
}

collisionData DynamicResolution(Transform & AT, Rigidbody & AR, const Collider & AC,
								Transform & BT, Rigidbody & BR, const Collider & BC, float bounciness)
{
	collisionData results = ColliderCollision(AT, AC, BT, BC);
	if (results.penetrationDepth >= 0)
	{
		vec2 MTV = results.penetrationDepth * results.collisionNormal;

		float am = magnitude(AR.mass * AR.velocity);
		float bm = magnitude(BR.mass * BR.velocity);
		float cm = am + bm;

		AT.m_position -= MTV * (1 - am / cm);
		BT.m_position += MTV * (1 - bm / cm);

		vec2  A = AR.velocity;
		float P = AR.mass;
		vec2  X;

		vec2  B = BR.velocity;
		float Q = BR.mass;
		vec2  Y;

		float E = bounciness;

		X = (A*P + B*Q + -E*(A - B)*Q) / (Q + P);
		Y = E*(A - B) + X;

		AR.velocity = X;
		BR.velocity = Y;
	}
	return results;
}