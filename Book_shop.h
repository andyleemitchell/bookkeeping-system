#pragma once
#include "Warehouse.h"

class Book_shop:public Warehouse{
public:
	Book_shop();
	Book_shop(Warehouse &);	// have to pass by reference to avoid double deletion
	~Book_shop();
	void sell(int,int);
};