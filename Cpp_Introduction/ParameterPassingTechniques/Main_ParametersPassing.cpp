// ===========================================================================
// Main_ParametersPassing.cpp // Parameter Passing Techniques
// ===========================================================================

#include <iostream>

namespace Parameter_Passing_Techniques
{
    static void func(int a, int b)
    {
        int sum;

        sum = a + b;

        std::cout << "In func: a = " << a << ", b = " << b << ", sum = " << sum << std::endl;
    }
    
    static void testFunc()
    {
        int x = 123;
        int y = 456;

        // passing parameters
        func(x, y);

        // passing again parameters
        func(123, 321);
    }

    static void scriptSnippets()
    {
        testFunc();
    }

    // doesn't do, what the function name promises (why)
    static void multiplyByTwo01(int n)
    {
        n = 2 * n;
    }

    // C-like Solution
    static void multiplyByTwo02(int* ip)      // demonstrating use of address (*)
    {
        int tmp = *ip;                 // *: Value-Of / value behind the address

        tmp = 2 * tmp;

        *ip = tmp;

        // or with a single statement
        // *ip = 2 * *ip;
    }

    // C++-like Solution
    static void multiplyByTwo03(int& n)       // demonstrating use of reference (&)
    {
        n = 2 * n;
    }

    static void multiplyByTwo()
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

void main_ParameterPassing()
{
    using namespace Parameter_Passing_Techniques;

    scriptSnippets();
    multiplyByTwo();
}

// ===========================================================================
// End-of-File
// ===========================================================================
