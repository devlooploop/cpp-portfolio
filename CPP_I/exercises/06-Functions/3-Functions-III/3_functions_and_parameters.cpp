
// Example #3 functions vs procedures

#include <iostream>
#include<string>

using namespace std;

// We put 2 parameters so it prompt the user to enter two values
int MySumFunction(int Number1, int Number2) {   // This is Function it has  <return> 

    return Number1 + Number2;
}

int main()
{
    int x,y;

    cout << "\nPlease enter Number1\n";
    cin >> x;
    cout << "\nPlease enter Number2\n";
    cin >> y;

    cout << "***************************\n";
    cout << MySumFunction(x,y);
    
    // Functions treated as variabls it can be used with operations as shown here
    // cout << MySumFunction() + 10 / 20;
    
    return 0;
}