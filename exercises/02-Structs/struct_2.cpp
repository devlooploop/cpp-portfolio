
// Structures
// Example #2

#include <iostream>
#include <string>

using namespace std;

struct Car
{
	string Brand;
	string Model;
	int Year;
};


int main()
{

	Car MyCar1, MyCar2, X;

	MyCar1.Brand = "BMW";
	MyCar1.Model = "X5";
	MyCar1.Year  = 2000;

	MyCar2.Brand = "Ford";
	MyCar2.Model = "Mustang";
	MyCar2.Year  = 2022;

	X.Brand = "Jeep";
	X.Model = "Cherokee";
	X.Year = 1988;

	cout << MyCar1.Brand << " " << MyCar1.Model << " " << MyCar1.Year << "\n";
	cout << MyCar2.Brand << " " << MyCar2.Model << " " << MyCar2.Year << endl;
	cout << X.Brand << " "<< X.Model << " " << X.Year << "\n";

	return 0;
}












