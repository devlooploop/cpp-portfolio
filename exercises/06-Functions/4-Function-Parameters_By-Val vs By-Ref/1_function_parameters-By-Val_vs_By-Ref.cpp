// Function Parameters - By-Val vs By-Ref
// Home Work Swap tow numbers

#include <iostream>

using namespace std;

// we use &(ampersand) to change the variable's value by referance
void MyFunction(int &Num1) 
{ 
    Num1 = 16000;

    cout << "Number inside function become = " << Num1 << endl;
}


int main()
{
    int Num1;

    Num1 = 1000;

    MyFunction(Num1);

    cout << "Number after calling the function become = " << Num1 << endl;

    return 0;
}
