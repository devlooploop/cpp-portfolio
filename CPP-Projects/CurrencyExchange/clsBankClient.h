// clsBankClient.h
#pragma once

#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include <vector>
#include <fstream>
#include "clsDate.h"

using namespace std;

class clsBankClient : public clsPerson
{
private:

	enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
	enMode _Mode;

	string _AccountNumber;
	string _PinCode;
	double _AccountBalance;
	bool _MarkedForDelete = false;


	//===============================================================
	// Convert Line To Client Object
	//===============================================================

	static clsBankClient _ConvertLinetoClientObject(string Line, string Seperator = "#//#")
	{
		vector<string> vClientData =
			clsString::Split(Line, Seperator);

		if (vClientData.size() != 7)
		{
			return _GetEmptyClientObject();
		}

		double AccountBalance;

		try
		{
			AccountBalance = stod(vClientData[6]);
		}
		catch (...)
		{
			return _GetEmptyClientObject();
		}

		return clsBankClient(
			enMode::UpdateMode,
			vClientData[0],
			vClientData[1],
			vClientData[2],
			vClientData[3],
			vClientData[4],
			vClientData[5],
			AccountBalance);
	}


	//===============================================================
	// Convert Client Object To Line
	//===============================================================

	static string _ConverClientObjectToLine(clsBankClient Client, string Seperator = "#//#")
	{
		string stClientRecord = "";

		stClientRecord += Client.FirstName + Seperator;
		stClientRecord += Client.LastName + Seperator;
		stClientRecord += Client.Email + Seperator;
		stClientRecord += Client.Phone + Seperator;
		stClientRecord += Client.AccountNumber() + Seperator;
		stClientRecord += Client.PinCode + Seperator;
		stClientRecord += to_string(Client.AccountBalance);

		return stClientRecord;
	}


	//===============================================================
	// Load Clients From File
	//===============================================================

	static vector<clsBankClient> _LoadClientsDataFromFile()
	{
		vector<clsBankClient> vClients;

		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				// Ignore empty or whitespace-only lines.
				if (clsString::Trim(Line) == "")
					continue;

				clsBankClient Client =
					_ConvertLinetoClientObject(Line);

				// Ignore malformed records.
				if (Client.IsEmpty())
					continue;

				vClients.push_back(Client);
			}

			MyFile.close();
		}

		return vClients;
	}


	//===============================================================
	// Save Clients To File
	//===============================================================

	static void _SaveCleintsDataToFile(vector<clsBankClient> vClients)
	{
		fstream MyFile;

		// ios::out overwrites the existing file.
		MyFile.open("Clients.txt", ios::out);

		if (MyFile.is_open())
		{
			string DataLine;

			for (clsBankClient C : vClients)
			{
				if (C.MarkedForDeleted() == false)
				{
					DataLine = _ConverClientObjectToLine(C);

					MyFile << DataLine << endl;
				}
			}

			MyFile.close();
		}
	}


	//===============================================================
	// Update
	//===============================================================

	void _Update()
	{
		vector<clsBankClient> _vClients;

		_vClients = _LoadClientsDataFromFile();

		for (clsBankClient& C : _vClients)
		{
			if (C.AccountNumber() == AccountNumber())
			{
				C = *this;
				break;
			}
		}

		_SaveCleintsDataToFile(_vClients);
	}


	//===============================================================
	// Add New
	//===============================================================

	void _AddNew()
	{
		_AddDataLineToFile(_ConverClientObjectToLine(*this));
	}

	void _AddDataLineToFile(string stDataLine)
	{
		fstream MyFile;

		MyFile.open("Clients.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{
			MyFile << stDataLine << endl;

			MyFile.close();
		}
	}


	//===============================================================
	// Get Empty Client Object
	//===============================================================

	static clsBankClient _GetEmptyClientObject()
	{
		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}


	//===============================================================
	// Transfer Log
	//===============================================================

	struct stTrnsferLogRecord;


	static stTrnsferLogRecord _ConvertTransferLogLineToRecord(string Line, string Seperator = "#//#")
	{
		
		stTrnsferLogRecord TrnsferLogRecord;

		vector<string> vTrnsferLogRecordLine =
			clsString::Split(Line, Seperator);

		
		if (vTrnsferLogRecordLine.size() != 7)
		{
			return TrnsferLogRecord;
		}

		try
		{
			TrnsferLogRecord.DateTime = vTrnsferLogRecordLine[0];

			TrnsferLogRecord.SourceAccountNumber = vTrnsferLogRecordLine[1];
				
			TrnsferLogRecord.DestinationAccountNumber = vTrnsferLogRecordLine[2];

			TrnsferLogRecord.Amount = stod(vTrnsferLogRecordLine[3]);

			TrnsferLogRecord.srcBalanceAfter = stod(vTrnsferLogRecordLine[4]);
				
			TrnsferLogRecord.destBalanceAfter = stod(vTrnsferLogRecordLine[5]);

			TrnsferLogRecord.UserName = vTrnsferLogRecordLine[6];
				
		}
		catch (...)
		{
			return stTrnsferLogRecord{};
		}

		return TrnsferLogRecord;
	}


	//===============================================================
	// Prepare Transfer Log Record
	//===============================================================

	string _PrepareTransferLogRecord(double Amount, clsBankClient DestinationClient, string UserName, string Seperator = "#//#")
	{

		string TransferLogRecord = "";

		TransferLogRecord += clsDate::GetSystemDateTimeString() + Seperator;
			
		TransferLogRecord += AccountNumber() + Seperator;

		TransferLogRecord += DestinationClient.AccountNumber() + Seperator;

		TransferLogRecord += to_string(Amount) + Seperator;

		TransferLogRecord += to_string(AccountBalance) + Seperator;

		TransferLogRecord += to_string(DestinationClient.AccountBalance) + Seperator;
		
		TransferLogRecord += UserName;


		return TransferLogRecord;
	}


	//===============================================================
	// Register Transfer Log
	//===============================================================

	void _RegisterTransferLog(double Amount, clsBankClient DestinationClient, string UserName)
	{
		string stDataLine =_PrepareTransferLogRecord(Amount, DestinationClient, UserName);

		fstream MyFile;

		MyFile.open( "TransfersLog.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{
			MyFile << stDataLine << endl;

			MyFile.close();
		}
	}


