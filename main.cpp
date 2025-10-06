////////////////////////////////////////////////////////////
// Project 3
//
// Developer : Matthew
// Date		 : 06/19/2025
// Purpose   : Corner Grocer Item-tracker
// The program analyzes text records and provides information related to the frequency of purchase per item.
// Provides search option input for the item name and various menu options.
// Code style: Attempted to follow google style guide. Decided against changing indentation. 
////////////////////////////////////////////////////////////

#include <iostream>

#include "menu_control.h"

int main() {
	try //try/catch to properly handle loadData's catch on not being able to open the file.
	{
		MenuControl run;
		run.startProgram();
	}
	catch (const std::exception& ex)
	{
		std::cerr << ex.what() << std::endl;
		return EXIT_FAILURE;
	}
}
