
// Problem #11 Circle Area Circumference

/*
Write a program to calculate circle area along the circumference, then print it on the screen.
The use should enter:
L
Example Inputs:
20
Outputs:
31.831
*/

#include <iostream>

using namespace std;

float CircleCircumference(float L) 
{
	float PI = 3.14;
	return  (L * L) / (4 * PI);
}

int main()
{
	float x, PI = 3.14;

	cout << "Enter The side L value\n";
	cin >> x;

	cout << CircleCircumference(x);

	return 0;
}













