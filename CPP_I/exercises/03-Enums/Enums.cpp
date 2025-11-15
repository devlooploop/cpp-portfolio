
// Enums- C++



#include<iostream>
#include<string>

using namespace std;

enum en_Marital_status { Married = 1, Single };
enum en_Salary { monthly = 5000, yearly = 60000 };
enum en_Age { Age = 44 };
enum en_Enumst_ContactInfo { phoneNumber = 1009238459 };
enum en_Gender { Male, Female };
enum en_Color { green, red, black, blue };

struct st_ID {
    string name;
    char en_Gender;
    // bool Married = true;

};

struct st_Address {
    string City;
    string country;
};

struct st_ContactInfo {
    string E_mail;
    st_Address st_adress;
    string socialMedia;
};

struct st_Income {
    float Monthlyen_Salary = 5000;
    float Yearlyen_Salary = 60000;
};

struct st_Person {
    st_ID st_st_ID;
    st_ContactInfo st_st_ContactInfo;
    st_Address st_st_Address;
    st_Income st_st_Income;
};

int main()
{

    st_Person alisha, alikhan, Mari;
    en_Color favoriteen_Color;

   
    alisha.st_st_ID.name = "Alisha Malik";
    alisha.st_st_Address.City = "Roma";
    alisha.st_st_Address.country = "Italy";
    alisha.st_st_ContactInfo.E_mail = "Myemail.gmail.com";
    alisha.st_st_ContactInfo.socialMedia = "Instagram";
    favoriteen_Color = en_Color::red;

    cout << "\n" << "*******************************************************************************************" << endl;

    cout << "Name: " << alisha.st_st_ID.name << "\n" << "en_Age: " << en_Age::Age << "\n" << "City: " << alisha.st_st_Address.City << "\n";

    cout << "Country: " << alisha.st_st_Address.country << "\n" << "Monthly Salary: "
        << en_Salary::monthly << "\n" << "Yearly Salary: " << en_Salary::yearly << "\n";

    cout << "Gender: " <<  en_Gender::Male << "\n" << "Married: " << en_Marital_status::Married << "\n" <<
        "Phone Number: " << en_Enumst_ContactInfo::phoneNumber;
    cout << "\n" << "Contact Info: " << alisha.st_st_ContactInfo.socialMedia << "\n" << "Favorite Color: " << favoriteen_Color << "\n";

    cout << "*******************************************************************************************" << endl;


    return 0;

}


