
// Continue Statement

#include <iostream>
using namespace std;

int main()
{
    for (int i = 1; i <= 5; i++)
    {
        //  Condition to continue  
        if (i == 3) 
        {
            continue;
        }

        cout << i << endl;
    }

    return 0;
}





