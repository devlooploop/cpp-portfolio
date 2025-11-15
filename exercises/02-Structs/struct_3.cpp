// Structures

// Example #3 - struct

#include <iostream>
#include <string>

using namespace std;

struct stAddress
{
	string Street1;
	string POBOX;
};

struct stOwner 
{
	string FullName;
	string Phone;
	stAddress Adress;

};

struct Car
{
	string Brand;
	string Model;
	int Year;
	stOwner Onwer;
};


int main()
{

	Car MyCar1, MyCar2, X;

	MyCar1.Brand = "BMW";
	MyCar1.Model = "X5";
	MyCar1.Year  = 2000;

	MyCar1.Onwer.FullName = "Bobo Dicky";
	MyCar1.Onwer.Phone = "44-55-66-77";

	MyCar1.Onwer.Adress.POBOX ;

	cout << MyCar1.Brand << " " << MyCar1.Model << " " << MyCar1.Year << "\n";
	cout << MyCar1.Onwer.FullName << endl;
	cout << MyCar1.Onwer.Phone << endl;

	return 0;
}












