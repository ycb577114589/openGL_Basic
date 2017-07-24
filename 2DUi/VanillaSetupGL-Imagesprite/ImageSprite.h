#pragma once 
#include <Windows.h>
#include <gl/GL.h>
#include "texture.h"
#include "vector3f.h"

class ImageSprite
{
public:
	Vector3f mMesh[4];
	Texture *mTexture;
	void SetTexture(Texture *texture);
	void SetRect(float x, float y, float width, float height);
	void Draw();
};