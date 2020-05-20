#include "drawCircleMidPoint.h"


drawCircleMidPoint::drawCircleMidPoint()
{
}


drawCircleMidPoint::~drawCircleMidPoint()
{
}


void drawCircleMidPoint::Draw(DrawPixelFunc drawpixelfunc, int x0, int y0, int radius)
{
	int p = 1 - radius;
	int x = 0;
	int y = radius;
	while (x < y){
		drawpixels(drawpixelfunc,x0, y0, x, y);
		x++;
		if (p < 0)
		{
			p += (2 * x + 1);
		}
		else{
			y--;
			p += (2 * x + 1 - 2 * y);
		}
	}
}
void drawCircleMidPoint::drawpixels(DrawPixelFunc drawpixelfunc, int x0, int y0, int x, int y)
{
	drawpixelfunc(x0 + x, y0 + y);
	drawpixelfunc(x0 + x, y0 - y);
	drawpixelfunc(x0 - x, y0 + y);
	drawpixelfunc(x0 - x, y0 - y);
	drawpixelfunc(x0 + y, y0 + x);
	drawpixelfunc(x0 + y, y0 - x);
	drawpixelfunc(x0 - y, y0 + x);
	drawpixelfunc(x0 - y, y0 - x);
}
