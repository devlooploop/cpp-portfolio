
// Using Procedure & Functions
/*
Write a program to print numbers from 1 to N.
Input
10
Outputs:
10
9
8
7
6
5
4
3
2
1

*/

#include <iostream>
using namespace std;

void PrintNumberFrom_N_To1(int Number)
{
	int i;

	for (i = Number; i >= 1; i--)
	{
		cout << i << endl;

	}		
}

int main()
{
	int N;
	cout << "Enter the reptation Value (N) \n";
	cin >> N;
	cout << "******************************\n";

	PrintNumberFrom_N_To1(N);

	return 0;
}