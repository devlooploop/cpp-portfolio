
/*
    Project #1 - Bank Extension #2 Requirements
    ==========================================

    You must extend the previous Bank project with a full User Management system and login/logout functionality.

    Main Menu Changes:
    - Add two new options:
        [7] Manage Users
        [8] Logout   (replace the old "Exit" option)

    Login System:
    - The program must start with a Login Screen.
    - Users must enter Username and Password.
    - If login fails → show "Invalid Username/Password!" and allow retry.
    - Only after successful login → show the Main Menu.
    - There must be at least one default admin user (usually "Admin" with full permissions).

    Users File:
    - Create a new file called "Users.txt"
    - Each line format:  UserName#//#Password#//#Permissions
      Example: Admin#//#1234#//#-1

    Permissions System:
    - Use bit-wise permissions (already defined in enum enUserPermissions):
        epAll              = -1  (full access)
        epShowClientList   = 1
        epAddNewClient     = 2
        epDeleteClient     = 4
        epUpdateClientInfo = 8
        epFindClient       = 16
        epTransactions     = 32
        epManageUsers      = 64
    - Each user has a Permissions field (int) that is a combination of these bits.
    - Before performing any action, check if the current logged-in user has the required permission using bit-wise AND.

    Manage Users Menu (Option 7):
    - Only accessible if the current user has epManageUsers permission.
    - If not → show "Access Denied" message and return to main menu.
    - Menu options:
        [1] List Users
        [2] Add New User
        [3] Delete User
        [4] Update User
        [5] Find User
        [6] Main Menu

    Manage Users Features:
    1. List Users:
       - Show all users in a table: UserName, Password, Permissions

    2. Add New User:
       - Ask for Username (must be unique)
       - Ask for Password
       - Ask for Permissions:
         • First ask: "Do you want to give full access? y/n?"
           → if yes → Permissions = -1
           → if no → ask individually for each permission (y/n) and add the corresponding bits
       - Save to Users.txt

    3. Delete User:
       - Prevent deleting the main "Admin" user
       - Show user card, confirm deletion
       - Mark and save (delete from file)

    4. Update User:
       - Find by Username
       - Allow changing Password and Permissions (same permission logic as add)
       - Cannot change Username

    5. Find User:
       - Search by Username and display user card

    Logout (Option 8):
    - Clear current user session
    - Return to the Login Screen (program continues, does not exit)

    General Rules:
    - Every main menu option (1–7) must check the corresponding permission.
    - If user lacks permission → show Access Denied message and return to main menu.
    - After most operations, return to appropriate menu using "Press any key...".
    - Use the existing file structure (Clients.txt and Users.txt) with "#//#" delimiter.
    - Code must be clean, well-structured, and use functions properly.

    Note: This is an extension of the previous Bank project — keep all previous functionality working.
*/

#include<iostream>
#include <string>
#include <vector>
#include<iomanip>
#include<fstream>
using namespace std;

const string ClientsFileName = "Clients.txt";
const string UsersFileName = "Users.txt";

