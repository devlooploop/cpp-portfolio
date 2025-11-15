// Math Functions in C++
//  pow()
// 

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int x = 2;
	int y = 4;

	cout << "Power value: x^y = (2^4)" << pow(x, y) << endl; // gives 16
	cout << "Power value: x^y = (4^3)" << pow(4, 3) << endl; // gives 64

	return 0;
}


