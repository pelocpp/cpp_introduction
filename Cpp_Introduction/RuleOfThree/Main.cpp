// ===========================================================================
// Main.cpp // "Rule of Three"
// ===========================================================================

#include "BigData.h"

namespace Rule_Of_Three {

    // test methods
    BigData createBigData() {
        BigData data(100);
        return data;
    }

    void testRuleOfThree01() {

        BigData data;
        data.print();
        data = createBigData();
        data.print();
    }

    void testRuleOfThree02() {

        BigData data;
        data = BigData(100);
    }
}

void testRuleOfThree()
{
    using namespace Rule_Of_Three;

    testRuleOfThree01();
    testRuleOfThree02();
}

// ===========================================================================
// End-of-File
// ===========================================================================
