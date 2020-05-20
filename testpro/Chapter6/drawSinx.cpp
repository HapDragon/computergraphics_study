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

//����������
//drawpixelfuncΪ���㺯��
//cyclexΪx��������
//maxyΪy�������ֵ
//x0,y0Ϊ��ʼ��
void drawSinx::Draw(DrawPixelFunc drawpixelfunc)
{
	//�������Һ���Ϊ��Asin(x/B)
	//��������ں�y�������ֵ�ɷֱ����A��B
	double A = _maxy;
	double B = _cyclex / (2 * PI);
	int x = 0;
	int y = 0;
	
	double cyclexexceptfour = _cyclex / 4;
	
	if (A <= B)
	{
		//��ԶK<1 X��������
		while (x <= cyclexexceptfour)
		{
			drawpixels(drawpixelfunc, x, y);
			x++;
			double xeb = x / B;
			y = A*sin(xeb);
		}
	}
	else{
		//б��ת�۵�		
		double y_turn = (sqrt(A*A - B*B));
		//y<=y_turnʱK>=1 Y��������
		while (y <= y_turn)
		{
			drawpixels(drawpixelfunc, x, y);
			y++;
			x = B*asin(y / A);
		}
		//y>y_turnʱK<1 X��������
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
	//�ұ�
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
	//���
	do
	{
		drawpixelfunc(_x0 - x - 4 * i*cyclexexceptfour, _y0 + y);
		drawpixelfunc(_x0 - 2 * cyclexexceptfour + x - 4 * i*cyclexexceptfour, _y0 + y);
		drawpixelfunc(_x0 - 2 * cyclexexceptfour - x - 4 * i*cyclexexceptfour, _y0 - y);
		drawpixelfunc(_x0 - 4 * cyclexexceptfour + x - 4 * i*cyclexexceptfour, _y0 - y);
		i++;
	} while (_x0 - x - 4 * i*cyclexexceptfour >= 0);

}