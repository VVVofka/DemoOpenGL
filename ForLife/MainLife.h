#pragma once
#include <windows.h> 
//#include <winbase.h> 

#include "MyGL.h"
MyGL g = MyGL();

/* Windows globals, defines, and prototypes */
CHAR szAppName[] = "Win OpenGL";
HWND  ghWnd;
HGLRC ghRC;

#define WIDTH           300 
#define HEIGHT          200 

LONG WINAPI MainWndProc(HWND, UINT, WPARAM, LPARAM);
BOOL bSetupPixelFormat(HDC);

