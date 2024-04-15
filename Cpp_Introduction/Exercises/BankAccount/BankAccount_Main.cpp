// ===========================================================================
// BankAccount_Main.cpp
// ===========================================================================

#include "BankAccount.h"

void exerciseBankAccount()
{
    BankAccount myAccount(50);
    myAccount.deposit(50);
    myAccount.withdraw(25);
    myAccount.print();

    BankAccount firstAccount;
    firstAccount.print();

    BankAccount secondAccount;
    secondAccount.deposit(50);
    secondAccount.withdraw(25);
    secondAccount.print();

    BankAccount thirdAccount;
    thirdAccount.deposit(100);
    thirdAccount.print();
    thirdAccount.setInterestRate(5.0);
    thirdAccount.updateInterest(365);
    thirdAccount.print();

    if (firstAccount.equals(secondAccount)) {
        std::cout << "Same Balance" << std::endl;
    }
    else {
        std::cout << "Different Balances" << std::endl;
    }
}

// ===========================================================================
// End-of-File
// ===========================================================================
