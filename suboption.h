#pragma once
#include "baseoption.h"
#include "subopmanager.h"

class SubOption : public BaseOption
{
	std::size_t m_IndexTo;

public:
	SubOption(std::string name, std::size_t indexto)
		: BaseOption{ name, OptionType::SubOption }, m_IndexTo{ indexto }
	{
	}

	~SubOption()
	{
	}

	virtual void Action() override
	{
		g_Manager->m_CurSubmenusIndexes.push_back(m_IndexTo);
	}

	virtual void PrintOption() override
	{
		std::cout << "Name: " << m_Name << " / Type: " << OptionTypeString(this->getType()) << " / SubIndex: " << m_IndexTo << " / SubIndexName: " << g_Manager->m_AllSubmenus[m_IndexTo]->getName() << '\n';
	}
};