#include "drawSinx.h"


drawSinx::drawSinx()
{
}


drawSinx::~drawSinx()
{
}
drawSinx::drawSinx(unsigned cyclex, unsigned maxy,int x0,int y0,int width)
{
	_cyclex = cyclex;
	_maxy = maxy;
	_x0 = x0;
	_y0 = y0;
	_width = width;
}

//绘制主函数
//drawpixelfunc为画点函数
//cyclex为x方向周期
//maxy为y方向最大值
//x0,y0为起始点
void drawSinx::Draw(DrawPixelFunc drawpixelfunc)
{
	//假设正弦函数为：Asin(x/B)
	//则根据周期和y方向最大值可分别求出A、B
	double A = _maxy;
	double B = _cyclex / (2 * PI);
	int x = 0;
	int y = 0;
	
	double cyclexexceptfour = _cyclex / 4;
	
	if (A <= B)
	{
		//永远K<1 X方向自增
		while (x <= cyclexexceptfour)
		{
			drawpixels(drawpixelfunc, x, y);
			x++;
			double xeb = x / B;
			y = A*sin(xeb);
		}
	}
	else{
		//斜率转折点		
		double y_turn = (sqrt(A*A - B*B));
		//y<=y_turn时K>=1 Y方向自增
		while (y <= y_turn)
		{
			drawpixels(drawpixelfunc, x, y);
			y++;
			x = B*asin(y / A);
		}
		//y>y_turn时K<1 X方向自增
		while (x <= cyclexexceptfour)
		{
			drawpixels(drawpixelfunc, x, y);
			x++;
			double xeb = x / B;
			y = A*sin(xeb);
		}
	}
}

void drawSinx::drawpixels(DrawPixelFunc drawpixelfunc, int x, int y)
{
	double cyclexexceptfour = _cyclex / 4;
	//右边
	int i = 0;
	do
	{
		drawpixelfunc(_x0 + x + 4 * i*cyclexexceptfour, _y0 - y);
		drawpixelfunc(_x0 + 2 * cyclexexceptfour - x + 4 * i*cyclexexceptfour, _y0 - y);
		drawpixelfunc(_x0 + 2 * cyclexexceptfour + x + 4 * i*cyclexexceptfour, _y0 + y);
		drawpixelfunc(_x0 + 4 * cyclexexceptfour - x + 4 * i*cyclexexceptfour, _y0 + y);
		i++;
	} while (_x0 + x + 4 * i*cyclexexceptfour <= _width);

	i = 0;
	//左边
	do
	{
		drawpixelfunc(_x0 - x - 4 * i*cyclexexceptfour, _y0 + y);
		drawpixelfunc(_x0 - 2 * cyclexexceptfour + x - 4 * i*cyclexexceptfour, _y0 + y);
		drawpixelfunc(_x0 - 2 * cyclexexceptfour - x - 4 * i*cyclexexceptfour, _y0 - y);
		drawpixelfunc(_x0 - 4 * cyclexexceptfour + x - 4 * i*cyclexexceptfour, _y0 - y);
		i++;
	} while (_x0 - x - 4 * i*cyclexexceptfour >= 0);

}