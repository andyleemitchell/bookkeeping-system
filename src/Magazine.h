#pragma once
#include "Mag_details.h"

class Magazine {
public:
	Mag_details *details;
	float Price;

	Magazine();
	Magazine(string, string, string, int, int, float);
	Magazine(const Magazine &a);
	~Magazine();
	void Mag_set_details(string, string, string, int, int, float);
	void Mag_print(void);
	void Add(int);
	void Subtract(int);
};