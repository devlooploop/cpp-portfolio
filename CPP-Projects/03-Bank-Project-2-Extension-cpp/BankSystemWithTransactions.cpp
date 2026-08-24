
/*
 * Project: Bank Management System - Extended (CRUD + Transactions) - Mar-dev
 * Description: A full-featured console-based bank management application
 *              implementing Create, Read, Update, Delete (CRUD) operations
 *              on client accounts with additional transaction capabilities.
 *
 * Key Features:
 *   - Persistent storage using Clients.txt (file I/O)
 *   - Full CRUD: Add, List, Find, Update, Delete clients with confirmation
 *   - Transactions menu:
 *       • Deposit with confirmation
 *       • Withdraw with overdraft protection
 *       • Total Balances view with formatted table and grand total
 *   - In-memory vector loading for faster searches (as per best practice)
 *   - Unique account number enforcement
 *   - Clean menu navigation with screen clearing and "press any key" prompts
 
 * Demonstrated C++ Concepts:
 *   - Structs for data modeling
 *   - std::vector for dynamic collections
 *   - File handling (fstream) - reading, writing, appending
 *   - String parsing and serialization
 *   - Enums for menu options
 *   - Modular design with separated functions
 *   - Basic input handling and validation
 
 * Notes:
 *   - Data file: data/Clients.txt (created automatically if missing)
 *   - Format: AccountNumber#//#PinCode#//#Name#//#Phone#//#Balance
 *   - Designed for Windows console (uses system("cls") and system("pause"))
 *   - Minimal input validation 
 *   - Portable across platforms with minor adjustments
 
*/

#include<iostream>
#include<string>
#include<iomanip>
#include<vector>
#include<fstream>

using namespace std;

const string ClientsFileName = "Clients.txt";

enum enMainMenuNumber
{
    eShowClientList = 1, eAddNewClient = 2, eDeleteClient = 3,
    eUpdateClientInfo = 4, eFindClient = 5, eTransactions = 6, eExit = 7
};

enum enTransactionsOptions
{
    eDeposit = 1, eWithdraw = 2, eTotalBalance = 3, eMainMenu = 4
};

struct stcClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;

    bool MarkedForDelet = false;
};

vector<stcClient> LoadClientsRecordFromFile(string);

short ReadTransactionsChoices()
{
    short Choice = 0;
    cout << "Chose what you want to do? [1 to 4]? ";
    cin >> Choice;

    return Choice;
}

string ReadClientAccountNumber()
{

    string AccountNumber = "";

    cout << "Please Enter Account Number ";
    cin >> AccountNumber;

    return AccountNumber;
}

void ChooseWhatToDo(enMainMenuNumber);

void TransactionsMenuSelection(enTransactionsOptions);

short ReadMainMenuOption()
{
    short Select = 0;
    cout << "Choose what do you want to do? [1-6]? ";
    cin >> Select;
    return Select;
}

void MainMenuScreen()
{
    system("cls");

    cout << "=======================================================\n";
    cout << "\t\tMain Menu Screen\n";
    cout << "=======================================================\n";
    cout << "\t[1] Show Client List.\n";
    cout << "\t[2] Add New Client.\n";
    cout << "\t[3] Delete Client.\n";
    cout << "\t[4] Update Client Info." << endl;
    cout << "\t[5] Find Client.\n";
    cout << "\t[6] Transactions.\n";
    cout << "\t[7] Exit.\n";
    cout << "=======================================================\n";

    ChooseWhatToDo((enMainMenuNumber)ReadMainMenuOption());

}

void GoBackToMainMenuMsg()
{
    cout << "\n\nPress any key to go back to Main Menu...\n";
    system("pause>0");

    cout << endl;
    MainMenuScreen();

}

void ClientList()
{
    system("cls");

    vector<stcClient> vClients = LoadClientsRecordFromFile(ClientsFileName);

    cout << "\t\t\tClient List " << vClients.size() << " Client(s).\n";

    cout << "-----------------------------------------------------------------------------------------------\n";
    cout << "|" << setw(17) << left << "Account Number"
        << setw(13) << left << "| Pin Code"
        << setw(25) << left << "| Client Name"
        << setw(17) << left << "| Phone " << "| Balance";
    cout << "\n-----------------------------------------------------------------------------------------------\n";

    if (vClients.size() == 0)
    {
        cout << "\t\t\tNo Clients available in the system\n";
    }
    else
    {
        for (stcClient& Client : vClients)
        {

            cout << "| " << setw(16) << left << Client.AccountNumber
                << "| " << setw(11) << left << Client.PinCode
                << "| " << setw(23) << left << Client.Name
                << "| " << setw(15) << left << Client.Phone
                << "| " << Client.AccountBalance
                << endl;

        }
    }

    cout << "-----------------------------------------------------------------------------------------------\n";

    GoBackToMainMenuMsg();

}

