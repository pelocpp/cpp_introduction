// ===========================================================================
// Main.cpp // "Rule of Three"
// ===========================================================================

#include "BigData.h"

namespace Rule_Of_Three {

    class Time{};


    void scriptSnippets01()
    {
        Time t1;
        Time t2;
        // ...
        t1 = t2;
    }

    void scriptSnippets02()
    {
        Time t1;
        // ...
        Time t2 (t1);
    }

    void scriptSnippets()
    {
        scriptSnippets01();
        scriptSnippets02();
    }

    // test methods
    void testRuleOfThree01() {

        BigData data(100);
    }

    void testRuleOfThree02() {

        BigData data1(100);
        BigData data2;
        data2 = data1;
    }

    void testRuleOfThree03() {

        BigData data1(100);
        BigData data2(data1);
    }

    BigData createBigData() {
        BigData data(100);
        return data;
    }

    void testRuleOfThree04() {

        BigData data;
        data.print();
        data = createBigData();
        data.print();
    }

    void testRuleOfThree05() {

        BigData data;
        data = BigData(100);
    }
}

void testRuleOfThree()
{
    using namespace Rule_Of_Three;

    testRuleOfThree01();
    //testRuleOfThree02();
    //testRuleOfThree03();
    //testRuleOfThree04();
    //testRuleOfThree05();
}

// ===========================================================================
// End-of-File
// ===========================================================================
