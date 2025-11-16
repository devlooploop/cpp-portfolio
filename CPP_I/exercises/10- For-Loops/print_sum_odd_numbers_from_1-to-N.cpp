
/* Problem : 
Write a program to Sum odd numbers from 1 to N.
Input
10
Outputs:
25  
*/

#include <iostream>
using namespace std;

int main()
{
    int N, sum=0, i=0;

    cout << "Enter N\n";
    cin >> N;
  
    for (int i = 1; i <= N; i++)
        
        if (i % 2 != 0)
        {
            sum = sum + i;
        }
    cout << "The sum is : " << sum;
       
     return 0;
}
