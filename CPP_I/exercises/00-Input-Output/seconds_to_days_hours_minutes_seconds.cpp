
// Problem #43 Seconds to Days Hours Minutes Seconds 

/*
Write a program that inputs the number of seconds and changes it to days, hours, minutes, and seconds

Input
193,535
Output :
2:5:45:35

*/

#include <iostream>
#include <cmath>

using namespace std;

int main() {

    unsigned int  num_of_secs, SecPerMinute, SecPerhour, SecPerDay;
    unsigned int  reminder;
    unsigned int  NumberOfDays, NumberOfHours, NumberOfMinutes;

    cout << "Enter number of secondes: ";
    cin >> num_of_secs;

    SecPerDay = 24 * 60 * 60;
    NumberOfDays = floor(num_of_secs / SecPerDay);
    reminder = num_of_secs % SecPerDay;

    SecPerhour = 60 * 60;
    NumberOfHours = floor(reminder / SecPerhour);
    reminder = num_of_secs % SecPerhour;

    SecPerMinute = 60;
    NumberOfMinutes = floor(reminder / SecPerMinute);
    reminder = num_of_secs % NumberOfMinutes;

    unsigned int Seconds = reminder;

    cout << endl;
    cout << NumberOfDays << ":" << NumberOfHours << ":" << NumberOfMinutes << ":" << Seconds;

    return 0;
}






















