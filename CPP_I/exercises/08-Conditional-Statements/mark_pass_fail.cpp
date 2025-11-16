
// Problem - Mark Pass Fail

/* Write a program to ask the user to enter:
• Mark
Then Print the “PASS” if mark >=50, otherwise print “Fail”
Example Inputs:
45
Outputs:
Fail */

#include<iostream>
#include<string>

using namespace std;


int main()
{
	short int Mark;

	cout << "Enter your mark: \n";
	cin >> Mark;

	if (Mark >= 50)
	{
		cout << "Pass \n";
	}
	else
	{
		cout << "Fail \n";
	}

	return 0;
}