enum enMainMenuNumber
{
    eShowClientList = 1, eAddNewClient = 2, eDeleteClient = 3,
    eUpdateClientInfo = 4, eFindClient = 5, eTransactions = 6,
    eManageUsers = 7, eLogout = 8 // eExit() = 8
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

struct stUser
{
    string UserName;
    string Password;
    short  Permissions;
    bool   MarkUserForDelete = false;
};

enum enUserPermissions
{
    epAll = -1, epShowClientList = 1, epAddNewClient = 2,
    epDeleteClient = 4, epUpdateClientInfo = 8, epFindClient = 16,
    epTransactions = 32, epManageUsers = 64
};

stUser CurrentUser;

vector<stUser>LoadUsersRecordFromFile(string FileName);
vector<stcClient> LoadClientsRecordFromFile(string FileName);

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

void MainMenuOptions(enMainMenuNumber);
void TransactionsMenuSelection(enTransactionsOptions);
void ManageUsersMenuScreen();
void AccessDeniedMsg();

short ReadMainMenuOption()
{
    short Select = 0;
    cout << "Choose what do you want to do? [1-8]? ";
    cin >> Select;
    return Select;
}

bool CheckUserPermission(enUserPermissions Permission)
{
    if ((CurrentUser.Permissions & Permission) == Permission)
        return true;
    else
        return false;
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
    cout << "\t[7] Manage Users.\n";
    cout << "\t[8] Logout.\n";
    cout << "=======================================================\n";

    MainMenuOptions((enMainMenuNumber)ReadMainMenuOption());
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

    if (!CheckUserPermission(enUserPermissions::epShowClientList))
    {
        AccessDeniedMsg();
        GoBackToMainMenuMsg();
        return;
    }

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

    if (vClientData.size() >= 5)
    {
        Client.AccountNumber = vClientData[0];
        Client.PinCode = vClientData[1];
        Client.Name = vClientData[2];
        Client.Phone = vClientData[3];
        Client.AccountBalance = stod(vClientData[4]);
    }

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
        cout << "Client with [" << Client.AccountNumber <<
            "] already exists, Enter another Account Number? ";
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
    if (!CheckUserPermission(enUserPermissions::epShowClientList))
    {
        AccessDeniedMsg();
        return;
    }

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

    if (!CheckUserPermission(enUserPermissions::epDeleteClient))
    {
        AccessDeniedMsg();
        GoBackToMainMenuMsg();
        return;
    }

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
    if (!CheckUserPermission(enUserPermissions::epUpdateClientInfo))
    {
        AccessDeniedMsg();
        GoBackToMainMenuMsg();
        return;
    }

    cout << "-----------------------------------\n";
    cout << "\tUpdate Client Info Screen\n";
    cout << "-----------------------------------\n";

    vector<stcClient> vClients = LoadClientsRecordFromFile(ClientsFileName);

    string AccountNumber = ReadClientAccountNumber();

    UpdateClientByAccountNumber(AccountNumber, vClients);
}

void ShowFindClientScreen()
{
    if (!CheckUserPermission(enUserPermissions::epFindClient))
    {
        AccessDeniedMsg();
        GoBackToMainMenuMsg();
        return;
    }

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

    if (!CheckUserPermission(enUserPermissions::epTransactions))
    {
        AccessDeniedMsg();
        GoBackToMainMenuMsg();
        return;
    }

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

bool FindUserByUserNameAndPassword(string UserName, string Password, stUser& User)
{
    vector <stUser> vUsers = LoadUsersRecordFromFile(UsersFileName);

    for (stUser& UserVector : vUsers)
    {
        if (UserVector.UserName == UserName && UserVector.Password == Password)
        {
            User = UserVector;
            return true;
        }
    }
    return false;
}

void AccessDeniedMsg()
{
    cout << "\n-------------------------------------------------------\n";
    cout << "Access Denied,\n You don't have permission to do this,\n"
        << "Please contact your Admin.";
    cout << "\n-------------------------------------------------------\n";
}

bool LoadUserInfo(string UserName, string Password)
{
    if (FindUserByUserNameAndPassword(UserName, Password, CurrentUser))
        return true;
    else
        return false;
}

void LogOut()
{
    bool LoginFaild = false; // flag variable for checking log in success

    string UserName, Password;

    do
    {
        system("cls");

        cout << "-----------------------------------\n";
        cout << "\t login screen \n";
        cout << "-----------------------------------\n";

        if (LoginFaild)
        {
            cout << "Invalid Username/Password!\n";
        }

        cout << "Enter User name? ";
        cin >> UserName;
        cout << "Enter Password? ";
        cin >> Password;

        LoginFaild = !LoadUserInfo(UserName, Password); // will negate the reteruned result

    } while (LoginFaild);

    MainMenuScreen();
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
                << "| " << Client.AccountBalance << endl;
        }
    }
    cout << "-----------------------------------------------------------------------------------------------\n";

    cout << "\nTotal Balances = " << CalculateTotalBalances(vClients);

}

enum enManageUsersMenu
{
    eListUser = 1, eAddNewUser = 2, eDeleteUser = 3,
    eUpdateUser = 4, eFindUser = 5//, eMainMenuUser = 6 
};

short ReadUsersMenuOptions()
{
    short Option;
    cout << "Chose what do you want to do ? [1 to 6]? ";
    cin >> Option;
    return Option;
}

