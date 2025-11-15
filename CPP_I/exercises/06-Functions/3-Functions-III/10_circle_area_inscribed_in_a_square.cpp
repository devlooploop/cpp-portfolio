
// Problem #10 Circle Inscribed Square 
/*
Write a program to calculate Circle area inscribed in a square, then print it on the screen.
The use should enter:
A
Example Inputs:
10
Outputs :
78.54
*/

#include <iostream>
#include <cmath>
using namespace std;

// Circle area inscribed in a square
double CircleArea(double A) 
{
	double PI = 3.14;
	return (PI * A * A) / 4;
}

int main()
{
	double A;

	cout << "Enter side A value\n";
	cin >> A;

	cout << "\n" << CircleArea(A);

	return 0;

}












