
// Problem - Power of 2,3,4
//after finding the result use round() and print the final results

/*
Write a program to ask the user to enter:
• Number
Then Print the Number^2 , Number^3 , Number^4
Example Inputs:
3
Outputs:
9
27
81
*/

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int num, num2, num3, num4;

    cout << "Enter a number\n";
    cin >> num;

    num2 = pow(num, 2);
    num3 = pow(num, 3);
    num4 = pow(num, 4);

    cout << "\n Output:" << "\n" << round(num2) << "\n" << round(num3) << "\n" << round(num4) << "\n";

    return 0;

}





