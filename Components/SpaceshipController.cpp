#include "SpaceshipController.h"

#include "sfwdraw.h"

SpacechipController::SpacechipController(unsigned a_CTR_LEFT,
										 unsigned a_CTR_RIGHT,
										 unsigned a_CTR_UP,
										 unsigned a_CTR_DOWN,
										 unsigned a_CTR_BREAK,
										 unsigned a_CTR_SPEED)
{
	CTR_LEFT	= a_CTR_LEFT;
	CTR_RIGHT	= a_CTR_RIGHT;
	CTR_UP		= a_CTR_UP;
	CTR_DOWN	= a_CTR_DOWN;
	CTR_BREAK   = a_CTR_BREAK;
	CTR_SPEED   = a_CTR_SPEED;
}

void SpacechipController::update(SpaceshipLocomotive & loco)
{
	float hInput = 0.0f;
	hInput += sfw::getKey('A');
	hInput -= sfw::getKey('D');

	float vInput = 0.0f;
	vInput += sfw::getKey('S');
	vInput -= sfw::getKey('W');

	float bInput = sfw::getKey(' ');
	

	loco.doStop(bInput);
	loco.doTurn(hInput);
	loco.doThrust(vInput);

}
