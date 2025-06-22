#include "menu_control.h"

#include <iostream>
#include <limits>

namespace  //helper function isolated for this file in unnamed namespace to wait and clear screen
{
	void pauseAndClear()
	{
		std::cout << "Press ENTER key to continue . . ."; //Waits for user input
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // flush newline
		std::cin.get();
		std::cout << "\x1b[2J\x1b[H" << std::flush; //clear console
	}
}

MenuControl::MenuControl() = default; //automatically calls the ItemTracker constructor through tracker_ which calls loadData.


void MenuControl::displayMenu() const
{
	std::cout << "\n===== Corner Grocer Item-Tracker Menu =====\n"
		<< "1. Search item frequency (case sensitive)\n"
		<< "2. List all frequencies\n"
		<< "3. List histogram visual\n"
		<< "4. Change file name\n"
		<< "5. Exit program\n"
	    << "Select an option by entering a number: ";
	
}

/* User input choice for each Menu option */
void MenuControl::inputChoice(int choice)
{
	switch (choice)
	{
	case 1: //Menu choice 1 (search by name)
		{
		std::string item;
		std::cout << "Enter item name: ";
		std::cin >> item;
		int count = tracker_.getItemCount(item);
		std::cout << "Your " << item << " had a total frequency of: " << count << '\n';
		pauseAndClear();
		break;
		}
	case 2: //Menu choice 2 (display all)
		tracker_.displayAllFrequencies();
		pauseAndClear();
		break;
	case 3: //Menu choice 3 (histogram)
		tracker_.displayHistogram(); //default '*'
		pauseAndClear();
		break;
	case 4: //Menu choice 4 (change file name)
		{
		std::string file_name;
		std::cout << "Please input a new file name, case specific, e.g. My_Text_File.txt \n";
		std::cin >> file_name;
		tracker_.setFileName(file_name);
		std::cout << "File name successfully changed. Press ENTER key to continue . . ."; //Waits for user input
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // flush newline
		std::cin.get();
		std::cout << "\x1b[2J\x1b[H" << std::flush; //clear console
		break;
		}
	default: //Wrong option
		std::cout << "Invalid option.\n";
		pauseAndClear();
	}
}

/* Main loop logic */
void MenuControl::startProgram()
{
	try
	{
		while (true) //main loop, breaks if option 5 is chosen.
		{
			displayMenu(); //display the main menu
			int choice;
			//input handling, requests user input for choice, if not an int, then clear & try again
			if (!(std::cin >> choice))
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Please enter a number.\n";
				continue; //continue with loop and start back over requesting input.
			}
			if (choice == 5) //Exit
			{
				std::cout << "Exiting program, good bye!\n";
				break; //exits loop and program finishes
			}
			inputChoice(choice);
		}
	}
	catch (const std::exception& ex) { // Catching by const reference any derived exception type.
		std::cerr << "Caught exception: " << ex.what() << '\n';
	}
}