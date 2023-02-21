#include "HelloGL.h"

HelloGL::HelloGL(int argc, char* argv[])
{
	rotation = 0.0f;

	GLUTCallbacks::Init(this);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Simple OpenGL Program");
	glutDisplayFunc(GLUTCallbacks::Display);
	glutTimerFunc(REFRESHRATE, GLUTCallbacks::Timer, REFRESHRATE);
	glutKeyboardFunc(GLUTCallbacks::Keyboard);
	glutMainLoop();
}

HelloGL::~HelloGL(void)
{
}


void HelloGL::Display()
{
	glClear(GL_COLOR_BUFFER_BIT); //this clears the scene

	glPushMatrix();
	glRotatef(rotation, 0.0f, -1.0f, 0.0f);

	glBegin(GL_POLYGON); //starts to draw a polygon
	glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
	glVertex2f(-0.75, 0.5); //define the first point of the polygon, top left
	glVertex2f(0.75, 0.5);//next point, top right
	glColor4f(0.0f, 1.0f, 0.0f, 0.0f);
	glVertex2f(0.75, -0.5); //bottom right
	glVertex2f(-0.75, -0.5); //last point of the polygon, bottom left
	glEnd(); // defines the end of the draw

	glPopMatrix();

	glPushMatrix();
	glRotatef(rotation, 0.0f, 0.0f, -1.0f);

	glBegin(GL_POLYGON); //starts to draw a polygon
	glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
	//glVertex2f(-0.75, 0.5); //define the first point of the polygon, top left
	glVertex2f(0.0, 0.5); //next point, top right
	glColor4f(0.0f, 1.0f, 0.0f, 0.0f);
	glVertex2f(0.75, -0.5); //bottom right
	glColor4f(0.0f, 0.0f, 1.0f, 1.0f);
	glVertex2f(-0.75, -0.5); //last point of the polygon, bottom left
	glEnd(); // defines the end of the draw

	glPopMatrix();
		
	glFlush(); //flushes the scene drawn to the graphics card

	glutSwapBuffers();
}

void HelloGL::Update()
{
	rotation += 0.5f;

	if (rotation >= 360.0f)
		rotation = 0.0f;

	glutPostRedisplay();
}

void HelloGL::Timer(int preferredRefresh)
{
}

void HelloGL::Keyboard(unsigned char key, int x, int y)
{
	if (key == 'd')
		rotation += 1;

	if (key == 'a')
		rotation -= 2;
}

