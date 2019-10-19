#pragma once
#include <windows.h> 
#include <wingdi.h> 
#include <GL/gl.h> 
#include <GL/glu.h> 

class MyGL {
public:
	MyGL();
	~MyGL();

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
	GLvoid drawTest(GLvoid);
	GLvoid resize(GLsizei width, GLsizei height);
	GLvoid SetBkColor(COLORREF m_BkClr);
private:
	GLvoid createObjects();
	void polarView(GLdouble radius, GLdouble twist, GLdouble latitude, GLdouble longitude);
}; // ******************************************************************************************
//2d http://www.cyberforum.ru/opengl/thread569240.html https://habr.com/ru/post/111175/
//https://www.helloworld.ru/texts/comp/games/opengl/opengl/2.htm
//https://www.rsdn.org/article/opengl/ogltutor.xml
