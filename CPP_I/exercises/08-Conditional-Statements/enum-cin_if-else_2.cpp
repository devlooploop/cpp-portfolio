#include <iostream>
using namespace std;

enum enCountryChoice { USA=1, UK=2, France=3, Mexico=4, Serbia=5, Croatia=6, Other=7 };

int main()
{
    cout << "****************************\n";
    cout << "Please Enter the number of your country?\n";
    cout << "(1) USA\n";
    cout << "(2) UK\n";
    cout << "(3) France\n";
    cout << "(4) Mexico\n";
    cout << "(5) Serbia\n";
    cout << "(6) Croatia\n";
    cout << "(7) Other\n";
    cout << "****************************\n\n";
    cout << "Your Choice? ";
    
    int c;
    enCountryChoice Coutnry;

    cin >> c;
    Coutnry = (enCountryChoice) c;

    if (Coutnry == enCountryChoice::USA)
    {
        cout << "Your country is USA\n";
    }
    else if (Coutnry == enCountryChoice::UK)
    {
        cout << "Your country is UK\n";
    }
    else if (Coutnry == enCountryChoice::France)
    {
        cout << "Your country is France\n";
    }
    else if (Coutnry == enCountryChoice::Mexico)
    {
        cout << "Your country is Mexico\n";
    }
    else if (Coutnry == enCountryChoice::Serbia)
    {
        cout << "Your country is Serbia\n";
    }
    else if (Coutnry == enCountryChoice::Croatia)
    {
        cout << "Your country is Croatia\n";
    }
    else
    {
        cout << "Your country is Other\n";
    };

    return 0;
}