vector<string> SplitString(string S1, string Delim = "#//#")
{
    vector<string> vString;

    short Pos = 0;
    string sWord; // define a string variable 

    // use find() function to get the position of the delimiters 
    while ((Pos = S1.find(Delim)) != std::string::npos)
    {
        sWord = S1.substr(0, Pos); // store the word

        if (sWord != " ")
        {
            vString.push_back(sWord);
        }

        S1.erase(0, Pos + Delim.length()); /* erase() until positon and move to next word. */
    }
    if (S1 != " ")
    {
        vString.push_back(S1); // it adds last word of the string.
    }
    return vString;
}

stcClient ConvertLineToRecord(string Line, string Seperator)
{
    stcClient Client;

    vector<string> vClientData = SplitString(Line);

    Client.AccountNumber = vClientData[0];
    Client.PinCode = vClientData[1];
    Client.Name = vClientData[2];
    Client.Phone = vClientData[3];
    Client.AccountBalance = stod(vClientData[4]);

    return Client;
}

string ConvertClientRecordToLine(stcClient Client, string Delim = "#//#")
{

    string ClientsDataLine = "";

    ClientsDataLine += Client.AccountNumber + Delim;
    ClientsDataLine += Client.PinCode + Delim;
    ClientsDataLine += Client.Name + Delim;
    ClientsDataLine += Client.Phone + Delim;
    ClientsDataLine += to_string(Client.AccountBalance);

    return ClientsDataLine;
}

bool FindClientByAccountNumber(string AccountNumber, vector<stcClient> vClients, stcClient& Client)
{
    for (stcClient& C : vClients)
    {
        if (C.AccountNumber == AccountNumber)
        {
            Client = C;
            return true;
        }
    }
    return false;
}

vector<stcClient> SaveCleintsDataToFile(string FileName, vector<stcClient> vClients)
{
    fstream MyFile;
    //overwrite/write mode (if app mode used it will duplicate records)
    MyFile.open(FileName, ios::out);

    stcClient Client;

    if (MyFile.is_open())
    {
        for (stcClient& C : vClients)
        {
            if (C.MarkedForDelet == false)
            {
                string DataLine = ConvertClientRecordToLine(C);

                MyFile << DataLine << endl;
            }
        }

        MyFile.close();
    }

    return vClients;
}

stcClient ChangeClientRecord(string AccountNumber)
{
    stcClient Client;

    Client.AccountNumber = AccountNumber;

    cout << "Enter PinCode? ";
    getline(cin >> ws, Client.PinCode);

    cout << "Enter Name? ";
    getline(cin, Client.Name);

    cout << "Enter Phone? ";
    getline(cin, Client.Phone);

    cout << "Enter AccountBalance? ";
    cin >> Client.AccountBalance;

    return Client;
}

void PrintClientCard(stcClient Client)
{
    cout << "\nThe following are the client details:\n";

    cout << "-----------------------------------------\n";
    cout << "Account Number   : " << Client.AccountNumber << "\n";
    cout << "Pin Code         : " << Client.PinCode << "\n";
    cout << "Name             : " << Client.Name << "\n";
    cout << "Phone            : " << Client.Phone << "\n";
    cout << "Account Balance  : " << Client.AccountBalance << "\n";
    cout << "-----------------------------------------" << endl;

    // printf("Account Balance  : %.6f\n", Client.AccountBalance);

}

bool MarkClientForDeleteByAccountNumber(string AccountNumber, vector<stcClient>& vClients)
{
    for (stcClient& C : vClients)
    {
        if (C.AccountNumber == AccountNumber)
        {
            C.MarkedForDelet = true;
            return true;
        }
    }

    return false;
}

bool ClientExistByAccountNumber(string AccountNumber, string FileName)
{
    vector<stcClient> vClients;

    fstream MyFile;
    MyFile.open(FileName, ios::in); //read Mode

    if (MyFile.is_open())
    {
        string Line;
        stcClient Client;

        while (getline(MyFile, Line))
        {
            Client = ConvertLineToRecord(Line, "#//#");
            if (Client.AccountNumber == AccountNumber)
            {
                MyFile.close();
                return true;
            }
            vClients.push_back(Client); // This has no effect as the program exist when returns true
        }

        MyFile.close();
    }
    return false;
}

