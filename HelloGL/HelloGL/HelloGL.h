#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"
#include "GLUTCallbacks.h"
#define REFRESHRATE 16

class HelloGL
{
private:
	float rotation;

public:

	//constructor definition
	HelloGL(int argc, char* argv[]);

	//destructor
	~HelloGL(void);

	void Display();

	void Update();

	void Timer(int preferredRefresh);

	void Keyboard(unsigned char key, int x, int y);
};