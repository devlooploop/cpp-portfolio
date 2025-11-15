
/*
// Problem-14 Power of 2,3,4

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

void PowerOfThreeInt() 
{
    int num;
    cout << "Enter a number\n";
    cin >> num;

    cout << "Output:" << "\n";
    cout << pow(num, 2) << endl << pow(num, 3) << endl << pow(num, 4) << "\n";
}

int main()
{
   // int a=0;

    PowerOfThreeInt();

    return 0;

}


