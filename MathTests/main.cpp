#include <cassert>
#include <cstdio>
#include "vec2.h"
#include "test.h"
#include "flpos.h"

int main()
{
	printf("Hello World! %d", doNothing(40));

	assert(doNothing(0) == 5);
	assert(doNothing(-1) == 4);
	assert(doNothing(1) == 8);

	///////////////////////////////////////////////////////////////
			//Vector tests

	assert((vec2{ 0,0 } == vec2{ 0,0 }));
	assert((vec2{ 1,0 } == vec2{ 1,0 }));

	assert((vec2{ 1,1 } + vec2{ -1,0 } == vec2{ 0,1 }));

	vec2 var = { 4,0 };
	var += vec2{ -3,1 };
	assert((var == vec2{ 1,1 }));

	vec2 N = normal(vec2{ 1,1 });
	assert(N.x == N.y);

	assert(fequals(magnitude(N),1));
	assert(normal(N) == N);
	assert((normal(vec2{ 0,1 }) == vec2{ 0,1 }));

	assert(fequals(1, .9999999f));
	assert(fequals(dot(vec2{ 5,4 }, vec2{ 0,1 }), 4));
	assert(fequals(dot(vec2{ 5,4 }, vec2{ 1,0 }), 5));

	fequals(angleBetween(vec2{ 0,1 }, vec2{ 0,1 }), deg2rad(45));
	return 0;



}