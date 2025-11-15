// Problem #4 Seconds to Days Hours Minutes Seconds

// Input 193,535 seconds, Output 2:5:45:35 ** in codeblocks oupts 2:5:45:42

/* when input is 193,535 you get wrong output so
the input should be without "," separator like 193535 */

/*
Write a program that inputs the number of seconds and changes it to days, hours, minutes, and seconds
Input
193535
Output :
2:5:45:35
*/

#include <iostream>
#include <cmath>

using namespace std;

void Duration_D_H_M(int num_of_secs) 
{

    int SecPerMinute = 60, SecPerhour = pow(60, 2), SecPerDay = 24 * pow(60, 2);

    int NumberOfDays, NumberOfHours, NumberOfMinutes, reminder;

    NumberOfDays = num_of_secs / SecPerDay;
    reminder = num_of_secs % SecPerDay;

    NumberOfHours = reminder / SecPerhour;
    reminder = reminder % SecPerhour;

    NumberOfMinutes = reminder / SecPerMinute;
    reminder = reminder % SecPerMinute;

    int Seconds = reminder;

    cout << NumberOfDays << ":" << NumberOfHours
        << ":" << NumberOfMinutes << ":" << Seconds;

}

int main() {

    int num_of_secs;

    cout << "Enter number of seconds: ";
    cin >> num_of_secs;
    
    Duration_D_H_M(num_of_secs);

    return 0;
}
