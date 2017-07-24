#pragma once
#include <windows.h>
#include <gl/GL.h>
#include <string>
#include <unordered_map>
//Ϊ��������׼��
class Texture
{
protected:
	void Init(const char*imagePath, bool invertYx);  
public:
	GLuint mTextureID;//gpu
	std::string mPath;
	static Texture *LoadTexture(const char *imagePath, bool invertYx = true); //�������� 
	static void UnLoadTexture(Texture *texture);
	static std::unordered_map<std::string, Texture*> mCachedTextures;
};