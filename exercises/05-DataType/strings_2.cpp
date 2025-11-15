
// String # 2

// Enter a string its length more 10 char , String1
// Enter 5 as string, String2
// Enter 10 as string, String3 10

// ouputs 
// The Length of string is 20
//Characters at 0,2,4,7 are: M h m d
//Concatenating String2 and String3 = 510
// 5 * 10 = 50

#include <iostream>
#include <string>

using namespace std;

int main()
{

    string st1, st2, st3;

    cout << "Please enter S1: \n";
    getline(cin, st1);

    cout << "\n" << "Please enter S2 number as string: \n";
    cin >> st2;

    cout << "\n" << "Please enter S3 number as string: \n";
    cin >> st3;

    // Casting string to int
    int result = stoi(st2) * stoi(st3);

    cout << "*********************************************" << "\n";

    cout << "\n" << "The Length of String1 is " << st1.length() << endl;
    cout << "Characters at 0,2,4,7 are " << st1[0] << " " << st1[2] << " " << st1[4]
        << " " << st1[7] << endl;

    cout << "Concatenating String2 and String3 = " << st2 + st3 << endl;
    cout << st2 << " * " << st3 << " = " << result << endl;

    return 0;
}