#pragma once

#include "SpaceshipLocomotive.h"
#include "sfwdraw.h"

class SpacechipController
{
public:
	unsigned CTR_LEFT, CTR_RIGHT, CTR_UP, CTR_DOWN, CTR_BREAK;

	SpacechipController(unsigned CTR_LEFT = 'A',
						unsigned CTR_RIGHT = 'D', 
						unsigned CTR_UP = 'W', 
						unsigned CTR_DOWN = 'S', 
						unsigned CTR_BREAK = ' ');
	void update(SpaceshipLocomotive &loco);







};