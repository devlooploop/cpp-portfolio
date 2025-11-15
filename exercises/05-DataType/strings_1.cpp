
// Example #1 Strings

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string MyString = "ABCDEFGHIJKLMNOPQRTSTUVWXyz";
    cout << "The Length of the MyString is: " << MyString.length() << endl;

    cout <<"The letter in index 2 is " << MyString[2] << endl; // will C
    
    // This will cause error the PASSED value should be numbers not letters
    // _Xout_of_range("stoi argument out of range");
    // string S1 = "AB", S2 = "CD";
    
    string S1 = "10", S2 = "20";

    string S3 = S1 + S2;
    cout << "S1 + S2 is " << S3 << endl; //Will print 1020

    int Sum = stoi(S1) + stoi(S2);
    cout <<"The Sum is " << Sum << endl; //Will print 30

    return 0;
}