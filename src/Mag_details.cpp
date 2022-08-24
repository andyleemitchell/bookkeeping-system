#include "Mag_details.h"


Mag_details::Mag_details() {
	Title = "Null";
	Publisher = "Null";
	Monthly_edition = "Null";
	Barcode = 0;
	num_copies = 0;
}

Mag_details::Mag_details(string A, string B, string C, int D, int E) {
	Title = A;
	Publisher = B;
	Monthly_edition = C;
	Barcode = D;
	num_copies = E;
}

void Mag_details::set_details(string A, string B, string C, int D, int E) {
	Title = A;
	Publisher = B;
	Monthly_edition = C;
	Barcode = D;
	num_copies = E;
}

void Mag_details::print_details(void) {
	cout << std::left << std::setw(20) << "Title: " << std::left << std::setw(50) << Title << endl;
	cout << std::left << std::setw(20) << "Publisher: " << std::left << std::setw(50) << Publisher << endl;
	cout << std::left << std::setw(20) << "Monthly Edition: " << std::left << std::setw(50) << Monthly_edition << endl;
	cout << std::left << std::setw(20) << "Barcode: " << std::left << std::setw(50) << Barcode << endl;
	cout << std::left << std::setw(20) << "Number of copies: " << std::left << std::setw(50) << num_copies << endl;
}
