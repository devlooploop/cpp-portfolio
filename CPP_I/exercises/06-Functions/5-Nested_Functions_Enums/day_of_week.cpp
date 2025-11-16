
// Nested Functions with Enums
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

enum enDay 
{
    Sunday = 1, Monday = 2, Tuesday = 3, Wednesday = 4,
    Thursday = 5, Friday = 6, Saturday = 7
};

enDay ReadDay()
{
    short unsigned int day;

    cout << "Enter the day\n";
    cin >> day;

    return (enDay)day;
}

string ChooseDay(short unsigned int Day)
{
    switch (Day)
    {
    case enDay::Sunday:
        return "It's Sunday\n";
        break;
    case enDay::Monday:
        return "It's Monday\n";
        break;
    case enDay::Tuesday:
        return "It's Tuesday\n";
        break;
    case enDay::Wednesday:
        return "It's Wednesday\n";
        break;
    case enDay::Thursday:
        return "It's Thursday\n";
        break;
    case enDay::Friday:
        return "It's Friday\n";
        break;
    case enDay::Saturday:
        return "It's Saturday\n";
        break;

    default:
        return "Wrong day Enter the day again\n";
        break;
    }
}

int main()
{

    cout << ChooseDay(ReadDay());

    return 0;
}