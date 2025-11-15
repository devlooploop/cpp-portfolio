
// Average of 3 Marks Problem

/*
Write a program to ask the user to enter:
• Mark1, Mark2, Mark3
Then Print the Average of entered Marks
Example Inputs:
90
80
70
Outputs:
80
*/

#include <iostream>

using namespace std;

int main()
{
    unsigned short int mark1, mark2, mark3, avg;

    cout << "Enter the marks below:\n";
    cout << "Enter mark 1\n";
    cin >> mark1;
    cout << "Enter mark 2\n";
    cin >> mark2;
    cout << "Enter mark 3\n";
    cin >> mark3;
    cout << "\n";

    avg = (mark1 + mark2 + mark3) / 3;
    cout << "The average is " << avg;
}


