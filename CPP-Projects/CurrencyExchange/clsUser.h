#pragma once

#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include <vector>
#include <fstream>
#include "clsDate.h"
#include "clsUtil.h"

using namespace std;

class clsUser : public clsPerson
{
private:

    enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };

    enMode _Mode;
    string _UserName;
    string _Password;
    string _EncryptedPassword;
    int _Permissions;

    bool _MarkedForDelete = false;


    //===============================================================
    // Login Register
    //===============================================================

    struct stLoginRegisterRecord;

    static stLoginRegisterRecord _ConvertLoginRegisterLineToRecord(
        string Line, string Seperator = "#//#")
    {
        stLoginRegisterRecord LoginRegisterRecord;

        vector<string> LoginRegisterDataLine =
            clsString::Split(Line, Seperator);

        // Make sure the line contains:
        // DateTime #//# UserName #//# Password #//# Permissions
        if (LoginRegisterDataLine.size() < 4)
        {
            return LoginRegisterRecord;
        }

        LoginRegisterRecord.DateTime = LoginRegisterDataLine[0];
        LoginRegisterRecord.UserName = LoginRegisterDataLine[1];
        LoginRegisterRecord.Password =
            clsUtil::DecryptText(LoginRegisterDataLine[2]);

        try
        {
            LoginRegisterRecord.Permissions =
                stoi(LoginRegisterDataLine[3]);
        }
        catch (...)
        {
            LoginRegisterRecord.Permissions = 0;
        }

        return LoginRegisterRecord;
    }


    string _PrepareLogInRecord(string Seperator = "#//#")
    {
        string LoginRecord = "";

        LoginRecord += clsDate::GetSystemDateTimeString() + Seperator;
        LoginRecord += UserName + Seperator;

        // We encrypt and store the encrypted password,
        // not the real password.
        LoginRecord += clsUtil::EncryptText(Password) + Seperator;

        LoginRecord += to_string(Permissions);

        return LoginRecord;
    }


    //===============================================================
    // Convert Line -> User Object
    //===============================================================

    static clsUser _ConvertLinetoUserObject(
        string Line, string Seperator = "#//#")
    {
        vector<string> vUserData =
            clsString::Split(Line, Seperator);

        // A valid user record must contain 7 fields:
        //
        // 0 FirstName
        // 1 LastName
        // 2 Email
        // 3 Phone
        // 4 UserName
        // 5 Password
        // 6 Permissions

        if (vUserData.size() != 7)
        {
            return _GetEmptyUserObject();
        }

        int Permissions;

        try
        {
            Permissions = stoi(vUserData[6]);
        }
        catch (...)
        {
            return _GetEmptyUserObject();
        }

        return clsUser(
            enMode::UpdateMode,
            vUserData[0],
            vUserData[1],
            vUserData[2],
            vUserData[3],
            vUserData[4],
            clsUtil::DecryptText(vUserData[5]),
            Permissions
        );
    }


    //===============================================================
    // Convert User Object -> Line
    //===============================================================

    static string _ConverUserObjectToLine(
        clsUser User, string Seperator = "#//#")
    {
        string UserRecord = "";

        UserRecord += User.FirstName + Seperator;
        UserRecord += User.LastName + Seperator;
        UserRecord += User.Email + Seperator;
        UserRecord += User.Phone + Seperator;
        UserRecord += User.UserName + Seperator;

        // Encrypt password before storing it.
        UserRecord += clsUtil::EncryptText(User.Password) + Seperator;

        UserRecord += to_string(User.Permissions);

        return UserRecord;
    }


    //===============================================================
    // Load Users
    //===============================================================

    static vector<clsUser> _LoadUsersDataFromFile()
    {
        vector<clsUser> vUsers;

        fstream MyFile;
        MyFile.open("Users.txt", ios::in);

        if (MyFile.is_open())
        {
            string Line;

            while (getline(MyFile, Line))
            {
                // Ignore empty or whitespace-only lines.
                if (clsString::Trim(Line) == "")
                    continue;

                clsUser User = _ConvertLinetoUserObject(Line);

                // Ignore malformed records.
                if (User.IsEmpty())
                    continue;

                vUsers.push_back(User);
            }

            MyFile.close();
        }

        return vUsers;
    }


    //===============================================================
    // Save Users
    //===============================================================

    static void _SaveUsersDataToFile(vector<clsUser> vUsers)
    {
        fstream MyFile;

        // ios::out overwrites the existing file.
        MyFile.open("Users.txt", ios::out);

        if (MyFile.is_open())
        {
            string DataLine;

            for (clsUser U : vUsers)
            {
                if (U.MarkedForDeleted() == false)
                {
                    DataLine = _ConverUserObjectToLine(U);

                    MyFile << DataLine << endl;
                }
            }

            MyFile.close();
        }
    }


    //===============================================================
    // Update
    //===============================================================

    void _Update()
    {
        vector<clsUser> _vUsers;

        _vUsers = _LoadUsersDataFromFile();

        for (clsUser& U : _vUsers)
        {
            if (U.UserName == UserName)
            {
                U = *this;
                break;
            }
        }

        _SaveUsersDataToFile(_vUsers);
    }


    //===============================================================
    // Add New
    //===============================================================

    void _AddNew()
    {
        _AddDataLineToFile(
            _ConverUserObjectToLine(*this)
        );
    }


    void _AddDataLineToFile(string stDataLine)
    {
        fstream MyFile;

        MyFile.open("Users.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {
            MyFile << stDataLine << endl;

            MyFile.close();
        }
    }


    //===============================================================
    // Empty User
    //===============================================================

    static clsUser _GetEmptyUserObject()
    {
        return clsUser(
            enMode::EmptyMode,
            "",
            "",
            "",
            "",
            "",
            "",
            0
        );
    }


    static string EnctyptedPassword(string Password)
    {
        return clsUtil::EncryptText(Password);
    }


