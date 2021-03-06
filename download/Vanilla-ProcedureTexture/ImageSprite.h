#pragma once
#include <windows.h>
#include <gl/GL.h>
#include "List.h"
#include "texture.h"
#include "vector3f.h"

class ImageSprite : public RenderableObject
{
public:
	ImageSprite();
	Texture*mTexture;
	Vector3f mMesh[4];
	unsigned char mAlpha;
	int mFadeSpeed;
	bool mbFadeIn, mbFadeOut;
	void SetTexture(Texture*texture);
	void SetRect(float x, float y, float width, float height);

	void FadeIn(float duration);
	void FadeOut(float duration);
	void Update(float deltaTime);
	void Draw();
};