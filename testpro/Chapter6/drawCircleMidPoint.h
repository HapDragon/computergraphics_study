#pragma once
#include "..\globaltypes.h"
//�е㻭Բ
class drawCircleMidPoint
{
public:
	drawCircleMidPoint();
	~drawCircleMidPoint();
	void Draw(DrawPixelFunc drawpixelfunc, int x0, int y0, int radius);
private:
	void drawpixels(DrawPixelFunc drawpixelfunc, int x0, int y0, int x, int y);
};

