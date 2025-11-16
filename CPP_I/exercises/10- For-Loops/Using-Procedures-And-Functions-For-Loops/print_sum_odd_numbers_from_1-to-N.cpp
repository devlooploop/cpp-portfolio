
// Using Procedure & Functions
/* 
Write a program to Sum odd numbers from 1 to N.
Input
10
Outputs:
25
*/

#include <iostream>
using namespace std;

int SumOddNumbers(int N)
{
    int i = 0, sum=0;

    for (int i = 1; i <= N; i++)
    {
        if (i % 2 != 0)
        {
            sum = sum + i; 
        }
    }
    
    return sum;
}

int main()
{
    int N;

    cout << "Enter N\n";
    cin >> N;

    cout << "The sum is:" << SumOddNumbers(N);

    return 0;
}
