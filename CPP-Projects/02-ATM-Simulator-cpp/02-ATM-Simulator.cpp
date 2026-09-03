// Project: ATM System
/*
   Description:
      Console-based ATM with user login, quick/normal withdraw, deposit, balance check and logout.

        - Data stored in Clients.txt file.
        - Use Clients.txt file as the data base.

   NOTE:
        This is a console-based demo project.
        PINs are intentionally stored as plain text in Clients.txt.

*/

#include<iostream>
#include <string>
#include <vector>
#include<iomanip>
#include<fstream>
#include <limits>

using namespace std;

struct stClient
{
    string AccountNumber;
    string PINCode;
    string Name;
    string Phone;
    double Balance = 0;

    bool MarkForDelete = false;
};

enum enATMChoicesMainMenu
{
    eQuickWithdraw = 1,
    eNormalWithdraw = 2,
    eDeposit = 3,
    eCheckBalance = 4,
    eLogout = 5
};

const string ClientsFileName = "Clients.txt";
stClient CurrentClient;


//============================================================
// Function Prototypes
//============================================================

void Login();
void ATMMainMenuScreen();
void NormalWithdrawScreen();
void QuickWithdrawScreen();

stClient ReadClientAccountAndPin();

vector<string> SplitString(string S1, string Delim);

bool TryConvertLineToClientRecord(string Line, stClient& Client, string Delim = "#//#");

string ConvertRecordToLine(stClient Client, string Delim);

vector<stClient> LoadCleintLineFromFileToVector(string FileName);

bool SaveCleintsDataToFile(string FileName, vector<stClient> vClients);

bool FindClientByAccountNumberAndPinCode(string AccountNumber, string PinCode, stClient& Client);

bool LoadClientInfo(string AccountNumber, string PinCode);

short ReadATMScreenChoices();

void GoBackMessage();

void CheckBalanceScreen();

short ReadWithdrawChoice();

bool UpdateClientBalanceByAccountNumber(string AccountNumber, double Amount, vector<stClient>& vClients);

double ReadDepositAmount();

void DepositPerform();

void DepositScreen();

short GetQuickWithdrawAmount(short QuickWithDrawOption);

void PerfromQuickWithdrawOption(short QuickWithDrawOption);

void QuickWithdrawScreen();

void ATMMainMenuPerform(enATMChoicesMainMenu ATMOptions);

int ReadNormalWithdrawAmount();

void NormalWithdrawPerform();

void NormalWithdrawScreen();


//============================================================
// Read Account Number and PIN
//============================================================

stClient ReadClientAccountAndPin()
{
    stClient Client;

    cout << "Enter Account Number? ";
    cin >> Client.AccountNumber;

    cout << "Enter PIN Code Number? ";
    cin >> Client.PINCode;

    return Client;
}


//============================================================
// Split String
//============================================================

vector<string> SplitString(string S1, string Delim = "#//#")
{
    vector<string> vString;
    size_t pos = 0;
    string sWord;

    while ((pos = S1.find(Delim)) != string::npos)
    {
        sWord = S1.substr(0, pos);

        if (sWord != "")
            vString.push_back(sWord);

        S1.erase(0, pos + Delim.length());
    }

    if (S1 != "")
        vString.push_back(S1);

    return vString;
}


//============================================================
// Convert Line To Client
//============================================================

bool TryConvertLineToClientRecord(string Line, stClient& Client, string Delim)
{
    vector<string> vClientsString = SplitString(Line, Delim);

    if (vClientsString.size() != 5)
        return false;

    try
    {
        Client.AccountNumber = vClientsString[0];
        Client.PINCode = vClientsString[1];
        Client.Name = vClientsString[2];
        Client.Phone = vClientsString[3];
        Client.Balance = stod(vClientsString[4]);

        return true;
    }
    catch (...)
    {
        return false;
    }
}


//============================================================
// Convert Client Record To Line
//============================================================

string ConvertRecordToLine(stClient Client, string Delim = "#//#")
{
    string ClientLine;

    ClientLine = "";

    ClientLine += Client.AccountNumber + Delim;
    ClientLine += Client.PINCode + Delim;
    ClientLine += Client.Name + Delim;
    ClientLine += Client.Phone + Delim;
    ClientLine += to_string(Client.Balance);

    return ClientLine;
}


//============================================================
// Load Clients From File
//============================================================

vector<stClient> LoadCleintLineFromFileToVector(string FileName)
{
    vector<stClient> vClients;

    fstream MyFile;
    MyFile.open(FileName, ios::in);

    if (MyFile.is_open())
    {
        string Line;
        stClient Client;

        while (getline(MyFile, Line))
        {
            if (Line.empty())
                continue;

            if (TryConvertLineToClientRecord(Line, Client))
            {
                vClients.push_back(Client);
            }
            else
            {
                cout << "\nWarning: Invalid client record skipped.\n";
            }
        }

        MyFile.close();
    }
    else
    {
        cout << "\nError: Could not open " << FileName << ".\n";
    }

    return vClients;
}


//============================================================
// Save Clients To File
//============================================================

