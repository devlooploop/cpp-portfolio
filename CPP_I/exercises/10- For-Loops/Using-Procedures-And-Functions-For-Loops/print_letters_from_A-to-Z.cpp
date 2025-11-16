
// Using Procedure & Functions
// Problem - Print Letters from A to Z

/* Write a program to print all letters from A to Z
Outputs:
A ... Z
a ... z
    */

#include <iostream>
using namespace std;

void PrintCapitalLetters() 
{
    for (int i = 65; i < 91; i++)
    {
        cout  << char(i) << "\n";
    }
}

void PrintSmallLetters() 
{

    for (int i = 97; i  < 123; i++)
    {
        cout << char(i) << "\n";
    }
}


int main()
{
    PrintCapitalLetters();
    PrintSmallLetters();

    return 0;
}



