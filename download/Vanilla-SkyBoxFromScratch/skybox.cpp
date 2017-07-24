#include "skybox.h"

void SkyBox::Init(const char*path)
{
	char temp[128] = {0};
	strcpy(temp, path);
	strcat(temp, "/front.bmp");
	front = Texture::LoadTexture(temp);
}

void SkyBox::Draw(float x, float y, float z)
{
	glDisable(GL_LIGHTING);
	glDisable(GL_DEPTH_TEST);
	glPushMatrix();
	glTranslatef(x,y,z);
	glBindTexture(GL_TEXTURE_2D, front->mTextureID);
	glColor4ub(255, 255, 255, 255);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);
	glVertex3f(-0.5f, -0.5f, -0.5f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.5f, -0.5f, -0.5f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.5f, 0.5f, -0.5f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.5f, 0.5f, -0.5f);
	glEnd();
	glPopMatrix();
}