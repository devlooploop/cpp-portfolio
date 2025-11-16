
// Preblem - Month Of Year

/*Write a program to ask the user to enter:
• Month
Then print the month as follows:
• 1 Print January
• 2 Print February
• 3 Print March
• 4 Print April
• 5 Print May
• 6 Print June
• 7 Print July
• 8 Print August
• 9 Print September
• 10 Print October
• 11 Print November
• 12 December
• Otherwise print “Wrong Month” and ask the use to enter the Month again.
Example Inputs:
11
Outputs:
November */

#include <iostream>
#include<string>
using namespace std;

string ChooseMonth(int month)
{
    if (month == 1)
    {
        return "It's January:\n";
    }
    else if (month == 2)
    {
        return "It's February:\n";
    }
    else if (month == 3)
    {
        return  "It's March:\n";
    }
    else if (month == 4)
    {
        return "It's April:\n";
    }
    else if (month == 5)
    {
        return "It's May:\n";
    }
    else if (month == 6)
    {
        return "It's June:\n";
    }
    else if (month == 7)
    {
        return "It's July:\n";
    }
    else if (month == 8)
    {
        return "It's August:\n";
    }
    else if (month == 9)
    {
        return "It's September:\n";
    }
    else if (month == 10)
    {
        return "It's October:\n";
    }
    else if (month == 11)
    {
        return "It's November:\n";
    }
    else if (month == 12)
    {
        return "It's December:\n";
    }
   
    else
    {
        return "Wrong month number. Enter the month number again\n";
    }
}

int main()
{
    int month;

    cout << "Enter the month number: \n";
    cin >> month;

    cout << ChooseMonth(month);

    return 0;
}