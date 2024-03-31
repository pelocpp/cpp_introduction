// ===========================================================================
// Wallet.h
// ===========================================================================

#pragma once

#include <iostream>

class Wallet
{
    friend std::ostream& operator<<(std::ostream& out, const Wallet& Wallet);

private:
    unsigned long long m_euros;
    unsigned int m_cents;

public:
    // c'tors
    Wallet();
    Wallet(unsigned long long euros, unsigned int cents);
    explicit Wallet(unsigned long long euros);
    Wallet(std::string euros, std::string cents);

    // getter
    unsigned long long getEuros() const;
    unsigned int getCent() const;

    // public interface
    void add(const Wallet& other);
    void add(unsigned long long euros);
    void sub(const Wallet& other);
    void sub(unsigned long long euros);
    void print() const;

    int compareTo(const Wallet& other) const;
    unsigned long long to_cents() const;
    std::string to_string() const;

    // operators
    void operator += (const Wallet&);
    void operator += (unsigned long long);
    void operator -= (const Wallet&);
    void operator -= (unsigned long long);

    // increment/decrement operators (prefix/postfix version)
    Wallet& operator++ ();     // prefix increment
    Wallet  operator++ (int);  // postfix increment
    Wallet& operator-- ();     // prefix decrement
    Wallet  operator-- (int);  // postfix decrement

    // comparison operators
    friend bool operator== (const Wallet&, const Wallet&);
    friend bool operator!= (const Wallet&, const Wallet&);
    friend bool operator<  (const Wallet&, const Wallet&);
    friend bool operator<= (const Wallet&, const Wallet&);
    friend bool operator>  (const Wallet&, const Wallet&);
    friend bool operator>= (const Wallet&, const Wallet&);
};

// ===========================================================================
// End-of-File
// ===========================================================================
