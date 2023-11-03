// ===========================================================================
// Main.cpp // Classes and Objects
// ===========================================================================

#include "Time.h"

void testClassesObjects()
{
    using namespace Classes_Objects;

    Time now;
    now.m_hours = 10;
    now.m_minutes = 20;
    now.m_seconds = 30;
    now.print();

    Time later;
    later.m_hours = 17;
    later.m_minutes = 0;
    later.m_seconds = 0;
    later.print();

    now.increment();
    now.print();

    now.reset();
    now.print();
}

// ===========================================================================
// End-of-File
// ===========================================================================
