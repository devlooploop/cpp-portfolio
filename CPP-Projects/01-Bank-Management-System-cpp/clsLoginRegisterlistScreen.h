// Project: Bank System

#pragma once

#include <iostream>
#include "clsUser.h"
using namespace std;


class clsLoginRegisterListScreen : protected clsScreen  
{
private:

	static void _PrintLoginRegisterList(clsUser::stLoginRegisterRecord LoginRegisterRecord)
	{
		cout << setw(8) << left << "" << "| " << setw(35) << left << LoginRegisterRecord.DateTime;
		cout << "| " << setw(20) << left << LoginRegisterRecord.UserName;
		cout << "| " << setw(20) << left << LoginRegisterRecord.Password;
		cout << "| " << setw(10) << left << LoginRegisterRecord.Permissions;
	}


public:
	static void ShowLoginRegisterListScreen()
	{
		string Title = "Login Register List Screen";
		string SubTitle = to_string(clsUser::GetRegisterLoginUsersList().size()) + " Record(s).";


		_DrawScreenHeader(Title, SubTitle);

		if (clsUser::GetRegisterLoginUsersList().size() == 0)
		{
			cout << "No Users Logged in the system\n";
		}
		else
		{
			vector <clsUser::stLoginRegisterRecord> vLoginRegisterRecord;
			vLoginRegisterRecord = clsUser::GetRegisterLoginUsersList();

			for (clsUser::stLoginRegisterRecord & R: vLoginRegisterRecord)
			{
				_PrintLoginRegisterList(R) ;
				cout << endl;
			}
		}

	}


};
