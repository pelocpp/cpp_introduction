// ===========================================================================
// Main.cpp // std::string
// ===========================================================================

#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>

namespace Strings
{
    static void testChar()
    {
        char ch;
        int n;

        ch = '*';
        std::cout << ch << std::endl;

        n = ch;
        std::cout << n << std::endl;

        ch = 65;     // ASCII table: 'A'
        std::cout << ch << std::endl;

        // printing ASCII table
        for (int i = 0; i <= 127; i++) {

            std::cout << i << ": " << (char) i << std::endl;
        }

        char digit('1');
        bool b1 = std::isdigit(digit);

        char noDigit('!');
        bool b2 = std::isdigit(noDigit);
    }

    static void testString()
    {
        // standard class 'std::string'

        // constructor
        std::string s("12345");

        // operator <<
        std::cout << s << std::endl;

        // getter: size
        size_t len = s.size();
        std::cout << "Length: " << len << std::endl;

        // getter: empty
        bool b = s.empty();
        std::cout << "Empty: " << std::boolalpha << b << std::endl;

        // method: insert
        // insert "ABC" at position 2
        s.insert(2, "ABC");
        std::cout << "s.insert(2, \"ABC\") ==> " << s << std::endl;

        // method: append
        // append "!!!"
        s.append("!!!");
        std::cout << "s.append(\"!!!\")    ==> " << s << std::endl;

        // comparison operators
        std::string s1("12345");
        std::string s2("12345");
        std::string s3("123456");

        bool b1 = (s1 == s2);
        bool b2 = (s1 == s3);

        std::cout << "s1 == s2           ==> " << std::boolalpha << b1 << std::endl;
        std::cout << "s1 == s3           ==> " << std::boolalpha << b2 << std::endl;

        // method: substr - retrieve a substring
        // first param = position of the first character to include
        // second param = length of the substring
        std::string sub = s1.substr(1, 3);
        std::cout << "s1.substr(1, 3)    ==> " << std::boolalpha << sub << std::endl;
        
        // index operator []
        s[2] = '?';
        std::cout << "s[2] = '?'         ==> " << s << std::endl;

        // method: append
        // append another std::string object
        std::string result;
        result = s1.append(s2);
        std::cout << "s1.append(s2)      ==> " << result << std::endl;

        // operator +
        // concatenating two strings (same as using method append)
        result = s1 + s3;
        std::cout << "s1 + s3            ==> " << result << std::endl;

        // converting a string to an integer
        std::string number("123");
        int value = std::stoi(number);
        std::cout << "std::stoi(\"123\")   ==> " << value << std::endl;
    }
}

void testStrings()
{
    using namespace Strings;

    testChar();
    testString();
}

// ===========================================================================
// End-of-File
// ===========================================================================
