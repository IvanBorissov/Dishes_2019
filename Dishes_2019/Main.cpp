#include <iostream>
#include "Dish.h"
#include "MeatDish.h"
#include "SeaFoodDish.h"
#include "SurfAndTurf.h"
using namespace std;

int main()
{
	char** ingr = new char* [5];
	ingr[0] = new char[5];
	strcpy_s(ingr[0], 5, "Salt");

	ingr[1] = new char[7];
	strcpy_s(ingr[1], 7, "Pepper");

	ingr[2] = new char[9];
	strcpy_s(ingr[2], 9, "Rosemary");

	ingr[3] = new char[9];
	strcpy_s(ingr[3], 9, "Potatoes");

	ingr[4] = new char[5];
	strcpy_s(ingr[4], 5, "Love");


	Dish A(ingr, 5, 20);
	Dish B = A;
	Dish C;
	
	C = B;
	A.Print();
	cout << "/----------------" << endl;
	B.Print(); 
	cout << " /---------------------" << endl;
	C.Print();
	cout << " /-----------------------" << endl;

	char* meat = new char[5];
	char* fish = new char[7];

	strcpy_s(meat, 5, "pork");
	strcpy_s(fish, 7, "Salmon");

	MeatDish M(ingr, 5, 40, meat);
	SeaFoodDish S(ingr, 5, 30, fish);

	M.Print();
	cout << "/----------------" << endl;
	S.Print();
	cout << "/--------------------" << endl;

	MeatDish M2 = M;
	SeaFoodDish S2 = S;

	M2.Print();
	cout << "/-----------------" << endl;
	S2.Print();
	cout << "/----------------------" << endl;

	SurfAndTurf Surf(ingr, 5, 50, meat, fish);

	Surf.Print();
	cout << "/---------------------------" << endl;

	Dish* DishPtr = new MeatDish(ingr, 5, 40, meat);

	DishPtr->Print();

	delete DishPtr;
	delete[] meat;
	delete[] fish;
	for (int i = 0; i < 5; i++)delete[] ingr[i];
	delete[] ingr;

	return 0;
}