bool SaveCleintsDataToFile(string FileName, vector<stClient> vClients)
{
    fstream MyFile;
    MyFile.open(FileName, ios::out);

    if (!MyFile.is_open())
    {
        cout << "\nError: Could not save data to " << FileName << ".\n";
        return false;
    }

    string Line;

    for (stClient& i : vClients)
    {
        if (i.MarkForDelete == false)
        {
            Line = ConvertRecordToLine(i, "#//#");
            MyFile << Line << endl;
        }
    }

    MyFile.close();

    return true;
}


//============================================================
// Find Client By Account Number And PIN
//============================================================

bool FindClientByAccountNumberAndPinCode(string AccountNumber, string PinCode, stClient& Client)
{
    vector<stClient> vClientsString =
        LoadCleintLineFromFileToVector(ClientsFileName);

    for (stClient& i : vClientsString)
    {
        if (i.AccountNumber == AccountNumber && i.PINCode == PinCode)
        {
            Client = i;
            return true;
        }
    }

    return false;
}


//============================================================
// Load Client Info
//============================================================

bool LoadClientInfo(string AccountNumber, string PinCode)
{
    if (FindClientByAccountNumberAndPinCode(AccountNumber, PinCode, CurrentClient))
        return true;
    else
        return false;
}


//============================================================
// Read ATM Screen Choices
//============================================================

short ReadATMScreenChoices()
{
    short Choice;

    do
    {
        cout << "Chose what do you want to do? [1 to 5]? ";
        cin >> Choice;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            Choice = 0;
        }

    } while (Choice < 1 || Choice > 5);

    return Choice;
}


//============================================================
// Go Back Message
//============================================================

void GoBackMessage()
{
    cout << "\n\nPress any key to go back to Main Menu ...\n";
    system("pause > 0");

    ATMMainMenuScreen();
}


//============================================================
// Check Balance
//============================================================

void CheckBalanceScreen()
{
    cout << "=================================\n";
    cout << "\tCheck Balance Screen\n";
    cout << "=================================\n";
    cout << fixed << setprecision(2);
    cout << "Your Balance is " << CurrentClient.Balance << endl;
}


//============================================================
// Read Withdraw Choice
//============================================================

short ReadWithdrawChoice()
{
    short Choice;

    do
    {
        cout << "Chose what to withdraw from[1] to [9] ? ";
        cin >> Choice;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            Choice = 0;
        }

    } while (Choice < 1 || Choice > 9);

    return Choice;
}


//============================================================
// Update Client Balance
//============================================================

bool UpdateClientBalanceByAccountNumber(string AccountNumber, double Amount, vector<stClient>& vClients)
{
    char Answer = 'n';

    cout << "\n\nAre you sure you want to perform this transaction? (y/n) ";
    cin >> Answer;

    if (Answer == 'y' || Answer == 'Y')
    {
        for (stClient& C : vClients)
        {
            if (C.AccountNumber == AccountNumber)
            {
                if (C.Balance + Amount < 0)
                {
                    cout << "\nTransaction rejected: insufficient balance.";
                    return false;
                }

                C.Balance += Amount;

                if (!SaveCleintsDataToFile(ClientsFileName, vClients))
                    return false;

                cout << "\n\nDone Successfully. New balance is: "
                    << fixed << setprecision(2) << C.Balance;

                return true;
            }
        }

        return false;
    }

    return false;
}


//============================================================
// Read Deposit Amount
//============================================================

double ReadDepositAmount()
{
    double Amount;

    do
    {
        cout << "Enter a positive deposit amount? ";
        cin >> Amount;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            Amount = 0;
        }

    } while (Amount <= 0);

    return Amount;
}


//============================================================
// Deposit Perform
//============================================================

void DepositPerform()
{
    double DepoAmount = ReadDepositAmount();

    vector<stClient> vClients =
        LoadCleintLineFromFileToVector(ClientsFileName);

    if (UpdateClientBalanceByAccountNumber(CurrentClient.AccountNumber, DepoAmount, vClients))
    {
        // Update Balance in memory only after successful save.
        CurrentClient.Balance += DepoAmount;
    }

    cout << "\nPress any key to go back to Main Menu\n";
    system("pause > 0");
}


//============================================================
// Deposit Screen
//============================================================

void DepositScreen()
{
    cout << "==================================\n";
    cout << "\tDeposit Screen\n";
    cout << "==================================\n";

    DepositPerform();

    ATMMainMenuScreen();
}


//============================================================
// Quick Withdraw Amount
//============================================================

short GetQuickWithdrawAmount(short QuickWithDrawOption)
{
    switch (QuickWithDrawOption)
    {
    case 1:
        return 20;
    case 2:
        return 50;
    case 3:
        return 100;
    case 4:
        return 200;
    case 5:
        return 400;
    case 6:
        return 600;
    case 7:
        return 800;
    case 8:
        return 1000;
    default:
        return 0;
    }
}


//============================================================
// Perform Quick Withdraw
//============================================================

