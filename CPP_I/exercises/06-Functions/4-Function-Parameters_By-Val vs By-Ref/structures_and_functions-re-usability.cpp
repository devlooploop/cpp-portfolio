
// Structures and Functions - Re - usability.

#include <iostream>
#include <string>

using namespace std;

struct stAdress 
{
    string City;
    string Country;
};

struct stPersonInfo 
{
    string Name;
    int    Age;
    double MonthySalary;
    double YearlySalary;
    char   Gender;
    bool isMarried;
    stAdress Adress;
};

void ReadInfo(stPersonInfo &PersonID) 
{

    cout << "Enter your name \n";
    cin.ignore(1, '\n');
    getline(cin, PersonID.Name);

    cout << "Enter your Age\n";
    cin >> PersonID.Age;
    cout << "Enter your City\n";
    cin >> PersonID.Adress.City;

    cout << "Enter your Country\n";
    cin >> PersonID.Adress.Country;
    cout << "Enter your Monthly Salary\n";
    cin >> PersonID.MonthySalary;
    cout << "Enter your Yearly Salary\n";
    cin >> PersonID.YearlySalary;

    cout << "Enter your Gender\n";
    cin >> PersonID.Gender;
    cout << "Enter your Martial Status\n";    
    cin >> PersonID.isMarried;
}

void PrintInfo(stPersonInfo PersonID)
{
    cout << "\n********************************************\n";

    cout << "Name: " << PersonID.Name << endl;
    cout << "Age:  " << PersonID.Age << endl;
    cout << "City: " << PersonID.Adress.City << endl;

    cout << "Country: " << PersonID.Adress.Country << endl;
    cout << "Monthly Salary" << PersonID.MonthySalary << endl;
    cout << "Yearly Salary: " << PersonID.YearlySalary << endl;

    cout << "Gender: " << PersonID.Gender << endl;
    cout << "Martial Status: " << PersonID.isMarried << endl;

    cout << "\n********************************************\n";

}


int main()
{
    // Here we can define mor than person in very easy way that we 
    // just call the function which save us alotof time 
    stPersonInfo Person1;
    ReadInfo(Person1);
    PrintInfo(Person1);

    stPersonInfo Person2;
    ReadInfo(Person2);
    PrintInfo(Person2);

    return 0;
}


