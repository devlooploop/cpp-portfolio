
// Problem - ATM PIN 3 Times

/* Write a program to read the ATM PIN code from the user, then check if PIN Code = 1234, then show the balance
to user, otherwise print “Wrong PIN” and ask the user to enter the PIN again.
Only allow user to enter the PIN 3 times, if fails, print “Card is locked!”
Assume User Balance is 7500.
Input
1234

5151
Outputs:
Your Balance is: 7500
Wrong PIN
    */

#include <iostream>

using namespace std;

string ReadPINCode(string& PIN)
{
    cin >> PIN;
    return PIN;
}

void CheckPINCode()
{
    string PIN ;
    int Balance = 7500, fail = 0;

    while (fail <= 2)
    {
        ReadPINCode(PIN);

        if (PIN == "1234")
        {
            cout << "Your Balance is " << Balance << endl;
            break;
        }
        else
        {
            fail++;
            cout << "Wrong PIN \n";

        }
    }
    if (fail == 3)
    {
        cout << "Your card is been blocked\n";
    }
}

int main()
{
    string pin;

    cout << "Enter the PIN Code\n";
   
    CheckPINCode();

    return 0;
}