#pragma once
#include "globaltypes.h"
class drawSinx
{
public:
	drawSinx();
	~drawSinx();
	drawSinx(unsigned cyclex, unsigned maxy, int x0, int y0,int width);
private:	
	//cyclexΪx�������� ������
	//maxyΪy�������ֵ ������
	//x0,y0Ϊ��ʼ��
	unsigned _cyclex;
	unsigned _maxy;
	int _x0;
	int _y0;
	int _width;
public:

	//����������
	//drawpixelfuncΪ���㺯��	
	void Draw(DrawPixelFunc drawpixelfunc);
private:
	void drawpixels(DrawPixelFunc drawpixelfunc, int x, int y);
};

