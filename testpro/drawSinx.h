#pragma once
#include "globaltypes.h"
class drawSinx
{
public:
	drawSinx();
	~drawSinx();
	drawSinx(unsigned cyclex, unsigned maxy, int x0, int y0,int width);
private:	
	//cyclex为x方向周期 正整数
	//maxy为y方向最大值 正整数
	//x0,y0为起始点
	unsigned _cyclex;
	unsigned _maxy;
	int _x0;
	int _y0;
	int _width;
public:

	//绘制主函数
	//drawpixelfunc为画点函数	
	void Draw(DrawPixelFunc drawpixelfunc);
private:
	void drawpixels(DrawPixelFunc drawpixelfunc, int x, int y);
};

