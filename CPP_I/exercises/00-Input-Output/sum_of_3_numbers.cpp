// Sum of three numbers Problem

/*
Write a program to ask the user to enter:
• Number1, Number2, Number3
Then Print the Sum of entered numbers
Example Inputs:
10
20
30
Outputs:
60
*/

#include <iostream>

using namespace std;

int main()
{
    short int Num1, Num2, Num3, sum;

    cout << "Enter Num1\n";
    cin >> Num1;
    cout << "Enter Num2\n";
    cin >> Num2;
    cout << "Enter Num3\n";
    cin >> Num3;

    sum = Num1 + Num2 + Num3;
    cout << sum;

    return 0;
}


