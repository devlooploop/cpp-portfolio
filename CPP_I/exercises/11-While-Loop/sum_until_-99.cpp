
/* Write a program to read numbers from user and sum them, 
keep reading until the user enters -99 then print
the Sum on screen.
Input
10
20
30
40
-99
Outputs:
100
*/

#include <iostream>

using namespace std;

int ReadN(int &N)
{  
    cout << "Enter the N\n";
    cin >> N;
    return N;
}

void SumReadNumbers(int N)
{
    int Sum = 0;

    while (N != -99)
    {
        Sum = Sum + N;
        cin >> N;
    }

    cout << "\n" << Sum;
}

int main()
{
    int x;
   
    SumReadNumbers(ReadN(x));
   
    return 0;
}



