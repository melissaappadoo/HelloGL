#pragma once

#include "SceneObject.h"

class Cube : public SceneObject
{
private:

	GLfloat _rotation;
	Vector3 _position;

public:
	Cube(Mesh* mesh, Texture2D* texture, float x, float y, float z);
	~Cube();

	void Draw();
	void Update();
};

