#pragma once
#include <windows.h> 
#include <GL/gl.h> 
#include <GL/glu.h> 
#define GLOBE    1 
#define CYLINDER 2 
#define CONE     3 

class MyGL {
public:
	MyGL();
	~MyGL();
	const int BLACK_INDEX = 0;
	const int RED_INDEX = 13;
	const int GREEN_INDEX = 14;
	const int BLUE_INDEX = 16;

	HDC   ghDC;
	void SwapBuf() {SwapBuffers(ghDC);}

	/* OpenGL globals, defines, and prototypes */
	GLfloat latitude, longitude, latinc, longinc;
	GLdouble radius;

private:

}; // ******************************************************************************************

