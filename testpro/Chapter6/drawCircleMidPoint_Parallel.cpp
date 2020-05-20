#include "drawCircleMidPoint_Parallel.h"


drawCircleMidPoint_Parallel::drawCircleMidPoint_Parallel()
{
}


drawCircleMidPoint_Parallel::~drawCircleMidPoint_Parallel()
{
}

void drawCircleMidPoint_Parallel::Draw(DrawPixelFunc drawpixelfunc, int x0, int y0, int radius)
{
	int p = 1 - radius;
	int x = 0;
	int y = radius;
	// 定义线程的 id 变量，多个变量使用数组
	
	
	while (x < y){
		drawpixels(drawpixelfunc, x0, y0, x, y);
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
void drawCircleMidPoint_Parallel::drawpixels(DrawPixelFunc drawpixelfunc, int x0, int y0, int x, int y)
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

