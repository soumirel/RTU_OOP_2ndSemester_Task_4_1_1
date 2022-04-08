#include "Cl_application.h"
#

int main()
{
	Cl_application AppObject;
	AppObject.buildTree();
	return AppObject.execApp();
}