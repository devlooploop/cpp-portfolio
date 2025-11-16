
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

int ReadIntN(int &N)
{
	cout << "Enter the N Value \n";
	cin >> N;
	cout << "******************************\n";

	return N;
}

void PrintFromNto1(int N)
{
	int i = 1;
	while (i <= N)
	{
		cout << i << endl;
		
		i++;
	}	
}

int main()
{
	int number;

	PrintFromNto1(ReadIntN(number));
	
	return 0;
}