#pragma once

#include "SpaceshipLocomotive.h"
#include "sfwdrawext.h"

class SpacechipController
{
public:
	unsigned CTR_LEFT, CTR_RIGHT, CTR_UP, CTR_DOWN, CTR_BREAK, CTR_SPEED;

	SpacechipController(unsigned CTR_LEFT = 'A',
						unsigned CTR_RIGHT = 'D', 
						unsigned CTR_UP = 'W', 
						unsigned CTR_DOWN = 'S', 
						unsigned CTR_BREAK = ' ',
						unsigned CTR_SPEED = KEY_LEFTSHIFT);

	void update(SpaceshipLocomotive &loco);







};