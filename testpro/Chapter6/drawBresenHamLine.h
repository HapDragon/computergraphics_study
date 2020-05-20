#pragma once
#include "..\globaltypes.h"
//BresenHam»­Ïß
class drawBresenHamLine
{
public:
	drawBresenHamLine();
	~drawBresenHamLine();
	
	void Draw(DrawPixelFunc drawpixelfunc, int x0, int y0, int xEnd, int yEnd);

};

