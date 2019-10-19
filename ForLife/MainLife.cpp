//from https://docs.microsoft.com/en-us/windows/win32/opengl/the-program-ported-to-win32
//Create new project -> Windows DeskTop Wizard -> Desktop Application (exe) & Empty project
//Project Property:
//		Advanced -> Character Set -> Use Multi Character set
//		Linker -> Input-> Additional Dependence -> add OPENGL32.LIB GLU32.LIB
#include "MainLife.h"
 // *********************************************************************************************
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow) {
	MSG        msg;
	WNDCLASS   wndclass;

	/* Register the frame class */
	wndclass.style = 0;
	wndclass.lpfnWndProc = (WNDPROC)MainWndProc;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(hInstance, szAppName);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wndclass.lpszMenuName = szAppName;
	wndclass.lpszClassName = szAppName;

	if(!RegisterClass(&wndclass))
		return FALSE;

	/* Create the frame */
	ghWnd = CreateWindow(szAppName,
		"Generic OpenGL Sample",
		WS_OVERLAPPEDWINDOW | WS_CLIPSIBLINGS | WS_CLIPCHILDREN,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		WIDTH,
		HEIGHT,
		NULL,
		NULL,
		hInstance,
		NULL);

	if(!ghWnd)	//	make sure window was created 
		return FALSE;
	ShowWindow(ghWnd, nCmdShow);	//  show and update main window 
	UpdateWindow(ghWnd);
	g.SetBkColor(RGB(0, 0, 95));
	while(1) {	//	 animation loop 
		 // Process all pending messages
		while(PeekMessage(&msg, NULL, 0, 0, PM_NOREMOVE) == TRUE) {
			if(GetMessage(&msg, NULL, 0, 0)) {
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
			else 
				return TRUE;
		}
		g.drawScene();		// DRAWSCENE !!!
	}
} // ///////////////////////////////////////////////////////////////////////////////
LONG WINAPI MainWndProc(	//	 main window procedure
	HWND    hWnd,
	UINT    uMsg,
	WPARAM  wParam,
	LPARAM  lParam) {
	LONG    lRet = 1;
	PAINTSTRUCT    ps;
	RECT rect;
	switch(uMsg) {
		case WM_CREATE:
			g.ghDC = GetDC(hWnd);
			if(!bSetupPixelFormat(g.ghDC))
				PostQuitMessage(0);
			ghRC = wglCreateContext(g.ghDC);
			wglMakeCurrent(g.ghDC, ghRC);
			GetClientRect(hWnd, &rect);
			g.initializeGL(rect.right, rect.bottom);	// INITIALIZE
			break;
		case WM_PAINT:
			BeginPaint(hWnd, &ps);
			EndPaint(hWnd, &ps);
			break;
		case WM_SIZE:
			GetClientRect(hWnd, &rect);
			g.resize(rect.right, rect.bottom);
			break;
		case WM_CLOSE:
			if(ghRC)
				wglDeleteContext(ghRC);
			if(g.ghDC)
				ReleaseDC(hWnd, g.ghDC);
			ghRC = 0;
			g.ghDC = 0;
			DestroyWindow(hWnd);
			break;
		case WM_DESTROY:
			if(ghRC)
				wglDeleteContext(ghRC);
			if(g.ghDC)
				ReleaseDC(hWnd, g.ghDC);

			PostQuitMessage(0);
			break;
		case WM_KEYDOWN:
			switch(wParam) {
				case VK_LEFT:
					g.longinc += 0.5F;
					break;
				case VK_RIGHT:
					g.longinc -= 0.5F;
					break;
				case VK_UP:
					g.latinc += 0.5F;
					break;
				case VK_DOWN:
					g.latinc -= 0.5F;
					break;
			}
		default:
			lRet = DefWindowProc(hWnd, uMsg, wParam, lParam);
			break;
	}
	return lRet;
} // ///////////////////////////////////////////////////////////////////////////////
BOOL bSetupPixelFormat(HDC hdc) {
	PIXELFORMATDESCRIPTOR pfd;
	pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	pfd.nVersion = 1;
	pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
	pfd.dwLayerMask = PFD_MAIN_PLANE;
	pfd.iPixelType = PFD_TYPE_COLORINDEX;
	pfd.cColorBits = 8;
	pfd.cDepthBits = 16;
	pfd.cAccumBits = 0;
	pfd.cStencilBits = 0;

	int pixelformat = ChoosePixelFormat(hdc, &pfd);
	if(pixelformat == 0) {
		MessageBox(NULL, "ChoosePixelFormat failed", "Error", MB_OK);
		return FALSE;
	}
	if(SetPixelFormat(hdc, pixelformat, &pfd) == FALSE) {
		MessageBox(NULL, "SetPixelFormat failed", "Error", MB_OK);
		return FALSE;
	}
	return TRUE;
} // ///////////////////////////////////////////////////////////////////////////////



