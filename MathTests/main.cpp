#include <cassert>
#include <cstdio>
#include "vec2.h"
#include "test.h"
int main()
{
	printf("Hello World! %d", doNothing(40));

	assert(doNothing(0) == 5);
	assert(doNothing(-1) == 4);
	assert(doNothing(1) == 8);


	assert((vec2{ 0,0 } == vec2{ 0,0 }));
	assert((vec2{ 1,1 } + vec2{ -1,0 } == vec2{ 0,1 }));
	assert((vec2{ 1,1 } - vec2{ 1,1 } == vec2{ 0,0 }));
	assert((vec2{ 1,1 } * vec2{ 1,1 } == vec2{ 1,1 }));
	assert((vec2{ 1,1 } * vec2{ -1,0 } == vec2{ 0,1 }));
	assert((vec2{ 1,1 } / vec2{ -1,0 } == vec2{ 0,1 }));
	assert((vec2{ 1,1 } / vec2{ -1,0 } == vec2{ 0,1 }));














	return 0;



}