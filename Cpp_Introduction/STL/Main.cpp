// ===========================================================================
// Main.cpp // Standard Template Library
// ===========================================================================

#include <iostream>
#include <string>
#include <unordered_map>
#include <map>
#include <utility>
#include <vector>
#include <algorithm>

namespace StandardTemplateLibrary
{
    void testSTL01()
    {
        // array of arbitraty length of int-values
        std::vector<int> vec;

        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);

        // works only for STL container (random access operator [])
        for (int i = 0; i < vec.size(); ++i) {

            std::cout << i << ": " << vec[i] << std::endl;
        }
    }

    void testSTL02()
    {
        // array of arbitraty length of int-values
        std::vector<int> vec;

        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);

        // defining STL interators
        std::vector<int>::iterator first = vec.begin();
        std::vector<int>::iterator ende = vec.end();

        int value = *first;
        std::cout << value << std::endl;

        ++first;
        value = *first;
        std::cout << value << std::endl;

        ++first;
        value = *first;
        std::cout << value << std::endl;

        ++first;
        // value = *first;   // does this line work?
    }

    void testSTL03()
    {
        // array of arbitraty length of int-values
        std::vector<int> vec;

        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);

        // defining STL interators
        std::vector<int>::iterator first = vec.begin();
        std::vector<int>::iterator ende = vec.end();

        // traversal of a STL container,
        // being conformant with the STL iterator concept
        for (; first != ende; ++first) {

            int value = *first;
            std::cout << value << std::endl;
        }
    }

    // C-style function
    void print(int value)
    {
        std::cout << value << std::endl;
    }

    void testSTL04()
    {
        // array of arbitraty length of int-values
        std::vector<int> vec;

        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);

        std::for_each(
            vec.begin(),
            vec.end(),
            print
        );
    }

    void testSTL05()
    {
        std::vector<int> vec;

        for (int i = 0; i < 100; ++i) {

            vec.push_back(2 * i);

            std::cout
                << i << ": " << vec[i] << ", size: " << vec.size()
                << ", capacity: " << vec.capacity() << std::endl;
        }

        // vec.shrink_to_fit();

        //std::cout
        //    << "size: " << vec.size()
        //    << ", capacity: " << vec.capacity() << std::endl;
    }

    void testSTL06()
    {
        std::vector<int> vec;

        vec.resize(100);

        // initialize all elements with the value 1
        for (int i = 0; i < 100; ++i) {
            vec[i] = 1;
        }

        // or

        std::fill(vec.begin(), vec.end(), 1);
    }

    // global variable i
    int i = -1;

    int init() {
        // static int i = -1;

        ++i;
        return 2 * i + 1;
    }

    void testSTL07()
    {
        std::vector<int> vec;

        vec.resize(100);

        // initialize with computed values
        for (int i = 0; i < 100; ++i) {

            vec[i] = 2 * i + 1;
        }

        // or 

        std::generate(vec.begin(), vec.end(), init);
    }

    // callable class // callable object
    class InitializerForVector
    {
    private:
        int m_value;

    public:
        InitializerForVector() {
            m_value = -1;
        }

        int nextValue() {

            ++m_value;
            return 2 * m_value + 1;
        }

        int operator () () {

            ++m_value;
            return 2 * m_value + 1;
        }
    };

    class OutputForVector
    {
    public:

        void operator () (int value) {
            std::cout << value << std::endl;
        }
    };

    class GeneralPurposeVectorHelper
    {
    private:
        int m_value;

    public:
        GeneralPurposeVectorHelper() {
            m_value = -1;
        }

        // comparing a method ...
        int nextValue() {
            ++m_value;
            return 2 * m_value + 1;
        }

        // ... with an operator
        int operator () () {

            ++m_value;
            return 2 * m_value + 1;
        }

        // operators can be overloaded
        void operator () (int value) {
            std::cout << value << std::endl;
        }
    };

    void testSTL08()
    {
        InitializerForVector initializer;

        int next = initializer.nextValue();
        next = initializer.nextValue();
        next = initializer.nextValue();

        next = initializer();
        next = initializer();
        next = initializer();
    }

    void testSTL09()
    {
        std::vector<int> vec;
        vec.resize(5);

        OutputForVector output;

        // GeneralPurposeVectorHelper handler;

        std::for_each(
            vec.begin(),
            vec.end(),
            output
        );

        InitializerForVector initializer;

        std::generate(
            vec.begin(),
            vec.end(),
            initializer
        );

        std::for_each(
            vec.begin(),
            vec.end(),
            output
        );
    }

    void testSTL10()
    {
        std::vector<int> vec;
        vec.resize(100);

        std::generate(vec.begin(), vec.end(), init);

        // searching a value
        int element = 99;  // 99 should be an element of the vector, 98 not.

        std::vector<int>::iterator pos = std::find(vec.begin(), vec.end(), element);

        if (pos == vec.end()) {

            std::cout << "Element " << element << " not found!" << std::endl;
        }
        else {
            std::cout << "Element " << element << " found!" << std::endl;
        }
    }

    // =======================================================================

    class PhonebookHelper
    {
    public:
        void operator () (std::pair <std::string, int> entry) {

            std::cout << entry.first << " - " << entry.second << std::endl;
        }
    };

    void testSTL20()
    {
        // hash table with STL
        std::unordered_map<std::string, int> phoneBook;

        std::pair <std::string, int> firstEntry("Hans", 123456);
        phoneBook.insert(firstEntry);

        std::pair <std::string, int> secondEntry("Sepp", 654321);
        phoneBook.insert(secondEntry);

        std::pair <std::string, int> thirdEntry("Anton", 223355);
        phoneBook.insert(thirdEntry);

        // print phonebook to console
        PhonebookHelper helper;
        std::for_each(
            phoneBook.begin(),
            phoneBook.end(),
            helper
        );
    }

    void testSTL21()
    {
        // hash table with STL
        std::unordered_map<std::string, int> phoneBook;

        std::pair <std::string, int> firstEntry("Hans", 123456);
        phoneBook.insert(firstEntry);

        std::pair <std::string, int> secondEntry("Sepp", 654321);
        phoneBook.insert(secondEntry);

        std::pair <std::string, int> thirdEntry("Anton", 223355);
        phoneBook.insert(thirdEntry);

        // searching an entry
        std::string key("Sepp");

        std::unordered_map<std::string, int>::iterator  position = phoneBook.find(key);

        if (position == phoneBook.end()) {

            std::cout << "Name " << key << " not found in phonebook" << std::endl;
        }
        else {
            std::cout << "Name " << key << " found: ";
            std::pair <std::string, int> foundEntry = *position;
            int number = foundEntry.second;
            std::cout << number << std::endl;
        }
    }
}

void testSTL()
{
    using namespace StandardTemplateLibrary;

    testSTL01();
    testSTL02();
    testSTL03();
    testSTL04();
    testSTL05();
    testSTL06();
    testSTL07();
    testSTL08();
    testSTL09();
    testSTL10();

    testSTL20();
    testSTL21();
}

// ===========================================================================
// End-of-File
// ===========================================================================
