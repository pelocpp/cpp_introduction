// ===========================================================================
// Fraction.cpp
// ===========================================================================

#include <iostream>

#include "Fraction.h"

// c'tors
Fraction::Fraction() : m_num(0), m_denom(1) { }

Fraction::Fraction(int num, int denom)
{
    m_num = num;
    m_denom = (denom == 0) ? 1 : denom;
    checkSigns();
    reduce();
}

// conversion c'tor
Fraction::Fraction(int num)
{
    m_num = num;
    m_denom = 1;
}

// setter
void Fraction::setNum(int num)
{
    m_num = num;
    reduce();
}

void Fraction::setDenom(int denom)
{
    if (denom != 0)
    {
        m_denom = denom;
        checkSigns();
        reduce();
    }
}

// implementation of unary arithmetic operators
Fraction operator+ (const Fraction& f)
{
    return Fraction(f);
}

Fraction operator- (const Fraction & f)
{
    return Fraction(-f.m_num, f.m_denom);
}

Fraction operator~ (const Fraction & f)
{
    return Fraction(f.m_denom, f.m_num);
}

// implementation of binary arithmetic operators
Fraction operator+ (const Fraction & f1, const Fraction & f2)
{
    int num = f1.m_num * f2.m_denom + f1.m_denom * f2.m_num;
    int denom = f1.m_denom * f2.m_denom;
    return Fraction(num, denom);
}

Fraction operator- (const Fraction& f1, const Fraction& f2)
{
    int num = f1.m_num * f2.m_denom - f1.m_denom * f2.m_num;
    int denom = f1.m_denom * f2.m_denom;
    return Fraction(num, denom);
}

Fraction operator* (const Fraction & f1, const Fraction & f2)
{
    int num = f1.m_num * f2.m_num;
    int denom = f1.m_denom * f2.m_denom;
    return Fraction(num, denom);
}

Fraction operator/ (const Fraction & f1, const Fraction & f2)
{
    int num = f1.m_num * f2.m_denom;
    int denom = f1.m_denom * f2.m_num;
    return Fraction(num, denom);
}

// arithmetic-assignment operators
const Fraction& operator+= (Fraction& f1, const Fraction& f2)
{
    f1.m_num = f1.m_num * f2.m_denom + f1.m_denom * f2.m_num;
    f1.m_denom = f1.m_denom * f2.m_denom;
    f1.reduce();
    return f1;
}

const Fraction& operator-= (Fraction& f1, const Fraction& f2)
{
    f1.m_num = f1.m_num * f2.m_denom - f1.m_denom * f2.m_num;
    f1.m_denom = f1.m_denom * f2.m_denom;
    f1.reduce();
    return f1;
}

const Fraction& operator*= (Fraction& f1, const Fraction& f2)
{
    f1.m_num = f1.m_num * f2.m_num;
    f1.m_denom = f1.m_denom * f2.m_denom;
    f1.reduce();
    return f1;
}

const Fraction & operator/= (Fraction & f1, const Fraction & f2)
{
    f1.m_num = f1.m_num * f2.m_denom;
    f1.m_denom = f1.m_denom * f2.m_num;
    f1.reduce();
    return f1;
}

// comparison operators   
bool operator<= (const Fraction & f1, const Fraction & f2)
{
    return f1.m_num * f2.m_denom <= f1.m_denom * f2.m_num;
}

bool operator< (const Fraction & f1, const Fraction & f2)
{
    return f1.m_num * f2.m_denom < f1.m_denom* f2.m_num;
}

bool operator>= (const Fraction & f1, const Fraction & f2)
{
    return !(f1 < f2);
}

bool operator> (const Fraction & f1, const Fraction & f2)
{
    return !(f1 <= f2);
}

bool operator== (const Fraction & f1, const Fraction & f2)
{
    return f1.m_num * f2.m_denom == f1.m_denom * f2.m_num;
}

bool operator!= (const Fraction & f1, const Fraction & f2)
{
    return !(f1 == f2);
}

// conversion operator (Fraction -> double)
Fraction::operator double()
{
    return (double)m_num / (double)m_denom;
}

// increment operator: prefix version
Fraction & operator++ (Fraction & f)
{
    f += 1;
    return f;
}

// decrement operator: prefix version
Fraction & operator-- (Fraction & f)
{
    f -= 1;
    return f;
}

// increment operator: postfix version
const Fraction operator++ (Fraction & f, int)
{
    Fraction tmp(f); // construct a copy
    ++f;             // increment number
    return tmp;      // return the copy
}

// decrement operator: postfix version
const Fraction operator-- (Fraction & f, int)
{
    Fraction tmp(f); // construct a copy
    --f;             // decrement number
    return tmp;      // return the copy
}

// private helper method
void Fraction::checkSigns()
{
    // normalize fraction
    if (m_denom < 0)
    {
        m_num *= -1;
        m_denom *= -1;
    }
}

void Fraction::reduce()
{
    int sign = (m_num < 0) ? -1 : 1;
    int gcd = Fraction::gcd(sign * m_num, m_denom);
    m_num /= gcd;
    m_denom /= gcd;
}

int Fraction::gcd(int n, int m)
{
    if (n != m)
    {
        // calculate greatest common divisor of numerator and denominator
        while (m > 0)
        {
            int rem = n % m;
            n = m;
            m = rem;
        }
    }

    return n;
}

// output operator
std::ostream & operator<< (std::ostream & os, const Fraction & f)
{
    os << f.m_num << '/' << f.m_denom;
    return os;
}

// input operator
std::istream & operator>> (std::istream & is, Fraction & f)
{
    is >> f.m_num >> f.m_denom;
    f.reduce();
    return is;
}

// ===========================================================================
// End-of-File
// ===========================================================================
