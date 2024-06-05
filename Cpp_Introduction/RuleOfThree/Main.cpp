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
    static void ruleOfThree01() {

        BigData data(100);
    }

    static void ruleOfThree02() {

        BigData data1(100);
        BigData data2;
        data2 = data1;
    }

    static void ruleOfThree03() {

        BigData data1(100);
        BigData data2(data1);
    }

    BigData createBigData() {
        BigData data(100);
        return data;
    }

    static void ruleOfThree04() {

        BigData data;
        data.print();
        data = createBigData();
        data.print();
    }

    static void ruleOfThree05() {

        BigData data;
        data = BigData(100);
    }
}

void main_RuleOfThree()
{
    using namespace Rule_Of_Three;

    ruleOfThree01();
    ruleOfThree02();
    ruleOfThree03();
    ruleOfThree04();
    ruleOfThree05();
}

// ===========================================================================
// End-of-File
// ===========================================================================
