#include "Magazine.h"

Magazine::Magazine() {
	details = new Mag_details;
	Price = 0.0;
}

Magazine::Magazine(string A, string B, string C, int D, int E, float F) {
	details = new Mag_details;
	details->set_details(A, B, C, D, E);
	Price = F;
}

Magazine::Magazine(const Magazine &a) {
	details = new Mag_details;
	details->set_details(a.details->Title, a.details->Publisher, a.details->Monthly_edition, a.details->Barcode, a.details->num_copies);
	Price = a.Price;
}

Magazine::~Magazine() {
	// cout << "Magazine destructor" << endl;
	delete details;
}

void Magazine::Mag_set_details(string A, string B, string C, int D, int E, float F) {
	details->set_details(A, B, C, D, E);
	Price = F;
}

void Magazine::Mag_print(void) {
	details->print_details();
	cout << std::left << std::setw(20) << "Price: " << std::left << std::setw(50) << Price << endl;
}

void Magazine::Add(int) {
	details->num_copies = details->num_copies + 1;
}

void Magazine::Subtract(int) {
	details->num_copies = details->num_copies - 1;
}
