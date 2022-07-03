#pragma once

class Dish
{
private:
	char** ingredintsNames;
	int cntIngredient;
	int cookTime;

	bool setIngredients(char**, int);
	void Copy(const Dish&);
	void Erase();
public:
	Dish();
	Dish( char**, int, int);
	Dish(const Dish&);
	Dish& operator=(const Dish&);
	virtual ~Dish();
	virtual void Print();
};