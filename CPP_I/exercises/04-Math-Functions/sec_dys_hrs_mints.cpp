
// Task Duration in Seconds Problem
// after finding the result use round() and print the final results


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

    int num_of_secs, SecPerMinute, SecPerhour, SecPerDay;
    int reminder;
    int NumberOfDays, NumberOfHours, NumberOfMinutes;

    cout << "Enter number of seconds: ";
    cin >> num_of_secs;

    SecPerDay = 24 * pow(60, 2);
    NumberOfDays = num_of_secs / SecPerDay;
    reminder = num_of_secs % SecPerDay;

    SecPerhour = pow(60, 2);
    NumberOfHours = reminder / SecPerhour;
    reminder = reminder % SecPerhour;

    SecPerMinute = 60;
    NumberOfMinutes = reminder / SecPerMinute;
    reminder = reminder % SecPerMinute;

    float Seconds = reminder;

    cout << round(NumberOfDays) << ":" << round(NumberOfHours)
        << ":" << round(NumberOfMinutes) << ":" << round(Seconds);

    return 0;
}












