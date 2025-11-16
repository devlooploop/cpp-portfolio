
// Switch .. Case Statement
// Problem - Day of the week

/*
Write a program to ask the user to enter:
• Day
Then print the day as follows:
• 1 Print Sunday
• 2 Print Monday
• 3 Print Tuesday
• 4 Print Wednesday
• 5 Print Thursday
• 6 Print Friday
• 7 Print Saturday
• Otherwise print “Wrong Day” and ask the use to enter the day again.
Example Inputs:
6
Outputs:
Its Friday
*/

#include <iostream>
#include<string>

using namespace std;

/*enum enDay {
    Sunday =1, Monday =2, Tuesday =3, Wednesday = 4, 
    Thursday =5, Friday = 6, Saturday =7, WrongDay=8
}; */

int main()
{
    int Day;
    

    cout << "Enter the day: \n";
    cin >> Day;

    switch (Day)
    {
    case 1:
        cout << "It's Sunday:\n";
        break;
    case 2:
        cout << "It's Monday:\n";
            break;
    case 3:
        cout << "It's Tuesday:\n";
        break;
    case 4:
        cout << "It's Wednesday:\n";
        break;
    case 5:
        cout << "It's Thursday:\n";
        break;
    case 6:
        cout << "It's Friday:\n";
        break;
    case 7:
        cout << "It's Saturday:\n";
        break;

    default:
        cout << "Wrong day Enter the day again\n";
        break;
    }

    return 0;
}