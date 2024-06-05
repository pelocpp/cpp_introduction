// ===========================================================================
// Main.cpp // Operator Overloading
// ===========================================================================

#include "Time.h"

static void scriptSnippets()
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

    // -----------------------------------------------

    int x = 1 - 2 - 3;

    // -----------------------------------------------

    int a = 1;
    int b = 2;
    int c = 3;

    int d;

    d = c = b = a;
}

static void timeOperators()
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

void main_OperatorsOverloading()
{
    scriptSnippets();
    timeOperators();
}

// ===========================================================================
// End-of-File
// ===========================================================================
