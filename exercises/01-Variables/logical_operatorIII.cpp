

 //Logical Operators 
 
// Using Boolean expression True or False

#include <iostream>

using namespace std;

int main()
{
	bool result;

	// This is the first coloumn
	result = (12 >= 12);
	cout << "12 >= 12 is " << result  << "\n";

	result = (12 > 7);
	cout << "12 > 7 is " << result << endl;
	
	result = (8 < 6);
	cout << "8 < 6 is " <<  result << endl;
	
	result = (8 == 8);
	cout << "8 = 8 is " << result  << endl;
	
	result = (12 <= 12);
	cout << "12 <= 12 is " << result<< endl;
	
	result = (7 == 5);
	cout << "7 = 5 is " << result << endl << "\n";

	// This is the second Coloumn!
	result = !(12 >= 12);
	cout << "Not(12 >= 12) is " << result << "\n";
	
	result = !(12 < 7);
	cout << "Not(12 < 7) is " << result << "\n";
	
	result = !(8 < 6);
	cout << "Not(8 < 6) is " << result << "\n";
	
	result = !(8 == 8);
	cout << "Not(8 = 8) is " << result << "\n";
	
	result = !(12 <= 12);
	cout << "Not(12 <= 12) is " << result << "\n";
	
	result = !(7 == 5);
	cout << "Not(7 = 5) is " << result << "\n\n";

	// This is the 3rd coloumn
	result = (1 && 1);
	cout << "1 AND 1 is " << result << "\n";
	
	result = (1 && 0);
	cout << "True AND 0 is " << result << "\n";
	
	result = (0 || 1);
	cout << "0 OR 1 is " << result << "\n";
	
	result = (0 || 0);
	cout << "0 OR 0 is " << result << "\n";
	
	result = !(0);
	cout << "Not 0 is " << result << "\n";
	
	result = !(1 || 0);
	cout << "Not(1 OR 0) is " << result << "\n\n";

	// This is the 4th coloumn
	result = ((7 == 7) && (7 > 5));
	cout << "(7 = 7) and (7 > 5) is " << result << endl;

	result = ((7 == 7) && (7 < 5));
	cout << "(7 = 7) and (7 < 5) is " << result << endl;
	
	result = ((7 == 7) || (7 < 5));
	cout << "(7 = 7) OR (7 < 5) is " << result << endl;
	
	result = ((7 < 7) || (7 > 5));
	cout << "(7 < 7) OR (7 > 5) is " << result << endl;
	
	result = (!(7 == 7) && (7 > 5));
	cout << "Not(7 = 7) and (7 > 5) is " << result << endl;
	
	result = ((7 == 7) && !(7 < 5));
	cout << "(7 = 7) and Not(7 < 5) is " << result << endl;

	return 0;

}


