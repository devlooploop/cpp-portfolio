
// Circle Inscribed Square Problem

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
#include <iomanip>

using namespace std;

int main()
{
	float area, A = 0, PI = 3.1415;

	cout << "Enter the side length of the square: ";
	cin >> A;

	area = (PI * A * A) / 4;

	cout << "Area of the inscribed circle: ";
	cout << "\n" << fixed << setprecision(2) << area;

	return 0;

}









