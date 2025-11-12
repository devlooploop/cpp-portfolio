
//  Loan Instalment Months Problem

/*
Write a program to read a LoanAmount and Monthly Payment 
and calculate how many months you need to settle the loan.
Input:
5000
500
Outputs:
10 Months
*/

#include <iostream>

using namespace std;

int main()
{
    float LoanAmount, Monthly_Payment;

    cout << "Enter the Loan Amount and Monthly Payment:\n";
    cin >> LoanAmount;
    cin >> Monthly_Payment;

    cout << LoanAmount / Monthly_Payment << " Months";

}