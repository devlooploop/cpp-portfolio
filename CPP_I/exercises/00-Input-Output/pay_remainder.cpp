
// Pay Remainder Problem

/*
Write a program to read a TotalBill and CashPaid and calculate the remainder to be paid back.
Input
20
50
Outputs:
30
*/

#include <iostream>

using namespace std;

int main()
{
	float TotalBill, CashPaid, reminder;

	cout << "Enter total bill and cash paid: \n";
	cin >> TotalBill;
	cin >> CashPaid;

	reminder = CashPaid - TotalBill;

	cout << "The reminder is \n" << reminder;

}















