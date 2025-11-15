
// #2 Write a program to ask user to print user's name on the screen

#include <iostream>
#include<string>

using namespace std;

string printName(string Name) 
{
    return Name;
}

int main()
{
    string YourName;

    cout << "Enter your Name\n";
    getline(cin, YourName);

    cout << "\n" << printName(YourName);

    return 0;
}


