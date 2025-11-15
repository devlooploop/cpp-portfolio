// 
// Problem - Circle Area 
// after finding the result use ceil and print the final result.

/*
Write a program to calculate circle area then print it on the screen.
The use should enter:
r
Example Inputs:
5
Outputs :
78.54
*/

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    float r, Area, PI = 3.14159;

    cout << "Enter radius value:\n";
    cin >> r;


    Area = PI * pow(r, 2);
    cout << ceil(Area) << "\n";

    return 0;
}

