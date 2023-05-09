#pragma once

#include "Structures.h"

class _Camera
{
private:
	float speed = 1.0f;

public:
	Vector3 eye;
	Vector3 center;
	Vector3 up;

	_Camera();

	void SetPosition(float x, float y, float z);

	void OnKeyboard(unsigned char Key);
};
