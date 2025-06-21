#include "menu_control.h"

#include <iostream>

MenuControl::MenuControl() = default; //automatically calls the ItemTracker constructor and loads data.


void MenuControl::displayMenu() const
{
	//TODO: basic main menu display
	//Option1: Search item frequency.
	//Option2: List all item frequencies.
	//Option3: Histogram Visual
	//Option4: Exit Program
	//Option5: Change file name.
	//Select an option
	//Wait for input
	
}

/* User input choice for each Menu option 1-4 */
void MenuControl::inputChoice(int choice)
{
	//TODO: Handle user input choice
	//1: Search one
	//2: List all
	//3: Histogram
	//4: change file name
	std::string new_file_name;
	std::cin >> new_file_name;
	tracker_.setFileName(new_file_name);
	//Switch cases? 4 cases and 1 default for invalid input
}

/* Main loop logic */
void MenuControl::startProgram()
{
	try
	{
		while (true) //main loop, breaks if option 4 is chosen.
		{
			displayMenu(); //display the main menu
			int choice;
			std::cout << "Press ENTER key to continue . . ."; //Replacing original press any key to continue with a universal method.
			std::cin.get();
			std::cout << "\x1b[2J\x1b[H" << std::flush; //clear console
			std::cout << "Please enter a number, (1) Search by name. (2) List all. (3) Histogram visual. 4) Exit program. (5) Change file name.'\n'";
			//input handling, requests user input for choice, if not an int, then clear & try again
			if (!(std::cin >> choice))
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Please enter a number.\n";
				continue; //continue with loop and start back over requesting input.

			}
			if (choice == 4) //Exit
			{
				std::cout << "Exiting program, good bye!'\n'";
				break; //exits loop and program finishes
			}
			inputChoice(choice);
		}
	}
	catch (const std::exception& ex) { // Catching by const reference
		std::cerr << "Caught exception: " << ex.what() << '\n';
	}
}