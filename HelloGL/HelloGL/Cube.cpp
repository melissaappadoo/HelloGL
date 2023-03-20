#include "Cube.h"
#include <fstream>


Cube::Cube(Mesh* mesh, float x, float y, float z) : SceneObject(mesh)
{
	_position.x = x;
	_position.y = y;
	_position.z = z;
	_rotation = 0;
}

Cube::~Cube()
{
}

void Cube::Draw()
{
	if (_mesh->Vertices != nullptr && _mesh->Colors != nullptr && _mesh->Indices != nullptr)
	{
		glPushMatrix();

		glBegin(GL_TRIANGLES);
		for (int i = 0; i < 36; i++)
		{
			glColor3fv(&_mesh->Colors[_mesh->Indices[i]].r);
			glVertex3fv(&_mesh->Vertices[_mesh->Indices[i]].x);
		}
		glTranslatef(_position.x, _position.y, _position.z);
		glRotatef(_rotation, 1.0f, 0.0f, 0.0f);
		glEnd();
		glPopMatrix();
	}
}

void Cube::Update()
{
	_rotation += 0.5f;
}
