
// Service Fee and Sales Tax Problem

/*
A restaurant charges 10% services fee and 16% sales tax.
Write a program to read a BillValue and add service fee and sales tax to it, and print the 
TotalBill on the screen.

Input
100
Outputs:
127.6
*/

#include <iostream>

using namespace std;

int main()
{
	float BillValue, TotalBill;

	cout << "Enter the Bill Value:";
	cin >> BillValue;


	TotalBill = BillValue * 1.1;
	TotalBill = TotalBill * 1.16;

	cout << "\nOutputs: " << TotalBill; 
	
	return 0;
}

















