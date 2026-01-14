// ===========================================================================
// Main.cpp // Memory Management
// ===========================================================================

#include <iostream>

namespace Memory_Management
{
    int g_counter = 0;
}

void main_MemoryManagement_01()
{
    int a = 1;
    int b = 2;
    int sum = a + b;
}

void main_MemoryManagement()
{
    using namespace Memory_Management;

    std::cout << "g_counter: " << g_counter << std::endl;
}

// ===========================================================================
// End-of-File
// ===========================================================================
