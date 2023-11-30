// ===========================================================================
// References_Pointers_Main.cpp
// ===========================================================================

#include <iostream>

void swap(int n, int m)
{
    int tmp = n;
    n = m;
    m = tmp;
}

void swapPointers(int* n, int* m)
{
    int tmp = *n;
    *n = *m;
    *m = tmp;
}

void swapReferences(int& n, int& m)
{
    int tmp = n;
    n = m;
    m = tmp;
}

void exerciseReferencesPointers01()
{
    int a = 1;
    int b = 2;

    std::cout << "a: " << a << " - b: " << b << std::endl;

    swap(a, b);

    std::cout << "a: " << a << " - b: " << b << std::endl;
}

void exerciseReferencesPointers02()
{
    int a = 1;
    int b = 2;

    std::cout << "a: " << a << " - b: " << b << std::endl;

    swap(a, b);

    std::cout << "a: " << a << " - b: " << b << std::endl;
}

void exerciseReferencesPointers03()
{
    int a = 1;
    int b = 2;

    std::cout << "a: " << a << " - b: " << b << std::endl;

    swap(a, b);

    std::cout << "a: " << a << " - b: " << b << std::endl;
}

void exerciseReferencesPointers()
{
    exerciseReferencesPointers01();
    exerciseReferencesPointers02();
    exerciseReferencesPointers03();
}

// ===========================================================================
// End-of-File
// ===========================================================================


