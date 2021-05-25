#pragma once
#include "abstractoption.h"

class BaseOption : public AbstractOption
{
protected:
	std::string m_Name;
	OptionType m_Type;

public:
	BaseOption(std::string name, OptionType type)
		: m_Name{ name }, m_Type{ type }
	{
	}

	~BaseOption()
	{
	}

	virtual void Action() { std::cout << "BaseOption" << std::endl; }
	virtual void PrintOption() {};

	decltype(m_Name) getName() { return m_Name; }
	decltype(m_Type) getType() { return m_Type; }
};