// This is the function declaration
void GoBackToManageUsersScreenMsg();
vector<stUser> LoadUsersRecordFromFile(string);

stUser ConvertLineToUserRecord(string UserLine, string Delim = "#//#")
{
    vector<string> vUsers;
    stUser User;
    vUsers = SplitString(UserLine, Delim);

    if (vUsers.size() >= 3)
    {
        User.UserName = vUsers[0];
        User.Password = vUsers[1];  // UserName & Password is empty !!!
        User.Permissions = stoi(vUsers[2]); // casting string to int
    }

    return User;
}

void ListUser()
{

    vector<stUser> vUsers = LoadUsersRecordFromFile(UsersFileName);

    cout << setw(30) << "Users List " << vUsers.size() << " User(s)\n";
    cout << "-------------------------------------------------------\n";
    cout << "| User Name\t" << "| Password  " << "| Permissions";
    cout << "\n-------------------------------------------------------\n";

    if (vUsers.empty())
    {
        cout << "\t\t\tNo Users available in the system\n";
    }
    else
    {
        for (stUser& User : vUsers)
        {
            cout << "| " << setw(13) << left << User.UserName << " | " << setw(10) << left
                << User.Password << "| " << User.Permissions << endl;
        }
    }
    cout << "-------------------------------------------------------\n";
}

short ReadPermissionsToSet()
{
    short Permissions = 0;
    char Answer = 'n';

    cout << "\nDo you want to give full access? y/n? \n";
    cin >> Answer;

    if (Answer == 'y' || Answer == 'Y')
    {
        return -1;
    }

    cout << "\nDo you want to give access to : \n";

    cout << "\nShow Client List? y/n? ";
    cin >> Answer;

    if (Answer == 'y' || Answer == 'Y')
    {
        Permissions += enUserPermissions::epShowClientList;
    }

    cout << "\nAdd New Client? y/n? ";
    cin >> Answer;
    if (Answer == 'y' || Answer == 'Y')
    {
        Permissions += enUserPermissions::epAddNewClient;
    }

    cout << "\nDelete Client? y/n? ";
    cin >> Answer;

    if (Answer == 'y' || Answer == 'Y')
    {
        Permissions += enUserPermissions::epDeleteClient;
    }

    cout << "\nUpdate Client? y/n? ";
    cin >> Answer;

    if (Answer == 'y' || Answer == 'Y')
    {
        Permissions += enUserPermissions::epUpdateClientInfo;
    }

    cout << "\nFind Client? y/n? ";
    cin >> Answer;

    if (Answer == 'y' || Answer == 'Y')
    {
        Permissions += enUserPermissions::epFindClient;
    }

    cout << "\nTransactions? y/n? ";
    cin >> Answer;

    if (Answer == 'y' || Answer == 'Y')
    {
        Permissions += enUserPermissions::epTransactions;
    }

    cout << "\nManage Users? y/n? ";
    cin >> Answer;

    if (Answer == 'y' || Answer == 'Y')
    {
        Permissions += enUserPermissions::epManageUsers;
    }

    return Permissions;
}

bool UserExistsByUserName(string UserName, string FileName)
{
    fstream MyFile;
    MyFile.open(FileName, ios::in);

    if (MyFile.is_open())
    {
        string Line;
        stUser User;

        while (getline(MyFile, Line))
        {
            User = ConvertLineToUserRecord(Line, "#//#");
            if (User.UserName == UserName)
            {
                MyFile.close();
                return true;
            }
        }
    }
    return false;
}

stUser ReadNewUser()
{
    stUser NewUser;

    cout << "Enter User Name? ";
    getline(cin >> ws, NewUser.UserName);

    while (UserExistsByUserName(NewUser.UserName, UsersFileName))
    {
        cout << "\nUser with [" << NewUser.UserName
            << "] Already exist, enter another user name? ";
        getline(cin >> ws, NewUser.UserName);
    }

    cout << "Enter Password? ";
    getline(cin >> ws, NewUser.Password);

    NewUser.Permissions = ReadPermissionsToSet();

    return NewUser;
}

string ConvertUserRecordToLine(stUser User, string Delim = "#//#")
{
    string UserLine = "";

    UserLine += User.UserName + Delim; //Admin#//#1234#//#-1;
    UserLine += User.Password + Delim;
    UserLine += to_string(User.Permissions);
    return UserLine;
}

