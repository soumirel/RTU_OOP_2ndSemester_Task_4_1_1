#pragma once

#include "Cl_base.h"

class Cl_branch : public Cl_base
{
public:
	Cl_branch(string objectName, Cl_base* root) :
		Cl_base(objectName, root) {};
};
