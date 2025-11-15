// Functions Part II - Functions vs Procedures

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// Procedure (no return value)
void printMessage()
{
    cout << "This is my first function :-)" << endl;
}

// Function that returns a string
string getMessage()
{
    return "This is my #2 function :-)";
}

// Function that returns a calculated float value
float multiplyValues()
{
    float x = 10.5f;
    float y = 20.3f;

    return x * y;     
}

int main()
{
    // Call a procedure
    printMessage();

    // Call a function that returns a string
    cout << getMessage() << endl;

    // Using a function inside another function (floor)
    int result = floor(multiplyValues());
    cout << "Result: " << result << endl;

    return 0;
}
