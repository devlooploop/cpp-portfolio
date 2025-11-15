// Strings
// Example #2 read white space Strings

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string FullName;

    // cin will read the string until the 1st white space
    // that's why it will read only one name and not the FULL NAME
    // To solve this problem we use function getline(cin, FullName);

    cout << "Enter your Full Name" << endl;
    getline(cin, FullName);

    cout << "Your Full Name is: " << FullName << endl;

    return 0;
}