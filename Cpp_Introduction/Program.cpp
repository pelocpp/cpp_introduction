// =====================================================================================
// https://github.com/pelocpp // https://peterloos.de
// =====================================================================================

#pragma message("Collection of introductionary C++ Code Examples - Copyright (C) 2019-2023 Peter Loos")

#include <iostream>

// function prototypes
extern void testTime();
extern void testTimeImproved();
extern void testTimeConstructors();
extern void testReferences();

int main()
{
    std::cout << "[Collection of introductionary C++ Code Examples - Copyright (C) 2019-2023 Peter Loos]" << std::endl;

    // main entry points code examples
    try
    {
        // testTime();
        // testTimeImproved();
        // testTimeConstructors();
        testReferences();
    }
    catch (const std::exception& ex) {
        std::cout << "Exception: " << ex.what() << std::endl;
    }

    std::cout << "[Done.]" << std::endl;
    return 0;
}

// =====================================================================================
// End-of-File
// =====================================================================================
