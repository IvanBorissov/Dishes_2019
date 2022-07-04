#pragma once

#include "Dish.h"

class SeaFoodDish : public Dish
{
private:
	char* seafood;

	void setSeaFood(char*);
	void Copy(const SeaFoodDish&);
	void Erase();
public:
	SeaFoodDish();
	SeaFoodDish(char**, int, int, char*);
	SeaFoodDish(const SeaFoodDish&);
	SeaFoodDish& operator=(const SeaFoodDish&);
	virtual ~SeaFoodDish();
	
	void PrintSeaFood();
	void Print();
};