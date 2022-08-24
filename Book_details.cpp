#include "Book_details.h"


Book_details::Book_details() {
	Title = "Null";
	Author = "Null";
	Publisher = "Null";
	Edition = 0;
	Barcode = 0;
	num_copies = 0;
}

Book_details::Book_details(string A, string B, string C, int D, int E, int F) {
	Title = A;
	Author = B;
	Publisher = C;
	Edition = D;
	Barcode = E;
	num_copies = F;
}

void Book_details::set_details(string A, string B, string C, int D, int E, int F) {
	Title = A;
	Author = B;
	Publisher = C;
	Edition = D;
	Barcode = E;
	num_copies = F;
}

void Book_details::print_details(void) {
	cout << std::left << std::setw(20) << "Title: " << std::left << std::setw(50) << Title << endl;
	cout << std::left << std::setw(20) << "Author: " << std::left << std::setw(50) << Author << endl;
	cout << std::left << std::setw(20) << "Publisher: " << std::left << std::setw(50) << Publisher << endl;
	cout << std::left << std::setw(20) << "Edition: " << std::left << std::setw(50) << Edition << endl;
	cout << std::left << std::setw(20) << "Barcode: " << std::left << std::setw(50) << Barcode << endl;
	cout << std::left << std::setw(20) << "Number of copies: " << std::left << std::setw(50) << num_copies << endl;
}