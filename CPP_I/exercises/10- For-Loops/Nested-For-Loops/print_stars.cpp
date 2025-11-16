
// In star example - row(outer for Loop) x column(inner for Loop) 
// it's 10 x 10

#include <iostream>
using namespace std;


int main()
{
    for (int i = 1; i <= 10; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
            cout << "*";
        }

        cout << "\n";
    }

    return 0;
}