#include "Include/GL/glut.h"  
#include "TestGlut.h"

#ifndef MAINENABL
TestGlut t = TestGlut();
Para inWnd;
GLint szCell=0;

void init(void) {
	glClearColor(0.0f, 0.0f, 0.3f, 0.0f);
	glShadeModel(GL_FLAT);
	t.Create(4, 1);
} // /////////////////////////////////////////////////////////////////////////////////
void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	glPointSize((GLfloat)szCell);
	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_POINTS);
	//glVertex2f(0.5, 0.5);
	//glVertex2f(1.5, 1.5);
	//glVertex2f(1.5, 0.5);
	//glVertex2f(2.5, 1.5);
	//glVertex2f(1.5, 1.5);
	//glVertex2f(2.5, 2.5);

	for(int y = 0, n = 0; y < t.sz; y++) {
		for(int x = 0; x < t.sz; x++, n++) {
			if(t[n])
				glVertex2f(x + 0.5f, y + 0.5f);
		}
	}
	glEnd();
	glPopMatrix();

	glutSwapBuffers();
	t.getVal();
} // /////////////////////////////////////////////////////////////////////////////////
void spinDisplay(void) {
	t.Transform();				// MAIN WORK !!!
	t.Rand();
	glutPostRedisplay();
} // /////////////////////////////////////////////////////////////////////////////////
void reSize(int w, int h) {
	inWnd.set(w, h);
	szCell = inWnd.Min() / t.sz - 1;
	GLfloat retv[2];
	glGetFloatv(GL_POINT_SIZE_RANGE, retv);
	if(szCell < retv[0]) szCell = (GLint)retv[0];
	if(szCell > retv[1]) szCell = (GLint)retv[1];
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
	glutReshapeFunc(reSize);
	glutMouseFunc(mouse);
	glutMainLoop();
	return 0;
} // /////////////////////////////////////////////////////////////////////////////////
#endif MAINENABL