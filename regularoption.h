#pragma once
#include "baseoption.h"

class RegularOption : public BaseOption
{
	std::function<void()> m_Function;

public:
	RegularOption(std::string name, std::function<void()> function)
		: BaseOption{ name, OptionType::RegularOption }, m_Function{ function }
	{
	}

	~RegularOption()
	{
	}

	virtual void Action() override
	{
		m_Function();
	}

	virtual void PrintOption() override
	{
		std::cout << "Name: " << m_Name << " / Type: " << OptionTypeString(this->getType()) << '\n';
	}
};