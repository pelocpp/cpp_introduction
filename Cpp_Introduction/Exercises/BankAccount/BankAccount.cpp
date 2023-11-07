// ===========================================================================
// BankAccount.cpp
// ===========================================================================

#include "BankAccount.h"

// initialization of static member variable
int BankAccount::s_NextAccountNumber = 10'000;

// c'tor
BankAccount::BankAccount()
{
    // retrieve next available account number
    m_number = s_NextAccountNumber;
    s_NextAccountNumber++;

    m_balance = 0.0;
    m_interestRate = 0.0;
}

// getter / setter
double BankAccount::getAccountNumber() const
{
    return m_number;
}

double BankAccount::getBalance() const
{
    return m_balance;
}

double BankAccount::getInterestRate() const
{

    return m_interestRate;
}

// public interface
void BankAccount::deposit(double amount) 
{
    m_balance += amount;
}

void BankAccount::withdraw(double amount)
{
    if (m_balance < amount)
        return;

    m_balance -= amount;
}

void BankAccount::setInterestRate(double rate)
{
    m_interestRate = rate;
}


void BankAccount::updateInterest(int days)
{
    double interest = (days * m_interestRate * m_balance) / 365.0 / 100.0;

    m_balance += interest;
}

void BankAccount::print() 
{
    std::cout << "BankAccount Nr. " << m_number << ":";
    std::cout << "   Balance=" << m_balance << "." << std::endl;
}

// ===========================================================================
// End-of-File
// ===========================================================================
