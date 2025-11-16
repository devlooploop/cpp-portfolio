
// Problem - Print Numbers from N to 1
/*
Write a program to print numbers from N to 1.
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

int main()
{	
	int N;
	cout << "Enter the reptation Value (N) \n";
	cin >> N;
	cout << "******************************\n";

	for (int i = N; i >= 1; i--)
	{
		cout  << i << endl;
	}

	return 0;
}