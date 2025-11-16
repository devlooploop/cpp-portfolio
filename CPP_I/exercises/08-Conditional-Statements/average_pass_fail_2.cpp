
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

void ReadMarks(float& Mark1, float& Mark2, float& Mark3)
{
	cout << "Enter your marks: \n";
	cin >> Mark1 >> Mark2 >> Mark3;
}

float Average(float Mark1, float Mark2, float Mark3)
{
	return  (Mark1 + Mark2 + Mark3) / 3;
}

int main()
{
	float Mark1, Mark2, Mark3;

	ReadMarks(Mark1, Mark2, Mark3);

	if (Average(Mark1, Mark2, Mark3) >= 50)
	{
		cout << "\n" << Average(Mark1, Mark2, Mark3) << "\nPass \n";
	}
	else
	{
		cout << "\n" << Average(Mark1, Mark2, Mark3) << "\nFail \n";
	}

	return 0;
}