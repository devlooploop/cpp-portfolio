
/* 
------------------------------------------------------------
Program Requirement
------------------------------------------------------------
Write a program that uses:
- Arrays 
- Structures 
- Functions

The program should store information for N persons 
(where N is from 1 to 100). 

You must:
1. Ask the user how many persons they want to enter.
2. Read each person’s info using ReadInfo().
3. Store all persons inside ArryPersons[100].
4. Print all persons’ info using PrintInfo().
5. Use a for-loop inside ReadArryPersonsInfo() and 
   PrintArryPersonsInfo() to handle N persons.
   
NOTE:
- Only modify the ReadInfo() and PrintInfo() functions 
  to work properly with the array.
- Do NOT modify any other part of the given program structure.
------------------------------------------------------------
*/


#include <iostream>
#include <string>
using namespace std;

struct strInfo
{
    string FirstName;
    string LastName;
    int Age;
    string Phone;
};

void ReadInfo(strInfo& Info)
{

    cout << "Please enter FirstName?\n";
    cin >> Info.FirstName;

    cout << "Please enter LastName?\n";
    cin >> Info.LastName;

    cout << "Please enter Age?\n";
    cin >> Info.Age;

    cout << "Please enter Phone?\n";
    cin >> Info.Phone;
    cout << "****************************\n";

}

void PrintInfo(strInfo Info)
{

    cout << "\n**********************************\n";

    cout << "FirstName: " << Info.FirstName << endl;
    cout << "LastName: " << Info.LastName << endl;
    cout << "Age: " << Info.Age << endl;
    cout << "Phone: " << Info.Phone << endl;

}

void ReadArryPersonsInfo(strInfo ArryPersons[100], int& NumberOfPersons)
{

    cout << "Enter the number of Persons 1-100: \n";
    cin >> NumberOfPersons;

    for (int i = 0; i <= NumberOfPersons - 1; i++)
    {
        cout << "Enter Persons' " << i + 1 <<" Info " << endl;
        cout << "--------------------------\n";
        ReadInfo(ArryPersons[i + 1]);
    }
}

void PrintArryPersonsInfo(strInfo ArryPersons[100], int NumberOfPersons)
{
    for (int i = 0; i <= NumberOfPersons - 1; i++)
    {
        cout << "\nPerson " << i + 1 << " Info";
        PrintInfo(ArryPersons[i + 1]);
    }
}


int main()
{
    int NumberOfPersons = 0;
    strInfo ArryPersons[100];

    ReadArryPersonsInfo(ArryPersons, NumberOfPersons);
    PrintArryPersonsInfo(ArryPersons, NumberOfPersons);

    return 0;
}