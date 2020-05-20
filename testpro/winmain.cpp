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

//��Ϣ������
LRESULT CALLBACK WndProc(HWND hWnd, UINT msgId, WPARAM wParam, LPARAM IParam)
{	
	switch (msgId)	
	{		
	case WM_CLOSE:	
	case WM_DESTROY:
	{		
		//���û��رմ��ڣ��������٣���������������˳���Ϣ�����˳���Ϣѭ��	
		PostQuitMessage(0);		
	}		
		break;
	default:	
		//������Ϣ������ϵͳ�ṩ��ȱʡ������	
		return DefWindowProc(hWnd, msgId, wParam, IParam);
	}	return 0;
} 
//Ӧ�ó���������
//CALLBACK�ȼ��� __stdcall ��׼����
int CALLBACK WinMain(HINSTANCE hInstance, 
	//Ӧ�ó���ʵ���ľ��	
	HINSTANCE hPrevInstance,  
	//ǰһ��ʵ���ľ��˭�����˻������exe
	LPSTR lpCmdLine,   
	//�����в���
	int nShowCmd)  
	//������ʾ���ص�����
{			
	//1 ����"������"�ṹ	
	WNDCLASS wndclass;
	memset(&wndclass, 0, sizeof(wndclass)); 	
	//wndclass.cbSize  = sizeof(wndclass);	
	wndclass.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC | CS_DBLCLKS;	
	wndclass.lpfnWndProc = WndProc;//������Ϣ������,���߲���ϵͳ��������¼����������������  
	wndclass.cbClsExtra = 0;		
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInstance;//ʵ�����	
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);//ͼ��	
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);//�����ʽ	
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);//��ˢ		
	wndclass.lpszMenuName = NULL;		
	wndclass.lpszClassName = _T("lesson01");//����������ƣ�����ϵͳ�������������ӳ��		
	//2 ���������ע�ᣨ���ߣ�������ϵͳ	
	RegisterClass(&wndclass);	
	//3 ��������			
	HWND hWnd = CreateWindowEx(	
		0          //���ڵ���չ���		
		, _T("lesson01")   //����������ƣ�����������lpszClassNameһ��	
		,_T("sinx����")    //���ڵı���	
		,WS_OVERLAPPEDWINDOW    //���ڵķ��	
		,100     //��Ļλ��		
		,100		
		,900     
		//���		
		,920		
		,0   //ϵͳ�˵�
		,0   //������	
		,hInstance	
		,0    //�û�����		
		);	
	//4 ������ʾ
	if (hWnd)	
	{		
		UpdateWindow(hWnd);	
		ShowWindow(hWnd,SW_SHOW);		
	}  	
	hdc = GetDC(hWnd);		
	outputtime();
	//�����Һ���
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
	//��BresenHamֱ��
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
	//�е㻭Բ
	//drawCircleMidPoint* drawcirclemidpoint = new drawCircleMidPoint();
	//drawcirclemidpoint->Draw(drawpixel, 450, 400, 300);
	MSG msg = { 0 }; 	
	//��Ϣѭ��	
	while (WM_QUIT != msg.message)		
	{			
		//���û����Ϣ�����������	
		//����ֵΪfalse�����ǵ��˹رհ�ť	
		//��һ��������������message�ṹ�ģ��ڶ��������� ����	
		//�������͵��ĸ���Ҫ������Ϣ�ķ�Χ����Ϊ0 ���ǽ������е���Ϣ����Ϊ0���ǽ��շ�Χ�ڵ���Ϣ		
		if (GetMessage(&msg, 0, 0, 0))		
		{			
			TranslateMessage(&msg);	
			DispatchMessage(&msg);
		}		
	}		
	return 0;
}
