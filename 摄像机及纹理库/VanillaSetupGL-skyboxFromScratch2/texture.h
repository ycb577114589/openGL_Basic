#pragma once
#include <windows.h>
#include <gl/GL.h>
#include <string>
#include <unordered_map>
//为纹理缓存做准备
class Texture
{
protected:
	void Init(const char*imagePath, bool invertYx);  
public:
	GLuint mTextureID;//gpu
	std::string mPath;
	static Texture *LoadTexture(const char *imagePath, bool invertYx = true); //创建纹理 
	static void UnLoadTexture(Texture *texture);
	static std::unordered_map<std::string, Texture*> mCachedTextures;
};