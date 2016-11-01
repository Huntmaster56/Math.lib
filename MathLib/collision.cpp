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
		retval.collisionNormal = vec2{1,0} * XCD.penetrationDepth;
	}
	else
	{
		retval.penetrationDepth = YCD.penetrationDepth;
		retval.collisionNormal = vec2{ 1,0 } * YCD.penetrationDepth;

	}
	return retval;
}

bool collisionData::result() const
{
	return penetrationDepth;
}

vec2 collisionData::MTV() const
{
	return vec2();
}

collisionData boxCollisionSwept(const AABB & A, const vec2 & dA, const AABB & B, const vec2 & dB)
{
	CollisionDataSwept retval;

	SweptCollisionData1D Xres = sweptDetection1D(A.min().x, A.max().x, dA.x,
												 B.min().x, B.max().x, dB.x);
	SweptCollisionData1D Yres = sweptDetection1D(A.min().y, A.max().y, dA.y,
												 B.min().y, B.max().y, dB.y);

	if (Yres.entryTime < Xres.entryTime)
	{
		retval.collisionNormal = vec2{ 1,0 } *Xres.collisionNormal;
		retval.entryTime = Yres.entryTime;
	}
	else
	{
		retval.collisionNormal = vec2{ 0,1 } *Yres.collisionNormal;
		retval.entryTime = Yres.entryTime;
	}

	if (Yres.exitTime < Xres.exitTime || isinf(Xres.exitTime))

		retval.exitTime = Yres.exitTime;
	else
		retval.exitTime = Xres.exitTime;

	return retval;






	//CollisionDataSwept retval;
	//float tLx = (A.min.x - B.max.x) / (dB.x - dA.x);
	//float tRx = (A.max.x - B.min.x) / (dA.x - dB.x);
	//float tLy = (A.min.y - B.max.y) / (dB.y - dA.y);
	//float tRy = (A.max.y - B.min.y) / (dA.y - dB.y);
	//float entryX = fminf(tLx, tRx);
	//float entryY = fmaxf(tLx, tRx);
	//float exitX = fminf(tLx, tRx);
	//float exitY = fmaxf(tLx, tRx);
	//retval.entryTime = fminf(tLx, tRx);
	//retval.exitTime = fmaxf(tLx, tRx);
	//return collisionData();
}









