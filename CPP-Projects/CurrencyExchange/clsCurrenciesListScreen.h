// Project: Currency Exchange
// clsListCurrenciesScreen.h

#pragma once
#include "clsScreen.h"
#include "clsCurrency.h"
#include <vector>


class clsListCurrenciesScreen : protected clsScreen  
{
private: 
	static void PrintCurrencyRecordLine(clsCurrency Currency)
	{

		cout << "| " << setw(10) << left << Currency.Country();
		cout << "| " << setw(8) << left << Currency.CurrencyCode();
		cout << "| " << setw(40) << left << Currency.CurrencyName();
		cout << "| " << setw(10) << left << Currency.Rate() << endl;

	}


public:
	static void _ShowCurrenciesListScreen()
	{
		vector<clsCurrency> vCurrencies =  clsCurrency::GetCurrenciesList();

		string Title = "Currencies List Screen";
		string SubTitle = "(   " + to_string(vCurrencies.size()) + ") Currency";

		_DrawScreenHeader(Title, SubTitle);

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_______________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(30) << "Country";
		cout << "| " << left << setw(8) << "Code";
		cout << "| " << left << setw(45) << "Name";
		cout << "| " << left << setw(10) << "Rate/(1$)";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_______________________________________________\n" << endl;

		if (vCurrencies.size() == 0)
		{
			cout << "There is no currency in the system\n\n";
		}
		else
		{
			for (clsCurrency &C : vCurrencies)
			{
				PrintCurrencyRecordLine(C);
			}
		}

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_______________________________________________\n" << endl;
	}
};

