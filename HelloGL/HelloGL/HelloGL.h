#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"
#include "GLUTCallbacks.h"
#include "MeshLoader.h"
#include "Cube.h"

#define REFRESHRATE 16

//class MeshLoader;
class HelloGL
{
private:
	float rotation;
	Camera* camera;
	Cube* cube;
	//MeshLoader::Load();
	

public:

	//constructor definition
	HelloGL(int argc, char* argv[]);

	//destructor
	~HelloGL(void);

	void InitObjects();
	void InitGL(int argc, char* argv[]);

	void Display();

	void Update();

	void Timer(int preferredRefresh);

	void Keyboard(unsigned char key, int x, int y);
};