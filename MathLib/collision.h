#pragma once
#include "shapes.h"
struct CollisionData1D
{
	float penetrationDepth;
	float collisionNormal;


	bool  result() const;
	float MTV() const;
};


CollisionData1D collisionDetection1D(float Amin, float Amax,
								 	 float Bmin, float Bmax);

 
struct SweptCollisionData1D
{
	float entryTime, exitTime;
	float collisionNormal;

	bool result() const;
};

//CollisionData1D sweptDetection1D(float Amin, float Amax, float Avel,
//								 float Bmin, float Bmax, float Bvel);
SweptCollisionData1D sweptDetection1D(float Amin, float Amax, float Avel,
									  float Bmin, float Bmax, float Bvel);



struct collisionData
{
	float penetrationDepth;
	vec2 collisionNormal;

	bool result() const;
	vec2 MTV() const;

};

collisionData boxCollision(const AABB &A, const AABB &B);

struct CollisionDataSwept
{
	float entryTime, exitTime;
	vec2 collisionNormal;
	bool collides;

	bool result() const;
};

CollisionDataSwept boxCollisionSwept(const AABB &A, const vec2 &dA,
								const AABB &B, const vec2 &dB);

collisionData planeBoxCollision(const Plane &P, const AABB &B);

CollisionDataSwept planeBoxCollisionSwept(const Plane & P, const vec2 &Pvel,
	const AABB & B, const vec2 & Bvel);