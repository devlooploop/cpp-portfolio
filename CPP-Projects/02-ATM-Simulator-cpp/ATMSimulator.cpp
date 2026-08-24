
// Project: ATM System

/*
 Description: Console-based ATM with user login, quick/normal withdraw, deposit, balance check 
                and logout. Data stored in Clients.txt file.
   
   - Use Clients.txt file as the data base.
   - You Can “Add more features” to the project if you want to, make implementation to the change as in
        [5] & [6] as bellow:

    - [5] CnageMyPassword.
    - [6] Logout.
*/

#include<iostream>
#include <string>
#include <vector>
#include<iomanip>
#include<fstream>

using namespace std;

struct stClient
{
    string AccountNumber;
    string PINCode;
    string Name;
    string Phone;
    double Balance;

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

void Login();
void ATMMainMenuScreen();
void NormalWithdrawScreen();
void QuickWithdrawScreen();

stClient ReadClientAccountAndPin()
{
    stClient Client;

    cout << "Enter Account Number? ";
    cin >> Client.AccountNumber;
    cout << "Enter PIN Code Number? ";
    cin >> Client.PINCode;

    return Client;
}

vector<string> SplitString(string S1, string Delim = "#//#")
{
    vector<string> vString;
    short pos = 0;
    string sWord; // define a string variable 

    // use find() function to get the position of the delimiters  
    while ((pos = S1.find(Delim)) != std::string::npos)
    {
        sWord = S1.substr(0, pos); // store the word   
        if (sWord != "")
        {
            vString.push_back(sWord);
        }
        S1.erase(0, pos + Delim.length());  /* erase() until positon and move to next word. */
    }
    if (S1 != "")
    {
        vString.push_back(S1); // it adds last word of the string.    
    }

    return vString;
}

stClient ConvertLineToClientRecord(string Line, string Delim = "#//#")
{
    stClient Client;         
    vector<string> vClientsString;

    vClientsString = SplitString(Line, Delim);

    Client.AccountNumber = vClientsString[0];
    Client.PINCode = vClientsString[1];
    Client.Name = vClientsString[2];
    Client.Phone = vClientsString[3];
    Client.Balance = stod(vClientsString[4]);   //cast string to double

    return Client;
}

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

vector<stClient> LoadCleintLineFromFileToVector(string FileName)
{
    vector<stClient> vClients;

    fstream MyFile;
    MyFile.open(FileName, ios::in); // read Mode

    if (MyFile.is_open())
    {
        string Line;
        stClient Client;

        while (getline(MyFile, Line))
        {
            Client = ConvertLineToClientRecord(Line);
            vClients.push_back(Client);
        }
    }
    return vClients;
}

vector<stClient> SaveCleintsDataToFile(string FileName, vector<stClient> vClients)
{
    fstream MyFile;
    MyFile.open(FileName, ios::out);
    string Line;

    if (MyFile.is_open())
    {
        for (stClient& i : vClients)
        {
            if (i.MarkForDelete == false)
            {
                Line = ConvertRecordToLine(i, "#//#");
                MyFile << Line << endl;
            }
        }
        MyFile.close();
    }
    return vClients;
}

bool FindClientByAccountNumberAndPinCode(string AccountNumber, string PinCode, stClient& Client)
{
    vector<stClient> vClientsString = LoadCleintLineFromFileToVector(ClientsFileName);

    for (stClient& i : vClientsString)
    {
        if (i.AccountNumber == AccountNumber && i.PINCode == PinCode)
        {
            Client = i; // Populate the CurrentClient object with the retrieved client's details
            return true;
        }
    }
    return false;
}

bool LoadClientInfo(string AccountNumber, string PinCode)
{
    if (FindClientByAccountNumberAndPinCode(AccountNumber, PinCode, CurrentClient))
        return true;
    else
        return false;
}

short ReadATMScreenChoices()
{
    short Choice;

    do
    {
        cout << "Chose what do you want to do? [1 to 5]? ";
        cin >> Choice;

    } while (Choice < 1 || Choice > 5);

    return Choice;
}

void GoBackMessage()
{
    cout << "\n\nPress any key to go back to Main Menu ...\n";
    system("pause > 0");

    ATMMainMenuScreen();
}

void CheckBalanceScreen()
{
    cout << "=================================\n";
    cout << "\tCheck Balance Screen\n";
    cout << "=================================\n";
    cout << "Your Balance is " << CurrentClient.Balance << endl;
}

short ReadWithdrawChoice()
{
    short Choice;
    do
    {
        cout << "Chose what to withdraw from[1] to [9] ? ";
        cin >> Choice;
    } while (Choice < 1 || Choice > 9);

    return Choice;
}

bool DepositBalanceToClientByAccountNumber(string AccountNumber, double Amount, vector<stClient>& vClients)
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
                C.Balance += Amount;
                SaveCleintsDataToFile(ClientsFileName, vClients);

                cout << "\n\nDone Successfully. New balance is: "
                    << C.Balance;
                return true;
            }
        }
        return false;
    }
}

double ReadDepositAmount()
{
    double Amount;
    do
    {
        cout << "Enter a positive deposit amount? ";
        cin >> Amount;

    } while (Amount <= 0);
    return Amount;
}

void DepositPerform()
{
    double DepoAmount = ReadDepositAmount();

    
    vector<stClient> vClients = LoadCleintLineFromFileToVector(ClientsFileName);

    // Update Balance in File
    DepositBalanceToClientByAccountNumber(CurrentClient.AccountNumber, DepoAmount, vClients);

    // Update Balance in Cash Memory
    CurrentClient.Balance += DepoAmount;

    cout << "\nPress any key to go back to Main Menu\n";
    system("pause > 0");
}

void DepositScreen()
{
    cout << "==================================\n";
    cout << "\tDeposit Screen\n";
    cout << "==================================\n";

    DepositPerform();
    ATMMainMenuScreen();
}

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

void PerfromQuickWithdrawOption(short QuickWithDrawOption)
{
    if (QuickWithDrawOption == 9)
    {
        return;
    }

    short WithdrawAmount = GetQuickWithdrawAmount(QuickWithDrawOption);

    if (WithdrawAmount > CurrentClient.Balance)
    {
        cout << "\nThe amount exceeds your balance, make another choice.\n"
            << "press any key to continue ...\n";

        system("pause>0");
        QuickWithdrawScreen();
        return; 
    }

    vector<stClient> vClients = LoadCleintLineFromFileToVector(ClientsFileName);
    DepositBalanceToClientByAccountNumber(CurrentClient.AccountNumber, WithdrawAmount * -1, vClients);

    CurrentClient.Balance -= WithdrawAmount;
}

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
    cout << "Your Balance is " << CurrentClient.Balance << endl;

    PerfromQuickWithdrawOption(ReadWithdrawChoice());
}

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

int ReadNormalWithdrawAmount()
{
    int Amount;

    do
    {
        cout << "\nEnter an amount multiple of 5's? ";
        cin >> Amount;

    } while (Amount % 5 != 0);

    return Amount;
}

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

    // updates Balance in file
    DepositBalanceToClientByAccountNumber(CurrentClient.AccountNumber, WithdrawAmount * -1, vClients);

    // Updates Balance in "Cash Memory" 
    CurrentClient.Balance -= WithdrawAmount;
}

void NormalWithdrawScreen()
{
    system("cls");
    cout << "==================================\n";
    cout << "\tNormal Withdraw Screen\n";
    cout << "==================================\n";

    NormalWithdrawPerform();
}

void Login()
{
    system("cls");

    stClient Client;
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


int main()
{
    Login();

    return 0;
}


