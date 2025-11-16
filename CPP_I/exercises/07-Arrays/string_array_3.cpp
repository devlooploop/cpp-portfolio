
// Write a program using array to do 3 grades and print the averages

#include <iostream>
using namespace std;

int main()
{

	float Grade[3];

	cout << "Enter grade 1\n";
	cin >> Grade[0];

	cout << "Enter grade 2\n";
	cin >> Grade[1];

	cout << "Enter grade 3\n";
	cin >> Grade[2];

	float Avg = (Grade[0] + Grade[1] + Grade[2]) / 3;

	cout << "The Average of grades is " << Avg;

	cout << "\n***********************************************" << endl;

	return 0;
}

