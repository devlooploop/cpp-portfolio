
// Variable Scope/ Local vs Global Variables

// Write a program that has two global variables int, function and main function
// and modify their values to see the diffrence btween local & global variables 

#include<iostream>
#include<string>
using namespace std;

// Global variables has a scope through whole the program
int x = 100;
int y = 20;

void MyFunction1()
{
	int x = 500;
	int y = 2;

	cout << "The value of x, y inside MyFunction is: " << x << "," << y << endl;
}

int main()
{
	int x = 10;
	int y = 4;

	cout << "The local value of x, y inside Main is: " << x <<","<< y << endl;
	MyFunction1();

	cout << "The global value of x, y is: " << ::x <<","<< ::y << endl;

	// ::x after modification
	::x = ::x - ::y;
	cout << "The modified global value of x = x - y is: " << ::x << endl;

	return 0;
}