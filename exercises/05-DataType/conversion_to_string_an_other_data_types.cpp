// Data Type Conversion
// Conversion to String an other Data Types

#include <iostream>
#include <string>

using namespace std;

int main()
{

    // Convert String to double, float, int
    string st1 = "43.22";

    double dbl = stod(st1);      //String to double
    float  flt = stof(st1);     // String to float
    int intgr = stoi(st1);     //  String to integer

    // When Converting to Data Type to String this will result in Zeros 
    // at the right of converted value it means it's a string such as  
    // double to string  N2 = 33.5 is 33.500000
   //  float to string   N3 = 55.23 is 55.230000
    
    // integer To string
    int N1 = 20;
    string  intToStr = to_string(N1);

    // Double To String
    double N2 = 33.5;
    string dubToString = to_string(N2);


    // float to string
    float N3 = 55.23;
    string flotToString = to_string(N3);

    //float to integer 
    int floatToInt_implicit = N3;            // Implicit conversion to int
    int floatToInt_C_type = (int)N3;         // Explicit Conversion (C style)
    int floatToInt_Intfunction = int(N3);    // Explicit Conversion conversion using int function int(parameter)

    cout << "String to double: st1 = \"43.22\" is " << dbl << endl;
    cout << "String to float:  " << flt << endl;
    cout << "String to integer:  " << intgr << endl;

    cout << "\n" << "integer to string N1 = 20 is " << intToStr;
    cout << "\n" << "double to string  N2 = 33.5 is " << dubToString;
    cout << "\n" << "float to string   N3 = 55.23 is " << flotToString << endl;

    cout << "\n" << "float to int N3 = 55.23:  is " << floatToInt_implicit;
    cout << "\n" << "float to int N3 = 55.23: C type conversion  (int) N3 is " << floatToInt_C_type;
    cout << "\n" << "float to int N3 = 55.23: using int function int (N3) is " << floatToInt_Intfunction << endl;

    return 0;
}