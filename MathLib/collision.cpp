#include "collision.h"
#include <cmath>
#include "vec2.h"
CollisionData1D collisionDetection1D(float Amin, float Amax,
									 float Bmin, float Bmax)
{
	CollisionData1D retval;

	float pDr = Amax - Bmin;
	float PDl = Bmax - Amin;

	retval.penetrationDepth = fmin(pDr, PDl);

	retval.collisionNormal = copysignf(1, PDl - pDr);

	//retval.penetrationDepth = fminf((Amax - Bmin) , (Bmax - Amin));
	//retval.collisionNormal = sin((Amax - Bmin) - (Bmax - Amin));
	//retval.result = retval.penetrationDepth >= 0;
	//retval.MTV = retval.penetrationDepth 
	//				* retval.collisionNormal;

	return retval;
}

bool CollisionData1D::result() const
{
	return penetrationDepth >= 0; 
}
float CollisionData1D::MTV() const
{
	return penetrationDepth * collisionNormal; 
}
bool SweptCollisionData1D::result() const
{
	return false;
}

SweptCollisionData1D sweptDetection1D(float Amin, float Amax, float Avel,
	float Bmin, float Bmax, float Bvel)
{
	SweptCollisionData1D retval;

	float tl = (Amin - Bmax) / (Bvel - Avel);
	float tr = (Bmin - Amax) / (Avel - Bvel);

	retval.entryTime = fmin(tl, tr);
	retval.exitTime  = fmax(tl, tr);

	retval.collisionNormal = copysignf(1, tl - tr);

	return retval;
}

collisionData boxCollision(const AABB & A, const AABB & B)
{
	collisionData retval;

	CollisionData1D XCD = collisionDetection1D(A.min().x, A.max().x,
											   B.min().x, B.max().x);

	CollisionData1D YCD = collisionDetection1D(A.min().y, A.max().y,
										 	   B.min().y, B.max().y);

	if (XCD.penetrationDepth < YCD.penetrationDepth)
	{
		retval.penetrationDepth = XCD.penetrationDepth;
		retval.penetrationDepth = vec2{1,0} * XCD.penetrationDepth;
	}
	else
	{
		retval.penetrationDepth = YCD.penetrationDepth;
		retval.penetrationDepth = vec2{ 1,0 } * YCD.penetrationDepth;

	}
	return retval;
}

bool collisionData::result() const
{
	return penetrationDepth;
}










