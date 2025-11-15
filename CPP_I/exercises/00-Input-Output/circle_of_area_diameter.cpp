
//  Circle Of Area Diameter Problem
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
#include <iomanip>

using namespace std;

int main()
{
    float D, area;
    float PI = 3.1415;

    cout << "Enter the diameter of the circle: \n";
    cin >> D;

    area = (PI * D * D) / 4;

    // in the solution printed area is 78.54 while here is 78.50
   //  cout << "\n" << fixed << setprecision(2) << area; //*** Output 78.50
    // cout << ceil(area);

    cout << "\nArea of the circle: \n";
    cout << area; 

    return 0;
}








