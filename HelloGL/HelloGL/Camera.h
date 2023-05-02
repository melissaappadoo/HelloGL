#pragma once

#include "Structures.h"

class _Camera
{
private:
	Vector3 eye;
	Vector3 center;
	Vector3 up;
	float speed = 1.0f;


public:
	_Camera();

	void SetPosition(float x, float y, float z);

	void OnKeyboard(unsigned char Key);
};
