// Project: Bank System
// clsTransferScreen.h
#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
using namespace std;

class clsTransferScreen : protected clsScreen
{
private:

	static string _ReadAccountNumber()
	{
		string AccountNumber;
		cout << "Please enter Account Number to Transfer from: ";
		AccountNumber = clsInputValidate::ReadString();
		cout << endl;

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "Account Not found, enter another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		return AccountNumber;
	}
	
	static void _PrintClientCard(clsBankClient Client)
	{
		cout << "Client card:\n";
		cout << "------------------\n";

		cout << "Full Name : " << Client.FullName() <<"\n";
		cout << "Acc.Number: " << Client.AccountNumber() <<"\n";
		cout << "Balance   : " << Client.AccountBalance <<"\n";
		cout <<"-------------------------\n\n";
	}

	static float _ReadAmount(clsBankClient ClientSource)
	{

		float Amount;
		cout << "\nEnter transfer Amount? ";

		Amount = clsInputValidate::ReadFloatNumber();

		while (ClientSource.AccountBalance < Amount)
		{
			cout << "\nAmount Exceeds the available Balance, Enter another Amount ? ";
			Amount = clsInputValidate::ReadFloatNumber();
		}

		return Amount;
	}

public:

	static void ShowTransferScreen() 
	{
		
		_DrawScreenHeader("Transfer Screen");

		clsBankClient ClientSource = clsBankClient::Find(_ReadAccountNumber());
		_PrintClientCard(ClientSource);

		clsBankClient ClientDestination = clsBankClient::Find(_ReadAccountNumber());
		_PrintClientCard(ClientDestination);
		
		float Amount = _ReadAmount(ClientSource);
	
		cout << "\nAre you sure to perform this operation? y/n:";
		char Answer = 'n';
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{
			if (ClientSource.Transfer(Amount, ClientDestination, CurrentUser.UserName))
				cout << "\nOperation succeeded :-)\n";
			else
				cout << "\nTransfer Faild \n";
		}

		_PrintClientCard(ClientSource);
		_PrintClientCard(ClientDestination);

	}
	
};

