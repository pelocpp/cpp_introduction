// ===========================================================================
// MoreBankAccounts.cpp
// ===========================================================================

#include <iostream>

namespace MoreBankAccounts {

    // Vertrag // Kontrakt
    class IAccount
    {
    public:
        // getter/setter
        virtual double getAccountNumber() = 0;
        virtual double getBalance() = 0;

        // public interface
        virtual void deposit(double amount) = 0;
        virtual bool withdraw(double amount) = 0;
        virtual void print() = 0;
    };

    // ===========================================================================

    // Abstrakte Basisklasse
    class Account : public IAccount
    {
    protected:
        int m_accountNumber;
        double m_balance;

    public:
        // default c'tor / d'tor
        Account(int account);

        // getter / setter
        double getAccountNumber() final  override;
        virtual double getBalance() final override;

        // public interface
        void deposit(double amount) final override;
    };

    Account::Account(int accountNumber)
        : m_accountNumber(accountNumber), m_balance(0) {}

    void Account::deposit(double amount) {
        m_balance += amount;
    }

    double Account::getAccountNumber() {
        return m_accountNumber;
    }

    double Account::getBalance() {
        return m_balance;
    }

    // ===========================================================================

    class CurrentAccount final : public Account
    {
    private:
        double m_limit;

    public:
        // c'tors
        CurrentAccount(int account);
        CurrentAccount(int account, double limit);
        virtual ~CurrentAccount() {};

        // getter / setter
        double getLimit();
        void setLimit(double limit);

        // public interface
        bool withdraw(double amount) override;
        void print() override;
    };

    CurrentAccount::CurrentAccount(int accountNumber)
        : CurrentAccount(accountNumber, 1000.0) {}

    CurrentAccount::CurrentAccount(int account, double limit)
        : Account(account), m_limit(limit) {}

    bool CurrentAccount::withdraw(double amount) {
        if (m_balance + m_limit < amount)
            return false;

        m_balance -= amount;
        return true;
    }

    double CurrentAccount::getLimit() {
        return m_limit;
    }

    void CurrentAccount::setLimit(double limit) {
        m_limit = limit;
    }

    void CurrentAccount::print() {
        std::cout << "CurrentAccount [Nr. " << m_accountNumber << "]:" << std::endl;
        std::cout << "   Balance=" << m_balance << ";" << std::endl;
        std::cout << "   Limit=" << m_limit << "." << std::endl;
    }

    // ===========================================================================

    class DepositAccount final : public Account
    {
    private:
        double m_interestRate;

    public:
        // c'tors
        DepositAccount(int account);
        DepositAccount(int account, double interestRate);
        virtual ~DepositAccount() {};

        // public interface
        bool withdraw(double amount) override;
        void print() override;

        void computeInterest(int days);

        // getter / setter
        double getInterestRate();
    };

    DepositAccount::DepositAccount(int accountNumber)
        : DepositAccount(accountNumber, 3.0) {}

    DepositAccount::DepositAccount(int accountNumber, double interestRate)
        : Account(accountNumber), m_interestRate(interestRate) {}

    bool DepositAccount::withdraw(double amount) {
        if (m_balance < amount)
            return false;

        m_balance -= amount;
        return true;
    }

    void DepositAccount::computeInterest(int days) {
        double interest =
            (days * m_interestRate * m_balance) / 365.0 / 100.0;

        m_balance += interest;
    }

    double DepositAccount::getInterestRate() {
        return m_interestRate;
    }

    void DepositAccount::print() {
        std::cout << "DepositAccount [Nr. " << m_accountNumber << "]:" << std::endl;
        std::cout << "   Balance=" << m_balance << ";" << std::endl;
        std::cout << "   InterestRate=" << m_interestRate << "." << std::endl;
    }

    // ===========================================================================

    class StudentsAccount final : public Account
    {
    public:
        // c'tors
        StudentsAccount(int accountNumber);
        virtual ~StudentsAccount() {};

        // public interface
        bool withdraw(double amount) override;
        void print() override;
    };

    StudentsAccount::StudentsAccount(int accountNumber)
        : Account(accountNumber) {}

    bool StudentsAccount::withdraw(double amount) {
        if (m_balance < amount)
            return false;

        m_balance -= amount;
        return true;
    }

    void StudentsAccount::print() {
        std::cout << "StudentsAccount [Nr. " << m_accountNumber << "]:" << std::endl;
        std::cout << "   Balance=" << m_balance << ";" << std::endl;
    }
}

// ===========================================================================

void exerciseMoreBankAccounts()
{
    using namespace MoreBankAccounts;

    CurrentAccount ca(123456, 1000);
    ca.deposit(100);
    ca.withdraw(40);
    ca.print();

    StudentsAccount sa(343434);
    sa.deposit(50);
    sa.withdraw(25);
    sa.print();

    DepositAccount da(654321, 4.0);
    da.deposit(200);
    da.withdraw(120);
    da.computeInterest(31);
    da.print();
}

// ===========================================================================
// End-of-File
// ===========================================================================
