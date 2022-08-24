#pragma once
#include "Book.h"
#include "Magazine.h"
#include <vector>

class Book_shop;//we use it in Warehouse before we define it..need declaration. 

class Warehouse {
public:
	std::vector<Hardback> Hardbacks;
	std::vector<Softback> Softbacks;
	std::vector<Magazine> Magazines;
	
	Warehouse();
	Warehouse(int,int,int);
	~Warehouse();
	void print_all_books();
	void transfer(Book_shop &, int, int);
	void add_book();
	void remove_book(int);
};