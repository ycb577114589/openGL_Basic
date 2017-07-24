#pragma once
#include "vector3f.h"


class Camera
{
public:
	Camera();
	Vector3f mPos, mViewCenter, mUp;
	void Update(float delaTime);
};