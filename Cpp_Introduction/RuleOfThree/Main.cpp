// ===========================================================================
// Main.cpp // "Rule of Three"
// ===========================================================================

#include "BigData.h"

namespace Rule_Of_Three {

    class Time{};

    static void scriptSnippets01()
    {
        Time t1;
        Time t2;
        // ...
        t1 = t2;
    }

    static void scriptSnippets02()
    {
        Time t1;
        // ...
        Time t2 (t1);
    }

    static void scriptSnippets()
    {
        scriptSnippets01();
        scriptSnippets02();
    }

    // test methods
    static void testRuleOfThree01() {

        BigData data(100);
    }

    static void testRuleOfThree02() {

        BigData data1(100);
        BigData data2;
        data2 = data1;
    }

    static void testRuleOfThree03() {

        BigData data1(100);
        BigData data2(data1);
    }

    BigData createBigData() {
        BigData data(100);
        return data;
    }

    static void testRuleOfThree04() {

        BigData data;
        data.print();
        data = createBigData();
        data.print();
    }

    static void testRuleOfThree05() {

        BigData data;
        data = BigData(100);
    }
}

void testRuleOfThree()
{
    using namespace Rule_Of_Three;

    testRuleOfThree01();
    testRuleOfThree02();
    testRuleOfThree03();
    testRuleOfThree04();
    testRuleOfThree05();
}

// ===========================================================================
// End-of-File
// ===========================================================================
