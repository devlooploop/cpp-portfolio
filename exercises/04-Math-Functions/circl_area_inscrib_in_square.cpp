// 
// Problem - Circle Area Inscribed in a Square
// after finding the result use ceil and print the final result.

/*
Write a program to calculate Circle area inscribed in a square, then print it on the screen.
The use should enter:
A
Example Inputs:
10
Outputs :
79
*/

#include <iostream>
#include <cmath>

using namespace std;

int main() 
{
    float A, Area, PI = 3.14159;

    cout << "Enter The Value:\n";
    cin >> A;

    //Area =  PI * pow((A/2),2);
    Area = (PI * pow(A, 2)) / 4;

    cout << ceil(Area) << "\n";

    return 0;
}




