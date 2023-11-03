// ===========================================================================
// Main.cpp // Classes and Objects Improved
// ===========================================================================

#include "Time.h"

void testTimeImproved()
{
    using namespace Classes_Objects_Improved;

    Time now;
    now.setHours(10);
    now.setMinutes(20);
    now.setSeconds(30);
    now.print();

    // now.m_hours = 9999;   // doesn't compile

    now.increment();
    now.print();

    now.decrement();
    now.print();

    Time what;
    what.setHours(9999);
    what.print();            // watch output carefully
}

// ===========================================================================
// End-of-File
// ===========================================================================
