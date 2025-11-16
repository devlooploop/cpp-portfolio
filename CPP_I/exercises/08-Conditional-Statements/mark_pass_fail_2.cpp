
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

void ReadMark(float& Mark)
{
	cout << "Enter your mark: \n";
	cin >> Mark;
}

float CheckMark(float Mark)
{
	return (Mark >= 50);
}

int main()
{
	float Mark;

	ReadMark(Mark);

	if (CheckMark(Mark))
	{
		cout << "Pass \n";
	}
	else
	{
		cout << "Fail \n";
	}

	return 0;
}