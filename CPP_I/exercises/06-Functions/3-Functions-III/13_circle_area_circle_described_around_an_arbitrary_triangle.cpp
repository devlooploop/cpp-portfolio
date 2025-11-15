
// Problem #13 Circle Area circle Described Around an Arbitrary Triangle

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
40.088
*/

#include <iostream>
#include <cmath>
using namespace std;

double CircleAreaAroundTringle(double a, double b, double c) 
{

    double T, p, Area, PI = 3.14159;

    p = (a + b + c) / 2;
    T = (a * b * c) / (4 * sqrt(p * (p - a) * (p - b) * (p - c)));
    
    Area = PI * T * T;

    return Area;
}

int main() {
    double x, y, z, T, p, PI = 3.14159;

    cout << "Enter The Value:\n";
    cin >> x >> y >> z;

    cout << CircleAreaAroundTringle(x, y, z) << "\n";

    return 0;
}

