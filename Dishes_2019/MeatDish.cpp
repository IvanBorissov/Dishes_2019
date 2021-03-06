#include <iostream>
#include "Dish.h"
#include "MeatDish.h"
using namespace std;

bool MeatDish::setMeat(char* meat)
{
	if (!(strcmp(meat, "chicken")
		|| strcmp(meat, "pork")
		|| strcmp(meat, "beef")
		|| strcmp(meat, "duck"))) return false;
	
	int sz = strlen(meat) + 1;
	Meat = new char[sz];
	strcpy_s(Meat, sz, meat);

	return true;
}

void MeatDish::Copy(const MeatDish& M)
{
	setMeat(M.Meat);
}

void MeatDish::Erase()
{
	delete Meat;
}

MeatDish::MeatDish()
{
	Meat = nullptr;
}

MeatDish::MeatDish(char** ingredients, int countingredients, int cookTime, char* meat) : Dish(ingredients, countingredients, cookTime)
{
	if (!setMeat(meat))
	{
		cout << "invalid Meat type" << endl;
		return;
	}
}

MeatDish::MeatDish(const MeatDish& M) : Dish(M)
{
	Copy(M);
}

MeatDish& MeatDish::operator=(const MeatDish& M)
{
	if (this != &M)
	{
		Erase();
		Copy(M);
		Dish::operator=(M);
	}
	return *this;
}

MeatDish::~MeatDish()
{
	Erase();
}

void MeatDish::PrintMeat()
{
	cout << Meat << endl;
}

void MeatDish::Print()
{
	Dish::Print();
	cout << Meat << endl;
}
