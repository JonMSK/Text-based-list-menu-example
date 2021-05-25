#pragma once
#include "submenu.h"

class Manager
{
public:
	std::vector<std::unique_ptr<Submenu>> m_AllSubmenus;
	std::vector<int> m_CurSubmenusIndexes;
	std::vector<std::string> m_Commands{"back", "action"};

	void addSubmenu(std::string name)
	{
		m_AllSubmenus.push_back(std::make_unique<Submenu>(name));

		if (m_CurSubmenusIndexes.size() == 0)
			m_CurSubmenusIndexes.push_back(0);
	}

	void printTopSub()
	{
		system("cls");
		m_AllSubmenus[m_CurSubmenusIndexes.back()]->PrintSub();
	}

	void update()
	{
		std::string command;
		while (true)
		{
			printTopSub();
			std::cout << "Enter a command: ";
			std::getline(std::cin, command);
			if (isCommandValid(command))
			{
				if (command == "back")
				{
					if (m_CurSubmenusIndexes.size() > 1)
						m_CurSubmenusIndexes.pop_back();
				}
				else if (command == "action")
				{
					int optionHandle = -1;
					while (optionHandle < 0 && optionHandle > (m_AllSubmenus[m_CurSubmenusIndexes.back()]->m_Options.size() - 1))
					{
						std::cout << "Enter the handle of the option you want to trigger: ";
						std::cin >> optionHandle;
					}
					m_AllSubmenus[m_CurSubmenusIndexes.back()]->m_Options[optionHandle]->Action();
				}
			}
		}
	}

	bool isCommandValid(std::string commandToCheck)
	{
		if (commandToCheck == "back")
			return true;
		else if (commandToCheck == "action")
			return true;
		return false;
	}
};

inline std::unique_ptr<Manager> g_Manager;