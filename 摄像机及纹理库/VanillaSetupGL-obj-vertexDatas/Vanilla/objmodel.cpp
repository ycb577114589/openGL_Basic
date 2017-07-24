#include "utils.h"
#include "objmodel.h"
#include <string.h>
#include <sstream>
#include <vector>

void ObjModel::Init(const char * objmodel)
{
	struct  FloatData
	{
		float v[3];
	};
	std::vector<FloatData> positions, texcoords, normals;
	unsigned char * fileContent = LoadFileContent(objmodel);
	//printf("%s\n", fileContent);
	std::stringstream ssFileContent((char *)fileContent);
	std::string temp;
	char szOneLine[256];

	while (!ssFileContent.eof())
	{
		memset(szOneLine, 0, 256);
		ssFileContent.getline(szOneLine, 256);
		if (strlen(szOneLine) > 0)
		{
			if (szOneLine[0] == 'v')
			{
				std::stringstream ssOneLine(szOneLine);
				if (szOneLine[1] == 't')//½âÎÆÀí×ø±ê
				{
					ssOneLine >> temp;
					FloatData floatData;
					ssOneLine >> floatData.v[0];
					ssOneLine >> floatData.v[1]; 
					printf(" texcoord : %f %f\n", floatData.v[0], floatData.v[1] );
					texcoords.push_back(floatData);
					;
				}
				else if (szOneLine[1] == 'n')
				{
					ssOneLine >> temp;
					FloatData floatData;
					ssOneLine >> floatData.v[0];
					ssOneLine >> floatData.v[1];
					ssOneLine >> floatData.v[2];
					printf(" normal : %f %f %f\n", floatData.v[0], floatData.v[1], floatData.v[2]);
					normals.push_back(floatData);
				}
				else
				{
					ssOneLine >> temp;
					FloatData floatData; 
					ssOneLine >> floatData.v[0];
					ssOneLine >> floatData.v[1];
					ssOneLine >> floatData.v[2];
					printf(" position : %f %f %f\n", floatData.v[0], floatData.v[1], floatData.v[2]);
					positions.push_back(floatData);
				}
			}
			else if (szOneLine[0] == 'f')
			{
				printf("face %s\n", szOneLine);
			}
		}

	}

	delete fileContent;
}


void ObjModel::Draw()
{

}