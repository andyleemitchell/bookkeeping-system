#pragma once
#include "Pub_details.h"

class Mag_details: public Pub_details {
public:
	string Publisher;
	string Monthly_edition;
	int num_copies;
	
	Mag_details();
	Mag_details(string, string, string, int, int);
	void set_details(string, string, string, int, int);
	void print_details(void);
};