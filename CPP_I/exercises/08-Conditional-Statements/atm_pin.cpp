
// Problem - ATM PIN

/*
Write a program to read the ATM PIN code from the user, then check if PIN Code = 1234, then show the
balance to user, otherwise print “Wrong PIN” and ask the user to enter the PIN again.
Assume User Balance is 7500.
Input
1234
5151

Outputs:
Your Balance is: 7500
*/

#include<iostream>
#include<string>
using namespace std;

int main()
{
	unsigned short int PIN;

	cout << "Enter PIN code: \n";
	cin >> PIN;

	if (PIN == 1234)
	{
		cout << "\n Your Balance is: 7500\n";
	}
	else
	{
		cout << "\n Wrong PIN, Please Enter the right PIN \n";
	}

	return 0;
}