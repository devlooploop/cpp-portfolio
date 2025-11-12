
// Problem #31 Power of 2,3,4 
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

using namespace std;

int main()
{
    int num, num2, num3, num4;

    cout << "Enter a number\n";
    cin >> num;
    
    num2 = num * num;
    num3 = num * num * num;
    num4 = num * num * num * num;

    cout << "Output :\n" << num2 << "\n" << num3 << "\n" << num4;

    return 0;

}















