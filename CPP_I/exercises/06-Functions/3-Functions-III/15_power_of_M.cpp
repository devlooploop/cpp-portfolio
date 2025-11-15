
// Problem #15 Power of M

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


int PowerM(int base, int power) 
{
    return pow(base, power);
}


int main()
{

    int Number , M ;

    cout << "Enter the numbers\n";
    cin >> Number >> M;
   
    cout << PowerM(Number,M);

    return 0;
}





