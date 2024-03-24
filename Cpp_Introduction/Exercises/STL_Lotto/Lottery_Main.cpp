// ===========================================================================
// Lottery_Main.cpp
// ===========================================================================

#include "Lottery.h"

#include <iostream>
#include <algorithm>

static void testLottery01()
{
    Lottery lottery(55);
    lottery.play();
    lottery.print();
}

static void printDrawNumber(int number) {
    std::cout << "> " << number << std::endl;
}

static void testLottery02()
{
    std::cout << std::endl;
    std::cout << "Ziehung der Lottozahlen:" << std::endl;;
    std::cout << "========================" << std::endl;;

    // using std::for_each
    Lottery lottery(55);
    std::for_each(
        lottery.begin(),
        lottery.end(),
        printDrawNumber
    );
}

static void testLottery03()
{
    std::cout << std::endl;
    std::cout << "Ziehung der Lottozahlen:" << std::endl;;
    std::cout << "========================" << std::endl;;

    // using range-based for loop
    Lottery lottery(55);
    for (int number : lottery) {
        std::cout << "> " << number << std::endl;
    }
}

void exerciseLotto()
{
    testLottery01();
    testLottery02();
    testLottery03();
}

// ===========================================================================
// End-of-File
// ===========================================================================
