
// Problem - Validate Age Between 18 and 45 

/* Write a program to ask the user to enter :
• Age
If age is between 18 and 45 print “Valid Age” otherwise print
“Invalid Age” */

#include<iostream>
#include<string>

using namespace std;

int main()
{
	short int Age;

	cout << "Enter your Age: \n";
	cin >> Age;

	if (Age >= 18 && Age <= 45)
	{
		cout << "\n" << "\n Valid Age \n";
	}
	else
	{
		cout << "\n" << "\nInValid Age \n";
	}

	return 0;
}