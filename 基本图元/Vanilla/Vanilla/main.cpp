#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>

#pragma  comment(lib,"opengl32.lib")
#pragma comment(lib,"glu32.lib")
LRESULT CALLBACK GLWindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_CLOSE://关闭窗口
		PostQuitMessage(0);
		break;
	}
	return DefWindowProc(hwnd, msg, wParam, lParam);
}

INT WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{

	//register class		
	WNDCLASSEX wndclass;
	wndclass.cbClsExtra = 0;
	wndclass.cbSize = sizeof(WNDCLASSEX);

	wndclass.cbWndExtra = 0; //无需为窗口准备额外存储空间
	wndclass.hbrBackground = NULL;//窗口背景无需额外东西，整个都是openGL
	wndclass.hCursor = NULL;//鼠标光标
	wndclass.hIcon = LoadCursor(NULL, IDC_ARROW);	//生成程序在文件夹中的图标
	wndclass.hIconSm = NULL;//窗口在左上角显示图标
	wndclass.hInstance = hInstance;//windows窗口传进来的实例
	wndclass.lpfnWndProc = GLWindowProc;//鼠标键盘   消息响应函数
	wndclass.lpszClassName = L"GLWindow";//唯一标识符
	wndclass.lpszMenuName = NULL;//菜单
	wndclass.style = CS_VREDRAW | CS_HREDRAW;//class style  垂直  水平
	ATOM atom = RegisterClassEx(&wndclass);//注册，会返回一个标记
	if (!atom)
	{
		return 0;
	}
	//create window
	HWND hwnd = CreateWindowEx(NULL, L"GLWindow", L"OpenGL Window", WS_OVERLAPPEDWINDOW, 100, 100, 800, 600, NULL, NULL, hInstance, NULL);
	// 1.额外窗口风格 2.之前注册的Class name 3.窗口名字 4.建立窗口风格5,创建起始位置 x.y 宽度 高度  9.父窗口，10.菜单 11.hinstance 12.其他参数
	//create opengl render context
	HDC dc = GetDC(hwnd);
	PIXELFORMATDESCRIPTOR pfd;//素格式描述符
	memset(&pfd, 0, sizeof(PIXELFORMATDESCRIPTOR));
	pfd.nVersion = 1;
	pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	pfd.cColorBits = 32;//深度缓冲区
	pfd.cDepthBits = 24;//颜色缓冲区
	pfd.cStencilBits = 8;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.iLayerType = PFD_MAIN_PLANE;
	pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;//双缓冲区。学校老师上课讲的终于用上了T-T 前台缓冲区和后台缓冲区，指针交换！

	int pixelFormat = ChoosePixelFormat(dc, &pfd);//选择一个颜色格式
	SetPixelFormat(dc, pixelFormat, &pfd);//告诉dc 选择像素格式出来，叫做pixelformat

	HGLRC rc = wglCreateContext(dc);
	wglMakeCurrent(dc, rc);//做成当前渲染设备
						   //setup opengl context complete

						   //opengl init
	glClearColor(0.1, 0.4, 0.6, 1.0);

	//show window
	ShowWindow(hwnd, SW_SHOW);
	UpdateWindow(hwnd);
	MSG msg;
	while (true)
	{
		if (PeekMessage(&msg, NULL, NULL, NULL, PM_REMOVE))//抓到消息	，从所有地方，抓所有消息，无任何过滤，从消息队列顶端移除掉
		{
			//处理消息
			if (msg.message == WM_QUIT)//判断是否是退出消息
			{
				break;
			}
			TranslateMessage(&msg);//转换消息类型
			DispatchMessage(&msg);
		}
		//draw scene	
		glClear(GL_COLOR_BUFFER_BIT);
		//present scene	
		SwapBuffers(dc);//交换缓冲区， 前后
	}
	return 0;

}