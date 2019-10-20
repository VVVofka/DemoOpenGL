#include <GL/glut.h>  
#include "TestGGlut.h"

#ifndef MAINENABL
TestGGlut t = TestGGlut();
Para inWnd;
GLint szCell=0;

GLfloat spin = 0.0;
void init(void) {
	glClearColor(0.0, 0.0, 0.1, 0.0);
	glShadeModel(GL_FLAT);
} // /////////////////////////////////////////////////////////////////////////////////
void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	glColor3f(1.0, 1.0, 0.0);
	glPointSize(szCell);
	glBegin(GL_POINTS);
	//glVertex2f(0.5, 0.5);
	//glVertex2f(1.5, 1.5);
	//glVertex2f(1.5, 0.5);
	//glVertex2f(2.5, 1.5);
	//glVertex2f(1.5, 1.5);
	//glVertex2f(2.5, 2.5);

	for(int y = 0, n = 0; y < t.sz; y++) {
		for(int x = 0; x < t.sz; x++, n++) {
			if(t.v[n])
				glVertex2f(x + 0.5, y + 0.5);
		}
	}
	glEnd();
	glPopMatrix();

	glutSwapBuffers();
} // /////////////////////////////////////////////////////////////////////////////////
void spinDisplay(void) {
	t.Rand();
	GLfloat sum = 0;
	for(int n = 0; n < 9; n++)
		sum += t.v[n];
	spin = spin + sum;
	if(spin > 360.0) spin = spin - 360.0;
	glutPostRedisplay();
} // /////////////////////////////////////////////////////////////////////////////////
void reshape(int w, int h) {
	inWnd.set(w, h);
	int min = w > h ? h : w;
	szCell = min / t.sz - 1;
	if(szCell < 1) szCell = 1;
	//glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	if(w > h)
		glViewport((GLsizei)((w - h) / 2), 0, (GLsizei)h, (GLsizei)h);
	else
		glViewport(0, (GLsizei)((h - w) / 2), (GLsizei)w, (GLsizei)w);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, t.sz, 0.0, t.sz);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
} // /////////////////////////////////////////////////////////////////////////////////
//При нажатии левой кнопки зарегистрировать 
//функцию фоновой обработки (поворота) 
//При нажатии правой – отменить регистрацию 
void mouse(int button, int state, int x, int y) {
	switch(button) {
		case GLUT_LEFT_BUTTON:
			if(state == GLUT_DOWN) glutIdleFunc(spinDisplay); break;
		case GLUT_RIGHT_BUTTON: if(state == GLUT_DOWN) glutIdleFunc(NULL); break;
	}
} // /////////////////////////////////////////////////////////////////////////////////
//Запросить режим двойной буферизации 
//Зарегистрировать функции обработки мышиного ввода 
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(inWnd.x = 512, inWnd.y = 512);
	glutInitWindowPosition(400, 300);
	glutCreateWindow("Двойная буферизация");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMouseFunc(mouse);
	glutMainLoop();
	return 0;
} // /////////////////////////////////////////////////////////////////////////////////
#endif MAINENABL