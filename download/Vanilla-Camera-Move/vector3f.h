#pragma once
#include <math.h>

class Vector3f
{
public:
	union
	{
		struct
		{
			float x, y, z;
		};
		float v[3];
	};
	Vector3f(float x,float y,float z);
};