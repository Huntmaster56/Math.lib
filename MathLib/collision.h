#pragma once

struct CollisionData1D
{
	bool  result;
	float penetrationDepth;
	float collisionNormal;
	float MTV;
};


CollisionData1D collisionDetection1D(float Amin, float Amax,
								 	 float Bmin, float Bmax);

 










