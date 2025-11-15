// Functions Part II - Functions vs Procedures

//  functions vs procedures

#include <iostream>
#include<string>

using namespace std;

void MySumProcedure() // This is procedure 
{ 
    

    int Number1, Number2;

    cout << "Please enter Number1\n";
    cin >> Number1;
    cout << "\nPlease enter Number2\n";
    cin >> Number2;

    cout << "***************************\n";
    cout << Number1 + Number2 << endl;
}

int MySumFunction()  // This is Function it has  <return>
{    

    int Number1, Number2;

    cout << "\nPlease enter Number1\n";
    cin >> Number1;
    cout << "\nPlease enter Number2\n";
    cin >> Number2;

    cout << "***************************\n";
    return Number1 + Number2;

}

int main()
{
    MySumProcedure();

    cout << MySumFunction();

    // Functions treated as variabls it can be used with operations as shown here
    // cout << MySumFunction() + 10 / 20;
    
   

    return 0;
}