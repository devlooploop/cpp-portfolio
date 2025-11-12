
// Half Number Problem
/*
Write a program to ask the user to enter:
• Number
Then Print the “Half of the <Number> is <???>”.
Example Inputs:
60
50
Outputs:
Half of 60 is 30
Half of 50 is 25
*/
#include <iostream>

using namespace std;

float Num, R, HalfNumber;

int main()
{
    cout << "Ente the Number\n";
    cin >> Num;
    HalfNumber = Num / 2;
    R = HalfNumber;
    cout << "Half of " << Num << " is " << R << endl;
}
