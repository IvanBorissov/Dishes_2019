#include <iostream>
#include <cstring>
#include "Dish.h"
#include "MeatDish.h"
#include "SeaFoodDish.h"
#include "SurfAndTurf.h"
using namespace std;

SurfAndTurf::SurfAndTurf() : MeatDish(), SeaFoodDish()
{
}

SurfAndTurf::SurfAndTurf(char** ingredients, int countIngredients, int cookTime, char* meat, char* seafood) : MeatDish(ingredients, countIngredients, cookTime, meat), SeaFoodDish(ingredients, countIngredients, cookTime, seafood)
{
}

SurfAndTurf::SurfAndTurf(const SurfAndTurf& S) : MeatDish(S), SeaFoodDish(S)
{
}

SurfAndTurf::~SurfAndTurf()
{
}

void SurfAndTurf::Print()
{
	Dish::Print();
	MeatDish::PrintMeat();
	SeaFoodDish::PrintSeaFood();
}
