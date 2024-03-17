// ===========================================================================
// String.cpp
// ===========================================================================

#include <stdexcept>

#include "String.h"

// c'tors and d'tor
String::String()
{
    // empty string
    m_len = 0;
    m_ptr = (char*)0;
}

String::String(const String & s)
{
    // allocate buffer
    m_len = s.m_len;
    m_ptr = new char[m_len];

    // copy object
    for (int i = 0; i < m_len; i++)
        m_ptr[i] = s.m_ptr[i];
}

String::String(const char* s)
{
    // length of string
    m_len = 0;
    while (s[m_len] != '\0')
        m_len++;

    // allocate buffer
    m_ptr = new char[m_len];

    // copy string
    for (int i = 0; i < m_len; i++)
        m_ptr[i] = s[i];
}

String::~String()
{
    delete[] m_ptr;
}

// getter
int String::length() const
{
    return m_len;
}

char& String::operator[] (int index)
{
    // check parameter
    if (index < 0 || index >= m_len)
        throw std::out_of_range("Wrong index");

    return m_ptr[index];
}

// public methods
bool String::insert(const String & s, int ofs)
{
    if (ofs > m_len)
        return false;

    // allocate new buffer
    char* tmp = new char[m_len + s.m_len];

    for (int i = 0; i < ofs; i++)      // copy first part
        tmp[i] = m_ptr[i];
    for (int i = 0; i < s.m_len; i++)  // copy string to insert
        tmp[ofs + i] = s.m_ptr[i];
    for (int i = ofs; i < m_len; i++)  // copy second part
        tmp[s.m_len + i] = m_ptr[i];

    delete[] m_ptr;   // release old buffer
    m_ptr = tmp;      // switch buffer
    m_len += s.m_len; // adjust buffer length

    return true;
}

void String::append(const String& s)
{
    insert(s, m_len);
}

bool String::remove(int ofs, int num)
{
    if (ofs + num > m_len)
        return false;

    // allocate new buffer
    char* tmp = new char[m_len - num];

    // copy remaining parts
    for (int i = 0; i < ofs; i++)            // first part
        tmp[i] = m_ptr[i];
    for (int i = ofs + num; i < m_len; i++)  // second part
        tmp[i - num] = m_ptr[i];

    delete[] m_ptr; // release old buffer
    m_ptr = tmp;    // switch buffer
    m_len -= num;   // adjust buffer length

    return true;
}

String String::subString(int ofs, int num) const
{
    String empty;
    if (ofs < 0)
        return empty;
    if (ofs > m_len)
        return empty;
    if (ofs + num > m_len)
        return empty;

    // allocate temporary buffer
    char* tmp = new char[num + 1];

    // copy partial string
    for (int i = 0; i < num; i++)
        tmp[i] = m_ptr[ofs + i];
    tmp[num] = '\0'; // terminate buffer

    // create result object
    String s(tmp);
    delete[] tmp; // release temporary buffer
    return s;
}

int String::find(const String & s) const
{
    for (int i = 0; i < m_len - s.m_len + 1; i++)
    {
        int k = 0;
        while (k < s.m_len)
        {
            if (m_ptr[i + k] != s.m_ptr[k])
                break;
            k++;
        }

        if (k == s.m_len)
            return i;
    }

    return -1;
}

void String::toUpper()
{
    for (int i = 0; i < m_len; i++)
        if (m_ptr[i] >= 'a' && m_ptr[i] <= 'z')
            m_ptr[i] -= ('a' - 'A');
}

void String::toLower()
{
    for (int i = 0; i < m_len; i++)
        if (m_ptr[i] >= 'A' && m_ptr[i] <= 'Z')
            m_ptr[i] += ('a' - 'A');
}

String String::left(int num) const
{
    return subString(0, num);
}

String String::right(int num) const
{
    return subString(length() - num, num);
}

// assignment operator
String & String::operator= (const String & s)
{
    if (this != &s)
    {
        // delete old string
        delete[] m_ptr;

        // allocate new buffer
        m_len = s.m_len;
        m_ptr = new char[m_len];

        // deep copy
        for (int i = 0; i < m_len; i++)
            m_ptr[i] = s.m_ptr[i];
    }

    return *this;
}

// string concatenation
String operator+ (const String & s1, const String & s2)
{
    String s(s1);
    s.append(s2);
    return s;
}

const String & operator+= (String & s1, const String & s2)
{
    s1.append(s2);
    return s1;
}

// comparison operators
bool operator== (const String & s1, const String & s2)
{
    if (s1.m_len != s2.m_len)
        return false;

    for (int i = 0; i < s1.m_len; i++)
        if (s1.m_ptr[i] != s2.m_ptr[i])
            return false;

    return true;
}

bool operator!= (const String & s1, const String & s2)
{
    return !(s1 == s2);
}

// output operator
std::ostream & operator<< (std::ostream & os, const String & s)
{
    os << '"';
    for (int i = 0; i < s.m_len; i++)
        os << s.m_ptr[i];
    os << "\"[" << s.m_len << ']';

    return os;
}

// input operator
std::istream & operator>> (std::istream & is, String & s)
{
    char line[256];
    is.getline(line, 256);

    // calculate length of string
    int len = 0;
    while (line[len] != '\0')
        len++;

    // release old buffer, if any
    delete[] s.m_ptr;

    // allocate new buffer and copy string
    s.m_ptr = new char[len];
    for (int i = 0; i < len; i++)
        s.m_ptr[i] = line[i];

    // adjust buffer length
    s.m_len = len;

    return is;
}

// ===========================================================================
// End-of-File
// ===========================================================================
