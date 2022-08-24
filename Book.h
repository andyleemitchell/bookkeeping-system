#pragma once
#include "Book_details.h"


class Book {
public:
	Book_details *details;
	float Price;
	
	Book();
	Book(string, string, string, int, int, float, int);
	Book(const Book &a);
	Book operator = (const Book &a);
	~Book();
	void Book_set_details(string, string, string, int, int, float, int);
	void Book_print(void);
	void Add(int);
	void Subtract(int);
};

class Hardback : public Book {
public:
	Hardback();
	Hardback(string, string, string, int, int, float, int);
	Hardback(const Hardback &a);
};

class Softback : public Book {
public:
	Softback();
	Softback(string, string, string, int, int, float, int);
	Softback(const Softback &a);
};