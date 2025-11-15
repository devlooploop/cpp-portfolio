

// Logical Operators II


#include <iostream>

using namespace std;

int main()
{
    bool Result;

    // NOT(5 > 6 OR 7=7) AND NOT (1 Or false)

    Result = !(5 > 6 || 7 == 7) && !(1 || 0);

    cout << "Result: " << Result << endl;
    
    return 0;

}


