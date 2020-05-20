#include "globalinclude.h"
#include <tchar.h> 
#include "Chapter6/drawSinx.h"
#include "Chapter6/drawBresenHamLine.h"
#include "Chapter6/drawCircleMidPoint.h"
#pragma warning(disable:4996)

HDC hdc = NULL;

void drawpixel(int x, int y){
	//HDC hdc = GetWindowDC(GetDesktopWindow());
	SetPixel(hdc, x, y, RGB(255, 0, 0));

}

void outputtime()
{

	time_t timep;

	time(&timep);

	char tmp[64];

	strftime(tmp, sizeof(tmp), "%Y-%m-%d %H:%M:%S", localtime(&timep));

	
	std::cout << tmp << std::endl;
	
}

//消息处理函数
LRESULT CALLBACK WndProc(HWND hWnd, UINT msgId, WPARAM wParam, LPARAM IParam)
{	
	switch (msgId)	
	{		
	case WM_CLOSE:	
	case WM_DESTROY:
	{		
		//当用户关闭窗口，窗口销毁，程序需结束，发退出消息，以退出消息循环	
		PostQuitMessage(0);		
	}		
		break;
	default:	
		//其他消息交给由系统提供的缺省处理函数	
		return DefWindowProc(hWnd, msgId, wParam, IParam);
	}	return 0;
} 
//应用程序主函数
//CALLBACK等价于 __stdcall 标准调用
int CALLBACK WinMain(HINSTANCE hInstance, 
	//应用程序实例的句柄	
	HINSTANCE hPrevInstance,  
	//前一个实例的句柄谁创建了或调用了exe
	LPSTR lpCmdLine,   
	//命令行参数
	int nShowCmd)  
	//窗口显示隐藏的命令
{			
	//1 定制"窗口类"结构	
	WNDCLASS wndclass;
	memset(&wndclass, 0, sizeof(wndclass)); 	
	//wndclass.cbSize  = sizeof(wndclass);	
	wndclass.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC | CS_DBLCLKS;	
	wndclass.lpfnWndProc = WndProc;//关联消息处理函数,告诉操作系统，如果有事件发生调用这个函数  
	wndclass.cbClsExtra = 0;		
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInstance;//实例句柄	
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);//图标	
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);//光标样式	
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);//画刷		
	wndclass.lpszMenuName = NULL;		
	wndclass.lpszClassName = _T("lesson01");//窗口类的名称，操作系统根据类的名称做映射		
	//2 将这个窗体注册（告诉）到操作系统	
	RegisterClass(&wndclass);	
	//3 创建窗口			
	HWND hWnd = CreateWindowEx(	
		0          //窗口的扩展风格		
		, _T("lesson01")   //窗口类的名称，必须和上面的lpszClassName一致	
		,_T("sinx函数")    //窗口的标题	
		,WS_OVERLAPPEDWINDOW    //窗口的风格	
		,100     //屏幕位置		
		,100		
		,900     
		//宽高		
		,920		
		,0   //系统菜单
		,0   //父窗口	
		,hInstance	
		,0    //用户数据		
		);	
	//4 更新显示
	if (hWnd)	
	{		
		UpdateWindow(hWnd);	
		ShowWindow(hWnd,SW_SHOW);		
	}  	
	hdc = GetDC(hWnd);		
	outputtime();
	//画正弦函数
	drawSinx* drawsinx1 = new drawSinx(260,30,140,240,900);
	drawsinx1->Draw(drawpixel);
	drawSinx* drawsinx2 = new drawSinx(260, 130, 140, 440,900);
	drawsinx2->Draw(drawpixel);
	drawSinx* drawsinx3 = new drawSinx(80, 50, 140, 640, 900);
	drawsinx3->Draw(drawpixel);
	delete drawsinx1;
	delete drawsinx2;
	drawsinx1 = NULL;
	drawsinx2 = NULL;
	outputtime();
	//画BresenHam直线
	//drawBresenHamLine* drawbresenham = new drawBresenHamLine();
	////dy==0
	//drawbresenham->Draw(drawpixel,20, 10, 300, 10);
	//drawbresenham->Draw(drawpixel, 300, 10, 20, 10);
	////dx==0
	//drawbresenham->Draw(drawpixel, 20, 10, 20, 300);
	//drawbresenham->Draw(drawpixel, 20, 300, 20, 10);
	////m<1
	//drawbresenham->Draw(drawpixel, 20, 10, 300, 40);
	//drawbresenham->Draw(drawpixel, 300, 40, 20, 10);
	//drawbresenham->Draw(drawpixel, 20, 40, 300, 10);
	//drawbresenham->Draw(drawpixel, 300, 10, 20, 40);
	////m>1
	//drawbresenham->Draw(drawpixel, 20, 10, 300, 600);
	//drawbresenham->Draw(drawpixel, 300, 600, 20, 10);
	//drawbresenham->Draw(drawpixel, 20, 600, 300, 10);
	//drawbresenham->Draw(drawpixel, 300, 10, 20, 600);
	//中点画圆
	//drawCircleMidPoint* drawcirclemidpoint = new drawCircleMidPoint();
	//drawcirclemidpoint->Draw(drawpixel, 450, 400, 300);
	MSG msg = { 0 }; 	
	//消息循环	
	while (WM_QUIT != msg.message)		
	{			
		//如果没有消息，这里会阻塞	
		//返回值为false，就是点了关闭按钮	
		//第一个参数用来接收message结构的，第二个参数是 窗口	
		//第三个和第四个是要过滤消息的范围，都为0 就是接收所有的消息，不为0就是接收范围内的消息		
		if (GetMessage(&msg, 0, 0, 0))		
		{			
			TranslateMessage(&msg);	
			DispatchMessage(&msg);
		}		
	}		
	return 0;
}
