
// Problem - Power of M

/* Write a program to ask the user to enter:
• Number
• M
Then Print the Number^M
Example Inputs:
2
4
Outputs:
16 */

#include <iostream>
using namespace std;

void PowerOfM(int Num, int M)
{
    int  P = 1;

    if (M == 0)
    {
        cout << "\n" << P << "\n";
    }
    else
    {
        int i = 0;
        while (i != M)
        {
            P = P * Num;
            i++;
        }
        cout << P << "\n";
    }
}

int main()
{
    // if you enter 2^99 returns 0 is wrong due to not enough 
    // memory even though with bigger data type
   
    int Num, M;

    cout << "Enter the number\n";
    cin >> Num;
    cout << "Enter the Power M\n";
    cin >> M;

    PowerOfM(Num,M);

    return 0;

}



