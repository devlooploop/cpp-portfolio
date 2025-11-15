// Function Parameters - By-Val vs By-Ref
//  Swap tow numbers

#include <iostream>

using namespace std;

// we use &(ampersand) to change the variable value by referance
void swapNumbers(int& num1, int& num2) 
{

    int temp = num1;
    num1 = num2;
    num2 = temp;

    cout << "After swapping inside function num1 = " << num1 << ", num2 = " << num2 << endl;

}


int main()
{
    int num1, num2;

    cout << "Enter Number 1: \n";
    cin >> num1;

    cout << "Enter Number 2: \n";
    cin >> num2;

    cout << "\nBefor swaping inside main() func \n num1 = " << num1 << ", num2 = " << num2 << endl;

    cout << "\n After swap inside main() function " << endl;
    swapNumbers(num1, num2);

    return 0;
}
