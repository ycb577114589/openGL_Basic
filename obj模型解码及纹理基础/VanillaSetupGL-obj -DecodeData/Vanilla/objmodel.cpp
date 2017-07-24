#include "utils.h"
#include "objmodel.h"
#include <string.h>
#include <sstream>

void ObjModel::Init(const char * objmodel)
{
	unsigned char * fileContent = LoadFileContent(objmodel);
	//printf("%s\n", fileContent);
	std::stringstream ssFileContent( (char *)fileContent);
	char szOneLine[256];
	while (!ssFileContent.eof())
	{
		memset(szOneLine, 0, 256);
		ssFileContent.getline(szOneLine, 256);
		if (strlen(szOneLine) > 0)
		{
			if(szOneLine[0]=='v')
			{ 
				if (szOneLine[1] == 't')
				{
					printf("texcoord %s\n",szOneLine);
				}
				else if(szOneLine[1]=='n')
				{ 
					printf("nomal %s\n", szOneLine);
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