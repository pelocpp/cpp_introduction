// ===========================================================================
// Strings_Main.cpp
// ===========================================================================

#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>

static bool isLeapYear(int year)
{
    return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
}

static int maxNumOfDays(int month, int year)
{
    switch (month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return 31;

    case 4:
    case 6:
    case 9:
    case 11:
        return 30;

    case 2:
        return (isLeapYear(year)) ? 29 : 28;

    default:
        return 0;
    }
}

static bool IsValid(int day, int month, int year)
{
    if (year < 0) {
        return false;
    }

    if (month < 1 || month > 12) {
        return false;
    }

    if (day < 1 || day > maxNumOfDays(month, year)) {
        return false;
    }

    return true;
}


static bool verifyDateFormat(const std::string& date)
{
    // accepted format: "tt.mm.jjjj"

    if (date.length() != 10) {
        return false;
    }
    else if (date[2] != '.' || date[5] != '.') {
        return false;
    }

    int indices[]{ 0, 1, 3, 4, 6, 7, 8, 9 };

    for (int i = 0; i < 8; ++i) {

        int index = indices[i];

        if (!std::isdigit(date[index])) {
            return false;
        }
    }

    return true;
}

static std::string dateToWord(const std::string& date)
{
    static std::string months[]{
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    if (!verifyDateFormat(date)) {
        return "";
    }

    // verify values
    std::string sDay = date.substr(0, 2);
    std::string sMonth = date.substr(3, 2);
    std::string sYear = date.substr(6, 4);

    // convert month string to int
    int day = std::stoi(sDay);
    int month = std::stoi(sMonth);
    int year = std::stoi(sYear);

    if (! IsValid(day, month, year)) {
        return "";
    }

    std::string label = months[month - 1];

    // remove leading '0', if any
    if (sDay[0] == '0') {
        sDay = sDay[1];
    }

    std::string word = sDay + ". " + label + " " + sYear;
    return word;
}

static void testDateToWord()
{
    // test 'verifyDateFormat'
    std::cout << std::boolalpha << verifyDateFormat("10.08.2000") << std::endl;
    std::cout << std::boolalpha << verifyDateFormat("ABCDEFGHIJK") << std::endl;
    std::cout << std::boolalpha << verifyDateFormat("10:08:4321") << std::endl;
    std::cout << std::boolalpha << verifyDateFormat("10.XX.4321") << std::endl;

    // test 'dateToWord'
    std::string s = dateToWord("12.08.2000");
    std::cout << s << std::endl;

    s = dateToWord("01.13.2023");
    std::cout << s << std::endl;

    s = dateToWord("32.12.2023");
    std::cout << s << std::endl;

    s = dateToWord("01.01.2023");
    std::cout << s << std::endl;

    s = dateToWord("31.12.2023");
    std::cout << s << std::endl;
}

void exerciseStrings()
{
    testDateToWord();
}

// ===========================================================================
// End-of-File
// ===========================================================================


