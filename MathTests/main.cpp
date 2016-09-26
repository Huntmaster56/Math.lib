#include <cassert>
#include <cstdio>

#include "test.h"
int main()
{
	printf("Hello World! %d", doNothing(40));

	assert(doNothing(0) == 5);
	assert(doNothing(-1) == 4);
	assert(doNothing(1) == 8);

	assert(test_quad( 0) == -7);
	assert(test_quad(-1) == -8);
	assert(test_quad( 1) == -4);
// B
	quad_results res = quad(1, 0, 0);
	assert(quad(4, 1, -5).roots == 2);
// C
	assert(lerp(4, 3, 1) == 3);
	getchar();
	return 0;

	// development branch

}