
// Project: Currency Exchange 
// clsCurrencyCalculatorScreen.h
#pragma once


class clsCurrencyCalculatorScreen : protected clsScreen  
{
private:
	static string _ReadCurrencyCode()
	{
		 string Currency = clsInputValidate::ReadString();
		 return Currency;
	}

	static float _ReadAmount()
	{
		float Amount;
		cout << "\nEnter the Amount to Exchange? ";
		Amount = clsInputValidate::ReadFloatNumber();
		return Amount;
	}

	static void _PrintCurrencyCard(clsCurrency Currency, string Title = "Currency Card:")
	{
		cout << endl << Title;
		cout << "\n_____________________________";
		cout << "\nCountry    : " << Currency.Country();
		cout << "\nCode       : " << Currency.CurrencyCode();
		cout << "\nName       : " << Currency.CurrencyName();
		cout << "\nRate(1$) = : " << Currency.Rate();

		cout << "\n_____________________________\n";
	}

	static clsCurrency _GetCurrency(string Message)
	{
		cout << Message << endl;
		string CurrencyCode = _ReadCurrencyCode();

		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			cout << "\nCurrency Not Found, Enter Another one? :";
			CurrencyCode = _ReadCurrencyCode();
		}

		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);

		return Currency;
	}

	static void _PrintCalculationResult(float Amount, clsCurrency Currency1, clsCurrency Currency2)
	{
		_PrintCurrencyCard(Currency1, "Convert From:");
		float AmountInUSD = Currency1.ConvertCurrencyToUSD(Amount);

		cout << Amount << " " << Currency1.CurrencyCode()
			<< " = " << AmountInUSD << " USD\n";
		
		if (Currency2.CurrencyCode() == "USD")
		{
			return;
		}


		  cout << "\nConverting from USD to:\n";
		_PrintCurrencyCard(Currency2, "To:");

		float AmountInCurrency2 = Currency1.ConvertUSDToOtherCurrency(Amount, Currency2);

		cout << Amount << " " << Currency1.CurrencyCode() << " = " << AmountInCurrency2 << " " << Currency2.CurrencyCode() << "\n";
		
	}


public:
	static void ShowCurrencyCalculatorScreen()
	{

		char Answer = 'y';
		
		while (Answer == 'y' || Answer == 'Y') 
		{
			system("cls");
			_DrawScreenHeader("Currency Calculator Screen");

			clsCurrency CurrencyFrom = _GetCurrency("Please Enter Currency1 Code:");

			clsCurrency CurrencyTo   = _GetCurrency("Please Enter Currency2 Code:");

			float Amount = _ReadAmount();

			_PrintCalculationResult(Amount, CurrencyFrom, CurrencyTo);

			cout << "\n\nDo you want to Perform another operation? y/n ?";
				cin >> Answer;

		}

	}

};

