#include "texture.h"
#include "utils.h"
 
unsigned char* DecodeBMP(unsigned char*bmpFileData, int&width, int&height)
{
	if (0x4D42==*((unsigned short*)bmpFileData))
	{
		printf("yes");
		int pixelDataOffset = *((int*)(bmpFileData + 10));
		width = *((int*)(bmpFileData+18));
		height = *((int*)(bmpFileData + 22));
		unsigned char*pixelData = bmpFileData + pixelDataOffset;
		//bgr bgr bgr ....
		//rgb rgb rgb
		for (int i=0;i<width*height*3;i+=3)
		{
			unsigned char temp = pixelData[i];
			pixelData[i] = pixelData[i+2];
			pixelData[i+2]=temp;
		}
		return pixelData;
	}
	else
	{
		printf("no");
		return nullptr;
	}
}

void Texture::Init(const char*imagePath)
{
	//load image file from disk to memory
	unsigned char*imageFileContent = LoadFileContent(imagePath);
	//decode image
	int width = 0, height = 0;
	unsigned char* pixelData = DecodeBMP(imageFileContent, width, height);

	//generate an opengl texture
	glGenTextures(1, &mTextureID);
	glBindTexture(GL_TEXTURE_2D, mTextureID);
	/*glGenTextures(GLsizei n, GLuint *textures)函数说明 
	百度百科：
	n：用来生成纹理的数量
	textures：存储纹理索引的第一个元素指针
	glGenTextures函数根据纹理参数返回n个纹理索引。纹理名称集合不必是一个连续的整数集合。
	（glGenTextures就是用来产生你要操作的纹理对象的索引的，比如你告诉OpenGL，我需要5个纹理对象，它会从没有用到的整数里返回5个给你）
	glBindTexture实际上是改变了OpenGL的这个状态，它告诉OpenGL下面对纹理的任何操作都是对它所绑定的纹理对象的，比如glBindTexture(GL_TEXTURE_2D,1)告诉OpenGL下面代码中对2D纹理的任何设置都是针对索引为1的纹理的。
	产生纹理函数假定目标纹理的面积是由glBindTexture函数限制的。先前调用glGenTextures产生的纹理索引集不会由后面调用的glGenTextures得到，除非他们首先被glDeleteTextures删除。你不可以在显示列表中包含glGenTextures。*/
	
	
	//operation on current texture  可以解决绝大多数问题
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, pixelData);
	glBindTexture(GL_TEXTURE_2D, 0);
	delete imageFileContent;
}