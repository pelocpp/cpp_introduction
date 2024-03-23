// ===========================================================================
// Lotto_Main.cpp
// ===========================================================================


#include "Lotto.h"

#include <iostream>

static void testLotto01()
{
    Lotto lotto(55);
    lotto.play();
    lotto.print();
}

static void testLotto02()
{
    Lotto lotto(55);
    lotto.playEx();  // uses std::generate
    lotto.print();
}

static void testLotto03()
{
    Lotto lotto(55);

    // range-based for loop
    //for (int number : lotto) {
    //    std::cout << "  ... number " << number << std::endl;
    //}
}

void exerciseLotto()
{
    testLotto01();
    testLotto02();
    testLotto03();
}

// ===========================================================================
// End-of-File
// ===========================================================================
