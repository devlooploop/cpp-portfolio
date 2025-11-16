// Problem - Hire a driver case 1

/* Write a program to ask the user to enter his/her:
• Age
• Driver license
Then Print “Hired” if his\her age is grater than 21 and s/he
has a driver license, otherwise Print “Rejected”  */

#include<iostream>
#include<string>

using namespace std;


int main()
{
	short int Age;
	bool  HasDriverLicense;

	cout << "Enter your age ";
	cin >> Age;
	cout << "Do you have driver license Answer true or false or 1 for yes or 0 for no ?\n ";
	cin >> HasDriverLicense;

	//if (Age > 21 && (DriverLicense == "Yes") || (DriverLicense == "yes"))  this is a bug
	if (Age > 21 && (HasDriverLicense == true))
	{
		cout << "You Are Hired\n";
	}
	else
	{
		cout << "You Are Rejected\n";
	}

	return 0;
}

