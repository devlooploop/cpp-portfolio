

/*

 Repeat H.W #2 instead of stars print numbers
 1 2 3 4 5 6 7 8 9 10
 1 2 3 4 5 6 7 8 9 
 1 2 3 4 5 6 7 8
 ...
 1

*/
#include <iostream>

using namespace std;

int main()
{
    
    for (int i = 10; i >= 1; i--)
    {
        
        for (int j = 1; j <= i; j++)
        {
            cout << j <<" ";
            
        }
        cout << "\n";
    }

    return 0;
}