#pragma once 
#include "vertexData.h"

class ObjModel
{
public:
	VertexData *mVertexes;
	int *mIndices;

	void Init(const char * ObjModel);
	void Draw();
};