#pragma once
#include "vector3f.h"

class Camera
{
public:
	Camera();
	Vector3f mPos,mViewCenter,mUp;
	bool mbMoveLeft, mbMoveRight,mbMoveForward,mbMoveBackward;
	void Update(float deltaTime);
};