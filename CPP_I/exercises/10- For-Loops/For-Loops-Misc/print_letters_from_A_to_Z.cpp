
// Problem - Print Letters from A to Z

/* Write a program to print all letters from A to Z
Outputs:
A ... Z
*/

#include <iostream>
using namespace std;

int main()
{

    for (int i = 65; i < 90; i++)
    {
        cout << " " << char(i) << "\n";
    }
         
    for (int i = 97; i < 122; i++)
    {
        cout << "\n" << char(i) ;
    }

    return 0;

}



