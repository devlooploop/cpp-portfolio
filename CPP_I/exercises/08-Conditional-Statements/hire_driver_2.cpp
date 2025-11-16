
/* Problem - Write a program to ask the user to enter his/her:
• Age
• Driver license
Then Print “Hired” if his\her age is grater than 21 and s/he
has a driver license, otherwise Print “Rejected”  */

#include<iostream>
using namespace std;

void ReadInfo(unsigned short int& Age, char& DriverLicense)
{
	cout << "Enter your age ";
	cin >> Age;

	cout << "Do you have driver license Y/N? \n ";
	cin >> DriverLicense;
}

bool CheckUser(unsigned short int Age, char DriverLicense)
{
	return (Age > 21 && (DriverLicense == 'Y' || DriverLicense == 'y'));

}

int main()
{
	unsigned short int x;
	char y{};

	ReadInfo(x, y);

	if (CheckUser(x, y))
	{
		cout << "You Are Hired\n";
	}
	else
	{
		cout << "You Are Rejected\n";
	}

	return 0;
}

