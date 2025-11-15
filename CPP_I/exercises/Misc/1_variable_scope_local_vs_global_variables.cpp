

// Variable Scope/ Local vs Global Variables

#include<iostream>
#include<string>
using namespace std;

int x = 300;

void MyFunction1()
{
	int x = 500;

	cout << "The value of x inside MyFunction is: " << x << endl;
}

int main()
{
	int x = 10;
	
	cout << "The local value of x inside Main() is: " << x << endl;
	MyFunction1();

	// increases global x by 1
	::x++;

	cout << "The global value of x is: " << ::x << endl;

	return 0;
}