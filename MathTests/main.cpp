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




	getchar();
	return 0;

	// development branch

}