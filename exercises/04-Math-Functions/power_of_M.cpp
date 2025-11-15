// 
// Problem - Power of M
// after finding the result use round and print the final results

/*
Write a program to ask the user to enter:
• Number
• M
Then Print the Number^M
Example Inputs:
2
4
Outputs:
16
*/

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int Number, M;

    cout << "Enter the number\n";
    cin >> Number >> M;

    Number = pow(Number, M);

    cout << "\nOutput:" << "\n" << round(Number) << "\n";

    return 0;

}









