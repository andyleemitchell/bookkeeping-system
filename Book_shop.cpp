#include "Warehouse.h"
#include "Book_shop.h"

Book_shop::Book_shop() {

}

Book_shop::Book_shop(Warehouse &W) {

	string A,B,C; int D,E; float F;
	// Hardbacks = new Hardback [W.num_hards];
	for(int i = 0; i<W.Hardbacks.size(); i++){
		A = W.Hardbacks[i].details->Title;
		B = W.Hardbacks[i].details->Author;
		C = W.Hardbacks[i].details->Publisher;
		D = W.Hardbacks[i].details->Edition;
		E = W.Hardbacks[i].details->Barcode;
		F = W.Hardbacks[i].Price;
		// Hardbacks[i].Book_set_details(A,B,C,D,E,F,0); // set num copies equal to zero (we dont copy this value from warehouse)
		Hardback temp_hardback;
		temp_hardback.Book_set_details(A,B,C,D,E,F,0);
		Hardbacks.push_back(temp_hardback);
	}

	// Softbacks = new Softback [W.num_softs];
	for(int i = 0; i<W.Softbacks.size(); i++){
		A = W.Softbacks[i].details->Title;
		B = W.Softbacks[i].details->Author;
		C = W.Softbacks[i].details->Publisher;
		D = W.Softbacks[i].details->Edition;
		E = W.Softbacks[i].details->Barcode;
		F = W.Softbacks[i].Price;
		// Softbacks[i].Book_set_details(A,B,C,D,E,F,0); // set num copies equal to zero (we dont copy this value from warehouse)
		Softback temp_softback;
		temp_softback.Book_set_details(A,B,C,D,E,F,0);
		Softbacks.push_back(temp_softback);
	}

	// Magazines = new Magazine [W.num_mags];
	for(int i = 0; i<W.Magazines.size(); i++){
		A = W.Magazines[i].details->Title;
		B = W.Magazines[i].details->Publisher;
		C = W.Magazines[i].details->Monthly_edition;
		E = W.Magazines[i].details->Barcode;
		F = W.Magazines[i].Price;
		// Magazines[i].Mag_set_details(A,B,C,E,0,F); // set num copies equal to zero (we dont copy this value from warehouse)
		Magazine temp_magazine;
		temp_magazine.Mag_set_details(A,B,C,E,0,F);
		Magazines.push_back(temp_magazine);
	}
}

Book_shop::~Book_shop() {
	// cout << "Book shop destructor" << endl;
}


void Book_shop::sell(int barcode, int amount){
	// Seraches for the hardback/softback book with the barcode and subtracts copies by amount
	
	//search for unique barcode and deduct amount by one 
	int i = 0;
	bool found = false; 

	// Check hardbacks
	while((i < Hardbacks.size())&&(found == false)){

		if(Hardbacks[i].details->Barcode == barcode){
		
			if(Hardbacks[i].details->num_copies>0){	// do we have any copies of the book?
				Hardbacks[i].details->num_copies--;
			} else{
				cout << endl << "Out of stock." << endl;
			}
			
			found = true;
		}
		
		i++;
	}

	// Check softbacks
	i=0;
	while((i < Softbacks.size())&&(found == false)){

		if(Softbacks[i].details->Barcode == barcode){
		
			if(Softbacks[i].details->num_copies>0){ 
				Softbacks[i].details->num_copies--;
			} else{
				cout << endl << "Out of stock." << endl;
			}
		
			found = true;
		}
		
		i++;
	}

	// Check magazines
	i=0;
	while((i < Magazines.size())&&(found == false)){

		if(Magazines[i].details->Barcode == barcode){
		
			if(Magazines[i].details->num_copies>0){ 
				Magazines[i].details->num_copies--;
			} else{
				cout << endl << "Out of stock." << endl;
			}
		
			found = true;
		}
		
		i++;
	}

	// no match for the barcode
	if(found == false){
		cout << "No such book or magazine in database" << endl;
	}

}