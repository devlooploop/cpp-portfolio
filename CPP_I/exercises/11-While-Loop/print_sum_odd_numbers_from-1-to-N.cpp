
/* 
Write a program to Sum odd numbers from 1 to N.
Input
10
Outputs:
25
*/

#include <iostream>
using namespace std;

int ReadNumber(int &N)
{
    cout << "Please Enter the number\n";
    cin >> N;
    return N;
}

void SumOddNumbers1ToN(int N)
{
    int sum = 0;
    int i = 1;

    {
        while (i <= N)
        {
            sum = sum + i;
            i += 2;
        }
        cout << "*********\n";
        cout << sum << "\n";
    }
}

int main()
{
    int Number;

    SumOddNumbers1ToN(ReadNumber(Number));


    return 0;
}
