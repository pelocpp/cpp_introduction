// ===========================================================================
// BankAccount.h
// ===========================================================================

#pragma once

#include <iostream>

class BankAccount
{
private:
    int m_number;
    double m_balance;
    double m_interestRate;

public:
    static int s_NextAccountNumber;

public:
    // c'tor
    BankAccount();

    // getter / setter
    double getAccountNumber() const;
    double getBalance() const;
    double getInterestRate() const;

    // public interface
    void deposit(double amount);
    void withdraw(double amount);
    void print();

    // interest
    void setInterestRate(double rate);
    void updateInterest(int days);
};

// ===========================================================================
// End-of-File
// ===========================================================================
