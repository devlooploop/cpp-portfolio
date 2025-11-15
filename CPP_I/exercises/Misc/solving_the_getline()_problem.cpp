
// Solving the getline() Problem

#include <iostream>
#include<string>

using namespace std;


int main()
{
    int Num;
    string Name;
    string Country;

    cout << "Enter Emplyee Number?\n";
    cin >> Num;

    cout << "Enter Name?\n";

    // using ignore() to solve getline \n input problem when Enter is pressed 
    cin.ignore(1, '\n');
    getline(cin, Name);

    cout << "Enter Country?\n";
    cin >> Country;

    cout << "\nNumber: " << Num << ", Name: " << Name << " Country: " << Country;

    return 0;
}