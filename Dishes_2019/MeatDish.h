#pragma once

#include "Dish.h"

class MeatDish : public Dish
{
private:
	char* Meat;

	bool setMeat(char*);
	void Copy(const MeatDish&);
	void Erase();

public:
	MeatDish();
	MeatDish(char**, int, int, char*);
	MeatDish(const MeatDish&);
	MeatDish& operator=(const MeatDish&);
	virtual ~MeatDish();
	void Print();
};