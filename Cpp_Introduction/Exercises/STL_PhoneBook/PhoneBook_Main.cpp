// ===============================================================================
// IPhoneBook.h
// ===============================================================================

#include <iostream>
#include <chrono> 

#include "PhoneBookVector.h"
#include "PhoneBookMap.h"

void test01_phonebook()
{
    using namespace PhoneBook;

    PhoneBookVector book;

    // testing insert
    book.insert("Franz", "Schneider", 8483);
    book.insert("Hans", "Mueller", 5326);
    book.insert("Hans", "Meier", 7561);
    book.insert("Anton", "Huber", 4899);
    book.print();

    // testing sort
    book.sort();
    book.print();

    // testing update
    std::cout << "Updating phone number of Franz Schneider:" << std::endl;
    bool succeeded = book.update("Franz", "Schneider", 1234);
    //   std::cout << book << std::endl;
    book.print();

    // testing remove
    std::cout << "Removing Anton Huber:" << std::endl;
    succeeded = book.remove("Anton", "Huber");
    book.print();

    // testing contains
    bool found = book.contains("Hans", "Meier");
    std::cout << "Found Hans Meier: " << std::boolalpha << found << std::endl;
    found = book.contains("Otto", "Meier");
    std::cout << "Found Otto Meier: " << found << std::endl;

    // testing search
    size_t numberMeier = 0;
    succeeded = book.search("Hans", "Meier", numberMeier);
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

void test02_phonebook()
{
    using namespace PhoneBook;

    PhoneBookMap book;

    // testing insert
    book.insert("Franz", "Schneider", 8483);
    book.insert("Hans", "Mueller", 5326);
    book.insert("Hans", "Meier", 7561);
    book.insert("Anton", "Huber", 4899);
    book.print();

    // testing sort
    book.sort();
    book.print();

    // testing update
    std::cout << "Updating phone number of Franz Schneider:" << std::endl;
    bool succeeded = book.update("Franz", "Schneider", 1234);
    //   std::cout << book << std::endl;
    book.print();

    // testing remove
    std::cout << "Removing Anton Huber:" << std::endl;
    succeeded = book.remove("Anton", "Huber");
    book.print();

    // testing contains
    bool found = book.contains("Hans", "Meier");
    std::cout << "Found Hans Meier: " << std::boolalpha << found << std::endl;
    found = book.contains("Otto", "Meier");
    std::cout << "Found Otto Meier: " << found << std::endl;

    // testing search
    size_t numberMeier = 0;
    succeeded = book.search("Hans", "Meier", numberMeier);
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

void test03_benchmark_01()
{
    std::string first{ "First_" };
    std::string last{ "Last_" };

    // Initialisierung
    for (int i = 0; i < 100; ++i) {

        std::string vorname = first + std::to_string(i);
        std::string nachname = last + std::to_string(i);

        std::cout << "First: " << vorname << std::endl;
        std::cout << "Last:  " << nachname << std::endl;
    }
}

const long long MaxIterations = 100000;
const long long MaxIterations2 = 100000;

void test03_benchmark_02()
{
    using namespace PhoneBook;

    std::cout << "Start Vector Phonebook" << std::endl;

    const auto startTime{ std::chrono::high_resolution_clock::now() };

    PhoneBookVector book;

    std::string first{ "First_" };
    std::string last{ "Last_" };

    // Initialisierung
    for (int i = 0; i < MaxIterations; ++i) {

        std::string vorname = first + std::to_string(i);
        std::string nachname = last + std::to_string(i);

        book.insert(vorname, nachname, (size_t)10000 + i);
    }

    std::cout << "Initialisierung fertig." << std::endl;

    const auto endTime{ std::chrono::high_resolution_clock::now() };

    std::cout
        << std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(endTime - startTime).count()
        << " msecs."
        << std::endl;

    // Test

    const auto startTime2{ std::chrono::high_resolution_clock::now() };

    for (int k = 0; k < 5; ++k)
    {
        for (int i = 0; i < MaxIterations2; ++i) {

            // Element löschen
        //    book.remove("First_99", "Last_99");

            // Element wieder einfügen
            book.insert("First_99", "Last_99", (size_t)10000 + i);
        }
    }

    const auto endTime2{ std::chrono::high_resolution_clock::now() };

    std::cout
        << std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(endTime2 - startTime2).count()
        << " msecs."
        << std::endl;
}

void test03_benchmark_03()
{
    using namespace PhoneBook;

    std::cout << "Start Vector Hashmap" << std::endl;

    const auto startTime{ std::chrono::high_resolution_clock::now() };

    PhoneBookMap book;

    std::string first{ "First_" };
    std::string last{ "Last_" };

    // Initialisierung
    for (int i = 0; i < MaxIterations; ++i) {

        std::string vorname = first + std::to_string(i);
        std::string nachname = last + std::to_string(i);

        book.insert(vorname, nachname, (size_t)10000 + i);
    }

    std::cout << "Initialisierung fertig." << std::endl;

    const auto endTime{ std::chrono::high_resolution_clock::now() };

    std::cout
        << std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(endTime - startTime).count()
        << " msecs."
        << std::endl;


    // Test

    const auto startTime2{ std::chrono::high_resolution_clock::now() };


    for (int k = 0; k < 5; ++k)
    {
        const auto startTime{ std::chrono::high_resolution_clock::now() };

        for (int i = 0; i < MaxIterations2; ++i) {

            // Element löschen
       //     book.remove("First_99", "Last_99");

            // Element wieder einfügen
            book.insert("First_99", "Last_99", (size_t)10000 + i);
        }
    }

    const auto endTime2{ std::chrono::high_resolution_clock::now() };

    std::cout
        << std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(endTime2 - startTime2).count()
        << " msecs."
        << std::endl;
}

void exerciseSTLPhoneBook()
{
    //test01_phonebook();
    test02_phonebook();
    //test03_benchmark_01();
    //test03_benchmark_02();
    //test03_benchmark_03();
}

// ===============================================================================
// End-of-File
// ===============================================================================
