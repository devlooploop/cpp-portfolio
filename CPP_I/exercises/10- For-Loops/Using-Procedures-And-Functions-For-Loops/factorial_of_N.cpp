
// Using Procedure & Functions
/* Problem - Factorial of N

Write a program to calculate factorial of N!
Example: factorial of 6 --> 6 x 5 x 4 x 3 x 2 x 1 = 720

Input
6
Outputs:
720

*/

#include <iostream>
using namespace std;

int PrintFactorial(int Num)
{
    int N=1;

    for (int i = 1; Num != 1; i++)
    {
        N = Num * N;
        Num = Num - 1;
    }
   return N;
}

int main()
{
    int F, N=1;

    cout << "Enter N\n";
    cin >> F;

   cout <<"Factorial of !" << F << " = " << PrintFactorial(F);

    return 0;
}
