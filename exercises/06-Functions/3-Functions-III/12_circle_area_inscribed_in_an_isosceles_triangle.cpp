
// Problem #12 Circle Area Inscribed in an Isosceles Triangle

/* Write a program to calculate circle area Inscribed in an Isosceles Triangle,
then print it on the screen.
The use should enter :
a
b
Example Inputs :
20
10
Outputs:
47.124
*/

#include <iostream>
using namespace std;

double CircleAreaInTriangle(double a, double b) 
{
	double PI = 3.14159;
	return (PI * b * b / 4) * ((2 * a - b) / (2 * a + b));
}

int main()
{
	double x, y, PI = 3.14159;

	cout << "Enter a and b value below: \n";
	cin >> x;
	cin >> y;

	cout << "\n" << CircleAreaInTriangle(x, y);

	return 0;
}











