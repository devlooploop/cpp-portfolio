
// while and for loop

#include <iostream>

using namespace std;

int main()
{
   
    cout << " For Loop\n";
    // for loop from 1 to 5
    for (int x = 1; x <= 5; x++)
    {
        cout << x << endl;
    }

    cout << " While Loop\n";
    // while loop from 1 to 5
    int i=1;
    while (i <= 5)
    {
        cout << i << endl;
        i++;
    }
    
    return 0;
}