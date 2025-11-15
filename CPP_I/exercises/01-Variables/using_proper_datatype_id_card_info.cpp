
// ID-Card Personal Info ... Using proper data type


#include <iostream>
#include <string>

using namespace std;

int main()
{
    string Name, City, Country;

    char Gender;
    unsigned short int Age;
    float Month_Salary = 5000, Yearly_Salary = 0.0;
    bool isMarried = true;

    cout << "Enter your name: ";
    getline(cin, Name);

    cout << "Enter your Age" << endl;
    cin >> Age;

    cout << "Enter your City" << endl;
    cin >> City;

    cout << "Enter your Country" << endl;
    cin >> Country;

    cout << "Monthly Salary" << endl;
    cin >> Month_Salary;

    cout << "Enter Gender: \n";
    cin >> Gender;

    cout << "Are You Married 1/0: \n";
    cin >> isMarried;

    cout << "****************************\n";

    cout << "Name: " << Name << endl;

    cout << "Age: " << Age << "\n";

    cout << "City: " << City << endl;

    cout << "Country: " << Country << endl;

    cout << "Monthly Salary: " << Month_Salary << endl;

    Yearly_Salary = Month_Salary * 12;

    cout << "Yearly Salary :" << Yearly_Salary << endl;

    cout << "Gender: " << Gender << endl;

    cout << "isMarried:" << isMarried << "\n";

    cout << "****************************\n";

    return 0;
}