void AddDataLineToFile(string FileName, string stDataLine)
{
    fstream MyFile;
    MyFile.open(FileName, ios::out | ios::app);

    if (MyFile.is_open())
    {
        MyFile << stDataLine << endl;

        MyFile.close();
    }
}

stcClient ReadNewClient()
{
    stcClient Client;
    cout << "Enter Account Number\n";

    // Usage of std::ws will extract all the whitespace character
    getline(cin >> ws, Client.AccountNumber);

    while (ClientExistByAccountNumber(Client.AccountNumber, ClientsFileName))
    {
        cout << "Client with [" << Client.AccountNumber << "] already exists, Enter another Account Number? ";
        getline(cin >> ws, Client.AccountNumber);
    }

    cout << "Enter PinCode? ";
    getline(cin, Client.PinCode);

    cout << "Enter Name? ";
    getline(cin, Client.Name);

    cout << "Enter Phone? ";
    getline(cin, Client.Phone);

    cout << "Enter AccountBalance? ";
    cin >> Client.AccountBalance;

    return Client;

}

void AddNewClient()
{
    stcClient Client;
    Client = ReadNewClient();
    AddDataLineToFile(ClientsFileName, ConvertClientRecordToLine(Client));
}

void AddNewClients()
{
    char More = 'y';

    do
    {
        cout << "Adding New Client:\n\n";

        AddNewClient();
        cout << "\nClient Added successfully do you want to add more clients? Y/N ?\n";
        cin >> More;

    } while (toupper(More) == 'Y');

}

void ShoweAddNewClientsScreen()
{
    cout << "-----------------------------------\n";
    cout << "\tAdd New Clients Screen\n";
    cout << "-----------------------------------\n";

    AddNewClients();
}

bool DeleteClientByAccountNumber(string AccountNumber, vector<stcClient> vClients)
{
    stcClient Client;
    char Answer = 'n';

    if (FindClientByAccountNumber(AccountNumber, vClients, Client))
    {
        PrintClientCard(Client);

        cout << "\n\nAre you sure you want to delete this client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            MarkClientForDeleteByAccountNumber(AccountNumber, vClients);
            SaveCleintsDataToFile(ClientsFileName, vClients);

            // Refresh the vector vClients
            vClients = LoadClientsRecordFromFile(ClientsFileName);

            cout << "\n\nClient Deleted Successfully.\n";
            return true;
        }
    }
    else
    {
        cout << "\n\nClient with Account Number [" << AccountNumber << " ]Not Found\n";
        return false;
    }

}

void DeleteClient()
{

    cout << "-----------------------------------\n";
    cout << "\tDelete Clients Screen\n";
    cout << "-----------------------------------\n";

    vector<stcClient> vClients = LoadClientsRecordFromFile(ClientsFileName);

    string AccountNumber = ReadClientAccountNumber();

    DeleteClientByAccountNumber(AccountNumber, vClients);

}

bool UpdateClientByAccountNumber(string AccountNumber, vector<stcClient>& vClients)
{
    stcClient Client;
    char Answer = 'n';

    if (FindClientByAccountNumber(AccountNumber, vClients, Client))
    {
        PrintClientCard(Client);

        cout << "\n\nAre you sure you want to update this client? y/n? ";
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {
            for (stcClient& C : vClients)
            {
                if (C.AccountNumber == AccountNumber)
                {
                    C = ChangeClientRecord(AccountNumber);
                    break;
                }
            }

            SaveCleintsDataToFile(ClientsFileName, vClients);

            cout << "\n\nClient Updated Successfully.\n";
            return true;
        }
    }
    else
    {
        cout << "\nClient with Account Number [" << AccountNumber << "] Not Found\n";
        return false;
    }

}

void UpdateClient()
{

    cout << "-----------------------------------\n";
    cout << "\tUpdate Client Info Screen\n";
    cout << "-----------------------------------\n";

    vector<stcClient> vClients = LoadClientsRecordFromFile(ClientsFileName);

    string AccountNumber = ReadClientAccountNumber();
    UpdateClientByAccountNumber(AccountNumber, vClients);

}

