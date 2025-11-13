 
// Postfix vs Prefix  ++A vs A++ , --A vs A--


#include <iostream>

using namespace std;

int main()
{
    int A = 10;
    int B = A++; // B will take the old value of A, then A will increased by 1 

    cout << "B = " << B << endl;
    cout << "A = " << A << endl;

    B = ++A; // A will increase by 1, then B will take the new value 
    cout << "B = " << B << endl;
    cout << "A = " << A << endl;

    return 0;

}

























