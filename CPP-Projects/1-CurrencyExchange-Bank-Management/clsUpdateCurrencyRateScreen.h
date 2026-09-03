
// Project: Currency Exchange
// clsUpdateCurrencyRateScreen.h

#pragma once
#include "clsScreen.h"


class clsUpdateCurrencyRateScreen :protected clsScreen 
{

private:

	static void _PrintCurrency(clsCurrency Currency)
	{
		cout << "\nCurrency Card:\n";
		cout << "_____________________________\n";
		cout << "\nCountry    : " << Currency.Country();
		cout << "\nCode       : " << Currency.CurrencyCode();
		cout << "\nName       : " << Currency.CurrencyName();
		cout << "\nRate(1$) = : " << Currency.Rate();

		cout << "\n_____________________________\n";
	}

	static void _ShowUpdateResult(clsCurrency Currency1)
	{
		if (!Currency1.IsEmpty())
		{
			cout << "\nUpdate Currency rate\n";
			cout << "-------------------------\n";

			
			Currency1.UpdateRate(_ReadRate());

			cout << "\nCurrency rate Updated Successfully :-)\n";
			_PrintCurrency(Currency1);
		}
		else
		{
			cout << "Currency Not Found :-( \n";
		}

	}

	static float _ReadRate()
	{
		cout << "Enter new rate?";
		float NewRate;
		NewRate = clsInputValidate::ReadFloatNumber();
		return NewRate;
	}


public:

	static void ShowUpdateCurrencyRateScreen()
	{
		string Title = "    Update Currency Screen";
		_DrawScreenHeader(Title);

		string CurrencyCode = ""; 
		cout << "Please enter Currency Code: ";
		CurrencyCode = clsInputValidate::ReadString();
		
		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			cout << "Currency does not, enter another one : ";
			CurrencyCode = clsInputValidate::ReadString();
		}

		clsCurrency Currency1 = clsCurrency::FindByCode(CurrencyCode);

		_PrintCurrency(Currency1);

		char Answer = 'n';
		cout << "\nAre you sure you want to update the rate of this Currency y / n ? ";
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{
			_ShowUpdateResult(Currency1);
		}

	}


};

