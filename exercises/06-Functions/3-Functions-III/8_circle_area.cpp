
// Problem #8 Circle Area

/*
Write a program to calculate circle area then print it on the screen.
The use should enter:
r
Example Inputs:
5
Outputs :
78.54
*/

#include <iostream>
#include <cmath>

using namespace std;

double CircleArea(double r) 
{
	double PI = 3.14;
	return PI * (r * r);
}

int main() 
{

	double r;

	cout << "Enter radius value:\n";
	cin >> r;

	cout << endl << CircleArea(r);

	return 0;
}