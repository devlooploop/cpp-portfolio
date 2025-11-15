
// Swap Numbers Problem

/*
Write a program to ask the user to enter:
• Number1
• Number2
Then print the two numbers , then Swap the two numbers and print them
Example Inputs:
10
20
Outputs:
10
20

20
10
*/

#include <iostream>

using namespace std;

int main()
{
    short int num1, num2, temp;

    cout << "Enter Number 1: \n";
    cin >> num1;
    
    cout << "Enter Number 2: \n";
    cin >> num2;

    temp = num1;
    num1 = num2;
    num2 = temp;

    cout << "\n" << num1 << endl;
    cout << num2 << "\n";

    return 0;
}




