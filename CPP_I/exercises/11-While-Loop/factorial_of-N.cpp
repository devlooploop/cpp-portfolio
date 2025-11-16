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

int FactorialOfNum(int N)
{
    int i = 0;
    int Factorial = 1;

    while (N != 0)
    {
        Factorial = Factorial * N;
        N = N - 1;
        i++;
    }
    return Factorial;
}

int main()
{
    int N;

    cout << "Enter N\n";
    cin >> N;

    cout << "Factorial : " << FactorialOfNum(N);

    return 0;
}


