// ===========================================================================
// Main.cpp  // "Hello World"
// ===========================================================================

#include <iostream>

namespace HelloWorld {

    void helloWorldClassic()
    {
        std::printf("Hello World\n");
    }

    void helloWorldCpp()
    {
        std::cout << "Hello World" << std::endl;
    }
}

void testHelloWorld()
{
    using namespace HelloWorld;

    helloWorldClassic();
    helloWorldCpp();
}

// ===========================================================================
// End-of-File
// ===========================================================================
