#include "fancy_ui.h"

void clear_screen() {
	std::cout << "\e[2J \e[3J \e[H";		// ANSI escape sequence
}

// the prompt after the user has preformed an item in the menu
int next_action_prompt() {

	int input = 0;

	while (input < 1 || input > 2) {
		cout << setw(25) << left << "(1) Return to Menu" << setw(25) << left << "(2) Quit" << endl;
		cout << "\n>> ";
		cin >> input;
	}
	return input;
}

// the main menu of the managment software
int menu() {

	int input = 0;

	while (input < 1 || input > 6) {
		clear_screen();
		cout << setw(25) << left << "(1) Warehouse Stock" << setw(25) << left << "(2) Modify Warehouse" << endl;
		cout << setw(25) << left << "(3) Bookshop Stock" << setw(25) << left << "(4) Modify Bookshop" << endl;
		cout << setw(25) << left << "(5) Point of Sale" << setw(25) << left << "(6) Quit" << endl;

		cout << "\n>> ";
		cin >> input;
	}
	return input;
}