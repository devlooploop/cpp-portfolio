
// Task Duration in Seconds Problem
// after finding the result use round() and print the final results


/*
Write a program to calculate the task duration in seconds and print it on screen
--> Given the time duration of a task in the number of days, hours, minutes, and seconds,.
Input:
2
5
45
35

Outputs:
193,535 Seconds
*/

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int days, hours, minutes, seconeds, total_Seconeds;

	// days = 24   hours
	// hours = 60  minutes
	// minuts = 60 seconeds

	cout << "Enter the time duration of a task\n";
	cin >> days >> hours >> minutes >> seconeds;

	total_Seconeds = (seconeds * 1) + (minutes * 60) + (hours * pow(60, 2)) + 
		(days * 24 * pow(60, 2));

	// The thousand seperator is for the next courses
	// The output will be without seperators

	cout << round(total_Seconeds) << " Seconeds " << endl;

	return 0;
}










