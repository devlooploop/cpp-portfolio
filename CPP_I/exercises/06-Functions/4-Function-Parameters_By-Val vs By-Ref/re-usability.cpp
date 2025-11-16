
// Structures and Functions - Re-usability.

#include <iostream>
#include <string>

using namespace std;

struct stInfo 
{
    string FirstName;
    string LastName;
    int    Age;
    string Phone;
};

void ReadInfo(stInfo &Info) 
{

    cout << "Enter your first name\n";
    cin >> Info.FirstName;

    cout << "Enter your last name\n";
    cin >> Info.LastName;

    cout << "Enter your age\n";
    cin >> Info.Age;

    cout << "Enter your phone \n";
    cin >> Info.Phone;
}

void PrintInfo(stInfo PersonID)
{
    cout << "\n********************************************\n";

    cout << "First Name: " << PersonID.FirstName << endl;
    cout << "Las Name: " << PersonID.LastName << endl;
    cout << "Age:  " << PersonID.Age << endl;
    cout << "Phone: " << PersonID.Phone << endl;

    cout << "\n********************************************\n";

}


int main()
{
    // Defines a variable (Person #1) of data type stInfo
    stInfo Person1Info;
    ReadInfo(Person1Info);
    PrintInfo(Person1Info);

    // Person #2
    stInfo Person2Info;
    ReadInfo(Person2Info);
    PrintInfo(Person2Info);

    return 0;
}





