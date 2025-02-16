// ===========================================================================
// Main.cpp // Dynamic Memory
// ===========================================================================

#include <cstdlib>
#include <ctime>
#include <iostream>

namespace Dynamic_Memory
{
    class SimpleClass
    {
    public:
        SimpleClass() { std::cout << "c'tor" << std::endl; }

        void print () { std::cout << "print" << std::endl; }

        ~SimpleClass() { std::cout << "d'tor" << std::endl; }
    };

    static void dynamicMemory_Scalar()
    {
        // allocating a single int variable
        int* pi = new int(123);
        std::cout << *pi << std::endl;

        // releasing memory
        delete pi;
    }

    static void dynamicMemory_Array()
    {
        // allocating an array of int values
        int* pArray = new int[5];

        // initialize array
        for (int i = 0; i < 5; ++i) {
            pArray[i] = i;
        }

        // accessing dynamically allocated array
        for (int i = 0; i < 5; ++i) {
            std::cout << pArray[i] << ' ';
        }
        std::cout << std::endl;

        // releasing memory - note: array delete (!)
        delete[] pArray;
    }

    static void dynamicMemory_ScalarObject()
    {
        // allocating a single variable
        SimpleClass* pSimpleClass = new SimpleClass;

        pSimpleClass->print();

        // releasing memory
        delete pSimpleClass;
    }

    static void dynamicMemory_ArrayObject()
    {
        // allocating and initializing an array of objects
        SimpleClass* pArray = new SimpleClass[5];

        // accessing dynamically allocated objects
        for (int i = 0; i < 5; ++i) {
            pArray[i].print();
        }

        // releasing memory - note: array delete (!)
        delete[] pArray;
    }
}

namespace Dynamic_Memory_Lottery
{
    class LotteryTickets
    {
    private:
        int  m_count;
        int* m_tickets;

    public:
        LotteryTickets() : m_count (0), m_tickets (NULL)
        {
            std::srand(  static_cast<unsigned int>(std::time(0))); // use current time as seed for random generator
        }

        ~LotteryTickets() {
            delete[] m_tickets; 
        }

        void buyTickets(int count)
        {
            m_count = count;
            m_tickets = new int[m_count];   // buying 'count' tickets at once

            for (int i = 0; i < m_count; i++) {
                m_tickets[i] = 1 + rand() % 49;
            }
        }

        void printTickets()
        {
            for (int i = 0; i < m_count; i++) {
                std::cout << "Ticket " << (i + 1) << ": " << m_tickets[i] << std::endl;
            }
        }
    };

    static void test_lottery()
    {
        std::cout << "How many lottery tickets do you want to buy? ";

        int numTickets;
        std::cin >> numTickets;

        LotteryTickets lottery;
        lottery.buyTickets(numTickets);
        lottery.printTickets();
    }
}

void main_DynamicMemory()
{
    using namespace Dynamic_Memory;

    dynamicMemory_Scalar();
    dynamicMemory_Array();
    dynamicMemory_ScalarObject();
    dynamicMemory_ArrayObject();

    using namespace Dynamic_Memory_Lottery;
    test_lottery();
}

// ===========================================================================
// End-of-File
// ===========================================================================
