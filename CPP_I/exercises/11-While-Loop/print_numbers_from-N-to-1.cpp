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

int ReadIntN(int& N)
{
	cout << "Enter the N Value \n";
	cin >> N;
	cout << "******************************\n";

	return N;
}

void PrintFromNto1(int N)
{
	int i = N;
	while (i >= 1)
	{
		cout << i << endl;
		i--;
	}

}

int main()
{
	int number;

	PrintFromNto1(ReadIntN(number));

	return 0;
}

