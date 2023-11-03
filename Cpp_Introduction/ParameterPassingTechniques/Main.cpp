// ===========================================================================
// Main.cpp // Parameter Passing Techniques
// ===========================================================================

#include <iostream>

namespace Parameter_Passing_Techniques
{
    void func(int a, int b)
    {
        int sum;

        sum = a + b;

        std::cout << "In func: a = " << a << ", b = " << b << ", sum = " << sum << std::endl;
    }
    
    void testFunc()
    {
        int x = 123;
        int y = 456;

        // passing parameters
        func(x, y);

        // passing again parameters
        func(123, 321);
    }

    void scriptSnippets()
    {
        testFunc();
    }

    // doesn't do, what the function name promises (why)
    void multiplyByTwo01(int n)
    {
        n = 2 * n;
    }

    // C-like Solution
    void multiplyByTwo02(int* ip)      // demonstrating use of address (*)
    {
        int tmp = *ip;                 // *: Value-Of / value behind the address

        tmp = 2 * tmp;

        *ip = tmp;

        // or with a single statement
        // *ip = 2 * *ip;
    }

    // C++-like Solution
    void multiplyByTwo03(int& n)       // demonstrating use of reference (&)
    {
        n = 2 * n;
    }

    void testMultiplyByTwo()
    {
        int x = 10;

        std::cout << x << std::endl;

        multiplyByTwo01(123);

        std::cout << x << std::endl;

        multiplyByTwo02(&x);           // &: address-of / pointer is passed

        // multiplyByTwo02(123);       // why does this not compile?

        std::cout << x << std::endl;

        multiplyByTwo03(x);            // Take care: a reference of 'x' is passed
                                        // (it's the address of x, that's being passed)

        std::cout << x << std::endl;

        // multiplyByTwo03(123);       // why does this not compile?
    }
}

void testParameterPassing()
{
    using namespace Parameter_Passing_Techniques;

    //scriptSnippets();
    testMultiplyByTwo();
}

// ===========================================================================
// End-of-File
// ===========================================================================
