// ===========================================================================
// BankAccount.h
// ===========================================================================

#pragma once

#include <iostream>

class BankAccount
{
private:
    const int  m_number;
    double     m_balance;
    double     m_rate;

private:
    static int s_NextAccountNumber;

public:
    // c'tor
    BankAccount();
    BankAccount(double start);

    // getter / setter
    double getAccountNumber() const;
    double getBalance() const;
    double getInterestRate() const;

    // public interface
    void deposit(double amount);
    void withdraw(double amount);
    bool equals(BankAccount other);
    void print();

    // interest
    void setInterestRate(double rate);
    void updateInterest(int days);

    // operators
    bool operator== (const BankAccount& other);
    bool operator!= (const BankAccount& other);
    bool operator<  (const BankAccount& other);
    bool operator<= (const BankAccount& other);
    bool operator>  (const BankAccount& other);
    bool operator>= (const BankAccount& other);
};

// ===========================================================================
// End-of-File
// ===========================================================================
