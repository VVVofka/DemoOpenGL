//from https://docs.microsoft.com/en-us/windows/win32/opengl/the-program-ported-to-win32
//Create new project -> Windows DeskTop Wizard -> Desktop Application (exe) & Empty project
//Project Property:
//		Advanced -> Character Set -> Use Multi Character set
//		Linker -> Input-> Additional Dependence -> add OPENGL32.LIB GLU32.LIB

#include "MainLife.h"

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

	/* make sure window was created */
	if(!ghWnd)
		return FALSE;

	/* show and update main window */
	ShowWindow(ghWnd, nCmdShow);

	UpdateWindow(ghWnd);

	/* animation loop */
	while(1) {
		/*
		 *  Process all pending messages
		 */

		while(PeekMessage(&msg, NULL, 0, 0, PM_NOREMOVE) == TRUE) {
			if(GetMessage(&msg, NULL, 0, 0)) {
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
			else {
				return TRUE;
			}
		}
		drawScene();
	}
} // ///////////////////////////////////////////////////////////////////////////////

/* main window procedure */
LONG WINAPI MainWndProc(
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
			g.initializeGL(rect.right, rect.bottom);
			break;

		case WM_PAINT:
			BeginPaint(hWnd, &ps);
			EndPaint(hWnd, &ps);
			break;

		case WM_SIZE:
			GetClientRect(hWnd, &rect);
			resize(rect.right, rect.bottom);
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
	PIXELFORMATDESCRIPTOR pfd, * ppfd;
	int pixelformat;

	ppfd = &pfd;

	ppfd->nSize = sizeof(PIXELFORMATDESCRIPTOR);
	ppfd->nVersion = 1;
	ppfd->dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL |
		PFD_DOUBLEBUFFER;
	ppfd->dwLayerMask = PFD_MAIN_PLANE;
	ppfd->iPixelType = PFD_TYPE_COLORINDEX;
	ppfd->cColorBits = 8;
	ppfd->cDepthBits = 16;
	ppfd->cAccumBits = 0;
	ppfd->cStencilBits = 0;

	pixelformat = ChoosePixelFormat(hdc, ppfd);

	if((pixelformat = ChoosePixelFormat(hdc, ppfd)) == 0) {
		MessageBox(NULL, "ChoosePixelFormat failed", "Error", MB_OK);
		return FALSE;
	}

	if(SetPixelFormat(hdc, pixelformat, ppfd) == FALSE) {
		MessageBox(NULL, "SetPixelFormat failed", "Error", MB_OK);
		return FALSE;
	}

	return TRUE;
} // ///////////////////////////////////////////////////////////////////////////////

/* OpenGL code */

GLvoid resize(GLsizei width, GLsizei height) {
	GLfloat aspect;

	glViewport(0, 0, width, height);

	aspect = (GLfloat)width / height;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, aspect, 3.0, 7.0);
	glMatrixMode(GL_MODELVIEW);
} // ///////////////////////////////////////////////////////////////////////////

void polarView(GLdouble radius, GLdouble twist, GLdouble latitude,
	GLdouble longitude) {
	glTranslated(0.0, 0.0, -radius);
	glRotated(-twist, 0.0, 0.0, 1.0);
	glRotated(-latitude, 1.0, 0.0, 0.0);
	glRotated(longitude, 0.0, 0.0, 1.0);

} // //////////////////////////////////////////////////////////////////////

GLvoid drawScene(GLvoid) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();

	g.latitude += g.latinc;
	g.longitude += g.longinc;

	polarView(g.radius, 0, g.latitude, g.longitude);

	glIndexi(g.RED_INDEX);
	glCallList(g.CONE);

	glIndexi(g.BLUE_INDEX);
	glCallList(g.GLOBE);

	glIndexi(g.GREEN_INDEX);
	glPushMatrix();
	glTranslatef(0.8F, -0.65F, 0.0F);
	glRotatef(30.0F, 1.0F, 0.5F, 1.0F);
	glCallList(g.CYLINDER);
	glPopMatrix();

	glPopMatrix();

	g.SwapBuf();
} // ///////////////////////////////////////////////////////////////////////