bool MarkUserForDeleteByUserName(string UserName, vector<stUser>& vUsers)
{
    for (stUser& Usr : vUsers)
    {
        if (Usr.UserName == UserName)
        {
            Usr.MarkUserForDelete = true;
            return true;
        }
    }
    return false;
}

vector<stUser> SaveUsersDataToFile(string FileName, vector<stUser> vUsers)
{
    fstream MyFile;
    MyFile.open(FileName, ios::out); //| ios::app

    stUser User;

    if (MyFile.is_open())
    {
        string UserLine;

        for (stUser& Usr : vUsers)
        {
            if (Usr.MarkUserForDelete == false)
            {
                UserLine = ConvertUserRecordToLine(Usr);
                MyFile << UserLine << endl;
            }
        }
    }

    MyFile.close();

    return vUsers;
}

void AddNewUser()
{
    stUser User;
    User = ReadNewUser();
    AddDataLineToFile(UsersFileName, ConvertUserRecordToLine(User));
}

void AddNewUsers()
{
    char AddMore = 'Y';

    do
    {
        cout << "Adding New User:\n\n";
        AddNewUser();

        cout << "\nUser Added successfully, do you want to add more users? Y/N? ";
        cin >> AddMore;

    } while (toupper(AddMore) == 'Y'); // must be fixed 
}

void ShowAddNewUserScreen()
{
    cout << "-----------------------------------------------\n";
    cout << "   Add New User Screen";
    cout << "\n---------------------------------------------\n";

    AddNewUser();
}

void PrintUserCard(stUser User)
{
    cout << "The following are the User detail:\n";
    cout << "\n-----------------------------------------\n";
    cout << "User Name       : " << User.UserName << "\n";
    cout << "User Password   : " << User.Password << endl;
    cout << "Permissions     : " << User.Permissions << "\n";
    cout << "\n-----------------------------------------\n";
}

bool FindUserByUserName(string UserName, vector<stUser> vUsers, stUser& User)
{

    for (stUser& U : vUsers)
    {
        if (U.UserName == UserName)
        {
            User = U;
            return true;
        }
    }

    return false;
}

// Must Be corrected !! always show "User not found!"
bool DeleteUserByUserName(string UserName, vector<stUser>& vUsers)
{

    cout << "Please enter user name? ";
    getline(cin >> ws, UserName);

    if (UserName == "Admin" || UserName == "admin")
    {
        cout << "\nYou cannot Delete this user\n";
        return false;
    }

    stUser User;

    cout << endl;

    if (FindUserByUserName(UserName, vUsers, User))
    {
        char Ask = 'n';

        PrintUserCard(User);

        cout << "\nAre you sure you want to delete this user? y/n? ";
        cin >> Ask;

        if ('Y' == toupper(Ask))
        {
            MarkUserForDeleteByUserName(User.UserName, vUsers);
            SaveUsersDataToFile(UsersFileName, vUsers);

            cout << "\nUser Deleted Successfully.\n";

            return true;
        }
    }
    else
    {
        cout << "\nUser with user name [" << UserName << "] is not found!";
        return false;
    }

    return false;
}

void DeleteUserScreen()
{
    stUser User;
    vector<stUser> vUsers = LoadUsersRecordFromFile(UsersFileName);

    cout << "--------------------------------------\n";
    cout << "\tDelete Users Screen\n";
    cout << "--------------------------------------\n";

    DeleteUserByUserName(User.UserName, vUsers);
}

void GoBackToManageUsersScreenMsg()
{
    cout << "\n\nPress any key to go back to Manage Users Screen Menu...\n";
    system("pause>0");

    ManageUsersMenuScreen();
}

