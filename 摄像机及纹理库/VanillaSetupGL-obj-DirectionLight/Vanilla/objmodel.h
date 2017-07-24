#pragma once 
#include "vertexData.h"

class ObjModel
{
public:
	VertexData *mVertexes;
	int *mIndices;
	int mIndexCount;
	void Init(const char * ObjModel);
	void Draw();
};