void ShowFindClientScreen()
{

    cout << "-----------------------------------\n";
    cout << "\tFind Client Screen\n";
    cout << "-----------------------------------\n";

    vector<stcClient> vClients = LoadClientsRecordFromFile(ClientsFileName);

    stcClient Client;

    string AccountNumber = ReadClientAccountNumber();

    if (FindClientByAccountNumber(AccountNumber, vClients, Client))
    {
        PrintClientCard(Client);
    }
    else
    {
        cout << "\n\nClient with Account Number [" << AccountNumber << "] Not Found\n";
    }

}

void ShowTransactionsScreen()
{
    system("cls");

    cout << "=========================================\n";
    cout << "\tTransactions Menu Screen\n";
    cout << "=========================================\n";

    cout << "[1] Deposit.\n";
    cout << "[2] Withdraw.\n";
    cout << "[3] Total Balances.\n";
    cout << "[4] Main Menu.\n";
    cout << "=======================================\n";

    TransactionsMenuSelection(enTransactionsOptions(ReadTransactionsChoices()));
}

void GoBackToTransactionMenu()
{
    cout << "\n\nPress any key to go back to Transaction Menu...\n";
    system("pause>0");

    cout << endl;
    ShowTransactionsScreen();

}

void ExitScreen()
{
    cout << "-----------------------------------\n";
    cout << "\tProgram Ends :-)\n";
    cout << "-----------------------------------\n";

}

stcClient PerformDepositCalculation(string AccountNumber, vector<stcClient>& vClients, stcClient& Client)
{
    char PerformTrans = 'n';
    string DepoAmount = "";

    if (FindClientByAccountNumber(AccountNumber, vClients, Client))
    {
        cout << "\nPlease Enter deposit amount? ";
        cin >> DepoAmount;

        cout << "\nAre you sure you want to perform this transaction? y/n? ";
        cin >> PerformTrans;

        if (PerformTrans == 'Y' || PerformTrans == 'y')
        {

            for (stcClient& C : vClients)
            {
                if (C.AccountNumber == Client.AccountNumber)
                {

                    C.AccountBalance = stod(DepoAmount) + C.AccountBalance;

                    // Update the client's balance
                    Client.AccountBalance = C.AccountBalance;
                    SaveCleintsDataToFile(ClientsFileName, vClients);

                    break;

                }
            }
        }

    }

    return Client;
}

stcClient PerformWithdrawCalculation(string AccountNumber, vector<stcClient>& vClients, stcClient& Client)
{
    char PerformTrans = 'n';
    string WithdrawAmount = "";

    if (FindClientByAccountNumber(AccountNumber, vClients, Client))
    {
        cout << "\nPlease Enter withdraw amount? ";
        cin >> WithdrawAmount;

        cout << "\nAre you sure you want to perform this transaction? y/n? ";
        cin >> PerformTrans;

        if (PerformTrans == 'Y' || PerformTrans == 'y')
        {
            for (stcClient& C : vClients)
            {
                if (C.AccountNumber == Client.AccountNumber)
                {
                    while (stod(WithdrawAmount) > C.AccountBalance || stod(WithdrawAmount) < 0)
                    {
                        cout << "Amount exceeds the balance, you can withdraw up to : "
                            << C.AccountBalance << "\nPlease enteranother amount? ";

                        cin >> WithdrawAmount;

                    }

                    C.AccountBalance = C.AccountBalance - stod(WithdrawAmount);

                    // Update the client's balance
                    Client.AccountBalance = C.AccountBalance;
                    SaveCleintsDataToFile(ClientsFileName, vClients);

                    break;

                }
            }
        }

    }

    return Client;
}

stcClient Deposit()
{
    vector<stcClient> vClients = LoadClientsRecordFromFile(ClientsFileName);

    stcClient Client;

    string AccountNumber;

    do
    {
        cout << "Please Enter Account Number? ";
        getline(cin >> ws, AccountNumber);

        if (!FindClientByAccountNumber(AccountNumber, vClients, Client))

            cout << "Client with [" << AccountNumber << "] does not exist.\n\n";

    } while (!FindClientByAccountNumber(AccountNumber, vClients, Client));

    PrintClientCard(Client);

    // Update the Client object Account Balance
    PerformDepositCalculation(AccountNumber, vClients, Client);

    cout << "\nTransaction done successfully the new balance is["
        << Client.AccountBalance << "]";

    return Client;
}

void DepositScreen()
{
    cout << "-----------------------------------------\n";
    cout << "\t Deposit Screen\n";
    cout << "-----------------------------------------\n\n";

    Deposit();
}

