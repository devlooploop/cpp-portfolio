
// Example #1 Enums

#include<iostream>

using namespace std;

enum Color {Red, Green, Yellow, Blue };

int main()
{
	Color MyColor;

	MyColor = Color::Yellow;

	cout << "Color is: " << MyColor << endl;

	return 0;
}

