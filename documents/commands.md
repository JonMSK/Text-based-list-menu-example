Here is a tutorial and explanation on how to use and add options/submenus to your menu.

## Command-Handling
The way you control the menu during execution is via commands. Here is a list of the base commands included in the menu:

Name: "back"
Usage: Go back in the submenu chain, e.g. if you previously entered a new submenu you can use this keyword to go back.

Name: "action"
Usage: Will ask you for the option handle of the option you wish to perform the action on.
Sub-name/Sub-input: option handle input
Usage: Is asked for after the action command is used, the option handle is the number next to the listed option in the submenu output e.g. lowest being 0 for the first option.

## Adding-new-commands
To add a new command to the base follow these steps (all of this work is done in subopmanager.h):
1. In the vector of strings called m_Commands, add a new element with the keyword for your command. You can use whitespace because command input is taken from the input stream with the getline method/function.
2. In the update function, you will see one if-elseif chain checking which command has been entered. Add an else-if statement comparing command to your new command from the vector e.g. if you added "help" the check would be command == "help".
3. Then in the else-if curly brackets add the functionality of the command e.g. displaying a list of all the commands in the base and what they do.
4. Finally, in the isCommandValid function add an else-if statement in the only if-elseif chain comparing commandToCheck with your command and returning true if the comparison is true.

Example implementation of a new command:

```
m_Commands-Vector:
std::vector<std::string> m_Commands{ "back", "action", /*this is our new command*/"ping" };

update-method-while-if-ifelsechain:
else if (command == "ping")
{
  std::cout << "pong";
}

isCommandValid-onlyifelsechain:
else if (commandToCheck == "ping")
  return true;
```
