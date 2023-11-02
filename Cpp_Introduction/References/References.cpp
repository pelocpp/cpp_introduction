// ===========================================================================
// References.cpp
// ===========================================================================
//
//#include <iostream>
//
//namespace References
//{
//    void referencesUnderstanding()
//    {
//        int n = 123;
//        int m;
//
//        int* ip;
//        ip = &n;
//        m = *ip;      // same as: m = n;
//        ++ip;
//        m = *ip;      // m = ???
//        --ip;
//        m = *ip;      // same as: m = n;
//
//        int& ri = n;
//        m = ri;       // same as: m = n;
//        ++ri;         // n is now n + 1
//    }
//
//    // doesn't do, what the function name promises (why)
//    void multiplyByTwo(int n)
//    {
//        n = 2 * n;
//    }
//
//    // C-like Solution
//    void multiplyByTwoEx(int* ip)     // address
//    {
//        int tmp = *ip;    // *: value of // value behind the address
//
//        tmp = 2 * tmp;
//
//        *ip = tmp;
//
//        // or with a single statement
//        *ip = 2 * *ip;
//    }
//
//    // C++-like Solution
//    void multiplyByTwoExEx(int& n)     // & reference
//    {
//        n = 2 * n;
//    }
//
//    void testMultiplyByTwo()
//    {
//        int x = 10;
//
//        std::cout << x << '\n';
//
//        multiplyByTwo(123);
//
//        std::cout << x << '\n';
//
//        multiplyByTwoEx(&x);   // &: Address of 
//
//        std::cout << x << '\n';
//
//        multiplyByTwoExEx(x);   // Reference is passed
//        // (address of x is passed)
//
//        std::cout << x << '\n';
//    }
//
//}


// ===========================================================================
// End-of-File
// ===========================================================================
