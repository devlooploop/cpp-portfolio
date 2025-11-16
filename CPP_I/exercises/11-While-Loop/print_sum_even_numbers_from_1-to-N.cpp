
/* 
Write a program to Sum even numbers from 1 to N.
Input
10
Outputs:
30
*/

#include <iostream>
using namespace std;

int ReadNumber(int& N)
{
    cout << "Please Enter the number\n";
    cin >> N;
    return N;
}

void SumEvenNumbers1ToN(int N)
{
    int sum = 0;
    int i = 0;

    while (i <= N)
    {
        sum = sum + i;
        i += 2;
    }
    cout << "The sum is : " << sum;
}

int main()
{
    int number;

    SumEvenNumbers1ToN(ReadNumber(number));
   
    return 0;
}



