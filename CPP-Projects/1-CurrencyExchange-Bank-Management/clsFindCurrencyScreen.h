// Project: Currency Exchange
// clsFindCurrency.h

#pragma once

#include<iostream>
#include "clsInputValidate.h"

using namespace std;

class clsFindCurrencyScreen : protected clsScreen 
{
private:

	static void _PrintCurrencyCard(clsCurrency Currency)
	{
		cout << "\nCurrency Card";
		cout << "\n-------------------------------\n" ;
		cout << "Currency    : " << Currency.Country() << endl;
		cout << "Code	    : " << Currency.CurrencyCode() << endl;
		cout << "Name	    : " << Currency.CurrencyName() << endl;
		cout << "Rate($) =   : " << Currency.Rate() << endl;
		cout << "\n-------------------------------\n";

	}

	static string _ReadString()
	{
		string ReadCode = clsString::UpperAllString((clsInputValidate::ReadString()));
		return ReadCode;
	}

    static void _ShowResult(clsCurrency Currency)
	{
		if (!Currency.IsEmpty())
		{
			cout << "Currency Found :-)\n";
			_PrintCurrencyCard(Currency);
		}
		else
		{
			cout << "Currency NOT Found :-(\n";
		}
	}

	
public:
	static void ShowFindCurrencyScreen()
	{
		string Title = "Find Currency Screen";
		_DrawScreenHeader(Title);

		cout << "Find By: [1] Code Or [2] Country ? ";
		short Answer = clsInputValidate::ReadShortNumberBetween(1, 2);

		if (Answer == 1)
		{
			cout << "\nPlease Enter Currency Code: ";
			string sCurrency = _ReadString();
			
			clsCurrency Currency = clsCurrency::FindByCode(sCurrency);
			_ShowResult(Currency);
		}
		else
		{
			cout << "Please Enter Country Name: ";
			string sCurrency = _ReadString();
			clsCurrency Currency = clsCurrency::FindByCountry(sCurrency);
			_ShowResult(Currency);
		}

	}
};

