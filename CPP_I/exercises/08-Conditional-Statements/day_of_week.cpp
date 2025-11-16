
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

string ChooseDay(int day)
{
    if (day == 1)
    {
        return "It's Sunday:\n";
    }
    else if (day == 2)
    {
        return "It's Monday:\n";
    }
    else if (day == 3)
    {
        return  "It's Tuesday:\n";
    }
    else if (day == 4)
    {
        return "It's Tuesday:\n";
    }
    else if (day == 5)
    {
        return "It's Wednesday:\n";
    }
    else if (day == 6)
    {
        return "It's Thursday:\n";
    }
    else if (day == 7)
    {
        return "It's Friday:\n";
    }
    else if (day == 8)
    {
        return "It's Saturday:\n";
    }
    else
    {
        return "Wrong day number. Enter the day number again\n";
    }
}

int main()
{
    int day ;

    cout << "Enter the day number: \n";
    cin >> day;

    cout << ChooseDay(day);

    return 0;
}
