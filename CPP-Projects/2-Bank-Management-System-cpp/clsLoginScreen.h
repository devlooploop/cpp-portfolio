// Project: Bank System

#pragma once

#include <iostream>
#include "clsScreen.h"
#include "Global.h"
#include "clsUser.h"
#include "clsMainScreen.h"


using namespace std;

class clsLoginScreen : protected clsScreen 
{
private:
	static bool _Login()
	{
		string UserName, Password;
		bool LoginFailed = false;
		short TrailsLogin = 3;

		do
		{
		     if (LoginFailed)
			 {
				//TrailsLogin--;
				cout << "\n\nInvalid User Name/Password\n"
					<< "You have [" << TrailsLogin << "] trails left\n\n";
			 }

			cout << "\nEnter UserName ";
			cin >> UserName;

			cout << "Enter Password ";
			cin >> Password;


			CurrentUser = clsUser::Find(UserName, Password);

			LoginFailed = CurrentUser.IsEmpty();
			
			if (LoginFailed)
			{
				TrailsLogin--;
			}

		} while (LoginFailed && TrailsLogin !=0);

		if (TrailsLogin == 0)
		{
			cout << "\n\nInvalid User Name/Password\n" <<
				"You have [" << TrailsLogin << "] trails left\n\n"
				<< "You are locked out after 3 failed trails! \n";
			return false;
		}
		else
		{
			clsMainScreen::ShowMainMenu();
		}
		
		return true;

	}

public:
	static bool ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("Login Screen");

		/*if (true)
		{
			return _Login();
		}*/
		
		return _Login();
	}
};
