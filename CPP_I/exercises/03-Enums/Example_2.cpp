// Example #2 Enums

#include<iostream>

using namespace std;

// I just changed Color to en_Color and the rest of Enums too
enum en_Color { Red, Green, Yellow, Blue };
enum en_Direction { North, South, East, West };
enum en_Week { Sat, Sun, Mon, Tue, Wed, Thu, Fri };
enum en_Gender { Male, Female };
enum en_Status { Single, Married };


int main()
{
	en_Color MyColor;
	en_Direction MyDirection;
	en_Week Today;
	en_Status MyStatus;

	MyColor = en_Color::Yellow;

	MyDirection = en_Direction::North;
	Today = en_Week::Sun;
	MyStatus = en_Status::Single;
	
	
	cout << "Color is: " << MyColor << endl;
	cout << "My Direction is: " << MyDirection << endl;
	
	cout << "Today is: " << Today << endl;
	cout << "My Status is: " << MyStatus << endl;

	return 0;
}

