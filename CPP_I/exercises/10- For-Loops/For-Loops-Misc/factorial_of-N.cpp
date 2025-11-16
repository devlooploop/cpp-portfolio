
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

int main()  
{
    int N, Factorial=1;

    cout << "Enter N\n";
    cin >> N;
  
    for (int i = 0; N != 0; i++)
    {
        {
            Factorial = Factorial * N;
            N = N - 1;
        }
    }
    
    cout << "Factorial : " << Factorial;  
       
     return 0;
}
