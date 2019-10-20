#include <windows.h> 
#include <wingdi.h> 
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>
#include "TestGlut.h"
#ifdef MAINENABL

TestGGlut t = TestGGlut();
void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
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
	glFlush();
} // /////////////////////////////////////////////////////////////////////////////////////////
void init(void) {
	glShadeModel(GL_FLAT);
	glClearColor(0.0, 0.0, 0.2, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, t.sz + 1., 0.0, t.sz + 1., -1.0, 1.0);
} // ///////////////////////////////////////////////////////////////////////////////////////////////
void fnc() {
	t.Rand();
	glutPostRedisplay();
} // ///////////////////////////////////////////////////////////////////////////////////////
void reshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 0, (GLdouble)w, (GLdouble)h);
} // ///////////////////////////////////////////////////////////////////////////////////////
void mouse(int button, int state, int x, int y) {
	switch(button) {
		case GLUT_LEFT_BUTTON:
			if(state == GLUT_DOWN) 
				glutIdleFunc(fnc); 
			break;
		case GLUT_RIGHT_BUTTON: 
			if(state == GLUT_DOWN) 
				glutIdleFunc(NULL); 
			break;
	}
} // ///////////////////////////////////////////////////////////////////////////////////////
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(250, 250);
	glutInitWindowPosition(700, 500);
	glutCreateWindow("hello");
	init();
	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	glutMainLoop();
	return 0;
} // ///////////////////////////////////////////////////////////////////////////////////////
#endif MAINENABL