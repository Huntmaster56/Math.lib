#include "shapeDraw.h"
#include "sfwdraw.h"

void drawCircle(const Circle &c, unsigned color)
{
	sfw::drawCircle(c.pos.x, c.pos.y, c.rad, 12U, color);
}