#include <cassert>
#include <cstdio>
#include "vec2.h"
#include "test.h"
#include "flpos.h"
#include "mat2.h"
#include "mat3.h"
#include "shapes.h"
#include "collision.h"

int main()
{
	printf("Hello World! %d", doNothing(40));


	assert(mat3Identity() * mat3Identity() == mat3Identity());

	vec2 N = normal(vec2{ 1,1 });
	assert(N.x == N.y);

	assert(fequals(magnitude(N),1));
	assert(normal(N) == N);
	assert((normal(vec2{ 0,1 }) == vec2{ 0,1 }));

	assert(fequals(1, .9999999f));
	assert(fequals(dot(vec2{ 5,4 }, vec2{ 0,1 }), 4));
	assert(fequals(dot(vec2{ 5,4 }, vec2{ 1,0 }), 5));

//	fequals(angleBetween(vec2{ 0,1 }, vec2{ 0,1 }), deg2rad(45));

	assert(fequals(lerp(.23, 124, 0), .23));
	assert(fequals(lerp(.23, 124, 0), 124));
	assert(fequals(lerp(0, 1, .5f), .5f));

	Circle c = { 10, 0, 5 };

	assert((translate(4, 0) * c == Circle{ 4, 0, 5 }));

	assert((scale(2, 1) * c == Circle{ 4, 0, 10 }));
	assert((scale(2, 2) * c == Circle{ 4, 0, 10 }));
	assert((scale(1, 2) * c == Circle{ 4, 0, 10 }));

	assert((scale(-1, 1) * c == Circle{ 4, 0, 5 }));
	assert((rotate(45) * c == Circle{ 0, 0, 5 }));


	



	return 0;














	mat2 m0 = mat2{ 0,0,0,0 };
	vec3 j = { 2,5,1 };
	//assert(fequals(quadBezier(15, 40, 21, 0), 15));
	//assert(fequals(quadBezier(15, 40, 21, 1), 21));
	//	vec2 someData;
	//	someData[1] == someData.y == someData.v[1];
	//assert((scale(5, 1) * j == vec3{ 10,5,1 }));
	//assert((rotate(deg2rad(90)) * j == vec3{ -5,2,1 }));
	//assert((translate(0, 3)*j == vec3{ 2,8,1 }));
	// development branch

	return 0;


}