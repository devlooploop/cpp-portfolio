// Functions Part 1
//  4 functions 

#include <iostream>

using namespace std;


#include <iostream>

using namespace std;

void DisplayMyCardInfo() 
{

    cout << "********************************" << endl;
    cout << "Name : Jack Jacki" << endl;
    cout << "Age  : 44 Years." << endl;
    cout << "City : Cali." << endl;
    cout << "Country: USA." << endl;
    cout << "********************************" << endl;
}

void PrintSqrStars() 
{
    cout << "\n" << "********" << endl;
    cout << "********" << endl;
    cout << "********" << endl;
    cout << "********" << endl;

}

void PrintaILoveProgramming() 
{
    cout << "\n" << "I Love Programming!" << endl;
    cout << "I Promise to be the best developer ever!" << endl;
    cout << "I know it will take some time to practice, but I will achive my goal!" << endl;
    cout << "Best Regrads,\n Jack Jacki";
}

void PrintH() 
{
    cout << "\n\n";
    cout << "*      *\n";
    cout << "*      *\n";
    cout << "*      *\n";
    cout << "********\n";
    cout << "*      *\n";
    cout << "*      *\n";
    cout << "*      *\n";
}


int main()
{
    DisplayMyCardInfo();
    PrintSqrStars();
    PrintaILoveProgramming();
    PrintH();

    return 0;
}