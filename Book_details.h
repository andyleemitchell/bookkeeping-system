#pragma once
#include "Pub_details.h"

class Book_details: public Pub_details {
public:
	string Author;
	string Publisher;
	int Edition;
	int num_copies;

	Book_details();
	Book_details(string, string, string, int, int, int);
	void set_details(string, string, string, int, int, int);
	void print_details(void);
};