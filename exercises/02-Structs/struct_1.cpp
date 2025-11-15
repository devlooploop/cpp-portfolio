
//  Structures

// Example #1

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

	Car MyCar1;

	MyCar1.Brand = "BMW";
	MyCar1.Model = "X5";
	MyCar1.Year  = 2000;

	cout << MyCar1.Brand << " " << MyCar1.Model << " " << MyCar1.Year << "\n";

	return 0;
}












