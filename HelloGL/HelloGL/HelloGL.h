#pragma once
#include "GLUTCallbacks.h"
#include "Cube.h"

#define REFRESHRATE 16

//class MeshLoader;
class HelloGL
{
private:
	float rotation;
	Camera* camera;
	//Cube* cube;
	SceneObject* objects[1000];
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