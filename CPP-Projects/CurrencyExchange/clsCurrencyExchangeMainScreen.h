// Course #11 - OOP as it Should Be (Applications)
// Lesson #44 Currency Calculator Screen
//   (Project 04: Currency Exchange 06)

// ** Mine **
#pragma once

#include "clsCurrenciesListScreen.h"
#include "clsFindCurrency.h"
#include "clsUpdateCurrencyRateScreen.h"
#include "clsCurrencyCalculatorScreen.h"

using namespace std;

class clsCurrencyExchangeMainScreen: protected clsScreen  // ** Mine **
{
private:
	static void PrintCurrencyRecordLine(clsCurrency Currency)
	{

		cout << setw(8) << left << "" << "| " << setw(30) << left << Currency.Country();
		cout << "| " << setw(8) << left << Currency.CurrencyCode();
		cout << "| " << setw(45) << left << Currency.CurrencyName();
		cout << "| " << setw(10) << left << Currency.Rate();

	}

	static short _ReadUserOption()
	{
		cout << "\t\tChoose what do you want to do ? [1 to 5] ?\n";
		return clsInputValidate::ReadShortNumberBetween(1,5);
	}

	enum enCurrencyExchangeOption{ 
		
		eListCurrencies = 1, eFindCurrency = 2, 
		eUpdateRate = 3, eCurrencyCalculator = 4
	};


	static void _ShowListCurrenciesScreen()
	{
		// cout << "here will be ListCurrencies Screen\n";
		clsListCurrenciesScreen::ShowListCurrenciesScreen();
	}

	static void _ShowFindCurrencyScreen()
	{
		//cout << "here will be Find Currency Screen\n";
		clsFindCurrency::ShowFindCurrencyScreen();
	}

	static void _ShowUpdateCurrencyRateScreen()
	{
		//cout << "here will be Update Rate Screen\n";
		clsUpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen();
	}

	static void _ShowCurrencyCalculatorScreen()
	{
		//cout << "here will be CurrencyCalculator Screen\n";
		clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
	}

	static void _GoBackToCurrenciesMenuMessage()
	{
		
		cout << "\nPress any key to go back to Currencies Menu ...\n";
		system("pause > 0");
		ShowCurrencyExchangeMainScreen();
	}


	static void _PerformCurrencyExchangeOperation(enCurrencyExchangeOption Option)
	{
		switch (Option)
		{
		case enCurrencyExchangeOption::eListCurrencies:
		{
			system("cls");
			_ShowListCurrenciesScreen();
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
		case enCurrencyExchangeOption::eUpdateRate:
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

	static void ShowCurrencyExchangeMainScreen()
	{
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
		_PerformCurrencyExchangeOperation(enCurrencyExchangeOption(_ReadUserOption()));

	}

};

