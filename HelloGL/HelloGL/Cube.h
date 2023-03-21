#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "Structures.h"
#include "SceneObject.h"

class Cube : public SceneObject
{
private:

	GLfloat _rotation;
	Vector3 _position;

public:
	Cube(Mesh* mesh, float x, float y, float z);
	~Cube();

	void Draw();
	void Update();
};

