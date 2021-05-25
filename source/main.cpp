#include "submenu.h"
#include "regularoption.h"
#include "booloption.h"
#include "suboption.h"
#include "subopmanager.h"

int main()
{
	g_Manager = std::make_unique<Manager>();
g_Manager->addSubmenu("Home"); // 0
	g_Manager->m_AllSubmenus.back()->createOption<RegularOption>("Option1", []() {});
	bool testbool = false;
	g_Manager->m_AllSubmenus.back()->createOption<BoolOption>("Option2", testbool);
	g_Manager->m_AllSubmenus.back()->createOption<SubOption>("Option3", 1);

g_Manager->addSubmenu("TestSub"); // 1
	g_Manager->m_AllSubmenus.back()->createOption<RegularOption>("IT REALLY WORKS!!!", []() {});

	g_Manager->update();

	return 0;
}

/* The following is an example of the usage of this test base.

This creates the manager class to manage all existing submenus and the current submenu stack. -				Manager manager;
This adds a submenu to the submenu class and adds the value 0 to the cur sub stack. It has the name Home. - manager.addSubmenu("Home"); // 0
This adds an option to the previously created sub. Alternatively, you can use the back() function to get -	manager.m_AllSubmenus[0]->createOption<RegularOption>("Option1", []() {});
the last added submenu.
This creates bool variable testBool and declares it as false. -												bool testBool = false;
This adds an option to teh previously created sub. This one is a boolean option. -							manager.m_AllSubmenus[0]->createOption<BoolOption>("Option2", testBool);
This prints the submenu. -																					manager.printTopSub();

																											std::cin.get();
This sets testBool to true. - 																				testBool = true;

This prints the submenu. -																					manager.printTopSub();

*/
