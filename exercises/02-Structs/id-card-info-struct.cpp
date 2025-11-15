// Structures 
// ID-Card-Info-struct

#include<iostream>

using namespace std;

struct st_ID {
    string name;
    int    age;
    char   gender;
    bool   Married;
};

struct st_Address {
    string City;
    string country;
};

struct st_ContactInfo {
    string  phoneNumber;
    st_ID      E_mail;
    st_Address Adress;
    string  socialMedia;
};

struct st_Income {
    float MonthlySalary = 5000;
    float YearlySalary = 60000;
};

struct st_Person {
    st_ID st_st_ID;
    st_ContactInfo st_st_ContactInfo;
    st_Address Address;
    st_Income st_st_Income;
};


int main()
{

    st_Person malik, wandaa, alisha;

    cout << "******************************************************************************************************************\n";

    malik.st_st_ID.name = "Malik Saber.";
    malik.st_st_ID.age = 44;
    malik.Address.City = "London.";
    malik.Address.country = "UK";
    malik.st_st_Income.MonthlySalary = 5000;
    malik.st_st_Income.YearlySalary = 60000;
    malik.st_st_ID.gender = 'M';
    malik.st_st_ID.Married = 1;


    cout << "Name: " << malik.st_st_ID.name << "\n" <<
        "Age : " << malik.st_st_ID.age << " Years." << "\n" <<
        "City: " << malik.Address.City << "\n";
    cout << "Country: " << malik.Address.country <<
        "\n" << "Monthly Salary: " << malik.st_st_Income.MonthlySalary << "\n"
        << "Yearly Salary: " << malik.st_st_Income.YearlySalary << "\n";

    cout << "Gender: " << malik.st_st_ID.gender << endl
        << "Married: " << malik.st_st_ID.Married << endl;

    cout << "\n" << "******************************************************************************************************************\n";

    return 0;
}

