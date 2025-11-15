
// Problem - Circle Area Along the Circumference
// after finding the result use floor() and print the final result

/*
Write a program to calculate circle area along the circumference, then print it on the screen.
The use should enter:
L
Example Inputs:
20
Outputs :
31.831

*/

#include <iostream>
#include <cmath>

using namespace std;

int main() 
{
    float L, Area, PI = 3.14159;

    cout << "Enter The Value:\n";
    cin >> L;

    Area = pow(L, 2) / (PI * 4);

    cout << floor(Area) << "\n";

    return 0;
}

