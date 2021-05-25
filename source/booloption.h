#pragma once
#include "baseoption.h"

class BoolOption : public BaseOption
{
	bool& m_Boolean;

public:
	BoolOption(std::string name, bool& boolean)
		: BaseOption{ name, OptionType::BoolOption }, m_Boolean{ boolean }
	{
	}

	~BoolOption()
	{
	}

	virtual void Action() override
	{
		switch (m_Boolean)
		{
		case true:
			m_Boolean = false;
			break;
		case false:
			m_Boolean = true;
			break;
		}
	}

	virtual void PrintOption() override
	{
		std::cout << "Name: " << m_Name << " / Type: " << OptionTypeString(this->getType()) << " / BooleanValue: " << (m_Boolean ? "true" : "false") << '\n';
	}
};
