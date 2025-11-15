
// Example #2 - Data overflow

#include <iostream>


using namespace std;

int main()
{
    double distance = 65E12; // 65E12 equals to 56*10^12
    cout << "\"double \" " << distance << endl;

    short d = 3434233; // Error! out of range
    cout << "\"short \" " << d << endl;

    unsigned int a = -10; // Error! can only store positive number
                          // Some compilers gives error, others substitute with some numbers!
    cout << "\"unsigned int \" " << a << endl;
    

    return 0;
}





