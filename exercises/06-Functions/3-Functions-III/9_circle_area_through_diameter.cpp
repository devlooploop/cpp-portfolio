
// Problem #9 Circle Of Area Through Diameter

/*
Write a program to calculate circle area through diameter, then print it on the screen.
The use should enter:
D
Example Inputs:
10
Outputs :
78.54

*/

#include <iostream>

using namespace std;

float CircleAreaDiameter(float D) 
{
    float PI = 3.14;
    return (PI * D * D) / 4;
}

int main()
{
    float PI = 3.14, X;

    cout << "Enter the diameter value\n";
    cin >> X;
    cout << endl << CircleAreaDiameter(X);

    return 0;
}













