#include <windows.h> 
#include <wingdi.h> 
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>
#include "TestGGlut.h"

TestGGlut t = TestGGlut();
void display(void) {
	/* стираем */
	//glClear(GL_COLOR_BUFFER_BIT);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	/* рисуем белый прямоугольник
	* (0.25, 0.25, 0.0) and (0.75, 0.75, 0.0)
	*/
	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_POINTS);
	for(int y = 0, n = 0; y < t.sz; y++) {
		for(int x = 0; x < t.sz; x++, n++) {
			if(t.v[n])
				glVertex2f(x + 0.5, y + 0.5);
			//glVertex2f(25, 25);
			//glVertex3f(75, 25, 0);
			//glVertex3f(75, 75, 0);
			//glVertex3f(25, 75, 0);
		}
	}
	glEnd();
	/* поехали ! */
	glFlush();
} // /////////////////////////////////////////////////////////////////////////////////////////
void init(void) {
	/* установим черный фон */
	glClearColor(0.0, 0.0, 70.0, 0.0);

	/* инициализация viewing values */
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, t.sz + 1., 0.0, t.sz + 1., -1.0, 1.0);
} // ///////////////////////////////////////////////////////////////////////////////////////////////
/*
Определим параметры окна , display mode
* (single buffer and RGBA). Откроем окно с фразой "hello"
* в title bar.
*/
void fnc() {
	t.Rand();
	//glutPostRedisplay();
} // ///////////////////////////////////////////////////////////////////////////////////////
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(250, 250);
	glutInitWindowPosition(700, 500);
	glutCreateWindow("hello");
	init();
	glutIdleFunc(fnc);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0; /* ISO C requires main to return int. */
} // ///////////////////////////////////////////////////////////////////////////////////////
void reshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 0, (GLdouble)w, (GLdouble)h);
} // ///////////////////////////////////////////////////////////////////////////////////////
