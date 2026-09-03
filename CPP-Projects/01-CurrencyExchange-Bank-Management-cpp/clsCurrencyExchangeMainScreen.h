
// Project: Currency Exchange
// clsCurrencyExchangeMainScreen.h
#pragma once

#include "clsCurrenciesListScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyRateScreen.h"
#include "clsCurrencyCalculatorScreen.h"
#include <iomanip>

using namespace std;

class clsCurrencyExchangeMainScreen: protected clsScreen  
{
private:
	enum enCurrencyExchangeOption
	{ 
		eListCurrencies = 1, eFindCurrency = 2, 
		eUpdateCurrencyRate = 3, eCurrencyCalculator = 4, eMainMenu = 5
	};
	
	static void PrintCurrencyRecordLine(clsCurrency Currency)
	{
		cout << setw(8) << left << "" << "| " << setw(30) << left << Currency.Country();
		cout << "| " << setw(8) << left << Currency.CurrencyCode();
		cout << "| " << setw(45) << left << Currency.CurrencyName();
		cout << "| " << setw(10) << left << Currency.Rate();
	}

	static short _ReadCurrenciesMainMenuOptions()
	{
		cout << "\t\tChoose what do you want to do ? [1 to 5] ?\n";
		return clsInputValidate::ReadShortNumberBetween(1,5);
	}

	static void _ShowCurrenciesListScreen()
	{
		clsListCurrenciesScreen::_ShowCurrenciesListScreen();
	}

	static void _ShowFindCurrencyScreen()
	{
		clsFindCurrencyScreen::ShowFindCurrencyScreen();
	}

	static void _ShowUpdateCurrencyRateScreen()
	{
		clsUpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen();
	}

	static void _ShowCurrencyCalculatorScreen()
	{
		clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
	}

	static void _GoBackToCurrenciesMenuMessage()
	{
		cout << "\nPress any key to go back to Currency Exchange Menu ...\n";
		system("pause > 0");
		ShowCurrencyExchangeMainScreen();
	}

	static void _PerformCurrencyExchangeOperation(enCurrencyExchangeOption CurrenciesMainMenueOptions)
	{
		switch (CurrenciesMainMenueOptions)
		{
		case enCurrencyExchangeOption::eListCurrencies:
		{
			system("cls");
			_ShowCurrenciesListScreen();
			_GoBackToCurrenciesMenuMessage();
			break;
		}
		case enCurrencyExchangeOption::eFindCurrency:
		{
			system("cls");
			_ShowFindCurrencyScreen();
			_GoBackToCurrenciesMenuMessage();
			break;
		}
		case enCurrencyExchangeOption::eUpdateCurrencyRate:
		{
			system("cls");
			 _ShowUpdateCurrencyRateScreen();
			_GoBackToCurrenciesMenuMessage();
			break;
		}
		case enCurrencyExchangeOption::eCurrencyCalculator:
		{
			system("cls");
			_ShowCurrencyCalculatorScreen();
			_GoBackToCurrenciesMenuMessage();
			break;
		}
		//No need for "eMainMenu" as it will break out and back to the "main menu"!!!
			
		}

	}
	

public:

	static void ShowCurrencyExchangeMainScreen() // <----- nammed ShowCurrenciesMenu
	{
		if (!CheckAccessRights(clsUser::enPermissions::pCurrencyExchange))
		{
			return;// this will exit the function and it will not continue
		}

		string Title = "Currency Exchange Main Screen";

		system("cls");
		_DrawScreenHeader(Title);

		cout << "\t\t=========================================\n";
		cout << "\t\t\t\t Currency Exchange Menu\n";
		cout << "\t\t=========================================\n";
		cout << "\t\t\t[1] List Currencies."	 << endl;
		cout << "\t\t\t[2] Find Currency."		 << endl;
		cout << "\t\t\t[3] Update Rate."		 << endl;
		cout << "\t\t\t[4] Currency Calculator." << endl;
		cout << "\t\t\t[5] Main Menu."			 << endl;
		cout << "\t\t=========================================\t\n";

		_PerformCurrencyExchangeOperation(enCurrencyExchangeOption(_ReadCurrenciesMainMenuOptions()));
	}

};

