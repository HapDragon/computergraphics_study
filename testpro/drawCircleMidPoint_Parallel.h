#pragma once
#include "globaltypes.h"
//�����е㻭Բ
class drawCircleMidPoint_Parallel
{
#define NUM_THREADS 5;
public:
	drawCircleMidPoint_Parallel();
	~drawCircleMidPoint_Parallel();
	void Draw(DrawPixelFunc drawpixelfunc, int x0, int y0, int radius);
private:
	void drawpixels(DrawPixelFunc drawpixelfunc, int x0, int y0, int x, int y);
};

