
//  Validate Age Between 18 and 45 

/* Write a program to ask the user to enter :
• Age
If age is between 18 and 45 print “Valid Age” otherwise print
“Invalid Age” 
*/

#include<iostream>
using namespace std;

void ReadAge(unsigned short int& Age)
{
	cout << "Enter your Age: \n";
	cin >> Age;
}

unsigned short int CheckAgeValidity(unsigned short int Age)
{
	return (Age >= 18 && Age <= 45);
}

int main()
{
	unsigned short int Age;

	ReadAge(Age);

	if (CheckAgeValidity(Age))
	{
		cout  << "\n Valid Age \n";
	}			
	else
	{
		cout << "\nInValid Age \n";
	}

	return 0;
}