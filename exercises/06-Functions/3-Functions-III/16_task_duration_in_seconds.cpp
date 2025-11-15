
// Problem #16 Task Duration inSeconds

/*
Write a program to calculate the task duration in seconds and print it on screen
--> Given the time duration of a task in the number of days, hours, minutes, and seconds,.
Input
2
5
45
35
Outputs:
193,535 Seconds
*/

#include <iostream>
using namespace std;

int TaskDurationInSec(int days, int hours, int minutes, int seconeds) 
{

	int total_Seconeds;

	// days = 24   hours
	// hours = 60  minutes
	// minuts = 60 seconeds

	total_Seconeds = (seconeds * 1) + (minutes * 60) +
		(hours * 60 * 60) + (days * 24 * 60 * 60);

	return total_Seconeds;
}


int main()
{
	int days, hours, minutes, seconeds;

	cout << "Enter  days, hours, minutes, seconeds" << endl;
	cin >> days >> hours >> minutes >> seconeds;

	// The thousand seperator is for the next courses
	// The output will be without seperators

	cout << TaskDurationInSec(days, hours, minutes, seconeds) << " Seconeds " << endl;

	return 0;
}

