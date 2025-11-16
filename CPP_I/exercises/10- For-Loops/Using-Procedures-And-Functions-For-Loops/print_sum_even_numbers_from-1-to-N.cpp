
// Using Procedure & Functions
/*  
Write a program to Sum even numbers from 1 to N.
Input
10
Outputs:
30
*/

#include <iostream>
using namespace std;

int PrintSumEvenNumbers(int N)
{
    int  sum=0;

    for (int i = 0; i <= N; i++)
    {
        if (i % 2 == 0)
        {
            sum = sum + i;
        }
    }
    return sum;
}

int main()
{
    int Num;

    cout << "Enter N\n";
    cin >> Num;

    cout << "The sum is : " << PrintSumEvenNumbers(Num);

    return 0;
}
