// Data Type Conversion
// Example #1 Implicite & explicit conversion

#include <iostream>
using namespace std;

int Num1;
double Num2 = 18.99;

int main()
{

//  Num1 = Num2; // Implicit(automatic) conversion from double to int, diffrent from compile to another

//	Num1 = (int)Num2; // Explicit Conversion (C style)

	Num1 = int(Num2); // Explicit Conversion // conversion via int function takes parameter (Num2)

	cout << Num1 << endl; // ouputs 18 

	return 0;
}