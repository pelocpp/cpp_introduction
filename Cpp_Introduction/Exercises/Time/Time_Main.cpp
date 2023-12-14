// ===========================================================================
// Time_Main.cpp
// ===========================================================================

#include "Time.h"

void testCtors()
{
    Time t1;
    std::cout << t1 << std::endl;
    Time t2(0, 30, 12);
    std::cout << t2 << std::endl;
    Time t3("09:30:00");
    std::cout << t3 << std::endl;
    Time t4(24 * 60 * 60 - 1);
    std::cout << t4 << std::endl;
}

void testAdd()
{
    // testing 'Add'
    Time t1(0, 0, 12);
    Time t2(33, 33, 3);
    for (int i = 0; i < 5; i++)
    {
        t1.add(t2);
        std::cout << t1 << std::endl;
    }
}

void testDiff()
{
    // testing 'Diff'
    Time t1;
    Time t2("23:59:59");
    Time t3 = t1.diff(t2);
    std::cout << t3 << std::endl;
    t3 = t2.diff(t1);
    std::cout << t3 << std::endl;
}

void testArithmeticOperators()
{
    // testing operators
    Time t1(15, 30, 6);
    Time t2 = t1 + t1;
    std::cout << t2 << std::endl;
    t2 += t1;
    std::cout << t2 << std::endl;
    t2 -= 120;
    std::cout << t2 << std::endl;
    t2 -= t1;
    std::cout << t2 << std::endl;
}

void testIncrementOperators()
{
    // testing 'Increment'
    Time t(55, 59, 23);
    for (int i = 0; i < 8; i++)
    {
        t.increment();
        std::cout << t << std::endl;
    }
}

void testIncrementDecrementOperators()
{
    // testing increment/decrement operator
    Time t1(0, 0, 12);
    Time t2 = t1++;
    std::cout << t2 << std::endl;
    t2 = ++t1;
    std::cout << t2 << std::endl;
    t2 = t1--;
    std::cout << t2 << std::endl;
    t2 = --t1;
    std::cout << t2 << std::endl;
}

void testConversion()
{
    Time t;
    t = 60 * 60 + 60 + 1;
    std::cout << "Time:    " << t << std::endl;
    std::cout << "Seconds: " << (int)t << std::endl;
}

void testInputOutput()
{
    Time t;
    std::cin >> t;
    std::cout << t << std::endl;
}

void exerciseTime()
{
    testCtors();
    testAdd();
    testDiff();
    testArithmeticOperators();
    testIncrementOperators();
    testIncrementDecrementOperators();
    testConversion();
    testInputOutput();
}

// ===========================================================================
// End-of-File
// ===========================================================================
