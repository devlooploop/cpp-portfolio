 
// Triangle Area Problem

/*
Write a program to calculate the area of a triangle and print it on the screen.
The user should enter:
a  -> base
h  -> height

Example Input:
10
8
Output:
40
*/


#include <iostream>

using namespace std;

int main()
{
	double a, h, area;

    cout << "Enter the base of the triangle: ";
    cin >> a;

    cout << "Enter the height of the triangle: ";
    cin >> h;

    area = (a * h) / 2.0;

    cout << "\nThe area of the triangle is: " << area << endl;

    return 0;

}






