// ===========================================================================
// Main.cpp // Streams
// ===========================================================================

#include <iostream>
#include <string>

namespace Streams
{
    static void scriptSnippets()
    {
        int n;
        std::cout << "Geben Sie eine Zahl ein: ";
        std::cin >> n;
        std::cout << "n: " << n << std::endl;
    }

    static void testCinCout()
    {
        int myInt;
        double myDouble;

        std::cout << "int:    ";
        std::cin >> myInt;

        std::cout << "double: ";
        std::cin >> myDouble;

        std::cout << "Int:    " << myInt << std::endl;
        std::cout << "Double: " << myDouble << std::endl;
    }
}

void testStreams()
{
    using namespace Streams;

    scriptSnippets();
    testCinCout();
}

// ===========================================================================
// End-of-File
// ===========================================================================
