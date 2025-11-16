
// Example #1 Arrays of Structure

#include <iostream>
using namespace std;

struct stInfo 
{
    string FirstName;
    string LastName;
    int    Age;
    string Phone;
};


int main()
{
    // defined array of struct stInfo of 3 persons
    stInfo Person[3]; 

    Person[0].FirstName = "Hamid";
    Person[0].LastName = "Hamidi";
    Person[0].Age = 44;
    Person[0].Phone = "989658695";

    Person[1].FirstName = "Hanna";
    Person[1].LastName = "Jinkinz";
    Person[1].Age = 77;
    Person[1].Phone = "888-000-111";

    cout << Person[1].FirstName << endl << Person[1].Phone << "\n";

	return 0;
}


