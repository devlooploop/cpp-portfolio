// Project: Bank System

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"

using namespace std;

class clsAddNewUsersScreen : protected clsScreen
{
private:

	static void _ReadUserInfo(clsUser &User)
	{
		
		cout << "Enter FirstName: ";
		User.FirstName =  clsInputValidate::ReadString();
		
		cout << "Enter LastName: ";
		User.LastName =  clsInputValidate::ReadString();
		
		cout << "Enter Email: ";
		User.Email =  clsInputValidate::ReadString();
		
		cout << "Enter Phone: ";
		User.Phone =  clsInputValidate::ReadString();

		cout << "Enter Password: ";
		User.Password = clsInputValidate::ReadString();

		cout << "Enter Permissions:\n";
		User.Permissions = _ReadPermissionsToSet();
	}


	static int _ReadPermissionsToSet()
	{
		int Permissions = 0;
		char Access = 'n';

		cout << "\nDo you want to give full access? y/n? ";
		cin >> Access;

		if (Access == 'y' || Access == 'Y')
		{
			return -1;
		}


		char Answer = 'n';
		cout << "\nDo you want to give access to:\n";

		cout << "Show Client List? y/n? ";
		cin >> Answer;
		if (Answer =='y' || Answer == 'Y')
		{
			 Permissions += clsUser::enPermissions::pListUsers;
		}

		cout << "\nAdd New Client ? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			 Permissions += clsUser::enPermissions::pAddNewUser;
		}

		cout << "\nDelete Client? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			 Permissions += clsUser::enPermissions::pDeleteUser;
		}

		cout << "\nUpdate Client? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			 Permissions += clsUser::enPermissions::pUpdateUser;
		}
		
		cout << "\nFind Client? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			 Permissions += clsUser::enPermissions::pFindUser;
		}

		cout << "\nTransactions? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pTranaction;
		}

		cout << "\nManage Users? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pManageUsers;
		}

		cout << "\nShow Login Register Screen? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pShowLoginRegisterList;
		}

		return Permissions;
	}

	static void _PrintUser(clsUser User)
	{
		cout << "\nUser Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << User.FirstName;
		cout << "\nLastName    : " << User.LastName;
		cout << "\nFull Name   : " << User.FullName();
		cout << "\nEmail       : " << User.Email;
		cout << "\nPhone       : " << User.Phone;
		cout << "\nUser Name   : " << User.UserName;
		cout << "\nPassword    : " << User.Password;
		cout << "\nPermissions : " << User.Permissions;
		cout << "\n___________________\n";

	}


public:

	static void ShowAddNewUserScreen()
	{
		_DrawScreenHeader("Add NewUser Screen");

		string UserName = "";
		cout << "Please enter UserName: ";
		UserName = clsInputValidate::ReadString();

		while (clsUser::IsUserExist(UserName))
		{
			cout << "User Already in use, chose another one: ";
			UserName = clsInputValidate::ReadString();
		}

		clsUser NewUser = clsUser::GetAddNewUserObject(UserName);

		_ReadUserInfo(NewUser);

		clsUser::enSaveResults SaveResult;
		
		SaveResult = NewUser.Save();

		switch (SaveResult)
		{
		case clsUser::enSaveResults::svFaildEmptyObject:
			
				cout << "Save failed due to empty object\n";
				break;

		case clsUser::enSaveResults::svSucceeded:
			cout << "Save Successed, User added -:) \n";
			_PrintUser(NewUser);
			break;

		case clsUser::enSaveResults::svFaildUserExists:
			
			cout << "User Already in use, save failed\n";
			break;
		
		}

	}
	
};
