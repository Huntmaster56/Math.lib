#include "collision.h"
#include <cmath>
CollisionData1D collisionDetection1D(float Amin, float Amax,
									 float Bmin, float Bmax)
{
	CollisionData1D retval;

	retval.penetrationDepth = fminf((Amax - Bmin) , (Bmax - Amin));

	retval.collisionNormal = sin((Amax - Bmin) - (Bmax - Amin));


	retval.result = retval.penetrationDepth >= 0;
	retval.MTV = retval.penetrationDepth 
					* retval.collisionNormal;

	return retval;
}
