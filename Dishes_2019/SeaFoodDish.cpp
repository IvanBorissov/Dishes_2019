#include <iostream>
#include "Dish.h"
#include "SeaFoodDish.h"
using namespace std;

void SeaFoodDish::setSeaFood(char* sfood)
{
	int sz = strlen(sfood) + 1;
	seafood = new char[sz];
	strcpy_s(seafood, sz, sfood);
}

void SeaFoodDish::Copy(const SeaFoodDish& S)
{
	setSeaFood(S.seafood);
}

void SeaFoodDish::Erase()
{
	delete seafood;
}

SeaFoodDish::SeaFoodDish()
{
	seafood = nullptr;
}

SeaFoodDish::SeaFoodDish(char** ingredients, int countIngredients, int cookTime, char* seaFood) : Dish(ingredients, countIngredients, cookTime)
{
	//Dish::Dish(ingredients, countIngredients, cookTime);
	setSeaFood(seaFood);
}

SeaFoodDish::SeaFoodDish(const SeaFoodDish& S) : Dish(S)
{
	Copy(S);
}

SeaFoodDish& SeaFoodDish::operator=(const SeaFoodDish& S)
{
	if (this != &S)
	{
		Erase();
		Copy(S);
		Dish::operator=(S);
	}
	return *this;
}

SeaFoodDish::~SeaFoodDish()
{
	Erase();
}

void SeaFoodDish::Print()
{
	Dish::Print();
	cout << seafood << endl;
}
