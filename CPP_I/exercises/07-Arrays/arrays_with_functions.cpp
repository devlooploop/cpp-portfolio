// Arrays with Functions

#include <iostream>
using namespace std;

void ReadArrayData(int x[3])
{
	cout << "Enter grade 1\n";
	cin >> x[0];

	cout << "Enter grade 2\n";
	cin >> x[1];

	cout << "Enter grade 3\n";
	cin >> x[2];

}

void PrintArrayData(int x[3])
{
	cout << "***********" << endl;
	cout << x[0] << endl;
	cout << x[1] << endl;
	cout << x[2] << endl;

}

int main()
{
	int x[3];
	
	ReadArrayData(x);
	PrintArrayData(x);
	
	return 0;
}

