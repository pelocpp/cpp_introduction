// ===========================================================================
// Fraction.h
// ===========================================================================

#pragma once

#include <iostream>

class Fraction
{
private:
    // private member data
    int m_num;    // numerator
    int m_denom;  // denominator

public:
    // c'tors
    Fraction();
    Fraction(int, int);

    // conversion c'tor
    Fraction(int);

    // getter / setter
    int getNum() const { return m_num; }
    void setNum(int num);
    int getDenom() const { return m_denom; }
    void setDenom(int denom);

    // unary arithmetic operators
    friend Fraction operator+ (const Fraction&);
    friend Fraction operator- (const Fraction&);
    friend Fraction operator~ (const Fraction&);

    // binary arithmetic operators
    friend Fraction operator+ (const Fraction&, const Fraction&);
    friend Fraction operator- (const Fraction&, const Fraction&);
    friend Fraction operator* (const Fraction&, const Fraction&);
    friend Fraction operator/ (const Fraction&, const Fraction&);

    // arithmetic-assignment operators
    friend const Fraction & operator+= (Fraction&, const Fraction&);
    friend const Fraction & operator-= (Fraction&, const Fraction&);
    friend const Fraction & operator*= (Fraction&, const Fraction&);
    friend const Fraction & operator/= (Fraction&, const Fraction&);

    // increment/decrement operators (prefix/postfix version)
    friend Fraction & operator++ (Fraction&);           // prefix increment
    friend const Fraction operator++ (Fraction&, int);  // postfix increment
    friend Fraction & operator-- (Fraction&);           // prefix decrement
    friend const Fraction operator-- (Fraction&, int);  // postfix decrement

    // comparison operators
    friend bool operator<= (const Fraction&, const Fraction&);
    friend bool operator<  (const Fraction&, const Fraction&);
    friend bool operator>= (const Fraction&, const Fraction&);
    friend bool operator>  (const Fraction&, const Fraction&);
    friend bool operator== (const Fraction&, const Fraction&);
    friend bool operator!= (const Fraction&, const Fraction&);

    // type conversion operator (Fraction -> double)
    operator double();

    // input / output operators
    friend std::ostream & operator<< (std::ostream&, const Fraction&);
    friend std::istream & operator>> (std::istream&, Fraction&);

    private:
    // private helper methods
    void checkSigns();
    void reduce();

private:
    // private class helper method
    static int gcd(int n, int m);
};

// ===========================================================================
// End-of-File
// ===========================================================================
