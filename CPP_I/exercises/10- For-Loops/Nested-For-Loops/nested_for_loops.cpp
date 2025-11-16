/*
-----------------------------------------
Program Requirement:
-----------------------------------------
Write a program that displays the full
multiplication table from 1 to 10.

The program must:

1. Use a nested loop structure.
2. The outer loop should run from 1 to 10.
3. The inner loop should multiply the outer
   loop number by numbers from 1 to 10.
4. Print each result in the format:
       i * j = result
5. After each multiplication group,
   print a separator line.
-----------------------------------------
*/


#include <iostream>
using namespace std;

int main()
{
    for (int i = 1; i <= 10; i++)
    {
        cout << "i=" << i << endl;

        for (int j = 1; j <= 10; j++)
        {
            cout << i << " * " << j << " = " << i * j << "\n";
        }

        cout << "------------------\n";

    }

    return 0;
}