public:

    //===============================================================
    // Permissions
    //===============================================================

    enum enPermissions
    {
        eAll = -1,
        pListUsers = 1,
        pAddNewUser = 2,
        pDeleteUser = 4,
        pUpdateUser = 8,
        pFindUser = 16,
        pTranaction = 32,
        pManageUsers = 64,
        pShowLoginRegisterList = 128
    };


    //===============================================================
    // Login Register Record
    //===============================================================

    struct stLoginRegisterRecord
    {
        string DateTime;
        string UserName;
        string Password;
        int Permissions = 0;
    };


    //===============================================================
    // Constructor
    //===============================================================

    clsUser(
        enMode Mode,
        string FirstName,
        string LastName,
        string Email,
        string Phone,
        string UserName,
        string Password,
        int Permissions)
        : clsPerson(FirstName, LastName, Email, Phone)
    {
        _Mode = Mode;
        _UserName = UserName;
        _Password = Password;
        _Permissions = Permissions;
    }


    //===============================================================
    // Is Empty
    //===============================================================

    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }


    //===============================================================
    // Delete Mark
    //===============================================================

    bool MarkedForDeleted()
    {
        return _MarkedForDelete;
    }


    //===============================================================
    // UserName
    //===============================================================

    string GetUserName()
    {
        return _UserName;
    }

    void SetUserName(string UserName)
    {
        _UserName = UserName;
    }

    __declspec(property(get = GetUserName, put = SetUserName))
        string UserName;


    //===============================================================
    // Password
    //===============================================================

    void SetPassword(string Password)
    {
        _Password = Password;
    }

    string GetPassword()
    {
        return _Password;
    }

    __declspec(property(get = GetPassword, put = SetPassword))
        string Password;


    //===============================================================
    // Permissions
    //===============================================================

    void SetPermissions(int Permissions)
    {
        _Permissions = Permissions;
    }

    int GetPermissions()
    {
        return _Permissions;
    }

    __declspec(property(get = GetPermissions, put = SetPermissions))
        int Permissions;


    //===============================================================
    // Find By UserName
    //===============================================================

    static clsUser Find(string UserName)
    {
        fstream MyFile;

        MyFile.open("Users.txt", ios::in);

        if (MyFile.is_open())
        {
            string Line;

            while (getline(MyFile, Line))
            {
                // Ignore empty or whitespace-only lines.
                if (clsString::Trim(Line) == "")
                    continue;

                clsUser User = _ConvertLinetoUserObject(Line);

                // Ignore malformed records.
                if (User.IsEmpty())
                    continue;

                if (User.UserName == UserName)
                {
                    MyFile.close();

                    return User;
                }
            }

            MyFile.close();
        }

        return _GetEmptyUserObject();
    }


    //===============================================================
    // Find By UserName + Password
    //===============================================================

    static clsUser Find(string UserName, string Password)
    {
        fstream MyFile;

        MyFile.open("Users.txt", ios::in);

        if (MyFile.is_open())
        {
            string Line;

            while (getline(MyFile, Line))
            {
                // Ignore empty or whitespace-only lines.
                if (clsString::Trim(Line) == "")
                    continue;

                clsUser User = _ConvertLinetoUserObject(Line);

                // Ignore malformed records.
                if (User.IsEmpty())
                    continue;

                if (User.UserName == UserName &&
                    User.Password == Password)
                {
                    MyFile.close();

                    return User;
                }
            }

            MyFile.close();
        }

        return _GetEmptyUserObject();
    }


    //===============================================================
    // Save Results
    //===============================================================

    enum enSaveResults
    {
        svFaildEmptyObject = 0,
        svSucceeded = 1,
        svFaildUserExists = 2
    };


    //===============================================================
    // Save
    //===============================================================

    enSaveResults Save()
    {
        switch (_Mode)
        {
        case enMode::EmptyMode:
        {
            if (IsEmpty())
            {
                return enSaveResults::svFaildEmptyObject;
            }

            break;
        }

        case enMode::UpdateMode:
        {
            _Update();

            return enSaveResults::svSucceeded;
        }

        case enMode::AddNewMode:
        {
            if (clsUser::IsUserExist(_UserName))
            {
                return enSaveResults::svFaildUserExists;
            }

            else
            {
                _AddNew();

                // After adding the user,
                // change mode to UpdateMode.
                _Mode = enMode::UpdateMode;

                return enSaveResults::svSucceeded;
            }
        }
        }

        return enSaveResults::svFaildEmptyObject;
    }


    //===============================================================
    // Is User Exist
    //===============================================================

    static bool IsUserExist(string UserName)
    {
        clsUser User = clsUser::Find(UserName);

        return (!User.IsEmpty());
    }


    //===============================================================
    // Delete
    //===============================================================

    bool Delete()
    {
        vector<clsUser> _vUsers;

        _vUsers = _LoadUsersDataFromFile();

        for (clsUser& U : _vUsers)
        {
            if (U.UserName == _UserName)
            {
                U._MarkedForDelete = true;

                break;
            }
        }

        _SaveUsersDataToFile(_vUsers);

        *this = _GetEmptyUserObject();

        return true;
    }


    //===============================================================
    // Get Add New User Object
    //===============================================================

    static clsUser GetAddNewUserObject(string UserName)
    {
        return clsUser(
            enMode::AddNewMode,
            "",
            "",
            "",
            "",
            UserName,
            "",
            0
        );
    }


    //===============================================================
    // Get Users List
    //===============================================================

    static vector<clsUser> GetUsersList()
    {
        return _LoadUsersDataFromFile();
    }


    //===============================================================
    // Check Access Permission
    //===============================================================

    bool CheckAccessPermission(enPermissions Permission)
    {
        if (this->Permissions == enPermissions::eAll)
            return true;

        if ((Permission & this->Permissions) == Permission)
            return true;

        return false;
    }


    //===============================================================
    // Register Login
    //===============================================================

    void RegisterLogIn()
    {
        string stDataLine = _PrepareLogInRecord();

        fstream MyFile;

        MyFile.open(
            "LoginRegister.txt",
            ios::out | ios::app
        );

        if (MyFile.is_open())
        {
            MyFile << stDataLine << endl;

            MyFile.close();
        }
    }


    //===============================================================
    // Get Login Register List
    //===============================================================

    static vector<stLoginRegisterRecord> GetLoginRegisterList()
    {
        vector<stLoginRegisterRecord> vLoginRegisterRecord;

        fstream MyFile;

        MyFile.open("LoginRegister.txt", ios::in);

        if (MyFile.is_open())
        {
            string Line;

            while (getline(MyFile, Line))
            {
                // Ignore empty or whitespace-only lines.
                if (clsString::Trim(Line) == "")
                    continue;

                vector<string> DataLine =
                    clsString::Split(Line, "#//#");

                // A login record must have 4 fields.
                if (DataLine.size() != 4)
                    continue;

                stLoginRegisterRecord LoginRegisterRecord =
                    _ConvertLoginRegisterLineToRecord(Line);

                vLoginRegisterRecord.push_back(
                    LoginRegisterRecord
                );
            }

            MyFile.close();
        }

        return vLoginRegisterRecord;
    }

};