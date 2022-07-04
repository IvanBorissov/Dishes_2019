#pragma once
 
#include "Dish.h"
#include "MeatDish.h"
#include "SeaFoodDish.h"

class SurfAndTurf : virtual public MeatDish, virtual public SeaFoodDish
{
public:
	SurfAndTurf();
	SurfAndTurf(char**, int, int, char*, char*);
	SurfAndTurf(const SurfAndTurf&);
	virtual ~SurfAndTurf();
	virtual void Print();
};