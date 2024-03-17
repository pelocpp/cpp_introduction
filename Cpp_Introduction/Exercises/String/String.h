// ===========================================================================
// String.h
// ===========================================================================

#pragma once

#include <iostream>

class String
{
private:
    char* m_ptr; // buffer
    int m_len;   // buffer length

public:
    // c'tors and d'tor
    String();
    String(const char*);
    String(const String&);
    ~String();

    // public methods
    int length() const;
    bool insert(const String&, int);
    bool remove(int, int);
    void append(const String&);
    String subString(int, int) const;
    int find(const String&) const;
    void toUpper();
    void toLower();
    String left(int) const;
    String right(int) const;

    // assignment operator
    String & operator= (const String&);

    // subscript operator
    char& operator[] (int index);

    // string concatenation
    friend String operator+ (const String&, const String&);
    friend const String & operator+= (String&, const String&);

    // comparison operators
    friend bool operator== (const String&, const String&);
    friend bool operator!= (const String&, const String&);

    // input/output
    friend std::ostream & operator<< (std::ostream&, const String&);
    friend std::istream & operator>> (std::istream&, String&);
};

// ===========================================================================
// End-of-File
// ===========================================================================
