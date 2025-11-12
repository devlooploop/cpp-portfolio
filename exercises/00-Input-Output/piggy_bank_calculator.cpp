
// Problem #35 Piggy Bank Calculator

/*
Write a program to ask the user to enter:
• Pennies, Nickels, Dimes, Quarters, Dollars
Then calculate the total pennies , total dollars and print them on screen
giving that:
• Penny = 1
• Nickel = 5
• Dime = 10
• Quarter = 25
• Dollar = 100
Example Inputs:
5,5,5,5,5
Outputs:
705 Pennies
7.05 Dollars
*/

#include <iostream>

using namespace std;

// Penny = 1
// Nickel = 5
// Dime = 10
// Quarter = 25
// Dollar = 100 pennies

int main()
{
    float Pennies, Nickels, Dimes, Quarters, Dollars;
    float Dollars_totall, Pennies_totall;

    cout << "Enter Pennies, Nickels, Dimes, Quarters, Dollars \n";
    cin >> Pennies;
    cin >> Nickels;
    cin >> Dimes;
    cin >> Quarters;
    cin >> Dollars;

    Pennies_totall = (Pennies * 1) + (Nickels * 5) + (Dimes * 10) +
        (Quarters * 25) + (Dollars * 100);
    Dollars_totall = Pennies_totall / 100;

    cout << "\n Outputs : \n" << Pennies_totall << " Pennies";
    cout << "\n" << Dollars_totall << " Dollars\n";

    return 0;
}
















