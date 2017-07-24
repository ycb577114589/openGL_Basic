#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>

#pragma  comment(lib,"opengl32.lib")
#pragma comment(lib,"glu32.lib")
LRESULT CALLBACK GLWindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_CLOSE://�رմ���
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

	wndclass.cbWndExtra = 0; //����Ϊ����׼������洢�ռ�
	wndclass.hbrBackground = NULL;//���ڱ���������ⶫ������������openGL
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);;//�����
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);	//���ɳ������ļ����е�ͼ��
	wndclass.hIconSm = NULL;//���������Ͻ���ʾͼ��
	wndclass.hInstance = hInstance;//windows���ڴ�������ʵ��
	wndclass.lpfnWndProc = GLWindowProc;//������   ��Ϣ��Ӧ����
	wndclass.lpszClassName = L"GLWindow";//Ψһ��ʶ��
	wndclass.lpszMenuName = NULL;//�˵�
	wndclass.style = CS_VREDRAW | CS_HREDRAW;//class style  ��ֱ  ˮƽ
	ATOM atom = RegisterClassEx(&wndclass);//ע�ᣬ�᷵��һ�����
	if (!atom)
	{
		return 0;
	}
	//create window
	HWND hwnd = CreateWindowEx(NULL, L"GLWindow", L"OpenGL Window", WS_OVERLAPPEDWINDOW, 100, 100, 800, 600, NULL, NULL, hInstance, NULL);
	// 1.���ⴰ�ڷ�� 2.֮ǰע���Class name 3.�������� 4.�������ڷ��5,������ʼλ�� x.y ��� �߶�  9.�����ڣ�10.�˵� 11.hinstance 12.��������
	//create opengl render context
	HDC dc = GetDC(hwnd);
	PIXELFORMATDESCRIPTOR pfd;//�ظ�ʽ������
	memset(&pfd, 0, sizeof(PIXELFORMATDESCRIPTOR));
	pfd.nVersion = 1;
	pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	pfd.cColorBits = 32;//��Ȼ�����
	pfd.cDepthBits = 24;//��ɫ������
	pfd.cStencilBits = 8;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.iLayerType = PFD_MAIN_PLANE;
	pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;//˫��������ѧУ��ʦ�Ͽν�������������T-T ǰ̨�������ͺ�̨��������ָ�뽻����

	int pixelFormat = ChoosePixelFormat(dc, &pfd);//ѡ��һ����ɫ��ʽ
	SetPixelFormat(dc, pixelFormat, &pfd);//����dc ѡ�����ظ�ʽ����������pixelformat

	HGLRC rc = wglCreateContext(dc);
	wglMakeCurrent(dc, rc);//���ɵ�ǰ��Ⱦ�豸
						   //setup opengl context complete

	//opengl init

	glMatrixMode(GL_PROJECTION);//tell the gpu processer that i would select the project		
	gluPerspective(50.0f, 800.0f / 600.0f, 0.1f, 1000.0f);//set some values to projections
	glMatrixMode(GL_MODELVIEW);//tell  .. model view matrix
	glLoadIdentity();//��������λ����

	
	glClearColor(0.1f, 0.4f, 0.6f, 1.0f);


	//show window
	ShowWindow(hwnd, SW_SHOW);
	UpdateWindow(hwnd);
	//�߿�ģʽ��������ͼ�ζ���
	glEnable(GL_CULL_FACE); 
	//init light

	float blackColor[] = { 0.0f,0.0f,0.0f,1.0f };
	float whiteColor[] = { 1.0f,1.0f,1.0f,1.0f };
	float lightPos[] = { 0.0f,1.0f,0.0f,0.0f };		//���÷����
	glLightfv(GL_LIGHT0, GL_AMBIENT, whiteColor);	//������
	glLightfv(GL_LIGHT0, GL_DIFFUSE, whiteColor);	//�������
	glLightfv(GL_LIGHT0, GL_SPECULAR, whiteColor);	//���淴���
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);	//���ù�Դ

	float	blackMat[]= { 0.0f,0.0f,0.0f,1.0f };
	float ambientMat[] = { 0.1f,0.1f,0.1f,1.0f };
	float diffuseMat[] = { 0.4f,0.4f,0.4f,1.0f };
	float specularMat[] = { 0.9f,0.9f,0.9f,1.0f };
	glMaterialfv(GL_FRONT, GL_AMBIENT, ambientMat);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuseMat);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specularMat);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	

	//Ĭ��Ϊ glpolygonMode(GL_FRONT, GL_FULL); ���ģʽ
	MSG msg;
	while (true)
	{
		if (PeekMessage(&msg, NULL, NULL, NULL, PM_REMOVE))//ץ����Ϣ	�������еط���ץ������Ϣ�����κι��ˣ�����Ϣ���ж����Ƴ���
		{
			//������Ϣ
			if (msg.message == WM_QUIT)//�ж��Ƿ����˳���Ϣ
			{
				break;
			}
			TranslateMessage(&msg);//ת����Ϣ����
			DispatchMessage(&msg);
		}
		//draw scene	
		glLoadIdentity(); 
		glClear(GL_COLOR_BUFFER_BIT);
		glBegin(GL_TRIANGLES);//start to draw something
 // 
		glNormal3f(0.0f, -1.0f, 0.0f);
		glVertex3f(-1.0f, -1.0f, -5.0f);

		glNormal3f(0.0f, -1.0f, 0.0f);
		glVertex3f(1.0, -1.0f, -5.0f);

		glNormal3f(0.0f, 1.0f, 0.0f);
		glVertex3f(0.0f, -1.0f, -10.0f);
		 
		 
		glEnd(); //end



				 //present scene	
		SwapBuffers(dc);//������������ ǰ��
	}
	return 0;

}