public:

	//===============================================================
	// Transfer Log Record
	//===============================================================

	struct stTrnsferLogRecord
	{
		string DateTime;
		string SourceAccountNumber;
		string DestinationAccountNumber;

		double Amount;
		double srcBalanceAfter;
		double destBalanceAfter;

		string UserName;
	};


	//===============================================================
	// Constructor
	//===============================================================

	clsBankClient( enMode Mode, string FirstName, string LastName, string Email, string Phone, string AccountNumber,
		string PinCode, double AccountBalance)
			: clsPerson(FirstName, LastName, Email, Phone)

	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;
	}


	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}


	bool MarkedForDeleted()
	{
		return _MarkedForDelete;
	}

	string AccountNumber()
	{
		return _AccountNumber;
	}


	void SetPinCode(string PinCode)
	{
		_PinCode = PinCode;
	}

	string GetPinCode()
	{
		return _PinCode;
	}

	__declspec(property(get = GetPinCode, put = SetPinCode))
		string PinCode;


	void SetAccountBalance(double AccountBalance)
	{
		_AccountBalance = AccountBalance;
	}

	double GetAccountBalance()
	{
		return _AccountBalance;
	}

	__declspec(property(get = GetAccountBalance, put = SetAccountBalance))
		double AccountBalance;


	//===============================================================
	// Find By Account Number
	//===============================================================

	static clsBankClient Find(string AccountNumber)
	{
		fstream MyFile;

		MyFile.open("Clients.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				// Ignore empty or whitespace-only lines.
				if (clsString::Trim(Line) == "")
					continue;

				clsBankClient Client =
					_ConvertLinetoClientObject(Line);

				// Ignore malformed records.
				if (Client.IsEmpty())
					continue;

				if (Client.AccountNumber() == AccountNumber)
				{
					MyFile.close();

					return Client;
				}
			}

			MyFile.close();
		}

		return _GetEmptyClientObject();
	}


	//===============================================================
	// Find By Account Number + Pin Code
	//===============================================================

	static clsBankClient Find(string AccountNumber, string PinCode)
	{
		fstream MyFile;

		MyFile.open("Clients.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				// Ignore empty or whitespace-only lines.
				if (clsString::Trim(Line) == "")
					continue;

				clsBankClient Client =
					_ConvertLinetoClientObject(Line);

				// Ignore malformed records.
				if (Client.IsEmpty())
					continue;

				if (Client.AccountNumber() == AccountNumber &&
					Client.PinCode == PinCode)
				{
					MyFile.close();

					return Client;
				}
			}

			MyFile.close();
		}

		return _GetEmptyClientObject();
	}


	//===============================================================
	// Save Results
	//===============================================================

	enum enSaveResults
	{
		svFaildEmptyObject = 0,
		svSucceeded = 1,
		svFaildAccountNumberExists = 2
	};


	//===============================================================
	// Save
	//===============================================================

	enSaveResults Save()
	{
		switch (_Mode)
		{
		case enMode::EmptyMode:
		{
			if (IsEmpty())
			{
				return enSaveResults::svFaildEmptyObject;
			}

			break;
		}

		case enMode::UpdateMode:
		{
			_Update();

			return enSaveResults::svSucceeded;
		}

		case enMode::AddNewMode:
		{
			if (clsBankClient::IsClientExist(_AccountNumber))
			{
				return enSaveResults::svFaildAccountNumberExists;
			}
			else
			{
				_AddNew();

				// After adding the client,
				// change mode to UpdateMode.
				_Mode = enMode::UpdateMode;

				return enSaveResults::svSucceeded;
			}
		}
		}

		return enSaveResults::svFaildEmptyObject;
	}


	//===============================================================
	// Is Client Exist
	//===============================================================

	static bool IsClientExist(string AccountNumber)
	{
		clsBankClient Client1 =
			clsBankClient::Find(AccountNumber);

		return (!Client1.IsEmpty());
	}


	//===============================================================
	// Delete
	//===============================================================

	bool Delete()
	{
		vector<clsBankClient> _vClients;

		_vClients = _LoadClientsDataFromFile();

		for (clsBankClient& C : _vClients)
		{
			if (C.AccountNumber() == _AccountNumber)
			{
				C._MarkedForDelete = true;

				break;
			}
		}

		_SaveCleintsDataToFile(_vClients);

		*this = _GetEmptyClientObject();

		return true;
	}


	//===============================================================
	// Get Add New Client Object
	//===============================================================

	static clsBankClient GetAddNewClientObject(string AccountNumber)
	{
		return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
	}


	//===============================================================
	// Get Clients List
	//===============================================================

	static vector<clsBankClient> GetClientsList()
	{
		return _LoadClientsDataFromFile();
	}


	//===============================================================
	// Deposit
	//===============================================================

	void Deposit(double Amount)
	{
		_AccountBalance += Amount;

		Save();
	}


	//===============================================================
	// Withdraw
	//===============================================================

	bool Withdraw(double Amount)
	{
		if (Amount <= 0 || Amount > _AccountBalance)
			return false;

		_AccountBalance -= Amount;
		Save();

		return true;
	}


	//===============================================================
	// Get Total Balances
	//===============================================================

	static double GetTotalBalances()
	{
		vector<clsBankClient> vClients = clsBankClient::GetClientsList();

		double TotalBalances = 0;

		for (clsBankClient Client : vClients)
		{
			TotalBalances += Client.AccountBalance;
		}

		return TotalBalances;
	}


	//===============================================================
	// Transfer
	//===============================================================

	bool Transfer(double Amount, clsBankClient& DestinationClient, string UserName)
	{
		// Don't allow transferring more than balance.
		if (Amount > AccountBalance)
		{
			return false;
		}

		// Withdraw first.
		if (!Withdraw(Amount))
		{
			return false;
		}

		// Deposit into destination.
		DestinationClient.Deposit(Amount);

		// Register transfer.
		_RegisterTransferLog(Amount, DestinationClient, UserName);

		return true;
	}


	//===============================================================
	// Get Transfers Log List
	//===============================================================

	static vector<stTrnsferLogRecord> GetTransfersLogList()
	{
		vector<stTrnsferLogRecord>
			vTransferLogRecord;

		fstream MyFile;

		MyFile.open("TransfersLog.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				// Ignore empty or whitespace-only lines.
				if (clsString::Trim(Line) == "")
					continue;

				vector<string> DataLine = clsString::Split(Line, "#//#");

				// A valid transfer record has 7 fields.
				if (DataLine.size() != 7)
					continue;

				stTrnsferLogRecord TransferRecord = _ConvertTransferLogLineToRecord(Line);

				vTransferLogRecord.push_back(TransferRecord);
				
			}

			MyFile.close();
		}

		return vTransferLogRecord;
	}

};