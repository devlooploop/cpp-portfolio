
// Problem - Print Numbers from 1 to N
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

int main()
{	
	int N;
	cout << "Enter the reptation Value (N) \n";
	cin >> N;
	cout << "******************************\n";

	for (int i = 1; i <= N; i++)
	{
		cout  << i << endl;
		
	}
	
	return 0;
}