// ===========================================================================
// Main.cpp // Operator Overloading
// ===========================================================================

#include "Time.h"

void scriptSnippets()
{
    using namespace OperatorOverloading;

    int n = 123;
    int m = 456;

    if (n == m) {
        std::cout << "n and m are equal" << std::endl;
    }

    Time now(10, 20, 30);
    Time later(17, 0, 0);

    if (now == later) {
        std::cout << "'now' and 'later' are equal" << std::endl;
    }
}

void testTimeOperators()
{
    using namespace OperatorOverloading;

    Time now(10, 20, 30);
    Time later(17, 0, 0);

    if (now == later) {
        std::cout << "'now' and 'later' are equal" << std::endl;
    }
    else {
        std::cout << "'now' and 'later' are not equal" << std::endl;
    }

    if (now < later) {
        std::cout << "'now' is less than 'later'" << std::endl;
    }
}

void testOperatorsOverloading()
{
    scriptSnippets();
    testTimeOperators();
}

// ===========================================================================
// End-of-File
// ===========================================================================
