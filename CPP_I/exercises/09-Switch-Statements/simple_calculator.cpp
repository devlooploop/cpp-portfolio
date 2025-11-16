
// Switch .. Case Statement
// Problem - Simple Calculator

/*
Write a program to ask the user to enter:
• Number 1
• Number 2
• OperationType
Then perform the calculation according to the Operation Type as follows:
• “+” : add the two numbers.
• “-” : Subtract the two numbers.
• “*” : Multiply the two numbers.
• “/” : Divide the two numbers.
Example Inputs:
10
20
*
Outputs:
200
*/

#include <iostream>
using namespace std;


int main()
{

    int  Number1, Number2;
    char   OperationType;
    
    cout << "Enter Number 1: \n";
    cin >> Number1;
    cout << "Enter Number 2: \n";
    cin >> Number2;

    cout << "Enter the Operation Type: \n";
    cin >> OperationType;

    switch (OperationType)
    {
    case '+':
        cout << Number1 + Number2;
        break;
    case '-':
        cout << Number1 - Number2;
        break;
    case '*':
        cout << Number1 * Number2;
        break;
    case '/':
        cout << Number1 / Number2;
        break;

    default:
        cout << "Wrong Operation type Please enter right ops type\n";
        break;
    }

    return 0;
}