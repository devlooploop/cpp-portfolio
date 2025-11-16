
// Using Procedure & Functions
// Print Numbers from 1 to N
/*
Write a program to print numbers from 1 to N.
Input
10
Outputs:
1
2
3
4
5
6
7
8
9
10

*/

#include <iostream>
using namespace std;

int PrintNumber1ToN(int Number)
{
	int i;

	for (i = 1; i <= Number; i++)
	{
		cout << i << endl;
	}
		
	return i;
}

int main()
{
	int N;
	cout << "Enter the reptation Value (N) \n";
	cin >> N;
	cout << "******************************\n";

	PrintNumber1ToN(N);

	return 0;
}