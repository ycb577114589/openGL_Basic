#include "ground.h"

void  Ground::Init()
{
	mGround = glGenLists(1);
	glNewList(mGround, GL_COMPILE);
	glBegin(GL_QUADS);
	for (int z = 0; z < 20; ++z)
	{
		float zStart = 100.0f - z*10.0f;
		for (int x = 0; x < 20; ++x)
		{
			float xStart = x*10.0f - 100.0f;
			glVertex3f(xStart, 0.0f, zStart);
			glVertex3f(xStart+10.0f, 0.0f, zStart);
			glVertex3f(xStart+10.0f, 0.0f, zStart);
			glVertex3f(xStart, 0.0f, zStart-10.0f);
		}
	}
	glEnd();

}

void Ground::Draw()
{
	glEnable(GL_DEPTH_TEST);
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
	glDisable(GL_LIGHTING);
	glCallList(mGround);
}