
// Example #2 else ....Conditional Statements

#include <iostream>
#include <string>
using namespace std;

int main()
{
    int x;

    cout << "Please enter your number? \n";
    cin >> x;

    if (x > 5 )
    {
        cout << "Yes, x is greater than 5" << endl;
    }
    else
    {
        cout << "No, x is less than 5 " << endl;
    }

    cout << "The code after if body always executed" << endl;

    return 0;
}