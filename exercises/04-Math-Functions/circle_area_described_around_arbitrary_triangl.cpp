
//Problem - Circle Area circle Described Around an Arbitrary Triangle
//after finding the result use round() and print the final results

/*
Write a program to calculate circle area circle described around an arbitrary triangle,
then print it on the screen.
The use should enter:
a
b
C
Example Inputs:
5
6
7
Outputs :
40 
*/

#include <iostream>
#include <cmath>

using namespace std;

int main() {

    double a, b, c, T, p, Area, PI = 3.14159;

    cout << "Enter The Value:\n";
    cin >> a >> b >> c;

    p = (a + b + c) / 2;

    T = (a * b * c) / (4 * sqrt(p * (p - a) * (p - b) * (p - c)));

    Area = PI * pow(T, 2);

    cout << round(Area) << "\n";

    return 0;
}

