
// This program shows Data type's Range & Size

#include <iostream>
using namespace std;

int main()
{
    cout << "Char Range (" << CHAR_MIN << ", " << CHAR_MAX << ")\n";
    cout << "Char Size  (" << sizeof(char) <<" byte)" << endl << endl;

    cout << "Unsigned Char Range (" << 0 << ", " << UCHAR_MAX << ")\n";
    cout << "Unsigned Char Size  (" << sizeof(unsigned char) << " byte)" << endl << endl;

    cout << "Short int Range (" << SHRT_MIN << ", " << SHRT_MAX << ")\n";
    cout << "Short int Size  (" << sizeof(short int) << " byte)" << "\n" << "\n";

    cout << "Unsigned Short int Range (" << 0 << ", " << USHRT_MAX << ")\n";
    cout << "Unsigned Short int Size  (" << sizeof(unsigned short int) << " byte)" << "\n " << "\n";

    cout << "int Range (" << INT_MIN << ", " << INT_MAX << ")\n";
    cout << "int Size  (" << sizeof(int) << " byte)" << endl << endl;

    cout << "Unsigned int Range (" << 0 << ", " << UINT_MAX << ")\n";
    cout << "Unsigned int Size  (" << sizeof(unsigned int) << " byte)" << endl << endl;

    cout << "int Long  Range (" << LONG_MIN << ", " << LONG_MAX << ")\n";
    cout << "int Long Size  (" << sizeof(long int) << " byte)" << endl << endl;

    cout << "Unsigned Long Range (" << 0 << ", " << ULONG_MAX << ")\n";
    cout << "Unsigned int Long  Size  (" << sizeof(unsigned long int) << " byte)" << endl << endl;

    cout << "int Long Long Range (" << LLONG_MIN << ", " << LLONG_MAX << ")\n";
    cout << "int Long Long Size  (" << sizeof(long long int) << " byte)" << endl << endl;

    cout << "Unsigned int Long Long Range (" << 0 << ", " << ULLONG_MAX << ")\n";
    cout << "Unsigned int Long Long Size (" << sizeof(unsigned long long int) << " byte)" << endl << endl;

    cout << "float Range (" << FLT_MIN << ", " << FLT_MAX << ")\n";
    cout << "float Size  (" << sizeof(float) << " byte)" << endl;
    cout << "Float (negative) Range (" << -FLT_MIN << ", " << -FLT_MAX << ")\n\n";

    cout << "double Range (" << DBL_MIN << ", " << DBL_MAX << ")\n";
    cout << "double Size  (" << sizeof(double) << " byte)" << endl;
    cout << "double (negative) Range (" << -DBL_MIN << ", " << -DBL_MAX << ")\n";

    cout << "Long double Range: (" << LDBL_MIN_10_EXP << ", " << LDBL_MAX_10_EXP << ")\n";
    cout << "Long double Size  (" << sizeof(long double) << " byte)\n" << endl;

    cout << "bool Size  (" << sizeof(bool) << " byte)  \n\n"
        "Note: The size of the (Data type)it depends on the compiler and the machine architect\n"
        "Here the size of Long double is 8 bytes \n" 
        "on other machine and compiler versions it may show (16 bytes). "<< endl << endl;

    cout << "*****************************************\n\n";

    return 0;

}

