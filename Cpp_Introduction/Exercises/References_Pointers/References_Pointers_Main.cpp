// ===========================================================================
// References_Pointers_Main.cpp
// ===========================================================================

#include <iostream>

static void swap(int n, int m)
{
    int tmp = n;
    n = m;
    m = tmp;
}

static void swapPointers(int* n, int* m)
{
    int tmp = *n;
    *n = *m;
    *m = tmp;
}

static void swapReferences(int& n, int& m)
{
    int tmp = n;
    n = m;
    m = tmp;
}

static void testReferencesPointers01()
{
    int a = 1;
    int b = 2;

    std::cout << "a: " << a << " - b: " << b << std::endl;

    swap(a, b);

    std::cout << "a: " << a << " - b: " << b << std::endl;
}

static void testReferencesPointers02()
{
    int a = 1;
    int b = 2;

    std::cout << "a: " << a << " - b: " << b << std::endl;

    swap(a, b);

    std::cout << "a: " << a << " - b: " << b << std::endl;
}

static void testReferencesPointers03()
{
    int a = 1;
    int b = 2;

    std::cout << "a: " << a << " - b: " << b << std::endl;

    swap(a, b);

    std::cout << "a: " << a << " - b: " << b << std::endl;
}

void exerciseReferencesPointers()
{
    testReferencesPointers01();
    testReferencesPointers02();
    testReferencesPointers03();
}

// ===========================================================================
// End-of-File
// ===========================================================================


