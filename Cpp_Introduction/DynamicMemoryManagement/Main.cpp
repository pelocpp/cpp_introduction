// ===========================================================================
// Main.cpp // Dynamic Memory Management
// ===========================================================================

#include <iostream>

namespace Dynamic_Memory_Management
{
    class SimpleClass
    {
    public:
        SimpleClass() { std::cout << "Default constructor SimpleClass" << std::endl; }

        void print () { std::cout << "SimpleClass" << std::endl; }
    };

    void dynamicMemory_Scalar()
    {
        // allocating a single int variable
        int* pInt = new int(123);
        std::cout << *pInt << std::endl;

        // releasing memory
        delete pInt;
    }

    void dynamicMemory_Array()
    {
        // allocating an array of int values
        int* pArray = new int[10];

        // initialize array
        for (int i = 0; i < 10; ++i) {
            pArray[i] = i;
        }

        // accessing dynamically allocated array
        for (int i = 0; i < 10; ++i) {
            std::cout << pArray[i] << ' ';
        }
        std::cout << std::endl;

        // releasing memory - note: array delete (!)
        delete[] pArray;
    }

    void dynamicMemory_Object()
    {
        // allocating a single variable
        SimpleClass* pSimpleClass = new SimpleClass;
        pSimpleClass->print();

        // releasing memory
        delete pSimpleClass;
    }
}

void testDynamicMemoryManagement()
{
    using namespace Dynamic_Memory_Management;

    dynamicMemory_Scalar();
    dynamicMemory_Array();
    dynamicMemory_Object();
}

// ===========================================================================
// End-of-File
// ===========================================================================
