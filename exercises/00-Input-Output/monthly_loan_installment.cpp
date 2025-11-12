
// Monthly Loan Installment Problem 

/*
Write a program to read a Loan Amount and ask you how many months you need to settle the loan, then
calculate the monthly installment amount.
Input
5000
10
Outputs:
500
*/

#include <iostream>

int main()
{
    float LoanAmount, MonthsTosettle, MonthlyInstallment;

    std::cout << "Enter the Loan Amount: ";
    std::cin >> LoanAmount;

    std::cout << "Enter the Number of the monthes to settle the loan ";
    std::cin >> MonthsTosettle;

    MonthlyInstallment = LoanAmount / MonthsTosettle;
    std::cout << "Monthly installment: " << MonthlyInstallment << "\n";

    return 0;

}

























