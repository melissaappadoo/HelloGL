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
	Vector4* _lightPosition;
	Lighting* _lightData;

public:

	//constructor definition
	HelloGL(int argc, char* argv[]);

	//destructor
	~HelloGL(void);

	void InitObjects();
	void InitGL(int argc, char* argv[]);
	void InitLighting();
		
	void Display();

	void Update();

	void Timer(int preferredRefresh);

	void Keyboard(unsigned char key, int x, int y);

	void Draw();

	void DrawString(const char* text, Vector3* position, Color* color);
};