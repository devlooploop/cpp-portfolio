

// Problem - Circle Area Through Diameter 
// after finding the result use ceil and print the final result.

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
#include <cmath>

using namespace std;

int main() {
    float D, Area, PI = 3.14159;

    cout << "Enter radius value:\n";
    cin >> D;


    Area = PI * pow(D, 2) / 4;
    cout << ceil(Area) << "\n";

    return 0;
}




