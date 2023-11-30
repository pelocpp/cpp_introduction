// ===========================================================================
// BankAccount.cpp
// ===========================================================================

#include "BankAccount.h"

// initialization of static member variable
int BankAccount::s_NextAccountNumber = 10'000;

// c'tor
BankAccount::BankAccount(double start) : m_number(s_NextAccountNumber)
{
    // move to next available account number
    s_NextAccountNumber++;

    m_balance = 0.0;
    m_rate = 0.0;
}

BankAccount::BankAccount() : BankAccount(0.0) {}

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
    return m_rate;
}

void BankAccount::setInterestRate(double rate)
{
    m_rate = rate;
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

void BankAccount::updateInterest(int days)
{
    double interest = (days * m_rate * m_balance) / 365.0 / 100.0;

    m_balance += interest;
}

void BankAccount::print() 
{
    std::cout << "BankAccount Nr. " << m_number << ":";
    std::cout << "   Balance=" << m_balance << "." << std::endl;
}

// operators
bool BankAccount::operator== (const BankAccount& other) {

    if (m_balance == other.m_rate) {
        return true;
    }
    else {
        return false;
    }
}

bool BankAccount::operator!= (const BankAccount& other) {

    return ! (*this == other);
}

bool BankAccount::operator<  (const BankAccount& other) {

    if (m_balance < other.m_rate) {
        return true;
    }
    else {
        return false;
    }
}

bool BankAccount::operator<= (const BankAccount& other) {

    return (*this < other || *this == other);
}

bool BankAccount::operator>  (const BankAccount& other) {

    return ! (*this <= other);
}

bool BankAccount::operator>= (const BankAccount& other) {

    return !(*this < other);
}

// ===========================================================================
// End-of-File
// ===========================================================================
