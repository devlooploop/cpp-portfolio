
// Read positive Number

#include <iostream>
using namespace std;

int main()
{
    int Number;
    cout << "Please enter a positive number?\n";
    cin >> Number;

    while (Number < 0)
    {
        cout << "Wrong Number, Please Enter a positive Number ?\n";
        cin >> Number;
    }

    cout << "\n The number you entered is " << Number << endl;
    
    return 0;
}