
// Circle Area Inscribed in an Isosceles Triangle Problem

/*
Write a program to calculate circle area Inscribed in an Isosceles Triangle,
then print it on the screen.
The use should enter:
Inputs:
  a → length of the equal sides
  b → base length

Example Inputs:
20
10
Outputs :
47.124
*/

#include <iostream>

using namespace std;

int main()
{
	float area, a, b, PI = 3.14159;

	cout << "Enter a and b value below: \n";
	cin >> a;
	cin >> b;

	area = (PI * b * b / 4) * ((2 * a - b) / (2 * a + b));
	cout << "Area of the inscribed circle: " << "\n" << area;

	return 0;
}