bool UserUpdateByUserName(string UserName, vector<stUser>& vUsers) // must be fixed
{
    stUser User;

    cout << "\nPlease enter user name? ";
    getline(cin >> ws, UserName);
    cout << endl;

    if (FindUserByUserName(UserName, vUsers, User))
    {
        PrintUserCard(User);

        char Update;
        cout << "\nAre you sure you want to update this user? y/n? ";
        cin >> Update;

        if ('Y' == toupper(Update))
        {
            cout << "\nEnter Password? ";
            cin >> User.Password;

            for (stUser& Usr : vUsers)
            {
                if (Usr.UserName == User.UserName)
                {
                    Usr.Password = User.Password;
                    Usr.Permissions = ReadPermissionsToSet();
                    break;
                }
            }

            SaveUsersDataToFile(UsersFileName, vUsers);
            cout << "\nUser Updated Successfully";
        }
        return true;
    }
    else
    {
        cout << "\nUser Not Found!\n";
        return false;
    }
    return false;
}

void UpdateUserScreen()
{
    vector<stUser> vUsers = LoadUsersRecordFromFile(UsersFileName);
    stUser User;

    cout << "\n----------------------------------\n";
    cout << "\t Update Users Screen";
    cout << "\n----------------------------------\n";

    UserUpdateByUserName(User.UserName, vUsers);
}

void FindUsers()
{
    vector<stUser> vUsers = LoadUsersRecordFromFile(UsersFileName);
    stUser User;

    cout << "Please Enter User Name? ";
    cin >> User.UserName;

    if (FindUserByUserName(User.UserName, vUsers, User))
        PrintUserCard(User);
    else
        cout << "User with User Name [" << User.UserName << "] Not Found?\n";
}

void FindUsersScreen()
{
    cout << "\n----------------------------------\n";
    cout << "\t Find Users Screen";
    cout << "\n----------------------------------\n";

    FindUsers();
}

void ManageUsersOption(enManageUsersMenu Options)
{
    switch (Options)
    {
    case enManageUsersMenu::eListUser:
        system("cls");
        ListUser();
        GoBackToManageUsersScreenMsg();
        break;
    case enManageUsersMenu::eAddNewUser:
        system("cls");
        ShowAddNewUserScreen();
        GoBackToManageUsersScreenMsg();
        break;
    case enManageUsersMenu::eDeleteUser:
        system("cls");
        DeleteUserScreen();
        GoBackToManageUsersScreenMsg();
        break;
    case enManageUsersMenu::eUpdateUser:
        system("cls");
        UpdateUserScreen();
        GoBackToManageUsersScreenMsg();
        break;
    case enManageUsersMenu::eFindUser:
        system("cls");
        FindUsersScreen();
        GoBackToManageUsersScreenMsg();
        break;
    }
}

int main()
{

    // MainMenuScreen();
    LogOut();


    return 0;
}

// Function defenition
void MainMenuOptions(enMainMenuNumber enSelect)
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

    case enMainMenuNumber::eManageUsers:
        system("cls");
        ManageUsersMenuScreen();
        GoBackToMainMenuMsg();

    case enMainMenuNumber::eLogout:
        system("cls");
        LogOut();
        GoBackToMainMenuMsg();
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

void ManageUsersMenuScreen()
{
    if (!CheckUserPermission(enUserPermissions::epManageUsers))
    {
        AccessDeniedMsg();
        // GoBackToMainMenuMsg();
        return;
    }

    system("cls");

    cout << "======================================\n";
    cout << "\t   Manage Users Menu Screen\n";
    cout << "======================================\n";
    cout << "\t[1] List Users.\n";
    cout << "\t[2] Add New User.\n";
    cout << "\t[3] Delete User.\n";
    cout << "\t[4] Update User.\n";
    cout << "\t[5] Find User.\n";
    cout << "\t[6] Main Menu.\n";
    cout << "====================================\n";

    ManageUsersOption(enManageUsersMenu(ReadUsersMenuOptions()));
}

// This is definition of the function
vector<stUser>LoadUsersRecordFromFile(string FileName)
{
    vector<stUser> vUsers;

    fstream UserFile;
    UserFile.open(FileName, ios::in); // read mode 

    if (UserFile.is_open())
    {
        string  Line;
        stUser User;

        while (getline(UserFile, Line))
        {
            // If the Separator is NOT #//# this cause the vector "out of range" exception
            // like if the User's not separated by #//# in the file this will cause error!! 
            User = ConvertLineToUserRecord(Line, "#//#");
            vUsers.push_back(User);
        }
        UserFile.close();
    }
    return vUsers;
}


