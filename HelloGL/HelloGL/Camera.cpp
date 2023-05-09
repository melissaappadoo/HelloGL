#include "Camera.h"

_Camera::_Camera()
{
	eye.x = 0.0f, eye.y = 0.0f, eye.z = -35.0f;
	center.x = 0.0f; center.y = 0.0f; center.z = 0.0f;
	up.x = 0.0f; up.y = 1.0f; up.z = 0.0f;
}

void _Camera::SetPosition(float x, float y, float z)
{
	eye.x = x;
	eye.y = y;
	eye.z = z;
}

void _Camera::OnKeyboard(unsigned char Key)
{
	switch (Key) {
	case 'w':
		eye.z += speed;
		break;

	case 's':
		eye.z -= speed;
		break;

	case 'a':
		eye.x += speed;
		break;

	case 'd':
		eye.x -= speed;
		break;
	}
}