void PerfromQuickWithdrawOption(short QuickWithDrawOption)
{
    if (QuickWithDrawOption == 9)
    {
        return;
    }

    short WithdrawAmount = GetQuickWithdrawAmount(QuickWithDrawOption);

    if (WithdrawAmount <= 0)
        return;

    if (WithdrawAmount > CurrentClient.Balance)
    {
        cout << "\nThe amount exceeds your balance, make another choice.\n"
            << "press any key to continue ...\n";

        system("pause>0");
        QuickWithdrawScreen();
        return;
    }

    vector<stClient> vClients =
        LoadCleintLineFromFileToVector(ClientsFileName);

    if (UpdateClientBalanceByAccountNumber(CurrentClient.AccountNumber, WithdrawAmount * -1, vClients))
    {
        CurrentClient.Balance -= WithdrawAmount;
    }

}


//============================================================
// Quick Withdraw Screen
//============================================================

void QuickWithdrawScreen()
{
    system("cls");

    cout << "=================================\n";
    cout << "\tQuick Withdraw \n";
    cout << "=================================\n";
    cout << "\t[1] 20    [2] 50\n";
    cout << "\t[3] 100   [4] 200\n";
    cout << "\t[5] 400   [6] 600\n";
    cout << "\t[7] 800   [8] 1000\n";
    cout << "\t[9] Exit\n";
    cout << "=================================\n";
    cout << fixed << setprecision(2);
    cout << "Your Balance is " << CurrentClient.Balance << endl;

    PerfromQuickWithdrawOption(ReadWithdrawChoice());
}


//============================================================
// ATM Main Menu Perform
//============================================================

void ATMMainMenuPerform(enATMChoicesMainMenu ATMOptions)
{
    switch (ATMOptions)
    {
    case enATMChoicesMainMenu::eQuickWithdraw:
        system("cls");
        QuickWithdrawScreen();
        GoBackMessage();
        break;

    case enATMChoicesMainMenu::eNormalWithdraw:
        system("cls");
        NormalWithdrawScreen();
        GoBackMessage();
        break;

    case enATMChoicesMainMenu::eDeposit:
        system("cls");
        DepositScreen();
        GoBackMessage();
        break;

    case enATMChoicesMainMenu::eCheckBalance:
        system("cls");
        CheckBalanceScreen();
        GoBackMessage();
        break;

    case enATMChoicesMainMenu::eLogout:
        system("cls");
        Login();
        break;
    }
}


//============================================================
// ATM Main Menu Screen
//============================================================

void ATMMainMenuScreen()
{
    system("cls");

    cout << "==================================\n";
    cout << "\tATM Main Menu Screen\n";
    cout << "==================================\n";

    cout << "\t[1] Quick Withdraw.\n";
    cout << "\t[2] Normal Withdraw.\n";
    cout << "\t[3] Deposit.\n";
    cout << "\t[4] Check Balance.\n";
    cout << "\t[5] Logout.\n";
    cout << "============================\n";

    ATMMainMenuPerform(enATMChoicesMainMenu(ReadATMScreenChoices()));

}


//============================================================
// Read Normal Withdraw Amount
//============================================================

int ReadNormalWithdrawAmount()
{
    int Amount;

    do
    {
        cout << "\nEnter an amount multiple of 5's? ";
        cin >> Amount;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            Amount = 0;
        }

    } while (Amount <= 0 || Amount % 5 != 0);

    return Amount;
}


//============================================================
// Normal Withdraw Perform
//============================================================

void NormalWithdrawPerform()
{
    int WithdrawAmount = ReadNormalWithdrawAmount();

    if (WithdrawAmount > CurrentClient.Balance)
    {
        cout << "\nThe amount exceeds your balance, make another choice.\n"
            << "press any key to continue ...\n";

        system("pause>0");
        return;
    }

    vector<stClient> vClients = LoadCleintLineFromFileToVector(ClientsFileName);

    if (UpdateClientBalanceByAccountNumber(CurrentClient.AccountNumber, WithdrawAmount * -1, vClients))
    {
        CurrentClient.Balance -= WithdrawAmount;
    }
}


//============================================================
// Normal Withdraw Screen
//============================================================

void NormalWithdrawScreen()
{
    system("cls");

    cout << "==================================\n";
    cout << "\tNormal Withdraw Screen\n";
    cout << "==================================\n";

    NormalWithdrawPerform();
}


//============================================================
// Login
//============================================================

void Login()
{
    system("cls");

    string AccountNumber, PINCode;

    bool LoginFailed = false;

    cout << "\n---------------------------------\n";
    cout << "\tLogin Screen";
    cout << "\n---------------------------------\n";

    do
    {
        if (LoginFailed)
        {
            cout << "\nInvalid Account Number/PinCode\n";
        }

        cout << "Enter Account Number? ";
        cin >> AccountNumber;

        cout << "Enter PIN Code Number? ";
        cin >> PINCode;

        LoginFailed = !LoadClientInfo(AccountNumber, PINCode);

    } while (LoginFailed);

    ATMMainMenuScreen();
}


//============================================================
// Main
//============================================================

int main()
{
    Login();

    return 0;
}
