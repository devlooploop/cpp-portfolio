//
// Problem - Grade A,B,C,D

/*
Write a program to ask the user to enter:
• Grade
Then print the grade as follows:
• 90 – 100 Print A
• 80 – 89 Print B
• 70 – 79 Print C
• 60 – 69 Print D
• 50 – 59 Print E
• Otherwise Print F
Example Inputs:
95
Outputs:
A
*/

#include <iostream>
using namespace std;


void CheckGrade(short int grade)
{
	cin >> grade;

	if ((grade >= 90) || grade == 100)
	{
		cout << 'A';
	}
	else if ((grade >= 80) || grade == 89)
	{
		cout << 'B';
	}
	else if ((grade >= 70) || grade == 79)
	{
		cout << 'C';
	}
	else if ((grade >= 60) || grade == 69)
	{
		cout << 'D';
	}
	else if ((grade >= 50) || grade == 59)
	{
		cout << 'E';
	}
	else
	{
		cout << 'F' << endl;
	}
	
}

int main()
{
	short int mark = 0;

	cout << "Enter the mark\n";

	CheckGrade(mark);

	return 0;
}

