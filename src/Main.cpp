#include "Book_details.h"
#include "Book.h"
#include "Warehouse.h"
#include "Book_shop.h"
#include "fancy_ui.h"

int main(void)
{
	clear_screen();

	cout << "Initial Setup:\n" << endl;

	//request info to set up warehouse and shop
	int hard_copies, soft_copies, mag_copies;
	cout << "Enter number of hardbacks in warehouse: "; cin >> hard_copies;
	cout << "Enter number of softbacks in warehouse: "; cin >> soft_copies;
	cout << "Enter number of magazines in warehouse: "; cin >> mag_copies;
	
	Warehouse Dublin_Warehouse(soft_copies,hard_copies,mag_copies);
	Book_shop Mullingar(Dublin_Warehouse);
	
	// variables to navigate through menu 
	int current_operation = 0;
	int exit_choice = 0;


	while(exit_choice != 2) {

		current_operation = menu();		// call the menu

		switch(current_operation) {		

			case 1: {
				clear_screen();
				cout << string(70, '=') << endl;
				cout << "WAREHOUSE STOCK" << endl;
				cout << string(70, '=') << endl;
				Dublin_Warehouse.print_all_books();
				exit_choice = next_action_prompt();
				break;
			}


			case 2: {
				clear_screen();

				int add_or_remove = 0;
				
				while (add_or_remove < 1 || add_or_remove > 2) {
					cout << "Would you like to add(1) or remove(2) a book? ";
					cin >> add_or_remove;
				}

				switch (add_or_remove) {
					case 1: {
						Dublin_Warehouse.add_book();
						break;
					}

					case 2: {
						int barcode;
						cout << endl << "Enter barcode to remove: "; cin >> barcode;
						Dublin_Warehouse.remove_book(barcode);
						break;
					}
				}

				
				exit_choice = next_action_prompt();
				break;
			}

			case 3: {
				clear_screen();
				cout << string(70, '=') << endl;
				cout << "BOOKSHOP STOCK" << endl;
				cout << string(70, '=') << endl;
				Mullingar.print_all_books();

				exit_choice = next_action_prompt();
				break;
			}

			case 4: {
				clear_screen();
				int barcode, copies;
				cout << endl << "Enter barcode to transfer: "; cin >> barcode;
				cout << endl << "Enter number of copies to transfer"; cin >> copies;
				
				//Transfer Books
				Dublin_Warehouse.transfer(Mullingar, barcode, copies);

				exit_choice = next_action_prompt();
				break;
			}

			case 5: {
				clear_screen();
				int barcode;
				cout << string(70, '=') << endl;
				cout << "BOOKSHOP STOCK" << endl;
				cout << string(70, '=') << endl;

				Mullingar.print_all_books();
				cout << endl << "Enter barcode to sell: "; cin >> barcode;
				Mullingar.sell(barcode,1);

				exit_choice = next_action_prompt();
				break;
			}


			case 6: {		// user wants to quit :(
				clear_screen();
				exit_choice = 2;
			}

		}

	}

}