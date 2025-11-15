
// Problem - Rectangle Area Diagonal Side
// use pow inside sqrt

/*
Write a program to calculate rectangle area through diagonal and side area of
rectangle and print it on the screen.
The use should enter:
a
d
Example Inputs:
5
40
Outputs:
198.431
*/


#include <iostream>
#include <cmath>
using namespace std;

int main() {
    float a, d, Area;

    cout << "Enter side and diagonal value:\n";
    cin >> a;
    cin >> d;

    Area = a * sqrt(pow(d, 2) - pow(a, 2));
    cout << Area << "\n";

    return 0;
}

