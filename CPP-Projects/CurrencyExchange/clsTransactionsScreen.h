// Project: Bank System
// clsTransactionsScreen.h
#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsTransferLogScreen.h"
#include "clsTransferScreen.h"

using namespace std;

class clsTransactionsScreen :protected clsScreen 
{

private:
    enum enTransactionsMenuOptions {
        eDeposit = 1, eWithdraw = 2,
        eShowTotalBalance = 3, eTransfer = 4,
        eShowMainMenu = 5
    };

    static short ReadTransactionsMenuOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 5, "Enter Number between 1 to 5? ");
        return Choice;
    }


    static void _ShowDepositScreen()
    {
        clsDepositScreen::ShowDepositScreen();
    }

    static void _ShowWithdrawScreen()
    {
        clsWithdrawScreen::ShowWithdrawScreen();
    }

    static void _ShowTotalBalancesScreen()
    {
        clsTotalBalancesScreen::ShowTotalBalancesScreen();
    }

    static void _ShowTransferScreen()
    {
        clsTransferScreen::ShowTransferScreen();
    }

    static void _GoBackToTransactionsMenu()
    {
        cout << "\n\nPress any key to go back to Transactions Menu...";
        system("pause>0");
        ShowTransactionsMenu();
    }

    static void _PerformTransactionsMenuOption(enTransactionsMenuOptions TransactionsMenuOption)
    {
        switch (TransactionsMenuOption)
        {
        case enTransactionsMenuOptions::eDeposit:
        {
            system("cls");
            _ShowDepositScreen();
            _GoBackToTransactionsMenu();
            break;
        }

        case enTransactionsMenuOptions::eWithdraw:
        {
            system("cls");
            _ShowWithdrawScreen();
            _GoBackToTransactionsMenu();
            break;
        }

        case enTransactionsMenuOptions::eShowTotalBalance:
        {
            system("cls");
            _ShowTotalBalancesScreen();
            _GoBackToTransactionsMenu();
            break;
        }

        case enTransactionsMenuOptions::eTransfer:
        {
            system("cls");
            _ShowTransferScreen();
            _GoBackToTransactionsMenu();
            break;
        }

        case enTransactionsMenuOptions::eShowMainMenu:
        {
            //do nothing here the main screen will handle it :-) ;

        }
        }

    }


public:


    static void ShowTransactionsMenu()
    {

        if (!CheckAccessRights(clsUser::enPermissions::pTranaction))
        {
            return;
        }

        system("cls");
        _DrawScreenHeader("\tTransactions Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Transactions Menu\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Deposit.\n";
        cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
        cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
        cout << setw(37) << left << "" << "\t[4] Transfer.\n";
        cout << setw(37) << left << "" << "\t[5] Main Menu.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformTransactionsMenuOption((enTransactionsMenuOptions)ReadTransactionsMenuOption());
    }

};

