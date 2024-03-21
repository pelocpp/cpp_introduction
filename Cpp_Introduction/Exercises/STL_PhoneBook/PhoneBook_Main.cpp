#include <iostream>
#include <memory>
#include <chrono> 

#include "PhoneBook.h"
#include "PhoneBookEx.h"
#include "PhoneBookShared.h"

//using namespace PhoneBookVectorBased;
using namespace PhoneBookMapBased;

void test_01()
{
    PhoneBook book;

    // testing insert
    book.insert("Hans", "Mueller", 5326);
    book.insert("Hans", "Meier", 7561);
    book.insert("Franz", "Schneider", 8483);
    book.insert("Anton", "Huber", 4899);
    std::cout << book << std::endl;

    // testing sort
    book.sort();
    std::cout << book << std::endl;

    // testing update
    std::cout << "Updating phone number of Franz Schneider:" << std::endl;
    bool succeeded = book.update("Franz", "Schneider", 1234);
    std::cout << book << std::endl;

    // testing remove
    std::cout << "Removing Anton Huber:" << std::endl;
    succeeded = book.remove("Anton", "Huber");
    std::cout << book << std::endl;

    // testing contains
    bool found = book.contains("Hans", "Meier");
    std::cout << "Found Hans Meier: " << std::boolalpha << found << std::endl;
    found = book.contains("Otto", "Meier");
    std::cout << "Found Otto Meier: " << found << std::endl;

    // testing search
    long numberMeier = 1;
    succeeded = book.search("Hans", "Meier", numberMeier);
    if (succeeded) {
        std::cout << "Hans Meier: " << numberMeier << std::endl;
    }
    std::cout << std::endl;

    // testing 'getNames'
    std::forward_list<std::string> allNames = book.getNames();
    for (size_t i = 1; const auto& name : allNames) {
        std::cout << i << ": " << name << std::endl;
        ++i;
    }
    std::cout << std::endl;

    // testing iterator support of PhoneBook
    for (size_t i = 1; const auto& [first, last, number] : book) {
        std::cout << i << ": " << first << " " << last << ": " << number << std::endl;
        ++i;
    }
}

void test_01_iterator()
{
    PhoneBook book;

    // testing insert
    book.insert("Hans", "Mueller", 5326);
    book.insert("Hans", "Meier", 7561);
    book.insert("Franz", "Schneider", 8483);
    book.insert("Anton", "Huber", 4899);
    std::cout << book << std::endl;

    // testing iterator support of PhoneBook
    for (size_t i = 1; const auto & [first, last, number] : book) {
        std::cout << i << ": " << first << " " << last << ": " << number << std::endl;
        ++i;
    }


    //auto iter = book.begin();

    //std::tuple<>
    //*iter = 123;

 }

void test_02()
{
    std::shared_ptr<PhoneBook> book = std::make_shared<PhoneBook>();

    book->insert("Hans", "Mueller", 5326);
    book->insert("Hans", "Meier", 7561);
    book->insert("Franz", "Schneider", 8483);
    book->insert("Anton", "Huber", 4899);
    std::cout << book << std::endl;

    book->sort();
    std::cout << book << std::endl;

    // testing remove
    std::cout << "Removing Anton Huber: " << std::endl;
    bool succeeded = book->remove("Anton", "Huber");
    std::cout << book << std::endl;

    // testing contains
    bool found = book->contains("Hans", "Meier");
    std::cout << "Found Hans Meier: " << std::boolalpha << found << std::endl;
    found = book->contains("Otto", "Meier");
    std::cout << "Found Otto Meier: " << found << std::endl;

    // testing search
    long numberMeier = 1;
    succeeded = book->search("Hans", "Meier", numberMeier);
    if (succeeded) {
        std::cout << "Hans Meier: " << numberMeier << std::endl;
    }
    std::cout << std::endl;

    // testing 'getNames'
    std::forward_list<std::string> allNames = book->getNames();
    for (size_t i = 1; const auto & name : allNames) {
        std::cout << i << ": " << name << std::endl;
        ++i;
    }
    std::cout << std::endl;

    // testing iterator support of PhoneBook
    for (size_t i = 1; const auto & [first, last, number] : *book) {
        std::cout << i << ": " << first << " " << last << ": " << number << std::endl;
        ++i;
    }
}

void test_benchmark()
{
    //PhoneBook book;

    //std::string first{ "First_" };
    //std::string last{ "Last_" };

    //// Initialisierung
    //for (int i = 0; i < 1000000; ++i) {

    //    std::string vorname = first + std::to_string(i);
    //    std::string nachname = last + std::to_string(i);
    //    
    //    book.insert(vorname, nachname, 10000 + i);
    //}

    //std::cout << "Initialisierung fertig." << std::endl;

    //size_t size = book.vectorsizeof();

    //std::cout << "Vectorsizeof: " << size << std::endl;

    //// Test
    //for (int k = 0; k < 5; ++ k)
    //{
    //    const auto startTime{ std::chrono::high_resolution_clock::now() };

    //    for (int i = 0; i < 100; ++i) {

    //        // Element löschen
    //        book.remove("First_99", "Last_99");

    //        // Element wieder einfügen
    //        book.insert("First_99", "Last_99", 10000 + i);
    //    }

    //    const auto endTime{ std::chrono::high_resolution_clock::now() };

    //    std::cout
    //        << std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(endTime - startTime).count()
    //        << " msecs."
    //        << std::endl;
    //}
}


// Hauptprogramm
int main ()
{
    test_01();
    //test_02();
    //test_benchmark();

    return 0;
}