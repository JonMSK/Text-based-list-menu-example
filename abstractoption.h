#pragma once
#include "common.h"

class AbstractOption
{
public:
	virtual void Action() { std::cout << "AbstractOption" << std::endl; }
	virtual void PrintOption() {};
};