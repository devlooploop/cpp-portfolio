
// Problem #5 Swap Numbers

#include <iostream>

using namespace std;

void swapNumbers(int num1, int num2) {

    int temp = num1;
    num1 = num2;
    num2 = temp;

    cout << "\nAfter swapping Numbers :\n" << num1 << "\n" << num2 << endl;
}


int main()
{
    int num1, num2;

    cout << "Enter Number 1: \n";
    cin >> num1;
    cout << "Enter Number 2: \n";
    cin >> num2;

    cout << "\n***************************\n";
    cout << "\nBefor swaping Numbers: \n" << num1 << endl << num2 << endl;

    swapNumbers(num1, num2);

    return 0;
}
