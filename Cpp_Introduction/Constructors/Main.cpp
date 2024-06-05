// ===========================================================================
// Main.cpp  // Constructors
// ===========================================================================

#include "Time.h"

void main_Constructors()
{
    using namespace Classes_Objects_Constructors;

    Time t1;
    t1.print();

    Time t2(12, 30, 0);
    t2.print();

    Time t3("09:30:00");
    t3.print();

    Time t4(24 * 60 * 60 - 1);
    t4.print();
}

// ===========================================================================
// End-of-File
// ===========================================================================
