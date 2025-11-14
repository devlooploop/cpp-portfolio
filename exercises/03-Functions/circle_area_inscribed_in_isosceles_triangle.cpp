
// Problem - Circle Area Inscribed in an Isosceles Triangle
// after finding the result use floor() and print the final result

/*
Write a program to calculate circle area Inscribed in an Isosceles Triangle,
then print it on the screen.
The use should enter:
a
b
Example Inputs:
20
10
Outputs :
47.124
*/

#include <iostream>
#include <cmath>

using namespace std;

int main() 
{
    float a, b, Area, PI = 3.14159;

    cout << "Enter The Value:\n";
    cin >> a;
    cin >> b;

    Area = PI * (pow(b, 2) / 4) * ((2 * a - b) / (2 * a + b));

    cout << floor(Area) << "\n";

    return 0;
}

