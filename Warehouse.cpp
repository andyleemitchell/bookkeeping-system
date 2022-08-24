#include "Warehouse.h"
#include "Book_shop.h"
#include <iterator>


Warehouse::Warehouse() {
}

Warehouse::Warehouse(int Num_soft, int Num_hard, int Num_mag) {
	
	// variables to store inputted data:
	string A,B,C; int D,E,G; float F;

	// Do we have hardbacks in the warehouse?
	if(Num_hard>0) 
		cout << "Please enter details of all " << Num_hard << " hardback books in the warehouse:" << endl;
	
	// Fill in their details
	for(int i = 0; i<Num_hard; i++){
		cout << endl << "For Book " << i+1 << endl;
		cout << "Please enter title: " << endl; cin >> A; 
		cout << "Please enter author: " << endl; cin >> B;
		cout << "Please enter publisher: " << endl; cin >> C;
		cout << "Please enter edition: " << endl; cin >> D;
		cout << "Please enter barcode: " << endl; cin >> E;
		cout << "Please enter price: " << endl; cin >> F;
		cout << "Please enter number of copies: " << endl; cin >> G;
		Hardback temp_hardback;
		temp_hardback.Book_set_details(A,B,C,D,E,F,G);
		Hardbacks.push_back(temp_hardback);
	}


	// Do we have softbacks in the warehouse?
	if(Num_soft>0) 
		cout << endl << "Please enter details of all " << Num_soft << " softback books in the warehouse:" << endl;
	
	// Fill in their details
	for(int i = 0; i<Num_soft; i++){
		cout << endl << "For Book " << i+1 << endl;
		cout << "Please enter title: " << endl; cin >> A; 
		cout << "Please enter author: " << endl; cin >> B;
		cout << "Please enter publisher: " << endl; cin >> C;
		cout << "Please enter edition: " << endl; cin >> D;
		cout << "Please enter barcode: " << endl; cin >> E;
		cout << "Please enter price: " << endl; cin >> F;
		cout << "Please enter number of copies: " << endl; cin >> G;
		Softback temp_softback;
		temp_softback.Book_set_details(A,B,C,D,E,F,G);
		Softbacks.push_back(temp_softback);
	}


	// Do we have magazines in the warehouse?
	if(Num_mag > 0) {
		cout << endl << "Please enter details of all " << Num_mag << " magazines in the warehouse:" << endl;
	}

	// If so, fill in their details
	for(int i=0; i<Num_mag; i++) {
		cout << endl << "For Magazine " << i+1 << endl;
		cout << "Please enter title: " << endl; cin >> A; 
		cout << "Please enter publisher: " << endl; cin >> B;
		cout << "Please enter monthly edition: " << endl; cin >> C;
		cout << "Please enter barcode: " << endl; cin >> D;
		cout << "Please enter price: " << endl; cin >> F;
		cout << "Please enter number of copies: " << endl; cin >> E;
		Magazine temp_magazine;
		temp_magazine.Mag_set_details(A,B,C,D,E,F);
		Magazines.push_back(temp_magazine);
	}
}

Warehouse::~Warehouse() {
	// cout << "Warehouse destructor" << endl;
}

void Warehouse::print_all_books(){

	cout << "LIST OF HARDBACKS:" << endl;
	cout << string(70, '-') << endl;
	for (auto &i : Hardbacks) {
		i.Book_print();
		cout<<endl;
	}

	cout << endl << "LIST OF SOFTBACKS:" << endl;
	cout << string(70, '-') << endl;
	for (auto &i : Softbacks) {
		i.Book_print();
		cout<<endl;
	}

	cout << endl << "LIST OF MAGAZINES:" << endl;
	cout << string(70, '-') << endl;
	for (auto &i : Magazines) {
		i.Mag_print();
		cout<<endl;
	}

}

/**
 * This function transfers a number of copies of a specified book from the 
 * warehouse to a given book shop.
 */
