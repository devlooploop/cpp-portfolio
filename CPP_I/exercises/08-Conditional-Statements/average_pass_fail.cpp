
// Problem - Average Pass Fail

/* Write a program to ask the user to enter:
• Mark1, Mark2, Mark3

Then Print the Average of entered Marks, and print “PASS” if average >= 50, otherwise print “FAIL”
Example Inputs:
90
80
70
Outputs:
80
Pass 
*/

#include<iostream>
#include<string>

using namespace std;

int main()
{
	short int Mark1, Mark2, Mark3;

	cout << "Enter your marks: \n";
	cin >> Mark1 >> Mark2 >> Mark3;

	short int Avg = (Mark1 + Mark3 + Mark3) / 3;

	if (Avg >= 50)
	{
		cout << "\n" << Avg << "\nPass \n";
	}
	else
	{
		cout << "\n" << Avg << "\nFail \n";
	}

	return 0;
}