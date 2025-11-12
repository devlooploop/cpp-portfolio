
// Task Duration in Seconds Problem 

/*
Write a program to calculate the task duration in seconds and print it on screen
 Given the time duration of a task in the number of days, hours, minutes, and seconds,.
Input
2
5
45
35
Outputs:
193535 Seconds
*/


#include <iostream>
using namespace std;

int main()
{
	int days, hours, minutes, seconeds, total_Seconeds;

	// days = 24   hours
	// hours = 60  minutes
	// minuts = 60 seconeds
	cin >> days;
	cin >> hours;
	cin >> minutes;
	cin >> seconeds;

	// The thousand seperator is for the next courses
	// The output will be without seperators

	total_Seconeds = seconeds * 1 + minutes * 60 + hours * 60 * 60 + days * 24 * 60 * 60;
	cout << total_Seconeds << " Seconeds ";
}



















