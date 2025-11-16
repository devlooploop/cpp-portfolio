
// Problem - Simple Calculator

/*
Write a program to ask the user to enter:
• Number 1
• Number 2
• OperationType
Then perform the calculation according to the Operation Type as follows:
• “+” : add the two numbers.
• “-” : Subtract the two numbers.
• “*” : Multiply the two numbers.
• “/” : Divide the two numbers.
Example Inputs:
10
20
*
Outputs:
200
*/

#include <iostream>

using namespace std;

struct stMathOperators 
{
    char Addition;
    char Subtraction;
    char Multiplication;
    char Division;
}; 

float Addition(float Num1, float Num2)
{
    
    return Num1 + Num2;
}

float Subtraction(float Num1, float Num2)
{

    return Num1 - Num2;
}

float Multiplication(float Num1, float Num2)
{
    return Num1 * Num2;
}

float Division(float Num1, float Num2)
{
    return Num1 / Num2;
}


void CalculateNumbers(float Num1, float Num2)
{
    char OperationType;

    cin >> OperationType;

    if (OperationType == '+')
    {
        cout << Addition(Num1,Num2);
       
    }
    else if (OperationType == '-')
    {
        
        cout << Subtraction(Num1, Num2);
    }
    else if (OperationType == '*')
    {
        cout << Multiplication(Num1, Num2);
    }
    else if (OperationType == '/')
    {
       
        cout << Division(Num1, Num2);
    }
    else
    {
        cout << "Wrong Operation type Please enter right ops type\n";
    }
    
}

int main()
{
    float Number1, Number2;
    cout << "Please Enter the numbers\n";
    cin >> Number1 >> Number2;

    cout << "Enter Arethmatic Operation Type\n";

    CalculateNumbers(Number1, Number2);

    return 0;
}
