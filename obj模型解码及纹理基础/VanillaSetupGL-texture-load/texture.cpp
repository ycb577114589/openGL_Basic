#include "texture.h"
#include "utils.h"
void Texture::Init(const char*imagePath)
{
	//load image file from disk to memory
	unsigned char*imageFileContent = LoadFileContent(imagePath);
	//decode image
	//generate an opengl texture
	 
}