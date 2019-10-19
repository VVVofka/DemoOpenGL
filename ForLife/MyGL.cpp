#include "MyGL.h"
#pragma warning(push)
#pragma warning(disable:26495) 

MyGL::MyGL() {}
MyGL::~MyGL() {}
// /////////////////////////////////////////////////////////////////////////
GLvoid MyGL::initializeGL(GLsizei width, GLsizei height) {
	GLfloat     maxObjectSize, aspect;
	GLdouble    near_plane, far_plane;

	glClearIndex((GLfloat)BLACK_INDEX);
	glClearDepth(1.0);

	glEnable(GL_DEPTH_TEST);

	glMatrixMode(GL_PROJECTION);
	aspect = (GLfloat)width / height;
	gluPerspective(45.0, aspect, 3.0, 7.0);
	glMatrixMode(GL_MODELVIEW);

	near_plane = 3.0;
	far_plane = 7.0;
	maxObjectSize = 3.0F;
	radius = near_plane + maxObjectSize / 2.0;

	latitude = 0.0F;
	longitude = 0.0F;
	latinc = 6.0F;
	longinc = 2.5F;

	createObjects();
} // ////////////////////////////////////////////////////////////////////////
GLvoid MyGL::createObjects() {
	GLUquadricObj* quadObj;

	glNewList(GLOBE, GL_COMPILE);
	quadObj = gluNewQuadric();
	gluQuadricDrawStyle(quadObj, GLU_LINE);
	gluSphere(quadObj, 1.5, 16, 16);
	glEndList();

	glNewList(CONE, GL_COMPILE);
	quadObj = gluNewQuadric();
	gluQuadricDrawStyle(quadObj, GLU_FILL);
	gluQuadricNormals(quadObj, GLU_SMOOTH);
	gluCylinder(quadObj, 0.3, 0.0, 0.6, 15, 10);
	glEndList();

	glNewList(CYLINDER, GL_COMPILE);
	glPushMatrix();
	glRotatef((GLfloat)90.0, (GLfloat)1.0, (GLfloat)0.0, (GLfloat)0.0);
	glTranslatef((GLfloat)0.0, (GLfloat)0.0, (GLfloat)-1.0);
	quadObj = gluNewQuadric();
	gluQuadricDrawStyle(quadObj, GLU_FILL);
	gluQuadricNormals(quadObj, GLU_SMOOTH);
	gluCylinder(quadObj, 0.3, 0.3, 0.6, 12, 2);
	glPopMatrix();
	glEndList();
} // //////////////////////////////////////////////////////////////////////////////
GLvoid MyGL::drawScene(GLvoid) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();

	latitude += latinc;
	longitude += longinc;

	polarView(radius, 0, latitude, longitude);

	glIndexi(RED_INDEX);
	glCallList(CONE);

	glIndexi(BLUE_INDEX);
	glCallList(GLOBE);

	glIndexi(GREEN_INDEX);
	glPushMatrix();
	glTranslatef(0.8F, -0.65F, 0.0F);
	glRotatef(30.0F, 1.0F, 0.5F, 1.0F);
	glCallList(CYLINDER);
	glPopMatrix();

	glPopMatrix();

	SwapBuf();
} // ///////////////////////////////////////////////////////////////////////
void MyGL::polarView(GLdouble radius, GLdouble twist, GLdouble latitude, GLdouble longitude) {
	glTranslated(0.0, 0.0, -radius);
	glRotated(-twist, 0.0, 0.0, 1.0);
	glRotated(-latitude, 1.0, 0.0, 0.0);
	glRotated(longitude, 0.0, 0.0, 1.0);

} // //////////////////////////////////////////////////////////////////////
GLvoid MyGL::resize(GLsizei width, GLsizei height) {
	GLfloat aspect;

	glViewport(0, 0, width, height);

	aspect = (GLfloat)width / height;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, aspect, 3.0, 7.0);
	glMatrixMode(GL_MODELVIEW);
} // ///////////////////////////////////////////////////////////////////////////
GLvoid MyGL::SetBkColor(COLORREF m_BkClr) {
	//====== Split the color to 3 components
	GLclampf red = GetRValue(m_BkClr) / 255.f,
		green = GetGValue(m_BkClr) / 255.f,
		blue = GetBValue(m_BkClr) / 255.f;
	//====== Set the clear (background) color
	glClearColor(red, green, blue, 0.f);

	//====== Actual background erasure
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
} // /////////////////////////////////////////////////////////////////////////////////
#pragma warning(pop)
