#pragma once
#include "vector3f.h"


class Camera
{
public:
	Vector3f mPos, mViewCenter, mUp;
	void Update(float deltaTime);

};