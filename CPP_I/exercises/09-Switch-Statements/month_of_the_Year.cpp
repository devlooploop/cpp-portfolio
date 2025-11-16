
//  Switch .. Case Statement
// Problem - Month Of Year

/*Write a program to ask the user to enter:
• Month
Then print the Month as follows:
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

int main()
{
    int Month;

    cout << "Enter the Month: \n";
    cin >> Month;

    switch (Month)
    {
    case 1:
        cout << "It's January:\n";
        break;
    case 2:
        cout << "It's February:\n";
        break;
    case 3:
        cout << "It's March:\n";
        break;
    case 4:
        cout << "It's April:\n";
        break;
    case 5:
        cout << "It's May:\n";
        break;
    case 6:
        cout << "It's June:\n";
        break;
    case 7:
        cout << "It's July:\n";
        break;
    case 8:
        cout << "It's August:\n";
        break;
    case 9:
        cout << "It's September:\n";
        break;
    case 10:
        cout << "It's Octobor:\n";
        break;
    case 11:
        cout << "It's Novomber:\n";
        break;
    case 12:
        cout << "It's December:\n";
        break;

    default:
        cout << "Wrong Month Enter the month again\n";
        break;
    }

    return 0;
}