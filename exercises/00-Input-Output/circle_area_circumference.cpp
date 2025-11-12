
// Circle Area Circumference Problem
/*
Write a program to calculate circle area along the circumference, then print it on the screen.
The user should enter:
L
Example Inputs:
20
Outputs:
31.831
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	float L, PI = 3.1415, area;

	cout << "Enter the circumference of the circle: \n";
	cin >> L;

	area = (L * L) / (4 * PI);
	//cout << fixed << setprecision(2) << area;
	cout << "Area of the circle: " << area;
}











