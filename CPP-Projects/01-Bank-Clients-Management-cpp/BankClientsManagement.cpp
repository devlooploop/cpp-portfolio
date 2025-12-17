
#include<iostream>
#include<string>
#include<iomanip>
#include<vector>
#include<fstream>
using namespace std;

/*
    Project: Simple Bank Clients Management System - Mar-dev

    Requirements / Program Description:

    This console-based application manages bank client records stored in a text file named "Clients.txt".
    Each client record contains the following information separated by "#//#":
    - Account Number
    - Pin Code
    - Client Name
    - Phone Number
    - Account Balance

    The program provides a main menu with the following options:

    1. Show Client List
       - Displays all clients in a formatted table showing Account Number, Pin Code, Name, Phone, and Balance.
       - Loads data from "Clients.txt" and shows the total number of clients.

    2. Add New Client
       - Allows adding one or multiple new clients interactively.
       - Ensures Account Number is unique (prevents duplicates).
       - Prompts for Pin Code, Name, Phone, and Account Balance.
       - Appends new records directly to the file.

    3. Delete Client
       - Searches for a client by Account Number.
       - Displays client details and asks for confirmation before deletion.
       - Permanently removes the client from the file if confirmed.

    4. Update Client Info
       - Searches for a client by Account Number.
       - Displays current details and asks for confirmation.
       - Allows updating Pin Code, Name, Phone, and Balance (Account Number remains unchanged).
       - Saves updated data back to the file.

    5. Find Client
       - Searches for a client by Account Number.
       - Displays full client details in a card format if found.

    6. Exit
       - Clears the screen and shows a goodbye message before terminating the program.

    Additional Features:
    - Data persistence using file I/O (Clients.txt).
    - Input validation for unique account numbers during addition.
    - User-friendly interface with clear screens and confirmation prompts.
    - Proper separation of concerns using functions for file operations, data conversion, and UI.

    Note: The program assumes the "Clients.txt" file is in the same directory and uses "#//#" as field delimiter.
*/

const string ClientsFileName = "Clients.txt";

enum enMainMenuNumber 
{ eShowClientList = 1, eAddNewClient = 2, eDeleteClient = 3,
  eUpdateClientInfo = 4, eFindClient = 5, eExit = 6 
};

struct stcClient 
{
    string AccountNumber ;
    string PinCode ;
    string Name ;
    string Phone ;
    double AccountBalance ;

    bool MarkedForDelet = false;
};

string ReadClientAccountNumber()
{
    string AccountNumber = "";
    cout << "Please Enter Account Number\n";
    cin >> AccountNumber;

    return AccountNumber;
}

vector<stcClient> LoadClientsRecordFromFile(string);

void ChooseWhatToDo(enMainMenuNumber );

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
    cout << "\t[6] Exit.\n";
    cout << "=======================================================\n";

    ChooseWhatToDo((enMainMenuNumber) ReadMainMenuOption());

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
    cout << "|" << setw(17)  << left << "Account Number"  
         << setw(13) << left << "| Pin Code" 
         << setw(25) << left << "| Client Name" 
         << setw(17) << left << "| Phone " <<  "| Balance";
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

stcClient ConvertLineToRecord(string Line, string Seperator )  
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

bool FindClientByAccountNumber(string AccountNumber, vector<stcClient> vClients, stcClient &Client)
{
    for (stcClient &C : vClients)
    {
        if (C.AccountNumber == AccountNumber )
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
    MyFile.open(FileName, ios::out );

    stcClient Client;

    if (MyFile.is_open())
    {
        for (stcClient &C : vClients)
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
    getline(cin , Client.Name);
   
    cout << "Enter Phone? ";
    getline(cin , Client.Phone);
    
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

   } while (toupper(More) == 'Y' );
    
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

bool UpdateClientByAccountNumber(string AccountNumber, vector<stcClient> &vClients)
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
        cout << "\nClient with Account Number [" << AccountNumber << "]Not Found\n";
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
    cout  << "\tFind Client Screen\n";
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

void ExitScreen()
{
    cout << "-----------------------------------\n";
    cout << "\tProgram Ends :-)\n";
    cout << "-----------------------------------\n";

    system("pause>0");
}



int main()
{
 
    MainMenuScreen();
    system("pause>0");

    return 0;

}
   

// Function defenition
void ChooseWhatToDo(enMainMenuNumber enSelect)
{

    switch (enSelect)
    {
    case enMainMenuNumber::eShowClientList:

         system("cls");
         ClientList();
         GoBackToMainMenuMsg();
         break;
    
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

    default:

        enMainMenuNumber::eExit;
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







