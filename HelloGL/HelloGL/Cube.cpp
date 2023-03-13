#include "Cube.h"
#include <fstream>

Vertex* Cube::indexedVertices = nullptr;

Color* Cube::indexedColors = nullptr;

GLushort* Cube::indices = nullptr;

int Cube::numVertices = 0;
int Cube::numColors = 0;
int Cube::numIndices = 0;


Cube::Cube(float x, float y, float z)
{
	_position.x = x;
	_position.y = y;
	_position.z = z;
	_rotation = 0;
}

Cube::~Cube()
{
}

bool Cube::Load(char* path)
{
	std::ifstream inFile;
	inFile.open(path);
	if (!inFile.good())
	{
		std::cerr << "Can't open text file " << path << std::endl;
		return false;
	}

	inFile >> numVertices;
	indexedVertices = new Vertex[numVertices];
	for (int i = 0; i < numVertices; i++)
	{
		inFile.seekg(0, ios::end);
		int fileSize = (int)inFile.tellg();
		inFile.seekg(0, ios::beg);
		//inFile.read(indexedVertices, fileSize);
	}

	inFile.close();

	return true;
}

void Cube::Draw()
{
	if (indexedVertices != nullptr && indexedColors != nullptr && indices != nullptr)
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
}

void Cube::Update()
{
	_rotation += 0.5f;
}
