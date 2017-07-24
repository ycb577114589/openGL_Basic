#pragma once
#include <windows.h>
#include <gl/GL.h>
#include <cmath>

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
	
};