// Project: Currency Exchange
// clsCurrency.h

#pragma once

#include<iostream>
#include<string>
#include "clsString.h"
#include <vector>
#include <fstream>

class clsCurrency 
{
private:
	enum enMode { eEmptyMode = 0, eUpdateMode = 1 };
	enMode _Mode;

	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	float _Rate;

	

	static clsCurrency _ConvertCurrencyLineToObject(string Line, string Delim = "#//#")
	{
		vector<string> vLine;
		vLine = clsString::Split(Line, Delim);

		return clsCurrency(enMode::eUpdateMode, vLine[0], vLine[1], vLine[2],
			stod(vLine[3]));
	}

	static string _ConvertCurrencyObjectToLine(clsCurrency Currency, string Delim = "#//#")
	{
		string CurrencyRecord = "";

		CurrencyRecord += Currency.Country() + Delim;
		CurrencyRecord += Currency.CurrencyCode() + Delim;
		CurrencyRecord += Currency.CurrencyName() + Delim;
		CurrencyRecord += to_string(Currency.Rate());

		return CurrencyRecord;
	}

	static vector <clsCurrency> _LoadCurrenciesFromFile()
	{
		
		vector <clsCurrency> vCurrencies;

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in); // read mode

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{

				clsCurrency Currency = _ConvertCurrencyLineToObject(Line);

				vCurrencies.push_back(Currency);
			}

			MyFile.close();
		}
		return vCurrencies;
	}

	static void _SaveCurrencyLineToFile(vector <clsCurrency> vCurrency)
	{
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::out); // overwrite

		string Record;

		if (MyFile.is_open())
		{
			for (clsCurrency C : vCurrency)
			{
				Record = _ConvertCurrencyObjectToLine(C);

				MyFile << Record << endl;
			}

			MyFile.close();

		}
	}

	void _Update()
	{
		vector <clsCurrency> _vCurrencies;
		_vCurrencies = _LoadCurrenciesFromFile();

		for (clsCurrency& C : _vCurrencies)
		{
			if (C.CurrencyCode() == CurrencyCode()) // this-> CurrencyCode() same as CurrencyCode()   
			{
				C = *this;
				break;
			}
		}

		_SaveCurrencyLineToFile(_vCurrencies);
	}


	static clsCurrency _GetEmptyCurrencyObject()
	{
		return clsCurrency(enMode::eEmptyMode, "", "", "", 0);
	}


public:

	clsCurrency(enMode Mode, string Country, string CurrencyCode, string CurrencyName, float Rate)
	{
		_Mode = Mode;
		_Country = Country;
		_CurrencyCode = CurrencyCode;
		_CurrencyName = CurrencyName;
		_Rate = Rate;
	}


	bool IsEmpty()
	{
		return (_Mode == enMode::eEmptyMode);
	}

	string Country()
	{
		return _Country;
	}

	// Getter for CurrencyCode
	string CurrencyCode()
	{
		return _CurrencyCode;
	}

	// Getter for CurrencyName
	string CurrencyName()
	{
		return _CurrencyName;
	}

	void UpdateRate(float NewRate)
	{
		_Rate = NewRate;
		_Update();
	}

	// Getter for Rate
	float Rate()
	{
		return _Rate;
	}

	static clsCurrency FindByCode(string CurrencyCode)
	{
		CurrencyCode = clsString::UpperAllString(CurrencyCode);

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in); // read mode

		
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{

				clsCurrency Currency = _ConvertCurrencyLineToObject(Line);

				if (Currency.CurrencyCode() == CurrencyCode)
				{
					MyFile.close();
					return Currency;

				}

			}

			MyFile.close();
		}

		return _GetEmptyCurrencyObject();

	}

	static clsCurrency FindByCountry(string Country)
	{

		Country = clsString::UpperAllString(Country);

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in); // read mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{

				clsCurrency Currency = _ConvertCurrencyLineToObject(Line);

				if (clsString::UpperAllString(Currency.Country()) == Country)
				{
					MyFile.close();
					return Currency;

				}

			}

			MyFile.close();
		}

		return _GetEmptyCurrencyObject();
	}

	static bool IsCurrencyExist(string CurrencyCode)
	{
		clsCurrency C1 = clsCurrency::FindByCode(CurrencyCode); 

		return (!C1.IsEmpty());
	}

	static vector <clsCurrency> GetCurrenciesList() 
	{
		return _LoadCurrenciesFromFile();
	}

	float ConvertCurrencyToUSD(float Amount)
	{
		return (float) (Amount / Rate());
	}

	// Currency1 --> USD 
	// USD-- > Currency2
	float ConvertUSDToOtherCurrency(float Amount, clsCurrency Currency2)
	{
		float AmountInUSD = ConvertCurrencyToUSD(Amount);

		if (Currency2.CurrencyCode() == "USD")
		{
			return AmountInUSD;
		}

		return (float) (Currency2.Rate() * AmountInUSD);

	}

};

