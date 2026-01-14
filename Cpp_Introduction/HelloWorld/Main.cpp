// ===========================================================================
// Main.cpp  // "Hello World"
// ===========================================================================

#include <iostream>

namespace HelloWorld {

    static void helloWorldClassic()
    {
        std::printf("Hello World\n");
    }

    static void helloWorldCpp()
    {
        std::cout << "Hello World" << std::endl;
    }
}

void main_HelloWorld()
{
    using namespace HelloWorld;

    helloWorldClassic();
    helloWorldCpp();
}

// ===========================================================================
// End-of-File
// ===========================================================================
