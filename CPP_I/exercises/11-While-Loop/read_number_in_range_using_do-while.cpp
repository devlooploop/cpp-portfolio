
/*
---------------------------------------------------------
Program Requirement -  Do . . . While Loop
---------------------------------------------------------
Write a program that reads a number from the user within
a certain range (From–To) using two different validation
methods:

1. A function that uses a WHILE loop to validate input.
2. A function that uses a DO...WHILE loop to validate input.

The program must:
- Ask the user to enter a number between the given range.
- Keep asking until the number is valid.
- Return the valid number and print it in main().

Functions required:
- ReadNumberInRangeUsingWhile(int From, int To)
- ReadNumberInRangeUsingDoWhile(int From, int To)
---------------------------------------------------------
*/

#include <iostream>
using namespace std;

int ReadNumberInRangeUsingWhile(int From, int To)
{
    int Number;
    cout << "Please enter a number between  " << From << " and " << To << endl;
    cin >> Number;

    while (Number < From || Number > To)
    {
        cout << "Wrong Number ";
        cout << "Please enter a number between  " << From << " and " << To << endl;
        cin >> Number;
    }

    return Number;
}

int ReadNumberInRangeUsingDoWhile(int From, int To)
{
    int Number;

    do
    {
        cout << "Please enter a number between  " << From << " and " << To << endl;
        cin >> Number;

    } while (Number < From || Number > To);

    return Number;
}

int main()
{
    // Using While ....
    //cout << "The number you entered is " << ReadNumberInRangeUsingWhile(1,10);

    // Using Do...While
     cout << "The number you entered is " << ReadNumberInRangeUsingDoWhile(1, 10);
      
    return 0;
}





