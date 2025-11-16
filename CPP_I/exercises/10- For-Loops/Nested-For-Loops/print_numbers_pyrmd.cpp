

/*

 #4 Same as hw # 3 but normal (Not invertesd) print numbers
1
1 2
1 2 3
...
1 2 3 4 5 6 7 8 9 10

*/
#include <iostream>
using namespace std;

int main()
{
    
    for (int i = 1; i <= 10; i++)
    {
        
        for (int j = 1; j <= i; j++)
        {
            cout << j << " ";
        }
        cout << "\n";
    }

    return 0;
}