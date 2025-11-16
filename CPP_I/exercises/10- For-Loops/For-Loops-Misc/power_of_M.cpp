// Problem - Power of M
// This program reads a number (Num) and a power (M),
// then prints Num^M.

#include <iostream>
using namespace std;

int main()
{
    int Num, M;
    long long Result = 1;   // Use long long for a bit more range

    cout << "Enter the number: ";
    cin >> Num;

    cout << "Enter the power (M): ";
    cin >> M;

    // Handle the case where M = 0
    if (M == 0)
    {
        Result = 1;  // Any number^0 = 1
    }
    else
    {
        for (int i = 1; i <= M; i++)
        {
            Result *= Num;
        }
    }

    cout << "\nOutput:\n" << Result << endl;

    return 0;
}
