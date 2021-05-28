## What-are-options?
Options are the entitys users can interact with to perform actions within the menu. Actions are pre-programmed into the options and various types of options have various uses.

Let's look at an example for help; say we are developing a GTA V mod menu and we want to add a function to give the player a pistol. Writing the function in c++ is good but how
will the user actually use/call it? We can create an option in the menu which will have a UI and can be navigated to and pressed by the user to call the specified function. In this case, 
it is the pistolGift function. This is only one example of an option though and in this text based menu example there are 3 types of options you can use to provide menu
functionality.

The following is a small list of the 3 different types of options you can add to your menu with this base...

#### Regular-options
Regular options are options where if the user presses enter (in this menus case, types the action function with a regular option's option handle) a function is called.
We use lambdas to write the functions called when a regular option is pressed (if you don't know what lambdas are read https://www.learncpp.com/cpp-tutorial/introduction-to-lambdas-anonymous-functions/).
Here is an example of adding a regular option to the last created submenu (more about submenus in another doc):
```
g_Manager->m_AllSubmenus.back()->createOption<RegularOption>("This is the name of the option which will be printed to the console. The next arg is the lambda.", []() { std::cout << "You used a regular option!";});
```

#### Bool-options
Bool options are options where if the user presses enter (in this menus case, types the action function with a regular option's option handle) a boolean value is changed to the
opposite of its current value e.g. if a boolean option is pressed and it controls the testBoolean bool variable which is currently false, it will be changed to be true, and vice-versa.
Here is an example of adding a bool option to the last created submenu:
```
bool testBoolean = false; // This is our boolean variable to use in the option.
g_Manager->m_AllSubmenus.back()->createOption<BoolOption>("Name of bool option, will be printed to the console.", testBoolean);
```
Note above that testBoolean doesn't appear to be passed as reference, but when it is passed as an arg it is automatically converted to a reference due to the BoolOption constructor
taking in a bool& value.

#### Sub-options (You probably won't understand this without reading the submenus.md document prior)
Sub options are options where if the user presses enter (in this menus case, types the action function with a regular option's option handle) the submenu specified by the submenu option's
argument will be added to the top of the curSubmenuIndexes vector. The way this vector works is that it stores the indexes of the submenus you are currently in and prints the submenu
from allSubMenus at the top index of curSubmenuIndexes. When you enter the "back" command, it pops the top value off of this vector unless there is only one element in it.
Here is an example of adding a sub option which, when pressed, adds the index of the "Next submenu" submenu to the curSubmenusIndexes vector:
```
g_Manager->addSubmenu("Home"); // 0 (0 to indicate that this submenu is at index 0 in the allSubmenu vector and is the first submenu added to the menu as a whole)
g_Manager->m_AllSubmenus.back()->createOption<SubOption>("Go to submenu 'Next submenu'", 1);
g_Manager->addSubmenu("Next submenu"); // 1
```

## Conclusion
I hope that after reading this you have a better understanding of menu options, how they work, and how to implement and play with them a bit.
As always, I encourage you to visit https://www.unknowncheats.me/ and visit the Grand Theft Auto V category for more information on modding as a whole, trust me, it helps a lot.
If you think something is missing from this document suggest it to me via my discord (find on my profile).
Have a great day :)
