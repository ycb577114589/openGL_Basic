#pragma once
#include <windows.h>
#include <gl/GL.h>
#include "texture.h"

class SkyBox
{
public:
	Texture*front, *back, *right, *left, *top, *bottom;
	void Init(const char*path);
	void Draw(float x,float y,float z);
};