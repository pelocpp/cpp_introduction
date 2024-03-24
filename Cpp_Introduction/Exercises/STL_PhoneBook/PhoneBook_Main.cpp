// ===============================================================================
// PhoneBook_Main.cpp
// ===============================================================================

#include <iostream>
#include <chrono> 

#include "PhoneBookVector.h"
#include "PhoneBookMap.h"

static void test01_phonebook()
{
    using namespace PhoneBook;

    PhoneBookVector book;

    // testing insert
    book.insert("Franz", "Schneider", 8483);
    book.insert("Hans", "Mueller", 5326);
    book.insert("Sepp", "Meier", 7561);
    book.insert("Anton", "Huber", 4899);
    book.print();

    // testing invalid insertion
    bool succeeded = book.insert("Franz", "Schneider", 4321);
    if (!succeeded) {
        std::cout << "Franz Schneider already in Phonebook!" << std::endl;
    }

    // testing toString
    std::string s = book.toString();
    std::cout << s << std::endl;

    // testing sort
    book.sort();
    book.print();

    // testing update
    std::cout << "Updating phone number of Franz Schneider:" << std::endl;
    succeeded = book.update("Franz", "Schneider", 1234);
    book.print();

    // testing remove
    std::cout << "Removing Anton Huber:" << std::endl;
    succeeded = book.remove("Anton", "Huber");
    book.print();

    // testing contains
    bool found = book.contains("Sepp", "Meier");
    std::cout << "Found Sepp Meier: " << std::boolalpha << found << std::endl;
    found = book.contains("Otto", "Meier");
    std::cout << "Found Otto Meier: " << found << std::endl;

    // testing search
    size_t numberMeier = 0;
    succeeded = book.search("Sepp", "Meier", numberMeier);
    if (succeeded) {
        std::cout << "Hans Meier: " << numberMeier << std::endl;
    }
    std::cout << std::endl;

    // testing 'getNames'
    std::forward_list<std::string> allNames = book.getNames();
    size_t i = 1;
    for (const std::string& name : allNames) {
        std::cout << i << ": " << name << std::endl;
        ++i;
    }
    std::cout << std::endl;
}

static void test02_phonebook()
{
    using namespace PhoneBook;

    PhoneBookMap book;

    // testing insert
    book.insert("Franz", "Schneider", 8483);
    book.insert("Hans", "Mueller", 5326);
    book.insert("Sepp", "Meier", 7561);
    book.insert("Anton", "Huber", 4899);
    book.print();

    // testing invalid insertion
    bool succeeded = book.insert("Franz", "Schneider", 4321);
    if (!succeeded) {
        std::cout << "Franz Schneider already in Phonebook!" << std::endl;
    }

    // testing toString
    std::string s = book.toString();
    std::cout << s << std::endl;

    // testing sort
    // book.sort();  // std::unordered map doesn't support sorting
    book.print();

    // testing update
    std::cout << "Updating phone number of Franz Schneider:" << std::endl;
    succeeded = book.update("Franz", "Schneider", 1234);
    book.print();

    // testing remove
    std::cout << "Removing Anton Huber:" << std::endl;
    succeeded = book.remove("Anton", "Huber");
    book.print();

    // testing contains
    bool found = book.contains("Sepp", "Meier");
    std::cout << "Found Sepp Meier: " << std::boolalpha << found << std::endl;
    found = book.contains("Otto", "Meier");
    std::cout << "Found Otto Meier: " << found << std::endl;

    // testing search
    size_t numberMeier = 0;
    succeeded = book.search("Sepp", "Meier", numberMeier);
    if (succeeded) {
        std::cout << "Hans Meier: " << numberMeier << std::endl;
    }
    std::cout << std::endl;

    // testing 'getNames'
    std::forward_list<std::string> allNames = book.getNames();
    size_t i = 1;
    for (const std::string& name : allNames) {
        std::cout << i << ": " << name << std::endl;
        ++i;
    }
    std::cout << std::endl;
}

// ===============================================================================

const long long MaxNames = 10000;
const long long MaxIterations = 10000;

static void test03_benchmark_01()
{
    std::string first("First_");
    std::string last("Last_");

    // initialization
    for (int i = 0; i < MaxNames; ++i) {

        std::string vorname = first + std::to_string(i);
        std::string nachname = last + std::to_string(i);

        std::cout << "First: " << vorname << std::endl;
        std::cout << "Last:  " << nachname << std::endl;
    }
}

