// ===========================================================================
// Wallet.cpp
// ===========================================================================

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <stdexcept>

#include "Wallet.h"

// c'tors
Wallet::Wallet() : m_euros(0), m_cents(0) {}

Wallet::Wallet(unsigned long long euros, unsigned int cents)
    : m_euros(euros), m_cents(cents)
{
    if (m_cents >= 100) {
        throw std::out_of_range("Cents larger than 100 are not allowed!");
    }
}

Wallet::Wallet(unsigned long long euros) 
    : m_euros(euros), m_cents(0)
{}

Wallet::Wallet(std::string euros, std::string cents)
    : m_euros(0), m_cents(0)
{
    std::size_t pos = 0;
    long long result = 0;
    std::size_t length = 0;

    // verifying euros
    try
    {
        length = euros.length();
        m_euros = std::stoll(euros, &pos);
    }
    catch (std::invalid_argument const& ex)
    {
        std::cout << "Wrong format for euros values expected: " << euros << " - " << ex.what() << std::endl;
        throw std::invalid_argument("Wrong format for euro value");
    }

    if (m_euros < 0) {
        throw std::invalid_argument("Only positive value for euro valid!");
    }

    if (length != pos) {
        throw std::invalid_argument("Wrong format for euro value!");
    }

    if (length == 0) {
        throw std::invalid_argument("Wrong format for euro value!");
    }

    if (euros[0] == '-') {
        throw std::invalid_argument("Negative value for euro not allowed!");
    }

    // verifying cents
    try
    {
        length = cents.length();
        m_cents = std::stoi(cents, &pos);
    }
    catch (std::invalid_argument const& ex)
    {
        std::cout << "Wrong format for cents values expected: " << cents << " - " << ex.what() << std::endl;
        throw std::invalid_argument("Wrong format for cent values");

    }

    if (m_cents < 0) {
        throw std::invalid_argument("Only positive value for cent valid!");
    }

    if (m_cents >= 100) {
        throw std::out_of_range("Cents larger than 100 are not allowed!");
    }

    if (length != pos) {
        throw std::invalid_argument("Wrong format for cent value!");
    }

    if (length == 0) {
        throw std::invalid_argument("Wrong format for cent value!");
    }

    if (cents[0] == '-') {
        throw std::invalid_argument("Negative value for cent not allowed!");
    }
}

// getter
unsigned long long Wallet::getEuros() const { return m_euros; }

unsigned int Wallet::getCent() const { return m_cents; }

// public interface
void Wallet::add(const Wallet& other) {

    m_cents = m_cents + other.m_cents;
    unsigned int carry = m_cents / 100;

    m_cents = m_cents % 100;
    m_euros = m_euros + other.m_euros + carry;
}

void Wallet::add(unsigned long long euros) {

    m_euros = m_euros + euros;
}

void Wallet::sub(const Wallet& other) {

    if (*this < other) {
        throw std::invalid_argument("Not enough money available in wallet!");
        return;
    }

    if (m_cents < other.m_cents)
    {
        m_euros = m_euros - 1;
        m_cents = m_cents + 100;
    }

    m_euros = m_euros - other.m_euros;
    m_cents = m_cents - other.m_cents;
}

void Wallet::sub(unsigned long long euros) {

    if (m_euros < euros) {
        throw std::invalid_argument("Not enough money available in wallet!");
        return;
    }

    m_euros = m_euros - euros;
}

void Wallet::print() const
{
    std::cout << m_euros << "." << std::setw(2) << std::setfill('0') << m_cents << std::endl;
}

int  Wallet::compareTo(const Wallet& other) const {

    int value = 0;

    if (m_euros < other.m_euros)
    {
        value = -1;
    }
    else if (m_euros > other.m_euros)
    {
        value = 1;
    }
    else if (m_cents < other.m_cents)
    {
        value = -1;
    }
    else if (m_cents > other.m_cents)
    {
        value = 1;
    }
    else
    {
        value = 0;
    }

    return value;
}

unsigned long long Wallet::to_cents() const {

    return 100 * m_euros + m_cents;
}

std::string Wallet::to_string() const {

    std::ostringstream oss;
    oss << m_euros << "." << std::setw(2) << std::setfill('0') << m_cents;
    return oss.str();
}

// operators
void Wallet::operator += (const Wallet& other) {
    add(other);
}

void Wallet::operator += (unsigned long long euros) {
    add(euros);
}

void Wallet::operator -= (const Wallet& other) {
    sub(other);
}

void Wallet::operator -= (unsigned long long euros) {
    sub(euros);
}

// increment operator: prefix version
Wallet& Wallet::operator++()
{
    add(1);
    return *this;
}

// decrement operator: prefix version
Wallet& Wallet::operator--()
{
    sub(1);
    return *this;
}

// increment operator: postfix version
Wallet Wallet::operator++(int)
{
    Wallet tmp(*this);  // construct a copy
    add(1);             // increment wallet
    return tmp;         // return the copy
}

// decrement operator: postfix version
Wallet Wallet::operator--(int)
{
    Wallet tmp(*this);  // construct a copy
    sub(1);             // decrement wallet
    return tmp;         // return the copy
}

// comparison operators
bool operator== (const Wallet& lhs, const Wallet& rhs) {
    if (lhs.m_euros == rhs.m_euros && lhs.m_cents == rhs.m_cents) {
        return true;
    }
    else {
        return false;
    }
}

bool operator!= (const Wallet& lhs, const Wallet& rhs) {
    return !(lhs == rhs);
}

bool operator<(const Wallet& lhs, const Wallet& rhs)
{
    if (lhs.m_euros < rhs.m_euros) {
        return true;
    }
    else if (lhs.m_euros == rhs.m_euros && lhs.m_cents < rhs.m_cents) {
        return true;
    }
    else {
        return false;
    }
}

bool operator<= (const Wallet& lhs, const Wallet& rhs)
{
    return lhs < rhs || lhs == rhs;
}

bool operator>  (const Wallet& lhs, const Wallet& rhs)
{
    return  !(lhs <= rhs);
}

bool operator>= (const Wallet& lhs, const Wallet& rhs)
{
    return  !(lhs < rhs);
}

// output
std::ostream& operator<<(std::ostream& os, const Wallet& wallet) {
    return os << wallet.to_string();
}

// ===========================================================================
// End-of-File
// ===========================================================================
