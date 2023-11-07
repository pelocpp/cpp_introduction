// ===========================================================================
// Strings_Main.cpp
// ===========================================================================

#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>

bool verifyDateFormat(std::string date)
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

std::string dateToWord(std::string date)
{
    if (!verifyDateFormat(date)) {
        return "";
    }

    std::string sDay = date.substr(0, 2);
    std::string sMonth = date.substr(3, 2);
    std::string sYear = date.substr(6, 4);

    // convert month string to int
    int month = std::stoi(sMonth);

    std::string monthLabel;

    switch (month)
    {
    case 1:
        monthLabel = "January";
        break;
    case 2:
        monthLabel = "February";
        break;
    case 3:
        monthLabel = "March";
        break;
    case 4:
        monthLabel = "April";
        break;
    case 5:
        monthLabel = "May";
        break;
    case 6:
        monthLabel = "June";
        break;
    case 7:
        monthLabel = "July";
        break;
    case 8:
        monthLabel = "August";
        break;
    case 9:
        monthLabel = "September";
        break;
    case 10:
        monthLabel = "October";
        break;
    case 11:
        monthLabel = "November";
        break;
    case 12:
        monthLabel = "December";
        break;
    default:
        break;
    }

    // remove leading '0', if any
    if (sDay.length() == 2 && sDay[0] == '0') {
        sDay = sDay[1];
    }

    std::string word = sDay + ". " + monthLabel + " " + sYear;
    return word;
}

void testDateToWord()
{
    // test 'verifyDateFormat'
    std::cout << std::boolalpha << verifyDateFormat("10.08.2000") << std::endl;
    std::cout << std::boolalpha << verifyDateFormat("ABCDEFGHIJK") << std::endl;
    std::cout << std::boolalpha << verifyDateFormat("10:08:4321") << std::endl;
    std::cout << std::boolalpha << verifyDateFormat("10.XX.4321") << std::endl;

    // test 'dateToWord'
    std::string s = dateToWord("12.08.2000");
    std::cout << s << std::endl;

    s = dateToWord("01.11.2023");
    std::cout << s << std::endl;
}

// ===========================================================================
// End-of-File
// ===========================================================================
