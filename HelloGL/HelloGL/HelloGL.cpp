#include "HelloGL.h"

HelloGL::HelloGL(int argc, char* argv[])
{
	rotation = 0.0f;
	camera = new Camera();
	camera->eye.x = 0.0f; camera->eye.y = 0.0f; camera->eye.z = -1.0f;
	camera->center.x = 0.0f; camera->center.y = 0.0f; camera->center.z = 0.0f;
	camera->up.x = 0.0f; camera->up.y = 1.0f; camera->up.z = 0.0f;

	GLUTCallbacks::Init(this);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Simple OpenGL Program");
	glutDisplayFunc(GLUTCallbacks::Display);
	glutTimerFunc(REFRESHRATE, GLUTCallbacks::Timer, REFRESHRATE);
	glutKeyboardFunc(GLUTCallbacks::Keyboard);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	// Set the viewport to be the entire window
	glViewport(0, 0, 800, 800);
	//Set the correct perspective
	gluPerspective(45, 1, 1, 1000);
	glMatrixMode(GL_MODELVIEW);
	glutMainLoop();
}

HelloGL::~HelloGL(void)
{
	delete camera;
}


void HelloGL::Display()
{
	glClear(GL_COLOR_BUFFER_BIT); //this clears the scene

	/*glPushMatrix();
	glTranslatef(0.0f, 0.0f, -5.0f);
	glRotatef(rotation, 0.0f, -1.0f, 0.0f);

	glBegin(GL_POLYGON); //starts to draw a polygon
	glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
	glVertex2f(-0.75, 0.5); //define the first point of the polygon, top left
	glVertex2f(0.75, 0.5);//next point, top right
	glColor4f(0.0f, 1.0f, 0.0f, 0.0f);
	glVertex2f(0.75, -0.5); //bottom right
	glVertex2f(-0.75, -0.5); //last point of the polygon, bottom left
	glEnd(); // defines the end of the draw

	glPopMatrix();*/

	glPushMatrix();
	glTranslatef(0.0f, 0.0f, 5.0f);
	glRotatef(rotation, 1.0f, 0.0f, 0.0f);
	glutWireTetrahedron();
	//glutWireTeapot(0.5f);
		
	glPopMatrix();
	glFlush(); //flushes the scene drawn to the graphics card

	glutSwapBuffers();
}

void HelloGL::Update()
{
	glLoadIdentity();
	gluLookAt(camera->eye.x, camera->eye.y, camera->eye.z, camera->center.x, camera->center.y, camera->center.z, camera->up.x, camera->up.y, camera->up.z);

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

	if (key == 'w')
		camera->eye.z -= 1.0f;
}

