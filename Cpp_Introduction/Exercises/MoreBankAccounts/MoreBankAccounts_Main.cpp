// ===========================================================================
// MoreBankAccounts_Main.cpp
// ===========================================================================

#include <iostream>

#include "MoreBankAccounts.h"

// initialization of static member variable
int MoreBankAccounts::Account::s_nextNumber = 10'000;

// ===========================================================================

static void testMoreBankAccounts_01()
{
    using namespace MoreBankAccounts;

    CurrentAccount ca(1000);
    ca.deposit(100);
    ca.withdraw(40);
    ca.print();

    StudentsAccount sa;
    sa.deposit(50);
    sa.withdraw(25);
    sa.print();

    DepositAccount da(4.0);
    da.deposit(200);
    da.withdraw(120);
    da.updateInterest(31);
    da.print();
}

static void testMoreBankAccounts_02()
{
    using namespace MoreBankAccounts;

    CurrentAccount ca(1000);
    ca.deposit(100);
    ca.print();

    StudentsAccount sa;
    sa.deposit(50);
    sa.print();

    DepositAccount da(4.0);
    da.deposit(200);
    da.print();

    IAccount* accounts[3]{ &ca, &sa, &da };

    double totalBalance = 0;
    for (int i = 0; i < 3; ++i) {

        totalBalance += accounts[i]->getBalance();
    }

    std::cout << "Total Balance: " << totalBalance << std::endl;
}

void exerciseMoreBankAccounts()
{
    testMoreBankAccounts_01();
    testMoreBankAccounts_02();
}

// ===========================================================================
// End-of-File
// ===========================================================================