stcClient Withdraw()
{
    vector<stcClient> vClients = LoadClientsRecordFromFile(ClientsFileName);

    stcClient Client;

    string AccountNumber;

    do
    {
        cout << "Please Enter Account Number? ";
        getline(cin >> ws, AccountNumber);

        if (!FindClientByAccountNumber(AccountNumber, vClients, Client))

            cout << "Client with [" << AccountNumber << "] does not exist.\n\n";

    } while (!FindClientByAccountNumber(AccountNumber, vClients, Client));

    PrintClientCard(Client);

    // Update the Client object Account Balance
    PerformWithdrawCalculation(AccountNumber, vClients, Client);

    cout << "\nTransaction done successfully the new balance is["
        << Client.AccountBalance << "]";

    return Client;
}

void WithdrawScreen()
{

    cout << "-----------------------------------------\n";
    cout << "\t Withdraw Screen\n";
    cout << "-----------------------------------------\n\n";

    Withdraw();

}

double CalculateTotalBalances(vector<stcClient> vClients)
{
    vClients = LoadClientsRecordFromFile(ClientsFileName);

    double TotalBalances = 0;

    for (stcClient& C : vClients)
    {
        TotalBalances += C.AccountBalance;
    }

    return TotalBalances;
}

void TotalBalanceScreen()
{
    system("cls");

    vector<stcClient> vClients = LoadClientsRecordFromFile(ClientsFileName);

    cout << "\t\t\tBalances List " << vClients.size() << " Client(s).\n";

    cout << "-----------------------------------------------------------------------------------------------\n";
    cout << "|" << setw(17) << left << "Account Number"
        << setw(25) << left << "| Client Name"
        << setw(26) << left << "| Balance";
    cout << "\n-----------------------------------------------------------------------------------------------\n";

    if (vClients.size() == 0)
    {
        cout << "\t\t\tNo Clients available in the system\n";
    }
    else
    {
        for (stcClient& Client : vClients)
        {

            cout << "| " << setw(16) << left << Client.AccountNumber
                << "| " << setw(23) << left << Client.Name
                << "| " << Client.AccountBalance
                << endl;

        }
    }

    cout << "-----------------------------------------------------------------------------------------------\n";

    cout << "\nTotal Balances = " << CalculateTotalBalances(vClients);

}

int main()
{

    MainMenuScreen();

    return 0;

}


// Function defenition
void ChooseWhatToDo(enMainMenuNumber enSelect)
{

    switch (enSelect)
    {
    case enMainMenuNumber::eShowClientList:
    {
        system("cls");
        ClientList();
        GoBackToMainMenuMsg();
        break;
    }
    case enMainMenuNumber::eAddNewClient:

        system("cls");
        AddNewClients();
        GoBackToMainMenuMsg();
        break;

    case enMainMenuNumber::eDeleteClient:

        system("cls");
        DeleteClient();
        GoBackToMainMenuMsg();
        break;

    case enMainMenuNumber::eUpdateClientInfo:

        system("cls");
        UpdateClient();
        GoBackToMainMenuMsg();
        break;

    case enMainMenuNumber::eFindClient:

        system("cls");
        ShowFindClientScreen();
        GoBackToMainMenuMsg();
        break;

    case enMainMenuNumber::eTransactions:
        system("cls");
        ShowTransactionsScreen();
        GoBackToMainMenuMsg();
        break;

    case enMainMenuNumber::eExit:

        system("cls");
        ExitScreen();
        break;

    }

}

vector<stcClient> LoadClientsRecordFromFile(string FileName)
{
    vector<stcClient> vClients;

    fstream MyFile;
    MyFile.open(FileName, ios::in); // read Mode

    if (MyFile.is_open())
    {
        stcClient Client;
        string Line;

        while (getline(MyFile, Line))
        {
            Client = ConvertLineToRecord(Line, "#//#");

            vClients.push_back(Client);
        }
        MyFile.close();
    }
    return vClients;
}

void TransactionsMenuSelection(enTransactionsOptions enChoices)
{

    switch (enChoices)
    {
    case enTransactionsOptions::eDeposit:
    {
        system("cls");
        DepositScreen();
        GoBackToTransactionMenu();
        break;
    }

    case enTransactionsOptions::eWithdraw:
    {
        system("cls");
        WithdrawScreen();
        GoBackToTransactionMenu();
        break;
    }
    case enTransactionsOptions::eTotalBalance:
    {
        system("cls");
        TotalBalanceScreen();
        GoBackToTransactionMenu();
        break;
    }
    case enTransactionsOptions::eMainMenu:
    {
        MainMenuScreen();
    }

    }

}





