
// Break Statement 

/*
Define an array integers contains 10 elements
arr[10] = {10,20,44,55,33,22,99,88,99,100}
Search for 20 and print its position, use for loop and break statement.
*/

#include <iostream>
using namespace std;

void SearchForElementArr(int SearchFor)
{
   int arr[10] = { 10,20,44,55,33,22,99,88,99,100 };
   int i = 0;

    while ( i <= 10)
    {
        // i + 1 to start at index/position 1 instead of 0
        cout << "We are at iteration " << i + 1 << endl;  

        if (SearchFor == arr[i])
        {
            cout << endl << SearchFor << " Found at position " << i << endl;
            break;
        }
        i++;
    }
}

int main()
{
    
    int SearchFor = 20;

    SearchForElementArr(SearchFor);

    return 0;
}





