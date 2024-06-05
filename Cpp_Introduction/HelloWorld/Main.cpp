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

void main_HelloWorld()
{
    using namespace HelloWorld;

    helloWorldClassic();
    helloWorldCpp();
}

// ===========================================================================
// End-of-File
// ===========================================================================
