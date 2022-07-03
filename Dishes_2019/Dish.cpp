#include <iostream>
#include <cstring>
#include "Dish.h"

using std::cin;
using std::cout;
using std::endl;

bool Dish::setIngredients(char** ingredients, int countIngredients)
{
	if (countIngredients > 100)
	{
		cout << "Too much ingredients" << endl;
		return false;
	}

	int sz = 0;
	cntIngredient = countIngredients;
	ingredintsNames = new char* [countIngredients];
	for (int i = 0; i < countIngredients; i++)
	{
		sz = strlen(ingredients[i]) + 1;
		ingredintsNames[i] = new char[sz];
		strcpy_s(ingredintsNames[i], sz, ingredients[i]);
	}

	return true;
}

void Dish::Copy(const Dish& D)
{
	if (!setIngredients(D.ingredintsNames, D.cntIngredient))return;
	cookTime = D.cookTime;
}

void Dish::Erase()
{
	for (int i = 0; i < cntIngredient; i++)
	{
		delete[] ingredintsNames[i];
	}
	delete ingredintsNames;
}

Dish::Dish()
{
	ingredintsNames = nullptr;
	cookTime = 0;
	cntIngredient = 0;
}

Dish::Dish(char** ingredients, int countIngredients, int CookTime)
{
	if (!setIngredients(ingredients, countIngredients))return;
	cookTime = CookTime;
}

Dish::Dish(const Dish& D)
{
	Copy(D);
}

Dish& Dish::operator=(const Dish& D)
{
	if (this != &D)
	{
		Erase();
		Copy(D);
	}

	return *this;
}

Dish::~Dish()
{
	Erase();
}

void Dish::print()
{
	for (int i = 0; i < cntIngredient; i++)
	{
		cout << ingredintsNames[i] << endl;
	}
}
