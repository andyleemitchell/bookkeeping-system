#include "Book.h"

Book::Book() {
	details = new Book_details;
	Price = 0.0;
}

Book::Book(string A, string B, string C, int D, int E, float F, int G) {
	details = new Book_details;
	details->set_details(A, B, C, D, E, G);
	Price = F;
}

Book::Book(const Book &a) {
	details = new Book_details;
	details->set_details(a.details->Title, a.details->Author, a.details->Publisher, a.details->Edition, a.details->Barcode, a.details->num_copies);
	Price = a.Price;
}

Book Book::operator = (const Book &a) {
	details->set_details(a.details->Title, a.details->Author, a.details->Publisher, a.details->Edition, a.details->Barcode, a.details->num_copies);
	Price = a.Price;
	return *this;
}

Book::~Book() {
	// cout << "Book destructor" << endl;
	delete details;
}

void Book::Book_set_details(string A, string B, string C, int D, int E, float F, int G) {
	details->set_details(A, B, C, D, E, G);
	Price = F;
}

void Book::Book_print() {
	details->print_details();
	cout << std::left << std::setw(20) << "Price: " << std::left << std::setw(50) << Price << endl;
}

void Book::Add(int N) {
	details->num_copies = details->num_copies + N;
}

void Book::Subtract(int N) {
	details->num_copies = details->num_copies - N;
}

Hardback::Hardback(){};
Hardback::Hardback(string A, string B, string C, int D, int E, float F, int G) :Book(A, B, C, D, E, F, G) {};
Hardback::Hardback(const Hardback &a) {
	details = new Book_details;
	details->set_details(a.details->Title, a.details->Author, a.details->Publisher, a.details->Edition, a.details->Barcode, a.details->num_copies);
	Price = a.Price;
}

Softback::Softback(){};
Softback::Softback(string A, string B, string C, int D, int E, float F, int G) :Book(A, B, C, D, E, F, G) {};
Softback::Softback(const Softback &a) {
	details = new Book_details;
	details->set_details(a.details->Title, a.details->Author, a.details->Publisher, a.details->Edition, a.details->Barcode, a.details->num_copies);
	Price = a.Price;
}