// Nested Functions with Enums
// Example - Choose Country 

#include <iostream>
using namespace std;

enum enCountryChoice { Germany = 1, France = 2, Italy = 3, Spain = 4, Sweden = 5, Netherlands = 6, Other = 7 };

void ShowCountryMenue()
{
    cout << "****************************\n";
    cout << "Please Enter the number of your country?\n";
    cout << "(1) Germany\n";
    cout << "(2) France\n";
    cout << "(3) Italy\n";
    cout << "(4) Spain\n";
    cout << "(5) Sweden\n";
    cout << "(6) Netherlands\n";
    cout << "(7) Other\n";
    cout << "****************************\n\n";
    cout << "Your Choice? ";
}

enCountryChoice ReadCountry()
{
    int c;
    cin >> c;
    return (enCountryChoice)c;
}

string GetCountry(enCountryChoice country)
{
    switch (country)
    {
    case enCountryChoice::Germany:
        return "Your country is Germany\n";
        break;

    case enCountryChoice::France:
        return "Your country is France\n";
        break;

    case enCountryChoice::Italy:
        return "Your country is Italy\n";
        break;

    case enCountryChoice::Spain:
        return "Your country is Spain\n";
        break;

    case enCountryChoice::Sweden:
        return "Your country is Sweden\n";
        break;

    case enCountryChoice::Netherlands:
        return "Your country is Netherlands\n";
        break;

    default:
        return "Your country is Other\n";
        break;
    }
}

int main()
{
    ShowCountryMenue();
    cout << GetCountry(ReadCountry()) << endl;

    return 0;
}
