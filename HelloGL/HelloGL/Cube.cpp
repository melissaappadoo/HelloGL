#include "Cube.h"

Vertex* Cube::indexedVertices = nullptr;

Color* Cube::indexedColors = nullptr;

GLushort* Cube::indices = nullptr;

Cube::Cube(float x, float y, float z)
{
	_position.x = x;
	_position.y = y;
	_position.z = z;
	//_rotation = 0;
}

Cube::~Cube()
{
}

void Cube::Draw()
{
	glPushMatrix();

	glBegin(GL_TRIANGLES);
	for (int i = 0; i < 36; i++)
	{
		glColor3fv(&indexedColors[indices[i]].r);
		glVertex3fv(&indexedVertices[indices[i]].x);
	}
	glRotatef(_rotation, 1.0f, 0.0f, 0.0f);
	glEnd();
	glPopMatrix();

	//glTranslatef(_position.x, _position.y, _position.z);
}

void Cube::Update()
{
	_rotation += 0.5f;
}
