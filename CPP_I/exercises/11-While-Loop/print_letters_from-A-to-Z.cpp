
// Problem - Print Letters from A to Z

/* Write a program to print all letters from A to Z
Outputs:
A ... Z
*/

#include <iostream>
using namespace std;

void PrintAtoZUpperCase()
{
    int i = 65;
    while (i <= 90)
    {
        cout << " " << char(i) << "\n";
        i++;
    }
    cout << "\n";
}

void PrintAtoZLowerCase()
{
   
    int j = 97;
    while (j <= 122)
    {
        cout << "\n" << char(j);
        j++;
    }
    cout << "\n";
}

int main()
{
    PrintAtoZUpperCase();
    PrintAtoZLowerCase();

    return 0;
}







