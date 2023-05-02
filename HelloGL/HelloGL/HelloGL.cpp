#include "HelloGL.h"

HelloGL::HelloGL(int argc, char* argv[])
{
	InitGL(argc, argv);
	InitObjects();
	InitLighting();
	glutMainLoop();
}

HelloGL::~HelloGL(void)
{
	delete camera;
}

void HelloGL::InitObjects()
{
	rotation = 0.0f;
	
	Mesh* cubeMesh = MeshLoader::Load((char*)"cube.txt");
	Texture2D* texture = new Texture2D();
	texture->Load((char*)"penguins.raw", 512, 512);
	camera = new Camera();
	camera->eye.x = 0.0f; camera->eye.y = 0.0f; camera->eye.z = -35.0f;
	camera->center.x = 0.0f; camera->center.y = 0.0f; camera->center.z = 0.0f;
	camera->up.x = 0.0f; camera->up.y = 1.0f; camera->up.z = 0.0f;
	//cube = new Cube(cubeMesh, 0.0f, 0.0f, 0.0f);
	for (int i = 0; i < 200; i++)
	{
		objects[i] = new Cube(cubeMesh, texture, ((rand() % 400) / 10.0f) - 20.0f, ((rand() % 200) / 10.0f) - 10.0f, -(rand() % 1000) / 10.0f);
	}
}

void HelloGL::InitGL(int argc, char* argv[])
{
	GLUTCallbacks::Init(this);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
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
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glCullFace(GL_BACK);
}

void HelloGL::InitLighting()
{
	_lightPosition = new Vector4();
	_lightPosition->x = 0.0;
	_lightPosition->y = 0.0;
	_lightPosition->z = 1.0;
	_lightPosition->w = 0.0;

	_lightData = new Lighting();
	_lightData->Ambient.x = 0.2;
	_lightData->Ambient.y = 0.2;
	_lightData->Ambient.z = 0.2;
	_lightData->Ambient.w = 1.0;
	_lightData->Diffuse.x = 1.0;
	_lightData->Diffuse.y = 1.0;
	_lightData->Diffuse.z = 1.0;
	_lightData->Diffuse.w = 1.0;
	_lightData->Specular.x = 0.2;
	_lightData->Specular.y = 0.2;
	_lightData->Specular.z = 0.2;
	_lightData->Specular.w = 1.0;
}


void HelloGL::Display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //this clears the scene

	for (int i = 0; i < 200; i++)
	{
		objects[i]->Draw();
	}

	Draw();

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

	for (int i = 0; i < 200; i++)
	{
		objects[i]->Update();
	}

	glutPostRedisplay();

	glLightfv(GL_LIGHT0, GL_POSITION, &(_lightPosition->x));
	glLightfv(GL_LIGHT0, GL_POSITION, &(_lightPosition->y));
	glLightfv(GL_LIGHT0, GL_POSITION, &(_lightPosition->z));

	glLightfv(GL_LIGHT0, GL_AMBIENT, &(_lightData->Ambient.x));
	glLightfv(GL_LIGHT0, GL_AMBIENT, &(_lightData->Ambient.y));
	glLightfv(GL_LIGHT0, GL_AMBIENT, &(_lightData->Ambient.z));
	glLightfv(GL_LIGHT0, GL_AMBIENT, &(_lightData->Ambient.w));
	glLightfv(GL_LIGHT0, GL_DIFFUSE, &(_lightData->Diffuse.x));
	glLightfv(GL_LIGHT0, GL_DIFFUSE, &(_lightData->Diffuse.y));
	glLightfv(GL_LIGHT0, GL_DIFFUSE, &(_lightData->Diffuse.z));
	glLightfv(GL_LIGHT0, GL_DIFFUSE, &(_lightData->Diffuse.w));
	glLightfv(GL_LIGHT0, GL_SPECULAR, &(_lightData->Specular.x));
	glLightfv(GL_LIGHT0, GL_SPECULAR, &(_lightData->Specular.y));
	glLightfv(GL_LIGHT0, GL_SPECULAR, &(_lightData->Specular.z));
	glLightfv(GL_LIGHT0, GL_SPECULAR, &(_lightData->Specular.w));
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
		camera->eye.z += 1.0f;

	if (key == 's')
		camera->eye.z -= 1.0f;
}

void HelloGL::Draw()
{
	Vector3 v = { -1.4f, 0.7f, -1.0f };
	Color c = { 255.0f, 255.0f, 255.0f };
	DrawString("OpenGL FOGGs Project", &v, &c);
}

void HelloGL::DrawString(const char* text, Vector3* position, Color* color)
{
	glDisable(GL_LIGHTING);
	glPushMatrix();
		glColor3f(color->r, color->g, color->b);
		glTranslatef(position->x, position->y, position->z);
		glRasterPos2f(0.0f, 0.0f);
		glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, (unsigned char*)text);
	glPopMatrix();
	glEnable(GL_LIGHTING);
}
