#include "camera.h"
#include <windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>


Camera::Camera() :mPos(0.0f, 0.0f, 0.0f),
mViewCenter(0.0f, 0.0f, -1.0f),
mUp(0.0f, 1.0f, 0.0f),
mbMoveLeft(false),
mbMoveRight(false),
mbMoveForward(false),
mbMoveBackward(false)
{
	
}

void Camera::Update(float deltaTime)
{
	//update everything
	float moveSpeed = 10.0f;
	if (mbMoveLeft)
	{
		//left direction vector
		Vector3f leftDirection(-1.0f,0.0f,0.0f);
		leftDirection.Normalize();
		mPos = mPos + leftDirection*moveSpeed*deltaTime;
		mViewCenter = mViewCenter + leftDirection*moveSpeed*deltaTime;
	}
	if (mbMoveRight)
	{
		//right direction vector
		Vector3f rightDirection(1.0f, 0.0f, 0.0f);
		rightDirection.Normalize();
		mPos = mPos + rightDirection*moveSpeed*deltaTime;
		mViewCenter = mViewCenter + rightDirection*moveSpeed*deltaTime;
	}
	if (mbMoveForward)
	{
		//left direction vector
		Vector3f forwardDirection(0.0f, 0.0f, -1.0f);
		forwardDirection.Normalize();
		mPos = mPos + forwardDirection*moveSpeed*deltaTime;
		mViewCenter = mViewCenter + forwardDirection*moveSpeed*deltaTime;
	}
	if (mbMoveBackward)
	{
		//right direction vector
		Vector3f backwardDirection(0.0f, 0.0f, 1.0f);
		backwardDirection.Normalize();
		mPos = mPos + backwardDirection*moveSpeed*deltaTime;
		mViewCenter = mViewCenter + backwardDirection*moveSpeed*deltaTime;
	}
	//set model view matrix
	gluLookAt(mPos.x, mPos.y, mPos.z,
		mViewCenter.x, mViewCenter.y, mViewCenter.z,
		mUp.x, mUp.y, mUp.z);
}