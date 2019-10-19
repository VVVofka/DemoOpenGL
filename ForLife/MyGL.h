#pragma once
#include <windows.h> 
#include <GL/gl.h> 
#include <GL/glu.h> 

class MyGL {
public:
	MyGL();
	~MyGL();
	const int BLACK_INDEX = 0;
	const int RED_INDEX = 13;
	const int GREEN_INDEX = 14;
	const int BLUE_INDEX = 16;

	const int GLOBE = 1;
	const int CYLINDER = 2;
	const int CONE = 3;

	HDC   ghDC = NULL;
	void SwapBuf() { SwapBuffers(ghDC); }

	/* OpenGL globals, defines, and prototypes */
	GLfloat latitude, longitude, latinc, longinc;
	GLdouble radius;

	GLvoid initializeGL(GLsizei width, GLsizei height);
	GLvoid drawScene(GLvoid);
	GLvoid resize(GLsizei width, GLsizei height);
private:
	GLvoid createObjects();
	void polarView(GLdouble radius, GLdouble twist, GLdouble latitude, GLdouble longitude);
}; // ******************************************************************************************

