
/*

H.W #6 Print numbers as
 1 2 3 4 5 6 7 8 9 10
 2 3 4 5 6 7 8 9 10
 3 4 5 6 7 8 9 10
 ....
 10

*/
#include <iostream>

using namespace std;

int main()
{
    for (int i = 1; i <= 10; i++)
    {

        for (int j = i; j <= 10; j++)
        {
            cout << j << " ";

        }

        cout << "\n";

    }
    /*for (int i = 2; i <= 11; i++)
    {

        for (int j = i - 1; j <= 10; j++)
        {
            cout << j << " ";

        }

        cout << "\n";

    }*/
    // Another solution 
    
    return 0;
}