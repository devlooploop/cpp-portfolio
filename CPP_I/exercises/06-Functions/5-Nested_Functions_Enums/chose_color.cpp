
// Nested Functions with Enums


#include <iostream>
using namespace std;

enum enScreenColor { Red = 1, Blue = 2, Green = 3, Yellow = 4 };

void ShowColorMenue()
{
    cout << "****************************\n";
    cout << "Please Chose the number of your color?\n";
    cout << "(1) Red\n";
    cout << "(2) Blue\n";
    cout << "(3) Green\n";
    cout << "(4) Yellow\n";
    cout << "****************************\n\n";
    cout << "Your Choice? ";
}

enScreenColor ReadColor() {
    int c;
    cin >> c;
    return (enScreenColor)c;
}

void GetColor(enScreenColor color)
{
    switch (color) 
    {
    case enScreenColor::Red:

        system("color 4F");
         break;

    case enScreenColor::Blue:

        system("color 1F");
         break;

    case enScreenColor::Green:

        system("color 2F");
         break;

       case enScreenColor::Yellow:

       system("color 6F");
        break;

    default:
        system("color 4F");
         break;

    }
}

int main()
{
    
    ShowColorMenue();
    GetColor(ReadColor());
    
    return 0;
}