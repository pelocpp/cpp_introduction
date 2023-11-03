// ===========================================================================
// Main.cpp // References
// ===========================================================================

#include <iostream>

namespace References
{
    void scriptSnippets()
    {
        int var = 123;
        int& rVar = var;

        std::cout << var << std::endl;
        std::cout << rVar << std::endl;
    }

    void referencesUnderstanding()
    {
        int n = 123;
        int m;

        // using pointers
        int* ip;

        ip = &n;      // address-of
        
        m = *ip;      // value-of / same as: m = n;
        
        ++ip;
        m = *ip;      // m = ???
        
        --ip;
        m = *ip;      // again value of n

        // using references
        int& ri = n;
        
        m = ri;       // same as: m = n;
        
        ++ri;         // n is now n + 1
    }
}

void testReferences()
{
    using namespace References;

    scriptSnippets();
    referencesUnderstanding();
}

// ===========================================================================
// End-of-File
// ===========================================================================
