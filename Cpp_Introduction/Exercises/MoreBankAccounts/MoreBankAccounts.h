// ===========================================================================
// MoreBankAccounts.h
// ===========================================================================

#include <iostream>

namespace MoreBankAccounts {

    // Interface 'IAccount'
    class IAccount
    {
    public:
        // getter/setter
        virtual double getAccountNumber() const = 0;
        virtual double getBalance() const = 0;

        // public interface
        virtual void deposit(double) = 0;
        virtual bool withdraw(double) = 0;
        virtual void print() const = 0;
    };

    // ===========================================================================

    // Abstract Base Class 'Account'
    class Account : public IAccount
    {
    protected:
        int    m_number;
        double m_balance;

    private:
        static int s_nextNumber;

    public:
        // default c'tor
        Account() : m_balance(0.0) {

            // retrieve next available account number
            m_number = s_nextNumber;
            s_nextNumber++;
        }

        // getter / setter
        double getAccountNumber() const final override {
            return m_number;
        }

        double getBalance() const final override {
            return m_balance; 
        }

        // public interface
        void deposit(double amount) final override {
            m_balance += amount;
        }

        void print() const override {
            std::cout << "    [Nr. " << m_number << "]:" << std::endl;
            std::cout << "    Balance = " << m_balance << ";" << std::endl;
        }
    };

    // ===========================================================================

    // Concrete Class 'CurrentAccount'
    class CurrentAccount : public Account
    {
    private:
        double m_limit;

    public:
        // c'tors
        CurrentAccount() : CurrentAccount(1000.0) {}
        CurrentAccount(double limit) : Account(), m_limit(1000.0) {}

        // getter / setter
        double getLimit() {
            return m_limit;
        }

        void setLimit(double limit) {
            m_limit = limit;
        }

        // public interface
        bool withdraw(double amount) override {

            if (m_balance + m_limit < amount)
                return false;

            m_balance -= amount;
            return true;
        }

        void print() const override {
            std::cout << "CurrentAccount:" << std::endl;
            Account::print();
            std::cout << "    Limit = " << m_limit << ";" << std::endl;
        }
    };

    // ===========================================================================

    // Concrete Class 'DepositAccount'
    class DepositAccount final : public Account
    {
    private:
        double m_rate;

    public:
        // c'tor
        DepositAccount() : DepositAccount(3.0) {}
        DepositAccount(double rate) : Account(), m_rate(rate) {}

        // public interface
        bool withdraw(double amount) override {

            if (m_balance < amount)
                return false;

            m_balance -= amount;
            return true;
        }

        // getter / setter
        double getInterestRate() {
            return m_rate;
        }

        void setInterestRate(double rate) {
            m_rate = rate;
        }

        // interest
        void updateInterest(int days)
        {
            double interest = (days * m_rate * m_balance) / 365.0 / 100.0;

            m_balance += interest;
        }

        // public interface
        void print() const override {
            std::cout << "DepositAccount:" << std::endl;
            Account::print();
            std::cout << "    InterestRate = " << m_rate << ";" << std::endl;
        }
    };

    // ===========================================================================

    // Concrete Class 'StudentsAccount'
    class StudentsAccount final : public Account
    {
    public:
        // c'tors
        StudentsAccount() : Account() {}

        bool withdraw(double amount) override {

            if (m_balance < amount)
                return false;

            m_balance -= amount;
            return true;
        }

        void print() const override {
            std::cout << "StudentsAccount:" << std::endl;
            Account::print();
        };
    };
}

// ===========================================================================
// End-of-File
// ===========================================================================
