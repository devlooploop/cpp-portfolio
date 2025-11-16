
// Write a program using array to do 3 grades and print the arerages

#include <iostream>

using namespace std;

void ReadGrades(float Grade[3]) 
{

	cout << "Enter grade 1\n";
	cin >> Grade[0];

	cout << "Enter grade 2\n";
	cin >> Grade[1];

	cout << "Enter grade 3\n";
	cin >> Grade[2];
}

float CalculateAverageOfGrades(float Grade[3]) 
{
	return (Grade[0] + Grade[1] + Grade[2]) / 3;
}


int main()
{
	float Grade[3];

	ReadGrades(Grade);

	cout << "The Average of grades is " << CalculateAverageOfGrades(Grade);
	cout << "\n***********************************************" << endl;
	return 0;
}