static void test03_benchmark_02()
{
    using namespace PhoneBook;

    std::cout << "Start PhoneBook Vector" << std::endl;

    const auto startTime(std::chrono::high_resolution_clock::now());

    PhoneBookVector book;

    std::string first("First_");
    std::string last("Last_");

    // initialization
    for (int i = 0; i < MaxNames; ++i) {

        std::string vorname = first + std::to_string(i);
        std::string nachname = last + std::to_string(i);

        book.insert(vorname, nachname, (size_t)10000 + i);
    }

    std::cout << "Done." << std::endl;

    const auto endTime(std::chrono::high_resolution_clock::now());

    std::cout
        << std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(endTime - startTime).count()
        << " msecs."
        << std::endl;
}

static void test03_benchmark_03()
{
    using namespace PhoneBook;

    std::cout << "Start PhoneBook Hashmap" << std::endl;

    const auto startTime(std::chrono::high_resolution_clock::now());

    PhoneBookMap book;

    std::string first("First_");
    std::string last("Last_");

    // initialization
    for (int i = 0; i < MaxIterations; ++i) {

        std::string vorname = first + std::to_string(i);
        std::string nachname = last + std::to_string(i);

        book.insert(vorname, nachname, (size_t)10000 + i);
    }

    std::cout << "Done." << std::endl;

    const auto endTime(std::chrono::high_resolution_clock::now());

    std::cout
        << std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(endTime - startTime).count()
        << " msecs."
        << std::endl;
}

static void test03_benchmark_04()
{
    using namespace PhoneBook;

    std::cout << "Start PhoneBook Vector" << std::endl;

    const auto startTime(std::chrono::high_resolution_clock::now());

    PhoneBookVector book;

    std::string first("First_");
    std::string last("Last_");

    // initialization
    for (int i = 0; i < MaxNames; ++i) {

        std::string firstName = first + std::to_string(i);
        std::string lastName = last + std::to_string(i);

        book.insert(firstName, lastName, (size_t)10000 + i);
    }

    std::cout << "Initialization done." << std::endl;

    const auto endTime(std::chrono::high_resolution_clock::now());

    std::cout
        << std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(endTime - startTime).count()
        << " msecs."
        << std::endl;

    // test searching a number
    const auto startTime2(std::chrono::high_resolution_clock::now());

    first = "First_999";
    last = "Last_999";

    for (int i = 0; i < MaxIterations; ++i) {

        size_t number = 0;
        bool succeeded = book.search(first, last, number);
        if (! succeeded) {
            std::cout << "Internal Error" << std::endl;
        }
    }

    const auto endTime2(std::chrono::high_resolution_clock::now());

    std::cout
        << std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(endTime2 - startTime2).count()
        << " msecs."
        << std::endl;
}

static void test03_benchmark_05()
{
    using namespace PhoneBook;

    std::cout << "Start PhoneBook Hashmap" << std::endl;

    const auto startTime(std::chrono::high_resolution_clock::now());

    PhoneBookMap book;

    std::string first("First_");
    std::string last("Last_");

    // Initialization
    for (int i = 0; i < MaxIterations; ++i) {

        std::string firstName = first + std::to_string(i);
        std::string lastName = last + std::to_string(i);

        book.insert(firstName, lastName, (size_t)10000 + i);
    }

    std::cout << "Initialization done." << std::endl;

    const auto endTime(std::chrono::high_resolution_clock::now());

    std::cout
        << std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(endTime - startTime).count()
        << " msecs."
        << std::endl;


    // test searching a number
    const auto startTime2(std::chrono::high_resolution_clock::now());

    first = "First_999";
    last = "Last_999";

    for (int i = 0; i < MaxIterations; ++i) {

        size_t number = 0;
        bool succeeded = book.search(first, last, number);
        if (!succeeded) {
            std::cout << "Internal Error" << std::endl;
        }
    }

    const auto endTime2(std::chrono::high_resolution_clock::now());

    std::cout
        << std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(endTime2 - startTime2).count()
        << " msecs."
        << std::endl;
}

void exerciseSTLPhoneBook()
{
    test01_phonebook();
    test02_phonebook();
    test03_benchmark_01();
    test03_benchmark_02();
    test03_benchmark_03();
    test03_benchmark_04();
    test03_benchmark_05();
}

// ===============================================================================
// End-of-File
// ===============================================================================
