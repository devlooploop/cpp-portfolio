
// Using Procedure & Functions
//Problem - Power of M

/* Write a program to ask the user to enter:
• Number
• M
Then Print the Number^M
Example Inputs:
2
4
Outputs:
16 
!!!!!! Due to the memory not enough to hold 100^80 it returns 0, even though
if bigger data type used!!!!!!!!!!
*/

#include <iostream>
using namespace std;

int PrintPowerOfNumber(int Num, int M)
{
    if (M == 0)
    {
        return 1;
    }
    else
    {
       int Power = 1;
        for (int i = 0; M != 0; i++)
        {
            Power = Power * Num;
            M = M - 1;
        }
        return Power;
    }
}

int main()
{
    int Number, M;

    cout << "Enter Number\n";
    cin >> Number;
    cout << "Enter M/Power\n";
    cin >> M;

   cout << "*********************************\n";
   
   cout << PrintPowerOfNumber(Number, M);

    return 0;
}
