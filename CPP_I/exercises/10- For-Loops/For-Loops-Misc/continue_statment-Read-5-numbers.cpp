
// Continue Statement
/*
H.W
Read 5 numbers and sum them up as long as the number is below 50 use
for loop and continue statement.
Input:
10
20
55
10
20
Output:
60
*/

#include <iostream>
using namespace std;

int ReadNumbers(int &Numbers)
{
    cout << "Enter the numbers" << endl;
    cin >> Numbers;

    return Numbers;
}

int SumNumbersBelow50(int Numbers)
{
    int sum = 0;
     
    for (int i = 1; i <= 5; i++)

    {
        ReadNumbers(Numbers);

        // continue condition
        if (Numbers > 50)
        {
            cout << "The number is greater than 50 and won't be calculated" << endl;
            continue;
        }

        sum += Numbers;
    }
    cout << "\n";
    return sum ;
}

int main()
{
    int x=0;
    
    cout <<  SumNumbersBelow50(x);

    return 0;
}





