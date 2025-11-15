
// Problem #6 Rectangle Area

/*
Write a program to calculate rectangle area and print it on the screen.
Example Inputs:
10
20
Outputs:
200
*/

#include <iostream>
#include <cmath>
using namespace std;


float RectangleArea(float a, float b) 
{
	return a * b;
}


int main() 
{
	float x, y;

	cout << "Enter the sides of Rectangle a and b: \n";
	cin >> x;
	cin >> y;

	cout << "\nThe Area of Rectangle is: " << RectangleArea(x, y);

	return 0;
}