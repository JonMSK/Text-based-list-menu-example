#pragma once
#include "regularoption.h"

class Submenu
{
	std::string m_Name;

public:
	std::vector<std::unique_ptr<AbstractOption>> m_Options{};

	Submenu(std::string name)
		: m_Name{ name }
	{
	}

	~Submenu()
	{
	}

	void PrintSub()
	{
		std::cout << "-_" << m_Name << "_-" << '\n';
		for (int i{}; i < m_Options.size(); ++i)
		{
			std::cout << "Handle: " << i << " / ";
			m_Options[i]->PrintOption();
		}
	}

	template <typename OptionType, typename ...TArgs>
	void createOption(TArgs&&... args)
	{
		m_Options.push_back(std::make_unique<OptionType>(std::forward<TArgs>(args)...));
	}

	decltype(m_Name) getName() { return m_Name; }
};