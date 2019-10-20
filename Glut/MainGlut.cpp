#include <windows.h> 
#include <wingdi.h> 
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>

void display(void) {
	/* ������� */
	//glClear(GL_COLOR_BUFFER_BIT);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	/* ������ ����� �������������
	* (0.25, 0.25, 0.0) and (0.75, 0.75, 0.0)
	*/
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex3f(0.25, 0.25, 0.0);
	glVertex3f(0.75, 0.25, 0.0);
	glVertex3f(0.75, 0.75, 0.0);
	glVertex3f(0.25, 0.75, 0.0);
	glEnd();

	/* ������� ! */
	glFlush();
}

void init(void) {
	/* ��������� ������ ��� */
	glClearColor(0.0, 0.0, 0.0, 0.0);

	/* ������������� viewing values */
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

/*
��������� ��������� ���� , display mode
* (single buffer and RGBA). ������� ���� � ������ "hello"
* � title bar.
*/
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(250, 250);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("hello");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0; /* ISO C requires main to return int. */
}

void reshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 0, (GLdouble)w, (GLdouble)h);
}