void Warehouse::transfer(Book_shop &A, int bar, int amount){
	//search for unique barcode in both the warehouse and bookshop databases and transfer number of copies 
	int i = 0;
	bool found = false; 

	// Check through hardbacks
	while((i < Hardbacks.size())&&(found == false)){

		if(Hardbacks[i].details->Barcode == bar){	// Does the barcode match?

			for(int j = 0; j < A.Hardbacks.size(); j++){
			
				if(A.Hardbacks[j].details->Barcode == bar){
			
					while(amount < 0){
						cout << endl << "negative transfer not allowed. Reenter amount to transfer: " << endl; cin >> amount; 
					}
					if(Hardbacks[i].details->num_copies>=amount) { 	// is there enough to transfer?
						Hardbacks[i].details->num_copies -= amount;	// Remove from warehouse
						A.Hardbacks[j].details->num_copies += amount;// Move to shop	
					} else {	// There isn't enough to move
						cout << endl << "not enough stock to transfer." << endl;
					}
				}
			
			}
			
			found = true;	// break the loop
		}

		i++;
	}

	// Check through softbacks
	i=0;
	while((i < Softbacks.size())&&(found == false)){

		if(Softbacks[i].details->Barcode == bar){

			for(int j = 0; j < A.Softbacks.size(); j++){

				if(A.Softbacks[j].details->Barcode == bar){

					while (amount < 0){
						cout << endl << "negative transfer not allowed. Reenter amount to transfer: " << endl; cin >> amount; 
					}
					if(Softbacks[i].details->num_copies>=amount){ 
						Softbacks[i].details->num_copies -= amount;
						A.Softbacks[j].details->num_copies += amount; 
					} else{
						cout << endl << "not enough stock to transfer." << endl;
					}
				}
			}

			found = true;
		}

		i++;
	}

	// Check through magazines
	i=0;
	while((i < Magazines.size())&&(found == false)){

		if(Magazines[i].details->Barcode == bar){

			for(int j = 0; j < A.Magazines.size(); j++){

				if(A.Magazines[j].details->Barcode == bar){

					while (amount < 0){
						cout << endl << "negative transfer not allowed. Reenter amount to transfer: " << endl; cin >> amount; 
					}
					if(Magazines[i].details->num_copies>=amount){ 
						Magazines[i].details->num_copies -= amount;
						A.Magazines[j].details->num_copies += amount; 
					} else{
						cout << endl << "not enough stock to transfer." << endl;
					}
				}
			}

			found = true;
		}

		i++;
	}

	// no match for the barcode
	if(found==false){
		cout << endl << "No such book or magazine exists in the warehouse." << endl;
	}
}

void Warehouse::add_book() {
	int choice = 0;
	
	do {
		cout << "Hardback(1) or Softback(2)? ";
		cin >> choice;
	} while(choice < 1 && choice > 2);	// wait until valid choice entered

	// variables to store the inputted details
	string A,B,C; int D,E,G; float F;

	switch(choice) {
	
		case 1:	// Hardback
		{
			cout << "Please enter title: " << endl; cin >> A; 
			cout << "Please enter author: " << endl; cin >> B;
			cout << "Please enter publisher: " << endl; cin >> C;
			cout << "Please enter edition: " << endl; cin >> D;
			cout << "Please enter barcode: " << endl; cin >> E;
			cout << "Please enter price: " << endl; cin >> F;
			cout << "Please enter number of copies: " << endl; cin >> G;
			Hardback temp_hardback;
			temp_hardback.Book_set_details(A,B,C,D,E,F,G);
			Hardbacks.push_back(temp_hardback);
			break;
		}

		case 2:	// Softback
		{
			cout << "Please enter title: " << endl; cin >> A; 
			cout << "Please enter author: " << endl; cin >> B;
			cout << "Please enter publisher: " << endl; cin >> C;
			cout << "Please enter edition: " << endl; cin >> D;
			cout << "Please enter barcode: " << endl; cin >> E;
			cout << "Please enter price: " << endl; cin >> F;
			cout << "Please enter number of copies: " << endl; cin >> G;
			Softback temp_softback;
			temp_softback.Book_set_details(A,B,C,D,E,F,G);
			Softbacks.push_back(temp_softback);
			break;
		}
	}
}


void Warehouse::remove_book(int test_barcode) {

	bool found = false;

	while(found == false) 
	{
		// check through hardbacks
		for (auto i = std::begin(Hardbacks); i != std::end(Hardbacks);)
		{
			if (i->details->Barcode == test_barcode) {	// does the barcode match?
				Hardbacks.erase(i);
				found = true;
			} else {
				++i;
			}
		}

		for (auto i = std::begin(Softbacks); i != std::end(Softbacks);)
		{
			if (i->details->Barcode == test_barcode) {	// does the barcode match?
				Softbacks.erase(i);
				found = true;
			} else {
				++i;
			}
		}

		// no match, break loop
		if (found == false)
			cout << "Could not find a matching barcode." << endl;
		break;
	}

}