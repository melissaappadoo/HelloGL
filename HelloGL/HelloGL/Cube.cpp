#include "Cube.h"
#include <fstream>


Cube::Cube(Mesh* mesh, Texture2D* texture, float x, float y, float z) : SceneObject(mesh, texture)
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
	if (_mesh->Vertices != nullptr && _mesh->Normals != nullptr && _mesh->Indices != nullptr)
	{
		glBindTexture(GL_TEXTURE_2D, _texture->GetID());
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		
		glEnableClientState(GL_VERTEX_ARRAY);
		//glEnableClientState(GL_COLOR_ARRAY);
		glEnable(GL_NORMAL_ARRAY);
		glVertexPointer(3, GL_FLOAT, 0, _mesh->Vertices);
		//glColorPointer(3, GL_FLOAT, 0, _mesh->Normals);
		glNormalPointer(GL_FLOAT, 0, _mesh->Normals);
		glTexCoordPointer(2, GL_FLOAT, 0, _mesh->TexCoords);
		glPushMatrix();
			InitMaterials();
			glMaterialfv(GL_FRONT, GL_AMBIENT, &(_material->Ambient.x));
			glMaterialfv(GL_FRONT, GL_AMBIENT, &(_material->Ambient.y));
			glMaterialfv(GL_FRONT, GL_AMBIENT, &(_material->Ambient.z));
			glMaterialfv(GL_FRONT, GL_AMBIENT, &(_material->Ambient.w));
			glMaterialfv(GL_FRONT, GL_DIFFUSE, &(_material->Diffuse.x));
			glMaterialfv(GL_FRONT, GL_DIFFUSE, &(_material->Diffuse.y));
			glMaterialfv(GL_FRONT, GL_DIFFUSE, &(_material->Diffuse.z));
			glMaterialfv(GL_FRONT, GL_DIFFUSE, &(_material->Diffuse.w));
			glMaterialfv(GL_FRONT, GL_SPECULAR, &(_material->Specular.x));
			glMaterialfv(GL_FRONT, GL_SPECULAR, &(_material->Specular.y));
			glMaterialfv(GL_FRONT, GL_SPECULAR, &(_material->Specular.z));
			glMaterialfv(GL_FRONT, GL_SPECULAR, &(_material->Specular.w));
			glMaterialfv(GL_FRONT, GL_SHININESS, &(_material->Shininess));
			glTranslatef(_position.x, _position.y, _position.z);
			glRotatef(_rotation, 1.0f, 0.0f, 0.0f);
			glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_SHORT, _mesh->Indices);
		glPopMatrix();

		//glDisableClientState(GL_COLOR_ARRAY);
		glDisableClientState(GL_NORMAL_ARRAY);
		glDisableClientState(GL_VERTEX_ARRAY);
		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	}
}

void Cube::InitMaterials()
{
	_material = new Material();
	_material->Ambient.x = 0.8; _material->Ambient.y = 0.05; _material->Ambient.z = 0.05;
	_material->Ambient.w = 1.0;
	_material->Diffuse.x = 0.8; _material->Diffuse.y = 0.05; _material->Diffuse.z = 0.05;
	_material->Diffuse.w = 1.0;
	_material->Specular.x = 1.0; _material->Specular.y = 1.0; _material->Specular.z = 1.0;
	_material->Specular.w = 1.0;
	_material->Shininess = 100.0f;

}

void Cube::Update()
{
	_rotation += 0.5f;
}
