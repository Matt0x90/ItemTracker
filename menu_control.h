#ifndef MENU_CONTROL_H_
#define MENU_CONTROL_H_

#include "item_tracker.h"

class MenuControl {
public:
	/* Forwards input file name from tracker_ */
	explicit MenuControl(); //default constructor
	void startProgram(); // Handles the main loop logic, breaks/exits on option 4.
private:
	ItemTracker tracker_; // Creating an instance of ItemTracker class inside MenuControl
	//an itemtracker 'composition, has/a relationship'. 
	void displayMenu() const; // Handles menu display logic for Menu options 1-3
	void inputChoice(int choice); // User input choice for each Menu option 1-4
};
#endif
