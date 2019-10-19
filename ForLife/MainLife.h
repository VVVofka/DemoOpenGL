#pragma once
#include <windows.h> 
#include <wingdi.h> 
//#define RGB(r,g,b)          ((COLORREF)(((BYTE)(r)|((WORD)((BYTE)(g))<<8))|(((DWORD)(BYTE)(b))<<16)))

//#include <winbase.h> 

#include "MyGL.h"
MyGL g = MyGL();

/* Windows globals, defines, and prototypes */
CHAR szAppName[] = "Win OpenGL";
HWND  ghWnd;
HGLRC ghRC;

#define WIDTH           800 
#define HEIGHT          400 

LONG WINAPI MainWndProc(HWND, UINT, WPARAM, LPARAM);
BOOL bSetupPixelFormat(HDC);

