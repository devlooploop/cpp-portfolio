
// Nested Functions with Enums
// Problem - Month Of Year

/*Write a program to ask the user to enter:
• Month
Then print the day as follows:
• 1 Print January
• 2 Print February
• 3 Print March
• 4 Print April
• 5 Print May
• 6 Print June
• 7 Print July
• 8 Print Agust
• 9 Print September
• 10 Print ctober
• 11 Print November
• 12 Print December
• Otherw=rint “Wrong Month” and ask the use to enter the Month again.
Example Inputs:
11
Outputs:
November */

#include <iostream>
#include<string>
using namespace std;

enum enMonth 
{
    Jan = 1,
    Feb = 2,
    Mar = 3,
    Apr = 4,
    May = 5,
    Jun = 6,
    Jul = 7,
    Aug = 8,
    Sep = 9,
    Oct = 10,
    Nov = 11,
    Dec = 12
};

enMonth ReadMonth()
{
    int month;
    cin >> month;
    return (enMonth)month;
}

void ShowMonthMenue()
{
    cout << "************************\n";
    cout << "   Month Of The Year    \n";
    cout << "************************\n";
    cout << "1: January\n";
    cout << "2: February\n";
    cout << "3: March\n";
    cout << "4: April\n";
    cout << "5: May\n";
    cout << "6: June\n";
    cout << "7: July\n";
    cout << "8: August\n";
    cout << "9: September\n";
    cout << "10: Octobor\n";
    cout << "11: Novomber\n";
    cout << "12: October\n";
    cout << "13: December \n";
    cout << "************************\n";
    cout << "Plese enter the month's Number\n";

}

string GetMonthName(enMonth month)
{
    switch (month)
    {
    case enMonth::Jan:
        return  "January\n";
        break;

    case enMonth::Feb:
        return "February\n";
        break;

    case enMonth::Mar:
        return "March\n";
        break;

    case enMonth::Apr:
        return "April:\n";
        break;

    case enMonth::May:
        return "May:\n";
        break;

    case enMonth::Jun:
        return "June:\n";
        break;

    case enMonth::Jul:
        return "July:\n";
        break;

    case enMonth::Aug:
        return "August:\n";
        break;

    case enMonth::Sep:
        return "September:\n";
        break;

    case enMonth::Oct:
        return "Octobor:\n";
        break;

    case enMonth::Nov:
        return "Novomber : \n";
        break;

    case enMonth::Dec:
        return "December:\n";
        break;

    default:
        return "Wrong Month Enter the month again\n";
        break;
    }

}

int main()
{

    ShowMonthMenue();
    cout << "It's " << GetMonthName(ReadMonth()) << endl;

    return 0;
}