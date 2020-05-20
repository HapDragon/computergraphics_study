#include "drawBresenHamLine.h"


drawBresenHamLine::drawBresenHamLine()
{
}


drawBresenHamLine::~drawBresenHamLine()
{
}


void drawBresenHamLine::Draw(DrawPixelFunc drawpixelfunc,int x0, int y0, int xEnd, int yEnd)
{
	int dx = abs(xEnd - x0);
	int dy = abs(yEnd - y0);
	int x, y;
	if (dx == 0)
	{
		int interval = (yEnd > y0) ? 1 : -1;
		x = x0, y = y0;
		drawpixelfunc(x, y);
		while (y != yEnd)
		{
			y += interval;
			drawpixelfunc(x, y);
		}
	}
	else if (dy == 0)
	{
		int interval = (xEnd > x0) ? 1 : -1;
		x = x0, y = y0;
		drawpixelfunc(x, y);
		while (x != xEnd)
		{
			x += interval;
			drawpixelfunc(x, y);
		}
	}
	else
	{


		bool klower1 = (dy <= dx);

		if (klower1)
		{
			int p = 2 * dy - dx;
			int twody = 2 * dy;
			int twodyminusdx = 2 * (dy - dx);

			if (xEnd < x0)
			{
				//交换首尾
				x0 = xEnd - x0;
				xEnd = xEnd - x0;
				x0 = xEnd + x0;
				y0 = yEnd - y0;
				yEnd = yEnd - y0;
				y0 = yEnd + y0;
			}
			x = x0;
			y = y0;
			drawpixelfunc(x, y);
			while (x < xEnd)
			{
				x++;
				if (p < 0)
				{
					drawpixelfunc(x, y);
					p += twody;
				}
				else
				{
					y += (yEnd > y0) ? 1 : -1;
					drawpixelfunc(x, y);
					p += twodyminusdx;
				}
			}
		}
		else
		{
			int p = 2 * dx - dy;
			int twodx = 2 * dx;
			int twodxminusdy = 2 * (dx - dy);
			if (yEnd < y0)
			{
				//交换首尾
				x0 = xEnd - x0;
				xEnd = xEnd - x0;
				x0 = xEnd + x0;
				y0 = yEnd - y0;
				yEnd = yEnd - y0;
				y0 = yEnd + y0;
			}
			x = x0;
			y = y0;
			drawpixelfunc(x, y);
			while (y < yEnd)
			{
				y++;
				if (p < 0)
				{
					drawpixelfunc(x, y);
					p += twodx;
				}
				else
				{
					x += (xEnd > x0) ? 1 : -1;
					drawpixelfunc(x, y);
					p += twodxminusdy;
				}
			}
		}
	}
}



