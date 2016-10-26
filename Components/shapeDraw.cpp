#include "shapeDraw.h"
#include "sfwdraw.h"

void drawCircle(const Circle &c, unsigned color)
{
	sfw::drawCircle(c.pos.x, c.pos.y, c.rad, 12U, color);
}

void drawAABB(const AABB & box, unsigned color)
{
	vec2 A = vec2{ box.min().x, box.max().y };
	vec2 B = vec2{ box.max().x, box.max().y };
	vec2 C = vec2{ box.max().x, box.min().y };
	vec2 D = vec2{ box.min().x, box.min().y };

	sfw::drawLine(A.x, A.y, B.x, B.y, color);
	sfw::drawLine(B.x, B.y, C.x, C.y, color);
	sfw::drawLine(C.x, C.y, D.x, D.y, color);
	sfw::drawLine(D.x, D.y, A.x, A.y, color);
}

